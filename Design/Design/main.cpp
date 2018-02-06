#include "Game.h"
#include <iostream>
#include <bitset>
using std::cout;
using std::getchar;
using std::bitset;
using std::endl;

int main() {
	BodyComponent b;
	cout << "Body Listeners Bitmask: " << std::bitset<16>(b.GetListeners()) << endl;
	cout << "Type: " << b.GetType() << endl;
	cout << "Collision Event Type: " << CollisionEvent::GetType() << endl;
	CollisionEvent c(1, 2, 3);
	cout << "Specific Collision: " << c.GetSource() << " " << c.GetAffected() << " " << c.GetDamage() << endl;
	cout << "Collision Bitmask: " << std::bitset<16>(CollisionEvent::GetBitMask()) << endl;
	Game::Initialize(4, 8);
	Entity& e = EntityManager::CreateDynamicEntity();
	cout << "Entity ID: " << e.GetId() << endl;;
	e.SetId(1);
	Entity& e2 = EntityManager::dynamicEntities.back();
	cout << "Altered Entity ID: " << e2.GetId() << endl;
	EntityManager::AddComponent(e, BodyComponent());
	cout << "BodyComponents Size: " << EntityManager::BodyComponents.size() << endl;
	Game::QueEvent(c);
	cout << "Collision Event Count: " << Game::CE.size() << endl;
	Game::ResolveEvents();
	cout << "Collision Event Count: " << Game::CE.size() << endl;
	getchar();
	return 0;
}