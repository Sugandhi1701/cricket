using namespace std;
#include"game.h"

int main() {
	setbuf(stdout,NULL);
	Game game;
	game.welcome();


    cout << "Press Enter to continue"<<endl;
	getchar();
	game.showAllPlayers();

	cout << "Press Enter to continue"<<endl;
	getchar();

	game.selectPlayers();

	game.showTeamPlayers();

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Press Enter to toss"<<endl;
		getchar();
	game.toss();

	game.startFristInnings();
	game.startSecondInnings();
	game.matchSummary();
	return 0;
}

