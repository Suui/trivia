#include "../TestRunner/catch.hpp"
#include "../../Source/Game.h"

/**
*	Notes on the initial functionality
*	---------------------------------------
*	When game is created it starts with 50 questions for each topic, between "xxx Question 0" and "xxx Question 49"
*	---
*	add(playerName) adds player to the players vector and also sets places and purses to 0 for the 
*	position of that player. Also, inPenaltyBox is set to false at first for the player.
*	Always returns true.
*	---
*	roll(number) rolls between 1 and 5. If the currentPlayer is in the penalty box:
*	if roll is an odd number, player is getting out of penalty box, places for the currentPlayer gets added the
*	roll number, and if places >= 12, places -= 12 because it has to be between o and 11 to select currentCategory() effectively.
*	==> places has to do with player location.
*	player then gets asked a question based on currentCategory().
*	if roll is pair,  player is not getting out of penalty box and is not asked a question.
*	if player was not in penalty box, he gets if places >= 12 places -= 12 and askQuestion()
*	---
*	currentCategory() returns a category based on player's location (places[currentPlayer])
*
*/



TEST_CASE("Trivia Game Should")
{
	Game testGame;

	SECTION("Have 50 popQuestions after construction")
	{
		CHECK(testGame.popQuestions.front() == "Pop Question 0");
		CHECK(testGame.popQuestions.back() == "Pop Question 49");
		CHECK(testGame.popQuestions.size() == 50);
	}

	SECTION("Be playable if number of players >= 2")
	{
		testGame.add("Angelo");
		testGame.add("Dani");

		CHECK(testGame.howManyPlayers() == 2);
		CHECK(testGame.isPlayable() == true);

		testGame.add("Ronny");
		
		CHECK(testGame.howManyPlayers() == 3);
		CHECK(testGame.isPlayable() == true);
	}

	SECTION("Have a winner if he gets 5 gold coins (5 correct answers)")
	{
		testGame.add("Angelo");
		testGame.add("Dani");
		
		for (int i = 0; i < 8; i++)
			testGame.wasCorrectlyAnswered();

		CHECK(testGame.didPlayerWin() == false);

		testGame.wasCorrectlyAnswered();
		testGame.ChangePlayer();
		CHECK(testGame.didPlayerWin() == true);
	}
}