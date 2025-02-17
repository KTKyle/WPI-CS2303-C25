#include "analysis_functions.h"

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
void read_data(const char *F, int wins[][10], int points[][10], int year_index, int years[]) {
    FILE *file = fopen(F, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", F);
        exit(1);
    }

    int year;
    if (fscanf(file, "Year: %d", &year) != 1) {
        fprintf(stderr, "Error: Could not read year from %s\n", F);
        fclose(file);
        exit(1);
    }
    years[year_index] = year; // Store the extracted year(s)

    int team1, team2, score1, score2;
    while (fscanf(file, "%d %d %d %d", &team1, &team2, &score1, &score2) == 4) { // Read data from file
        points[team1 - 1][year_index] += score1; // Update points for team1
        points[team2 - 1][year_index] += score2; // Update points for team2
        if (score1 > score2) { // if team1 wins
            wins[team1 - 1][year_index]++; // Update wins for team1
        } else if (score2 > score1) { // if team2 wins
            wins[team2 - 1][year_index]++; // Update wins for team2
        } else { // in case of tie, both teams get a win
            wins[team1 - 1][year_index]++; 
            wins[team2 - 1][year_index]++;
        }
    }
    fclose(file);
}

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
void find_top(int wins[][TEAMS], int points[][TEAMS], int num_years, int years[]) {
    for (int y = 0; y < num_years; y++) { // iterate through each year
        int max_wins = 0, max_points = 0, top_team = -1, tie_team = -1; // initialize variables to default values
        for (int t = 0; t < TEAMS; t++) { // iterate through each team
            if (wins[t][y] > max_wins || (wins[t][y] == max_wins && points[t][y] > max_points)) {
                max_wins = wins[t][y]; // update max_wins
                max_points = points[t][y]; // update max_points
                top_team = t + 1; // update top_team
                tie_team = -1; // reset tie_team
            } 
            else if (wins[t][y] == max_wins && points[t][y] == max_points) { // if there is a tie
                tie_team = t + 1; // update tie_team
            }
        }
        if (tie_team == -1) { // if there is no tie
            printf("The top team of %d was Team %d.\n", years[y], top_team); 
        } else { // if there is a tie
            printf("The top team of %d was tied between Team %d and Team %d.\n", years[y], top_team, tie_team);
        }
    }
}

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
void write_results(const char *F, int wins[][10], int points[][10], int num_years, int years[]) {
    FILE *out = fopen(F, "w");
    if (!out) {
        fprintf(stderr, "Error: Could not open output file %s\n", F);
        exit(1);
    }

    // Print the correct years in the header
    fprintf(out, "Team ");
    for (int y = 0; y < num_years; y++) {
        fprintf(out, "%d ", years[y]);  // Print extracted year for wins
    }
    for (int y = 0; y < num_years; y++) {
        fprintf(out, "%d ", years[y]);  // Print extracted year for points
    }
    fprintf(out, "\n");

    // Print team data for each team
    for (int i = 0; i < TEAMS; i++) { 
        fprintf(out, "%4d", i + 1);
        for (int j = 0; j < num_years; j++) {
            fprintf(out, "%5d", wins[i][j]); // Print wins per year
        }
        for (int j = 0; j < num_years; j++) { 
            fprintf(out, "%5d", points[i][j]); // Print points per year
        }
        fprintf(out, "\n");
    }
    fclose(out);
}