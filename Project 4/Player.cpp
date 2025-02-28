#include "Player.h"

using namespace std;

/*
This is a constructor for the Player class

Initializes the values of the Player class to default values
*/
Player::Player(){
    ID = 0;
    lastName = "";
    firstName = "";
    numStat = 0;
    for(int i = 0; i < 20; i++){
        memberData[i] = 0;
    }
}

/*
int Player::getID()

This functions purpose is to return the ID of the player

Parameters: 
    None

Returns:
    int: ID of the player
*/
int Player::getID(){
    return ID;
}

/*
int Player::setStats(float* stats, int statSize)

This functions purpose is to copy the player data from stats into memberData

Parameters: 
    float* stats: array of stats
    int statSize: size of the stats array

Returns:
    int: 0
*/
int Player::setStats(float* stats, int statSize){ 
    for(int i = 0; i < statSize; i++){ // loop through the stats array and initialize the values of memberData to the values of stats
        memberData[i] = stats[i]; // sets the value of memberData to the respective value in stats
    }
    numStat = statSize; // set the member value of numStat to statSize
    return 0;
}

/*
int Player::updateStats(float* newData, int statSize)

This functions purpose is to update the Players data using the data in stats

Parameters: 
    float* newData: array of stats
    int statSize: size of the stats array

Returns:
    int: 0
*/
int Player::updateStats(float* newData, int statSize){
    for(int i = 0; i < statSize; i++){ // loop through the stats array and update the values of memberData to the values of newData
        memberData[i] += newData[i]; // sets the new value of memberData to the respective value in newData
    }
    return 0;
}

/*
int Player::setAll(int num, string fname, string lname, float* stats, int statSize)

This functions purpose is to set the ID, first name, last name, stats, and number of stats of the player given a user input

Parameters: 
    int num: ID of the player
    string fname: first name of the player
    string lname: last name of the player
    float* stats: array of stats
    int statSize: size of the stats array

Returns:
    int: 0
*/
int Player::setAll(int num, string fname, string lname, float* stats, int statSize){
    ID = num; // set the ID to num
    firstName = fname; // set the first name to fname
    lastName = lname; // set the last name to lname
    numStat = statSize; // set the number of stats to statSize
    for(int i = 0; i < statSize; i++){ // loop through the stats array and set the values of memberData to the values of stats
        memberData[i] = stats[i];
    }
    return 0;
}

/*
void Player::loadPlayers(const string& FILENAME, vector <Player>& team, int numStats, int numPlayers)

This functions purpose is to load the data of each player from a file

Parameters: 
    const string& FILENAME: name of the file
    vector <Player>& team: vector of players
    int numStats: number of stats
    int numPlayers: number of players

Returns:
    Void
*/
void Player::loadPlayers(const string& FILENAME, vector <Player>& team, int numStats, int numPlayers){
    ifstream file(FILENAME); // open the file
    if(!file){ // if the file cannot be opened
        cout << "File could not be opened." << endl;
        return;
    }

    string header;
    getline(file, header); // get the header of the file and stores it in header

    for(int i = 0; i < numPlayers; i++){ // loop through the number of players
        int ID; 
        string fname, lname;
        float stats[20];

        file >> ID >> fname >> lname; // get the ID, first name, and last name of the player
        for(int j = 0; j < numStats; j++){ // loop through the stats array and get the values of the stats
            file >> stats[j]; // get the stats of the player
        }
        team[i].setAll(ID, fname, lname, stats, numStats); // set the values of the player
    }

    file.close(); // close the file
}

/*
void Player::updatePlayers(const string& FILENAME, vector<Player>& team, int numStats)

This functions purpose is to update the data of each player given the updated stats file
    
Parameters: 
    const string& FILENAME: name of the file
    vector <Player>& team: vector of players
    int numStats: number of stats

Returns:
    Void
*/
void Player::updatePlayers(const string& FILENAME, vector<Player>& team, int numStats) {
    ifstream file(FILENAME); // Open the file
    if (!file) { // If the file cannot be opened
        cout << "File could not be opened." << endl;
        return;
    }

    string header;
    getline(file, header); // Read and discard the header from the update file

    int ID;
    string fname, lname;
    float stats[20];

    while (file >> ID >> fname >> lname) { // Read the ID, first name, and last name of the player
        for (int i = 0; i < numStats; i++) { // Read the stats of the player
            file >> stats[i]; // Read the stats of the player
        }

        // Search for matching player in the existing team and update
        bool playerFound = false; 
        for (auto& player : team) { // Loop through each player in the team vector
            if (player.getID() == ID) {   // If the player is found, update the stats
                player.updateStats(stats, numStats);  
                playerFound = true; // Set playerFound to true
            }
        }

        if (!playerFound) {  // If the player was not found, add as a new player
            Player newPlayer; // Create a new player
            newPlayer.setAll(ID, fname, lname, stats, numStats); // Set the values of the new player
            team.push_back(newPlayer); // Add the new player to the team vector
        }
    }
    file.close(); // Close the file
}


/*
void Player::printPlayers(const string& OUT_FILENAME, const string& IN_FILENAME, vector<Player>& team) 

This functions purpose is to print the data of each player to an output file

Parameters: 
    const string& FILENAME: name of the output file
    const string& IN_FILENAME: name of the input file
    vector <Player>& team: vector of players

Returns:    
    Void
*/
void Player::printPlayers(const string& OUT_FILENAME, const string& IN_FILENAME, vector<Player>& team) {
    // Open the input file to extract the header
    ifstream inputFile(IN_FILENAME);  
    if (!inputFile) {
        cout << "File could not be opened." << endl;
        return;
    }

    string header;
    getline(inputFile, header);  // Read the first line (header)
    inputFile.close();  // Close the input file after reading the header

    // Open the output file to write updated player data
    ofstream outputFile(OUT_FILENAME);  
    if (!outputFile) { // If the output file cannot be opened
        cout << "File could not be opened." << endl;
        return;
    }

    outputFile << header << endl;  // Print the extracted header only once

    for (auto& player : team) { // Print each player's data
        outputFile << player.ID << "\t" << player.firstName << "\t" << player.lastName; // print the ID, first name, and last name of the player
        for (int i = 0; i < player.numStat; i++) { // loop through the stats array and print the values of memberData
            outputFile << "\t" << player.memberData[i]; // prints out each player's data
        }
        outputFile << endl; 
    }

    outputFile.close();  // Close the output file
}
