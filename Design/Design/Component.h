#pragma once
#include "Event.h"
#include<iostream>

using std::cout;
using std::endl;

enum ComponentType {
	ComponentType_Camera,
	ComponentType_PointLight,
	ComponentType_DirectionLight,
	ComponentType_SpotLight,
	ComponentType_Body,
	ComponentType_Driver,
	ComponentType_Count,
	ComponentType_Mesh
};

template<class T,  EventType... events>
class Component {
private:

	//Recursive template helpers
	template <EventType Last>
	static constexpr unsigned short BitCalc() {
		return 1 << Last;
	}

	template <EventType First, EventType Second, EventType ...Rest>
	static constexpr unsigned short BitCalc() {
		return BitCalc<First>() | BitCalc<Second, Rest...>();
	}



	//Actual bitmask we will use
	static constexpr unsigned short listeners = BitCalc<events...>();

public:
	//Getters
	static constexpr ComponentType GetType() { return T::InternalGetType(); }
	//Ensures that derived classes must implement their own InternalGetType() method
	template<class E>
	void HandleEvent(E *e) { return static_cast<T>(this)->InternalHandleEvent(E *e); }
	static constexpr int GetListeners() { return listeners; }
};

class BodyComponent : public Component<BodyComponent, EventType_Accelerate, EventType_Collision> {
	friend class Component<BodyComponent, EventType_Accelerate, EventType_Collision>;
protected:
	static constexpr ComponentType InternalGetType() { return ComponentType_Body; }
public:
	void HandleEvent(CollisionEvent *e) {
		cout << "(BodyComponent) Hello World! I have arrived!" << endl;
	}
};