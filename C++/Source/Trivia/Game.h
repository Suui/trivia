#include <iostream>
#include <list>
#include <vector>
using namespace std;

#ifndef GAME_H_
#define GAME_H_

class Game
{
	vector<string> players;

	int places[6];
	int purses[6];

	bool inPenaltyBox[6];

	list<string> popQuestions;
	list<string> scienceQuestions;
	list<string> sportsQuestions;
	list<string> rockQuestions;

	int currentPlayer;
	bool isGettingOutOfPenaltyBox;

	void askQuestion();
	string currentCategory();

	bool didPlayerWin();

public:

	Game();
	string createRockQuestion(int index);
	bool isPlayable();
	bool add(string playerName);

	int howManyPlayers();
	void roll(int roll);

	bool wasCorrectlyAnswered();
	bool wrongAnswer();
};

#endif /* GAME_H_ */
