#include "../TestRunner/catch.hpp"
#include "../../Source/Game.h"

TEST_CASE("Trivia Game Should")
{
	SECTION("Have 50 popQuestions after construction")
	{
		Game testGame;
		CHECK(testGame.popQuestions.front() == "Pop Question 0");
		CHECK(testGame.popQuestions.back() == "Pop Question 49");
		CHECK(testGame.popQuestions.size() == 50);
	}

	SECTION("Have 2 players after adding 2 players")
	{
		Game testGame;
		testGame.add("Angelo");
		testGame.add("Dani");

		CHECK(testGame.players.size() == 2);
	}
}