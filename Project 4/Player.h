#ifndef PLAYER_H
#define PLAYER_H

#include <fstream>
#include <iostream>
#include <string> 
#include <vector>

using namespace std;

class Player{ // creates a class representing a player
    private: 
        int ID; // Player # (ID)
        string lastName; // Player's last name
        string firstName; // Player's first name
        float memberData[20]; // An array of stats 
        int numStat; // Number of stats

    public:
        Player(); // Constructor
        
        /*
        This functions purpose is to copy the player data from stats into memberData

        Parameters: 
            float* stats: array of stats
            int statSize: size of the stats array

        Returns:
            int: 0
        */
        int setStats(float* stats, int statSize);

        /*
        This functions purpose is to update the Players data using the data in stats

        Parameters: 
            float* newData: array of stats
            int statSize: size of the stats array

        Returns:
            int: 0
        */
        int updateStats(float* newData, int statSize);

        /*
        This functions purpose is to print the data of each player to a file

        Parameters: 
            ostream& out: output stream

        Returns:
            Void
        */
        void printPlayer(ostream& out);

        /*
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
        int setAll(int num, string fname, string lname, float* stats, int statSize);

        /*
        This functions purpose is to return the ID of the player

        Parameters: 
            None

        Returns:
            int: ID of the player
        */
        int getID();

        /*
        This functions purpose is to load the data of each player from a file

        Parameters: 
            const string& FILENAME: name of the file
            vector <Player>& team: vector of players
            int numStats: number of stats
            int numPlayers: number of players

        Returns:
            Void
        */
        static void loadPlayers(const string& FILENAME, vector<Player>& team, int numStats, int numPlayers);

        /*
        This functions purpose is to print the data of each player to an output file

        Parameters: 
            const string& FILENAME: name of the output file
            const string& IN_FILENAME: name of the input file
            vector <Player>& team: vector of players

        Returns:    
            Void
        */
        static void printPlayers(const string& OUT_FILENAME, const string& IN_FILENAME, vector<Player>& team);

        /*
        This functions purpose is to update the data of each player given the updated stats file

        Parameters: 
            const string& FILENAME: name of the file
            vector <Player>& team: vector of players
            int numStats: number of stats

        Returns:
            Void
        */
        static void updatePlayers(const string& FILENAME, vector<Player>& team, int numStats);
};
#endif 