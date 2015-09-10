#include <stdlib.h>
#include "Game.h"

static bool notAWinner;

int main()
{
	Game aGame;

	aGame.add("Chet");
	aGame.add("Pat");
	aGame.add("Sue");

	do
	{
		aGame.roll(rand() % 5 + 1);		// random number between 1 and 5

		if (rand() % 9 == 7)			// really?
			notAWinner = aGame.wrongAnswer();
		else
			notAWinner = aGame.wasCorrectlyAnswered();
	} while (notAWinner);

}
