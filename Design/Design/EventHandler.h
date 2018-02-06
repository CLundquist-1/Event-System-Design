#pragma once
#include "EntityManager.h"

/*
enum ComponentType {
	ComponentType_Mesh,
	ComponentType_Camera,
	ComponentType_PointLight,
	ComponentType_DirectionLight,
	ComponentType_SpotLight,
	ComponentType_Body,
	ComponentType_Driver
};
*/

template<bool, class E> struct BodySelector {
	static void HandleEvent(E *e) { }
};

template<class E> struct BodySelector<true, E> {
	static void HandleEvent(E *e) {
		for (BodyComponent c : EntityManager::BodyComponents) {
			c.HandleEvent(e);
		}
		EntityManager::BodyComponents.clear();
	}
};

template<class E>
class EventHandler {
public:
	static void HandleEvent(E *e) {
		BodySelector <E::GetBitMask() & BodyComponent::GetListeners(), E>::HandleEvent(e);
	}
};