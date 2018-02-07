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
	unsigned short i = id & ~(1 << typeBit);
	/*if (id & (1 << typeBit))
		return &dynamicEntities[i];
	else
		&staticEntities[i];*/
	return (id & (1 << typeBit)) ? &dynamicEntities[i] : &staticEntities[i];
}

vector<Entity*> EntityManager::FindEntities(std::string tag) {
	vector<Entity*> taggedEntities;
	for (Entity &e : dynamicEntities) {
		if (tag == e.GetTag())
			taggedEntities.push_back(&e);
	}
	for (Entity &e : staticEntities) {
		if (tag == e.GetTag())
			taggedEntities.push_back(&e);
	}
	return taggedEntities;
}

void EntityManager::Initialize(int numContestants) {
	dynamicEntities.reserve(numContestants);
	staticEntities.reserve(128);
}

Entity& EntityManager::CreateEntity(std::vector<Entity> &entities, unsigned short i) {
	//size_t id = nextEntityId++;
	//idToEntity[id] = entity;
	entities.push_back(Entity((entities.size() | (i << typeBit))));
	//cout << "Unisgned Entity ID: " << (unsigned short)entities[0].GetId();
	//entities.push_back(Entity((entities.size() * i))));
	Entity& entity = entities.back();
	return entity;
}

Entity& EntityManager::CreateDynamicEntity() {
	return CreateEntity(dynamicEntities, 1);
}

Entity& EntityManager::CreateStaticEntity() {
	return CreateEntity(staticEntities, 0);
}