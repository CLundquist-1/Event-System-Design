#pragma once
#include "Entity.h"
#include <vector>
#include "Component.h"


///As a quick note the entity manager will reserve the first #contestants indices of applicable vectors for the contestants in play, the first #numplayers of which will be human controlled

using std::vector;

enum EntityType {
	EntityType_Static,
	EntityType_Dynamic
};

///////////////////This is the only part we have to update when new Components are Added////////////////////////////////////////
#define COMPONENTS 	X(BodyComponent)
#define X(ARG) std::vector<ARG>
using ComponentTuple = std::tuple<COMPONENTS>;
#undef X
//#undef COMPONENTS

class EntityManager {
private:
	static ComponentTuple components;
	static size_t nextEntityId;
public:
	static vector<Entity> dynamicEntities;
	static vector<Entity> staticEntities;
	static vector<Transform> transforms;
	//These are returning references to the original
	static Entity& CreateDynamicEntity();
	static Entity& CreateStaticEntity();
	static Entity& CreateEntity(vector<Entity> &entities);
	
	//static void AddComponent(ComponentType);
	static void Initialize(int);

	template<class T>
	static auto& Components();

	template<class T>
	static void AddComponent(Entity&, T);
};

template<class T>
auto& EntityManager::Components()
{
	return std::get<std::vector<T>>(components);
}

template<class T>
void EntityManager::AddComponent(Entity& e, T c) {
	auto& comp = Components<T>();
	comp.push_back(c);
	e.SetComponent(c.GetType(), comp.size());
}