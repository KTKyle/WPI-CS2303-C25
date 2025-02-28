#include <iostream>
#include <vector>
#include <string>
#include "Player.h"

using namespace std;

int main (int argc,char* argv[]){
    if(argc != 6){
        cout << "Missing command line arguments" << endl << endl;
        cout << "./teamData oldData.txt newData.txt outName.txt numStats numPlayers" << endl;
        return 1;
    }

    string oldData = argv[1];       // the old player data: first command line argument
    string newData = argv[2];       // the new player data: second command line argument
    string outputFile = argv[3];    // the outputfile: third command line argument
    int numStats = stoi(argv[4]);   // the number of stats: fourth command line argument
    int numPlayers = stoi(argv[5]); // the number of players: fifth command line argument

    if(numStats > 20){
        cout << "Too many player stats for this program (max of 20)." << endl;
    }

    vector<Player> team(numPlayers); // creates a vector the size of the amount of players
    Player::loadPlayers(oldData, team, numStats, numPlayers); // load the players from the oldData file
    Player::updatePlayers(newData, team, numStats); // update the players with the new data
    Player::printPlayers(outputFile, oldData, team); // save the players to the output file

    return 0;
}