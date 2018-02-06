#include "Entity.h"
Entity::Entity(size_t i) : id(i) {}

size_t Entity::GetId() const {
	return id;
}
unsigned short Entity::GetComponentIndex(ComponentType t) const {
	return components[t];
}