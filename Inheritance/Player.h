#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"

class Player : public Creature
{
	int m_level{1};

public:

	Player(std::string name) :
		Creature(name, '@', 10, 1, 0)
	{

	}

	int getLevel() { return m_level; }

	void levelUp()
	{
		++m_level;
		++m_damage;
	}

	bool hasWon() { return (m_level >= 20); }
};

#endif