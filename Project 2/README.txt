This program simulates a program that analyzes sports data from the last 4 years of college

The entire program is a collection of 4 seperate files
    - analysis_functions.h
        * conatins the function headers used by analysis_functions.c and analyze_scores.c

    - analysis_functions.c 
        * read_data: the functions purpose is to read the data from the input file and store the respective data into the wins and points arrays
        * find_top: the functions purpose is ot find the top team for each year based on the number of wins and points earned
        * write_results: the functions purpose is to print out the results of the analysis into the terminal and an output file respectively

    - analyze_scores.c 
        * checks to see if the user has inputted enough arguements
        * calls on the functions of analysis_functions.c 
        * returns 0;
    
    - makefile
        * compiles all the files above and creates an executable runScores to be used at the user's leisure

To compile: 
    - The program should be compiled using the provided makefile

To run:
    - The program should be run with the following command line arguements:
    "./runScores scores20.txt scores21.txt ... results.txt"

Sources: This program was written by Kyle Truong with the aid of:
    - https://stackoverflow.com to solve general syntax issues found when debugging the program
    - https://www.geeksforgeeks.org used mostly to figure out the intricacies of accessing files in c and the things I can do with it
The project was based on an assignment at WPI's 2303-Systems Programming Concepts taught by Professor Jennifer Mortensen