#include"game.h"  //<vector>,<string>,<ctime>,<cstdlib>,<limits>,<iostream>
using namespace std;

Game::Game(){
	isFirstInnings=false;
	teamA.name="Team-A";
	teamB.name="Team-B";
	playersPerTeam=4;
	maxBalls=6;
	totalPlayers=11;

	players[0] = "Virat";
	players[1] = "Rohit";
	players[2] = "Dhawan";
	players[3] = "Pant";
	players[4] = "Karthik";
	players[5] = "KLRahul";
	players[6] = "Jadeja";
	players[7] = "Hardik";
	players[8] = "Bumrah";
	players[9] = "BKumar";
	players[10] = "Ishant";

}

void Game::welcome(){

	cout<<"-----------------------------------"<<endl;
	cout<<"|=============CRIC-IN=============|"<<endl;
	cout<<"|                                 |"<<endl;
	cout<<"| Welcome to Virtual Cricket Game |"<<endl;
	cout<<"-----------------------------------"<<endl;

	cout<<"-----------------------------------------------"<<endl;
	cout<<"|================INSTRUCTIONS=================|"<<endl;
	cout<<"-----------------------------------------------"<<endl;
	cout<<"|                                             |"<<endl;
	cout<<"|1.Create 2 teams (Team-A and Team-B with 4   |"<<endl;
	cout<<"|players each)from a given pool of 11 players.|"<<endl;
	cout<<"|2.Lead the toss and decide the toss of play. |"<<endl;
	cout<<"|3.Each innings will be of 6 balls.           |"<<endl;
	cout<<"-----------------------------------------------"<<endl;
}

void Game::showAllPlayers(){

	cout << endl;
	cout << "---------------------------------------" << endl;
	cout << "|========== Pool of Players ==========|" << endl;
	cout << "---------------------------------------" << endl;
	cout << endl;

	for(int i=0;i<totalPlayers;i++)
	{
		cout<<"\t\t["<<i<<"]"<<players[i]<<endl;
	}

}
int Game::takeIntegerInput(){

	int n;
	while (!(cin >> n)) {

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input! Please try again with valid input: ";
		}

		return n;
}
void Game::selectPlayers(){

	cout << endl;
	cout << "------------------------------------------------" << endl;
	cout << "|========== Create Team-A and Team-B ==========|" << endl;
	cout << "------------------------------------------------" << endl;

	for(int i=0;i<playersPerTeam;i++){

		teamAPlayer:
		cout<<endl<<"Select a player "<<i+1<<" of Team A -";
		int playerIndexTeamA=takeIntegerInput();
		if(playerIndexTeamA<0 || playerIndexTeamA>10){
				cout<<"Please select from given players"<<endl;
				goto teamAPlayer;
		}


		else if(!validateSelectedPlayer(playerIndexTeamA)){

			cout<<"player has been already selected.Please select other player"<<endl;
			goto teamAPlayer;
		}

		else{
		Player teamAPlayer;
		teamAPlayer.id=playerIndexTeamA;
		teamAPlayer.name=players[playerIndexTeamA];
		teamA.players.push_back(teamAPlayer);
		}


		teamBPlayer:
		cout<<endl<<"Select a player "<<i+1<<" of Team B -";
		int playerIndexTeamB=takeIntegerInput();
		if(playerIndexTeamB<0 || playerIndexTeamB>10){
		     cout<<endl<<"Please select from given players"<<endl;
		    goto teamBPlayer;
		}
		else if(!validateSelectedPlayer(playerIndexTeamB)){

					cout<<"player has been already selected.Please select other player"<<endl;
					goto teamBPlayer;
				}
		else{
			Player teamBPlayer;
			teamBPlayer.id=playerIndexTeamB;
			teamBPlayer.name=players[playerIndexTeamB];
			teamB.players.push_back(teamBPlayer);
		}

	}
	}

bool Game::validateSelectedPlayer(int index) {

	int n;
	vector<Player> players;

	players = teamA.players;
	n = players.size();
	for (int i = 0; i < n; i++) {
        if (players[i].id == index) {
        	return false;
        }
    }

    players = teamB.players;
    n = players.size();
    for (int i = 0; i < n; i++) {
        if (players[i].id == index) {
            return false;
        }
    }

    return true;
}
void Game::showTeamPlayers() {

    vector<Player> teamAPlayers = teamA.players;
    vector<Player> teamBPlayers = teamB.players;

    cout << endl << endl;
    cout << "--------------------------\t\t--------------------------" << endl;
    cout << "|=======  Team-A  =======|\t\t|=======  Team-B  =======|" << endl;
    cout << "--------------------------\t\t--------------------------" << endl;

    for (int i = 0; i < playersPerTeam; i++) {
        cout << "|\t" << "[" << i << "] " << teamAPlayers[i].name << "\t |"
        	<< "\t\t"
			<< "|\t" << "[" << i << "] " << teamBPlayers[i].name << "\t |" << endl;
    }
    cout << "--------------------------\t\t--------------------------" << endl << endl;
}
void Game::toss(){

	cout<<"--------------------------"<<endl;
	cout<<"|=======let's Toss=======|"<<endl;
	cout<<"--------------------------"<<endl<<endl;
	cout<<"Tossing the coin............."<<endl<<endl;
	sleep(3);

	srand(time(NULL));
	switch(rand()%1){

	case 0:{
		cout<<"Team-A won the toss"<<endl;
		sleep(2);
		tossChoice(teamA);
		break;
	}
	case 1:{
		cout<<"Team-B won the toss"<<endl;
		sleep(2);
		tossChoice(teamB);
		break;
	}
	default:
	break;
	}
}
void Game::tossChoice(Team tossWinnerTeam) {

	cout << "Enter 1 to bat or 2 to bowl first. " << endl
       		 << "1. Bat" << endl
        	 << "2. Bowl " << endl;


	int tossInput = takeIntegerInput();

	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	switch (tossInput) {
		case 1:
			cout << endl << tossWinnerTeam.name << " won the toss and elected to bat first" << endl << endl;

			if (tossWinnerTeam.name.compare("Team-A") == 0) {	 // if Team-A is the toss winner
				battingTeam = &teamA;
				bowlingTeam = &teamB;
			} else {	// else Team-B is the toss winner
				battingTeam = &teamB;
				bowlingTeam = &teamA;
			}

			break;
		case 2:
			cout << endl << tossWinnerTeam.name << " won the toss and choose to bowl first" << endl << endl;

			if (tossWinnerTeam.name.compare("Team-A") == 0) {	// if Team-A is the toss winner
				bowlingTeam = &teamA;
				battingTeam = &teamB;
			} else {	// else Team-B is the toss winner
				bowlingTeam = &teamB;
				battingTeam = &teamA;
			}

			break;
		default:
			cout << endl << "Invalid input. Please try again:" << endl << endl;
			tossChoice(tossWinnerTeam);
			break;
   	}
}
void Game::startFristInnings(){

	cout<<"\t\t |||FIRST INNINGS STARTS|||"<<endl<<endl;
	isFirstInnings=true;
	initializePlayers();
	playInnings();
}
void Game::initializePlayers(){
	batsman=&battingTeam->players[0];
	bowler=&bowlingTeam->players[0];

	cout<<battingTeam->name<<"-"<<batsman->name<<endl;
	cout<<bowlingTeam->name<<"-"<<bowler->name<<endl<<endl;


}
void Game::playInnings(){
	for(int balls=0;balls<maxBalls;balls++){

		cout<<"Press enter to bowl.... ";
		getchar();
		cout<<"bowling...."<<endl;
		bat();

		if(!validateInningsScore()){
			break;
		}


	}

}
void Game::bat()
{
	srand(time(NULL));
	int runsScored=rand()%7;

	batsman->runsScored=batsman->runsScored+runsScored;
	battingTeam->totalRuns=battingTeam->totalRuns+runsScored;
	batsman->ballsPlayed=batsman->ballsPlayed+1;

	bowler->ballsBowled=bowler->ballsBowled+1;
	bowlingTeam->totalBallsBowled=bowlingTeam->totalBallsBowled+1;
	bowler->runsGiven=bowler->runsGiven+runsScored;


	if(runsScored!=0){
		cout<<bowler->name<<" to "<<batsman->name<<" "<<runsScored<<" runs"<<endl<<endl;

		showGameScoreCard();
	}
	else{
		cout<<endl<<bowler->name<<" to "<<batsman->name<<" OUT! "<<endl;

		battingTeam->wicketsLost=battingTeam->wicketsLost+1;
		bowlingTeam->wicketsTaken=bowlingTeam->wicketsTaken+1;
		bowler->wicketsTaken=bowler->wicketsTaken+1;

		showGameScoreCard();

		int nextPlayerIndex=battingTeam->wicketsLost;
		batsman=&battingTeam->players[nextPlayerIndex];
	}

}
bool Game::validateInningsScore(){


	if(isFirstInnings){
		if(battingTeam->wicketsLost==playersPerTeam || bowlingTeam->totalBallsBowled==maxBalls){
			cout << "\t\t       ||| FIRST INNINGS ENDS ||| " << endl << endl;

			cout << battingTeam->name << " " << battingTeam->totalRuns << " - "
								<< battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled
								<< ")" << endl;

			cout << bowlingTeam->name << " needs " << battingTeam->totalRuns+ 1
								<< " runs to win the match" << endl << endl;

			return false;

		}


	}
	else{

		if(bowlingTeam->totalRuns<battingTeam->totalRuns){

			cout<<endl<<battingTeam->name<<" WON THE MATCH"<<endl;
			return false;
		}
		else {
			 if(bowlingTeam->totalBallsBowled==maxBalls&&bowlingTeam->totalRuns==battingTeam->totalRuns){

			cout<<endl<<"TIE BREAK"<<endl;
			 cout<<"\t\t           |||MATCH ENDS|||"<<endl;
			return false;
			 }
			 else if(bowlingTeam->totalBallsBowled==maxBalls&&bowlingTeam->totalRuns>battingTeam->totalRuns){
				 cout<<endl<<bowlingTeam->name<< " WON THE MATCH"<<endl;
				 cout<<"\t\t           |||MATCH ENDS|||"<<endl;
				 return false;
				  }
			 else if(battingTeam->wicketsLost==playersPerTeam){


				 cout<<endl<<bowlingTeam->name<<" WON THE MATCH"<<endl;
				 cout<<"\t\t           |||MATCH ENDS|||"<<endl;
				 return false;
			 }

		}
}
	return true;
}
void Game::showGameScoreCard(){


	cout<<"---------------------------------------------------------------------------------------"<<endl;
	cout<<"\t\t"<<battingTeam->name<<"\t"<<battingTeam->totalRuns<<" - "<<battingTeam->wicketsLost<<"( "<<bowlingTeam->totalBallsBowled<<" )"<<" | "
			<<batsman->name<<" "<<batsman->runsScored<<"( "<<batsman->ballsPlayed<<" )"<<"\t"<<bowler->name<<" "<<bowler->ballsBowled<<" - "
			<<bowler->runsGiven<<" - "<<bowler->wicketsTaken<<endl;
	cout<<"---------------------------------------------------------------------------------------"<<endl;
}
void Game:: startSecondInnings(){

	swap(battingTeam,bowlingTeam);
	cout<<"\t\t |||SECOND INNINGS STARTS|||"<<endl<<endl;
	initializePlayers();
	isFirstInnings=false;
	playInnings();
	swap(battingTeam,bowlingTeam);



}
void Game::swap(Team *p,Team *q){

	Team r=*p;
	*p=*q;
	*q=r;

}
void Game::matchSummary(){



	cout<<endl<<teamA.name<<" "<<teamA.totalRuns<<"-"<<teamA.wicketsLost<<"("<<teamA.totalBallsBowled<<")"<<endl;
	cout<<"================================================="<<endl;
	cout<<"| PLAYER\t\tBATTING\t\tBOWLING\t|"<<endl;
	for(int j=0;j<4;j++){
	cout<<"-------------------------------------------------"<<endl;
	cout<<"| ["<<j<<"] "<<teamA.players[j].name<<"\t\t"<<teamA.players[j].runsScored<<"("<<teamA.players[j].ballsPlayed<<")"<<"\t\t"<<teamA.players[j].ballsBowled
			<<"-"<<teamA.players[j].runsGiven<<"-"
			<<teamA.players[j].wicketsTaken<<" \t|"<<endl;
	}

	cout<<"================================================="<<endl;

	cout<<endl<<teamB.name<<" "<<teamB.totalRuns<<"-"<<teamB.wicketsLost<<"("<<teamB.totalBallsBowled<<")"<<endl;
	cout<<"================================================="<<endl;
	cout<<"| PLAYER\t\tBATTING\t\tBOWLING\t|"<<endl;
	for(int j=0;j<4;j++){
	cout<<"-------------------------------------------------"<<endl;
	cout<<"| ["<<j<<"] "<<teamB.players[j].name<<"\t\t"<<teamB.players[j].runsScored<<"("<<teamB.players[j].ballsPlayed<<")"<<"\t\t"<<teamB.players[j].ballsBowled
				<<"-"<<teamB.players[j].runsGiven<<"-"
				<<teamB.players[j].wicketsTaken<<"\t|"<<endl;
		}

	cout<<"=================================================="<<endl;


}


