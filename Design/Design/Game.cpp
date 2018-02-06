#include "Game.h"
unsigned short Game::numContestants = 0;
unsigned short Game::numPlayers = 0;
vector<CollisionEvent> Game::CE;

void Game::Initialize(int players, int contestants) {
	EntityManager::Initialize(contestants);
	numContestants = contestants;
	numPlayers = players;
	CE.reserve(4);
}

void Game::ResolveEvents() {
	for (CollisionEvent e : CE) {
		EventHandler<CollisionEvent>::HandleEvent(&e);
	}
}