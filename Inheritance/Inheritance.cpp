#include "Fruit.h"
#include "Creature.h"
#include "Player.h"
#include "Monster.h"
#include "Utils.h"

#include <iostream>
#include <string>

void testFruit()
{
	Apple a{ "red" };
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

}

// This function handles the player attacking the monster
void attackMonster(Player& player, Monster& monster)
{
	// If the player is dead, we can't attack the monster
	if (player.isDead())
		return;

	std::cout << "You hit the " << monster.getName() << " for " << player.getDamage() << " damage.\n";

	// Reduce the monster's health by the player's damage
	monster.reduceHealth(player.getDamage());

	// If the monster is now dead, level the player up
	if (monster.isDead())
	{
		std::cout << "You killed the " << monster.getName() << ".\n";
		player.levelUp();
		std::cout << "You are now level " << player.getLevel() << ".\n";
		std::cout << "You found " << monster.getGold() << " gold.\n";
		player.addGold(monster.getGold());
	}
}

// This function handles the monster attacking the player
void attackPlayer(const Monster& monster, Player& player)
{
	// If the monster is dead, it can't attack the player
	if (monster.isDead())
		return;

	// Reduce the player's health by the monster's damage
	player.reduceHealth(monster.getDamage());
	std::cout << "The " << monster.getName() << " hit you for " << monster.getDamage() << " damage.\n";
}

// This function handles the entire fight between a player and a randomly generated monster
void fightMonster(Player& player)
{
	// First randomly generate a monster
	Monster monster{ Monster::getRandomMonster() };
	std::cout << "You have encountered a " << monster.getName() << " (" << monster.getSymbol() << ").\n";

	// While the monster isn't dead and the player isn't dead, the fight continues
	while (!monster.isDead() && !player.isDead())
	{
		std::cout << "(R)un or (F)ight: ";
		char input{};
		std::cin >> input;
		if (input == 'R' || input == 'r')
		{
			// 50% chance of fleeing successfully
			if (Utils::getRandomNumber(1, 2) == 1)
			{
				std::cout << "You successfully fled.\n";
				return; // success ends the encounter
			}
			else
			{
				// Failure to flee gives the monster a free attack on the player
				std::cout << "You failed to flee.\n";
				attackPlayer(monster, player);
				continue;
			}
		}

		if (input == 'F' || input == 'f')
		{
			// Player attacks first, monster attacks second
			attackMonster(player, monster);
			attackPlayer(monster, player);
		}
	}
}

void startGame(Player& player)
{
	while (!player.isDead() && !player.hasWon())
		fightMonster(player);

	// At this point, the player is either dead or has won
	if (player.isDead())
	{
		std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << " gold.\n";
		std::cout << "Too bad you can't take it with you!\n";
	}
	else
	{
		std::cout << "You won the game with " << player.getGold() << " gold!\n";
	}
}

void initGame()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
	std::rand(); // get rid of first result

	std::string name;
	std::cout << "Enter your name: ";
	std::cin >> name;
	std::cout << '\n';

	Player p{ name };

	std::cout << "Welcome, " << name << ".\n";
	std::cout << "You have " << p.getHealth() << " health"
		<< " and are carrying " << p.getGold() << " gold\n";

	startGame(p);
}

int main()
{
	initGame();
}

