This program simulates a program that tracks and analyzes the results of [sports/debate/robotics/etc.] events

The entire program is a collection of 4 seperate files
   - team_member.h 
        Contains the struct for every TeamMember created 
        Contains the function headers for all functions implemented in team_member.c and used in analyze_team.c
   - team_member.c 
        void load_data: 
            - loads the data from the first input file and stores the information in to an array of TeamMembers (structs)
            - Each players information will be dynamically allocated 
        void add_data:
            - Reads the new data from the second input file and updates the respective existing team member information by adding the new values
        void print_data:
            - Prints the updated team data onto an output file with the same format as the input file
        void free_team:
            - frees all memory allocated for each player in the team
   - analyze_team.c 
        Checks to see if we have a valid amount of command line arguments
        initialzes the command line arguments into their respective variables
        Allocates memory for the amount of players in the input file
        Calls on the functions from team_member.c 
        Releases the memory of the team members from the heap
    
    - makefile
        compiles all the files above and creates an executable runScores to be used at the user's leisure

To compile: 
    - The program should be compiled using the provided makefile command:
        make 

To run:
    - The program should be run with the following command line arguements:
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