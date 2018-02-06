#include "EntityManager.h"
vector<Entity> EntityManager::dynamicEntities;
vector<Entity> EntityManager::staticEntities;
vector<BodyComponent> EntityManager::BodyComponents;

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

void EntityManager::AddComponent(Entity& e, BodyComponent c) {
	BodyComponents.push_back(c);
	e.SetComponent(c.GetType(), BodyComponents.size());
}