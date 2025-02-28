This program simulates a program that tracks and analyzes the results of [sports/debate/robotics/etc.] events

The entire program is a collection of 4 seperate files:
    - Player.h 
        Contains the function headers for the functions used in analyze_team.cpp and implemented in Player.cpp
        Creates the template for the Player class implemented in Player.cpp

    - Player.cpp
        Implements functions that deals with the Player class
            - setters for the values of Player
            - getters for the values of Player
        Implements functions that deal with the command line inputs given by the user 
            - Loading the data
            - Updating the data 
            - Printing the data to a file 
        
    - analyze_team.cpp 
        Checks for valid number of command line arguments
        Initialzes the values of the command line arguments to local variables 
        Creates a vector the size of the amount of players listed in the file 
        Calls on the functions in Player.cpp to deal with parsing and outputting the data 

    - makefile 
        Compiles all of the files above, creating an executable teamData to be used at the user's leisure 
    
To compile: 
    Use the makefile command:
        make

To run: 
    The program should be run with the following command line template: 
        "./teamData oldData.txt newData.txt outName.txt numStats numPlayers"
        - oldData.txt: file containing team data
        - newData.txt: new team data to add
        - outName.txt: where to save the data
        - numStats: Number of columns of stats in both data files (does not include name and ID columns)
        - numPlayers: number of team members in oldData.txt

Sources: This program was written by Kyle Truong with the aid of:
    - https://stackoverflow.com 
    - https://www.geeksforgeeks.org 
The project was based on an assignment at WPI's 2303-Systems Programming Concepts taught by Professor Jennifer Mortensen
            