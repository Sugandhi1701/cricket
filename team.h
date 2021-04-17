#include<vector>
#include"player.h" //<string>

class Team{
public:
	Team();
	std::string name;
	int totalRuns;
	int wicketsLost;
	int wicketsTaken;
	int totalBallsBowled;
	std::vector<Player> players ;

};
