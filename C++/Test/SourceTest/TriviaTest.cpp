#include "../TestRunner/catch.hpp"
#include "../../Source/Trivia/Game.h"

/**
*	The game should end when a player gets 6 coins, he is the winner
*	A player receives a question about a category in his turn
*	If he answers correctly, he gets a gold coin, change turn
*	If he answers wrong, he is sent to the penalty box, change turn
*	A player may exit from the penalty box if he gets an Odd roll in his turn
*	Each roll is between 1 and 5
*	A player will answer wrong if rand() % 9 == 7, else he answers correctly
*	The category of the question for the player is determined by his location,
*		which is the places array, which gets the roll added % 12
*
*	The minimum number of players is 2 as it is stated in isPlayable(), but not used by default
*
*	POSSIBLE TESTS
*	Check the game ends when player gets 6 coins
*	Check can't play if players are not between 2 and 6
*	Check players are correctly added with initial place = 0, purse = 0 and inPenaltyBox = false
*	Check player gets a coin when he answers correctly
*	Check player is sent to the penalty box if he answers wrong, and doesn't get a coin
*	Check player exits penalty box if he rolls an odd number
*	Check roll is between 1 and 5
*	Check player's place gets added the roll he did and is % 12
*/


TEST_CASE("Trivia game should")
{
	Game testGame;

	SECTION("Have two players after adding them")
	{
		testGame.add("Player_01");
		testGame.add("Player_02");
		CHECK(testGame.howManyPlayers() == 2);
	}


}