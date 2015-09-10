﻿#include "Game.h"
#include <stdio.h>
#include <iostream>
#include <sstream>


Game::Game() : currentPlayer(0)
{

	for (int i = 0; i < 50; i++)
	{

		std::ostringstream oss (std::ostringstream::out);
		oss << "Pop Question " << i;

		popQuestions.push_back(oss.str());

		char str[255];
		sprintf_s(str, "Science Question %d", i);
		scienceQuestions.push_back(str);

		char str1[255];
		sprintf_s(str1, "Sports Question %d", i);
		sportsQuestions.push_back(str1);

		rockQuestions.push_back(createRockQuestion(i));
	}
}

std::string Game::createRockQuestion(int index)
{
	char indexStr[127];
	sprintf_s(indexStr, "Rock Question %d", index);
	return indexStr;
}

bool Game::isPlayable()
{
	return (howManyPlayers() >= 2);
}

bool Game::add(std::string playerName)
{
	players.push_back(playerName);

	places.push_back(0);
	purses.push_back(0);

	inPenaltyBox[howManyPlayers()] = false;

	std::cout << playerName << " was added" << std::endl;
	std::cout << "They are player number " << players.size() << std::endl;

	return true;
}

int Game::howManyPlayers()
{
	return players.size();
}

void Game::roll(int roll)
{
	std::cout << players[currentPlayer] << " is the current player" << std::endl;
	std::cout << "They have rolled a " << roll << std::endl;

	if (inPenaltyBox[currentPlayer])
	{
		if (roll % 2 != 0)	// Odd number
		{
			isGettingOutOfPenaltyBox = true;

			std::cout << players[currentPlayer] << " is getting out of the penalty box" << std::endl;
			places[currentPlayer] = places[currentPlayer] + roll;
			if (places[currentPlayer] > 11) places[currentPlayer] = places[currentPlayer] - 12;

			std::cout << players[currentPlayer] << "'s new location is " << places[currentPlayer] << std::endl;
			std::cout << "The category is " << currentCategory() << std::endl;
			askQuestion();
		}
		else	// Pair number
		{
			std::cout << players[currentPlayer] << " is not getting out of the penalty box" << std::endl;
			isGettingOutOfPenaltyBox = false;
		}

	}
	else
	{
		places[currentPlayer] = places[currentPlayer] + roll;
		if (places[currentPlayer] > 11) places[currentPlayer] = places[currentPlayer] - 12;

		std::cout << players[currentPlayer] << "'s new location is " << places[currentPlayer] << std::endl;
		std::cout << "The category is " << currentCategory() << std::endl;
		askQuestion();
	}
}

void Game::askQuestion()
{
	if (currentCategory() == "Pop")
	{
		std::cout << popQuestions.front() << std::endl;
		popQuestions.pop_front();
	}
	if (currentCategory() == "Science")
	{
		std::cout << scienceQuestions.front() << std::endl;
		scienceQuestions.pop_front();
	}
	if (currentCategory() == "Sports")
	{
		std::cout << sportsQuestions.front() << std::endl;
		sportsQuestions.pop_front();
	}
	if (currentCategory() == "Rock")
	{
		std::cout << rockQuestions.front() << std::endl;
		rockQuestions.pop_front();
	}
}


std::string Game::currentCategory()
{
	if (places[currentPlayer] == 0) return "Pop";
	if (places[currentPlayer] == 4) return "Pop";
	if (places[currentPlayer] == 8) return "Pop";
	if (places[currentPlayer] == 1) return "Science";
	if (places[currentPlayer] == 5) return "Science";
	if (places[currentPlayer] == 9) return "Science";
	if (places[currentPlayer] == 2) return "Sports";
	if (places[currentPlayer] == 6) return "Sports";
	if (places[currentPlayer] == 10) return "Sports";
	return "Rock";
}


void Game::ChangePlayer()
{
	currentPlayer++;
	if (currentPlayer == players.size()) currentPlayer = 0;
}

bool Game::wasCorrectlyAnswered()
{
	if (inPenaltyBox[currentPlayer])
	{
		if (isGettingOutOfPenaltyBox)
		{
			std::cout << "Answer was correct!!!!" << std::endl;
			purses[currentPlayer]++;
			std::cout << players[currentPlayer]
			     << " now has "
			     << purses[currentPlayer]
				<<  " Gold Coins." << std::endl;

			bool winner = didPlayerWin();
			ChangePlayer();

			return winner;
		}
		else
		{
			ChangePlayer();
			if (currentPlayer == players.size()) currentPlayer = 0;
			return true;
		}
	}
	else
	{
		std::cout << "Answer was corrent!!!!" << std::endl;
		purses[currentPlayer]++;
		std::cout << players[currentPlayer]
				<< " now has "
				<< purses[currentPlayer]
			<< " Gold Coins." << std::endl;

		bool winner = didPlayerWin();
		ChangePlayer();
		if (currentPlayer == players.size()) currentPlayer = 0;

		return winner;
	}
}

bool Game::wrongAnswer()
{
	std::cout << "Question was incorrectly answered" << std::endl;
	std::cout << players[currentPlayer] + " was sent to the penalty box" << std::endl;
	inPenaltyBox[currentPlayer] = true;

	ChangePlayer();
	if (currentPlayer == players.size()) currentPlayer = 0;
	return true;
}


bool Game::didPlayerWin()
{
	return (purses[currentPlayer] == 5);
}
