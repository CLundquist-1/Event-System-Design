#include "Game.h"
unsigned short Game::numContestants = 0;
unsigned short Game::numPlayers = 0;

#define EVENTS 	X(CollisionEvent)
#define X(ARG) std::vector<ARG>
std::tuple<EVENTS> Game::events;
#undef X
#undef EVENTS

void Game::Initialize(int players, int contestants) {
	EntityManager::Initialize(contestants);
	numContestants = contestants;
	numPlayers = players;
	Events<CollisionEvent>().reserve(4);
}

void Game::ResolveEvents() {
	for (CollisionEvent e : Events<CollisionEvent>()) {
		EventHandler<CollisionEvent>::HandleEvent(&e);
	}
	Game::Events<CollisionEvent>().clear();
}