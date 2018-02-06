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

class EntityManager {
private:
	static size_t nextEntityId;
public:
	static vector<Entity> dynamicEntities;
	static vector<Entity> staticEntities;
	static vector<BodyComponent> BodyComponents;
	static vector<Transform> transforms;
	//These are returning references to the original
	static Entity& CreateDynamicEntity();
	static Entity& CreateStaticEntity();
	static Entity& CreateEntity(vector<Entity> &entities);
	static void AddComponent(Entity&, BodyComponent);
	//static void AddComponent(ComponentType);
	static void Initialize(int);
};