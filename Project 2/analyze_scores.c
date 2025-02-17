#include "analysis_functions.h"

int main(int argc, char *argv[]) {
    if (argc < 3) { // check if the correct number of arguments are provided
        puts("Run the program with a list of input file, followed by the output file\n");
        puts("./runScores file_name.txt ... results.txt\n");
        puts("where file_name.txt ... is a list of files to process");
        puts("and results.txt is the name of the output file to produce.");
        return 1;
    }

    int num_years = argc - 2; // Number of years being analyzed
    if (num_years > YEARS_MAX) {
        fprintf(stderr, "Error: Too many input files. Maximum supported years: %d\n", YEARS_MAX);
        return 1;
    }

    int wins[TEAMS][YEARS_MAX] = {0}; // Initialize wins array
    int points[TEAMS][YEARS_MAX] = {0}; // Initialize points array
    int years[YEARS_MAX] = {0};  // Store extracted years from the files

    // Read data from each input file
    for (int i = 1; i <= num_years; i++) {
        read_data(argv[i], wins, points, i - 1, years);
    }

    find_top(wins, points, num_years, years); // Find top team for each year
    write_results(argv[argc - 1], wins, points, num_years, years); // Write results to output file

    return 0;
}
