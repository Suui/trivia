#include <iostream>
#include <list>
#include <vector>


#ifndef GAME_H_
#define GAME_H_

class Game
{
	int currentPlayer;
	std::vector<std::string> players;

	std::vector<int> places;
	std::vector<int> purses;

	bool inPenaltyBox[6];

	std::list<std::string> scienceQuestions;
	std::list<std::string> sportsQuestions;
	std::list<std::string> rockQuestions;

	bool isGettingOutOfPenaltyBox;

	void askQuestion();

	std::string currentCategory();


public:

	// TODO: Should be private
	std::list<std::string> popQuestions;
	bool didPlayerWin();

	Game();

	std::string createRockQuestion(int index);

	bool isPlayable();

	bool add(std::string playerName);

	int howManyPlayers();

	void roll(int roll);

	bool wasCorrectlyAnswered();

	bool wrongAnswer();

	void ChangePlayer();
};

#endif /* GAME_H_ */
