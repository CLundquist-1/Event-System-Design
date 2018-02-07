#pragma once
#include "EventHandler.h"
class Game {
private:
#define EVENTS 	X(CollisionEvent)
#define X(ARG) std::vector<ARG>
	using EventTuple = std::tuple<EVENTS>;
#undef X
#undef EVENTS
	static EventTuple events;
public:
	static unsigned short numContestants;
	static unsigned short numPlayers;
	static void Initialize(int, int);
	static void ResolveEvents();
	
	template<class T>
	static auto& Events();

	template<class T>
	static void QueEvent(T e) { Events<T>().push_back(e); }
};

template<class T>
auto& Game::Events()
{
	return std::get<std::vector<T>>(events);
}