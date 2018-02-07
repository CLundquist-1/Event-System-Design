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
	//e.SetId(1);
	//Entity& e2 = EntityManager::dynamicEntities.back();
	//cout << "Altered Entity ID: " << e2.GetId() << endl;
	EntityManager::AddComponent(e, BodyComponent());
	cout << "BodyComponents Size: " << EntityManager::Components<BodyComponent>().size() << endl;
	Game::QueEvent(c);
	cout << "Collision Event Count: " << Game::Events<CollisionEvent>().size() << endl;
	Game::ResolveEvents();
	cout << "Collision Event Count: " << Game::Events<CollisionEvent>().size() << endl;
	cout << "Entity[0] ID: " << std::bitset<16>(EntityManager::FindEntity(0 | 1UL << typeBit)->GetId()) << endl;
	cout << "Tuple Size: " << std::tuple_size<ComponentTuple>::value << endl;
	getchar();
	return 0;
}


/*#include <tuple>
#include <vector>
#include <iostream>

int main() {
	auto& data = getter<int>(components);
	data.push_back(1);

	const auto& data2 = getter<int>(components);
	std::cout << data2[0];
	//std::cin.get();
}*/