#include <iostream>
#include <list>
#include <vector>


#ifndef GAME_H_
#define GAME_H_

class Game
{
	int currentPlayer;


	std::vector<int> places;
	std::vector<int> purses;

	bool inPenaltyBox[6];

	std::list<std::string> scienceQuestions;
	std::list<std::string> sportsQuestions;
	std::list<std::string> rockQuestions;


	bool isGettingOutOfPenaltyBox;

	void askQuestion();

	std::string currentCategory();

	bool didPlayerWin();


public:

	// TODO: Should be private
	std::list<std::string> popQuestions;
	std::vector<std::string> players;

	Game();

	std::string createRockQuestion(int index);

	bool isPlayable();

	bool add(std::string playerName);

	int howManyPlayers();

	void roll(int roll);

	bool wasCorrectlyAnswered();

	bool wrongAnswer();
};

#endif /* GAME_H_ */
