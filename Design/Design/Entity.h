#pragma once
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
	std::string tag;
	array<unsigned short, ComponentType_Count> components;
public:
	bool HasTag(std::string _tag) const { return tag.compare(_tag) == 0; }
	std::string GetTag() const { return tag; }
	void SetTag(std::string _tag) { tag = _tag; }

	short GetId() const;
	void SetComponent(ComponentType t, unsigned short i) { components[t] = i; }
	void SetId(int i) { id = i; }						//Remove This!!!!!
	unsigned short GetComponentIndex(ComponentType t) const;
};