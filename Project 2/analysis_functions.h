#ifndef ANALYSIS_FUNCTIONS_H
#define ANALYSIS_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEAMS 10  // Number of teams
#define YEARS_MAX 10  // Maximum number of years the program can handle

/*
void read_data(const char *F, int wins[][], int points[][], int year_index, int years[])

This functions purpose is to read the data from the input file and store the data in the wins and points arrays

Parameters: 
    const char *F: The name of the file that contains the data
    int wins[][10]: A 2D array storing wins for each team in each year
    int points[][10]: A 2D array storing points for each team in each year
    int year_index: The index of the year in the arrays
    int years[]: An array to store the year(s) extracted from the files

Returns:
    void
*/
void read_data(const char *F, int wins[][TEAMS], int points[][TEAMS], int year_index, int years[]);

/*
void find_top(int wins[][], int points[][], int num_years, int years[])

This functions purpose is to find the top team for each year based on the number of wins and points

Parameters: 
    int wins[][10]: A 2D array storing wins for each team in each year
    int points[][10]: A 2D array storing points for each team in each year
    int num_years: The number of years being analyzed
    int years[]: An array storing the extracted year(s)

Returns: 
    void
*/
void find_top(int wins[][TEAMS], int points[][TEAMS], int num_years, int years[]);

/*
void write_results(const char *F, int wins[][], int points[][], int num_years, int years[])

This functions purpose is to write the results of the analysis to an output file

Parameters: 
    const char *F: The name of the output file
    int wins[][10]: A 2D array storing wins for each team in each year
    int points[][10]: A 2D array storing points for each team in each year
    int num_years: The number of years being analyzed
    int years[]: An array storing the extracted year(s)

Returns: 
    void
*/
void write_results(const char *F, int wins[][TEAMS], int points[][TEAMS], int num_years, int years[]);

#endif
