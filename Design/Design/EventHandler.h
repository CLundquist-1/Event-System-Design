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

template<bool, class E, class C> struct ComponentSelector {
	static void HandleEvent(E *e) { }
};

template<class E, class C> struct ComponentSelector<true, E, C> {
	static void HandleEvent(E *e) {
		for (C c : EntityManager::Components<C>()) {
			c.HandleEvent(e);
		}
	}
};

template<class E>
class EventHandler {
public:
	static void HandleEvent(E *e) {
#define X(ARG) ComponentSelector <E::GetBitMask() & ARG::GetListeners(), E, ARG>::HandleEvent(e);
		COMPONENTS
#undef X
		//ComponentSelector <E::GetBitMask() & BodyComponent::GetListeners(), E, BodyComponent>::HandleEvent(e);
	}
};