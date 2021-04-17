#include<iostream>
#include<ctime>
#include<cstdlib>
#include<limits>
#include<unistd.h>
#include"team.h" //<string>,<vector>

class Game{
public:
	Game();
	int playersPerTeam;
	int maxBalls;
	int totalPlayers;
	std::string players[11];


	Team teamA,teamB;
	Team *battingTeam;
	Team *bowlingTeam;
	Player *batsman,*bowler;
	bool isFirstInnings;
	void welcome();
	void showAllPlayers();
	int takeIntegerInput();
	void selectPlayers();
	bool validateSelectedPlayer(int);
	void showTeamPlayers();
	void toss();
	void tossChoice(Team);
	void startFristInnings();
	void initializePlayers();
	void playInnings();
	void bat();
	bool validateInningsScore();
	void showGameScoreCard();
	void startSecondInnings();
	void swap(Team *,Team *);
	void matchSummary();

};
