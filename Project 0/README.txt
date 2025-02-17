This program simulates a program similar to a cash register with the fuction of finding the change due when purchasing items

The program has three distinct functions:
    - CHECK_AMOUNT which is supposed to check whether or not the user has given the correct amount of money to pay for their given items
    - PRINT_FORMATTED is used in the case that the user paid with money greater than the total and 
    will format the remainder that is due to the customer breaking it down by bills and coins like such:
        * 5 dollar bills
        * 1 dollar bills
        * Quarters
        * Dimes
        * Nickels
        * Pennies
    - The main takes records the two user inputs, while using CHECK_AMOUNT and PRINT_FORMATTED, run the calculations of how much we owe the customer
    or an error message if they haven't paid the full total

To compile: 
    - gcc change_calculator.c -Wall -o getChange

To run: 
    - ./getChange

Sources: This program was written by Kyle Truong.
The project was based on an assignment at WPI's 2303-Systems Programming Concepts taught by Professor Jennifer Mortensen