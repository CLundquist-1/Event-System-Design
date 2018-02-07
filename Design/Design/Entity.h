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
	Entity(short _id);
	short id;
	array<unsigned short, ComponentType_Count> components;
public:
	short GetId() const;
	void SetComponent(ComponentType t, unsigned short i) { components[t] = i; }
	void SetId(int i) { id = i; }						//Remove This!!!!!
	unsigned short GetComponentIndex(ComponentType t) const;
};