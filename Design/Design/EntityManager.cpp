#include "EntityManager.h"
vector<Entity> EntityManager::dynamicEntities;
vector<Entity> EntityManager::staticEntities;
//vector<Entity> EntityManager::entities;


#define COMPONENTS 	X(BodyComponent)
#define X(ARG) std::vector<ARG>
std::tuple<COMPONENTS> EntityManager::components;
#undef X
#undef COMPONENTS


Entity* EntityManager::FindEntity(short id) {
	if (id > 0) {
		return &dynamicEntities[id - 1];
	}
	else {
		return &staticEntities[id - 1];
	}
}

vector<Entity*> EntityManager::FindEntities(std::string tag) {

}

void EntityManager::Initialize(int numContestants) {
	dynamicEntities.reserve(numContestants);
	staticEntities.reserve(128);
}

Entity& EntityManager::CreateEntity(std::vector<Entity> &entities, short i) {
	//size_t id = nextEntityId++;
	//idToEntity[id] = entity;
	entities.push_back(Entity((entities.size()+1)*i));
	Entity& entity = entities.back();
	return entity;
}

Entity& EntityManager::CreateDynamicEntity() {
	return CreateEntity(dynamicEntities, 1);
}

Entity& EntityManager::CreateStaticEntity() {
	return CreateEntity(staticEntities, -1);
}