#include "Game.h"
unsigned short Game::numContestants = 0;
unsigned short Game::numPlayers = 0;

#define EVENTS 	X(CollisionEvent)
#define X(ARG) std::vector<ARG>
std::tuple<EVENTS> Game::events;
#undef X

void Game::Initialize(int players, int contestants) {
	EntityManager::Initialize(contestants);
	numContestants = contestants;
	numPlayers = players;
#define X(ARG) 	Events<ARG>().reserve(4);
	EVENTS
#undef X
}

void Game::ResolveEvents() {
#define X(ARG) 	for (ARG e : Events<ARG>()) { EventHandler<ARG>::HandleEvent(&e); } Game::Events<ARG>().clear();
	EVENTS
#undef X
#undef EVENTS
}