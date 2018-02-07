#include "EntityManager.h"
vector<Entity> EntityManager::dynamicEntities;
vector<Entity> EntityManager::staticEntities;
#define COMPONENTS 	X(BodyComponent)
#define X(ARG) std::vector<ARG>
std::tuple<COMPONENTS> EntityManager::components;
#undef X
#undef COMPONENTS

size_t EntityManager::nextEntityId = 0;


void EntityManager::Initialize(int numContestants) {
	dynamicEntities.reserve(numContestants);
	staticEntities.reserve(128);
}

Entity& EntityManager::CreateEntity(std::vector<Entity> &entities) {
	size_t id = nextEntityId++;
	entities.push_back(Entity(id));
	Entity& entity = entities.back();
	return entity;
}

Entity& EntityManager::CreateDynamicEntity() {
	return CreateEntity(dynamicEntities);
}

Entity& EntityManager::CreateStaticEntity() {
	return CreateEntity(staticEntities);
}