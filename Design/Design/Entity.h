#pragma once
#include <string>
#include <array>
#include "Transform.h"
#include "Component.h"

using std::array;

class EntityManager;

class Entity {
	friend class EntityManager;
private:
	Entity(size_t _id);
	size_t id;
	array<unsigned short, ComponentType_Count> components;
public:
	size_t GetId() const;
	void SetComponent(ComponentType t, unsigned short i) { components[t] = i; }
	void SetId(int i) { id = i; }						//Remove This!!!!!
	unsigned short GetComponentIndex(ComponentType t) const;
};