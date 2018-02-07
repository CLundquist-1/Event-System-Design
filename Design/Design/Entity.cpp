#include "Entity.h"
Entity::Entity(short i) : id(i) {}

short Entity::GetId() const {
	return id;
}
unsigned short Entity::GetComponentIndex(ComponentType t) const {
	return components[t];
}