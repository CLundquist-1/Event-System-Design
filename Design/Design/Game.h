#pragma once
#include "EventHandler.h"
class Game {
public:
	static unsigned short numContestants;
	static unsigned short numPlayers;
	static vector<CollisionEvent> CE;
	static void Initialize(int, int);
	static void QueEvent(CollisionEvent e) { CE.push_back(e); }
	static void ResolveEvents();
};