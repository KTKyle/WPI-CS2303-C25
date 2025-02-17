This program simulates more programs that a typical cash register would be able to compute

The entire program is a collection of three seperate files:

    - sales_functions: The file that does the bulk of the calculations 
        *overall_revenue: goes through the input file, calculates the total revenue, returns the total revenue
        *overall_profit: goes through the input file, calculates the total profit, returns the total profit
        *report_one: takes an integer input along with the input file and goes through the file printing out a formatted string
         of all necessary data for that given item code
    
    - analyze_sales: The file that deals with the user inputs
        *Offers three options that match the three functions in sales_functions
        *Runs the user inputted number against an if statement to check if the number is invalid (not < 1 and not > 3)
        *If inputted number is a valid number, runs through a switch case block where it will print out the statement 
        related to the number inputted 

    - sales_functions.h: Contains the prototypes for the functions in sales_functions.c

To compile: 
    - gcc analyze_sales.c sales_functions.c -o runSales

To run: 
    - ./runSales

Sources: This program was written by Kyle Truong with the aid of:
    - https://stackoverflow.com to solve general syntax issues found when debugging the program
    - https://www.geeksforgeeks.org used mostly to figure out the intricacies of accessing files in c and the things I can do with it
The project was based on an assignment at WPI's 2303-Systems Programming Concepts taught by Professor Jennifer Mortensen