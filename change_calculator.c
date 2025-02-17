#include <stdio.h>

/**
 * int check_amount (float total, float paid)
 * 
 * This fuction's purpose is to take the user inputted numbers and check them against each other 
 * comparing to see if the amount paid is greater than or equal to the cost.
 * 
 * Parameters: 
 *      float total: A number of type float that represents the total cost 
 *      float paid: A number of type float that represents how much the user has paid
 * 
 * Returns: 
 *      If the amount paid is greater than the total cost then returns 1.
 *      If the amount paid is not greater than the total cost then it will return 0
 */
int check_amount(float total, float paid);

/**
 * void print_formatted(float change)
 * 
 * This fuction's purpose is to format the remainder of change left in terms of:
 * five dollar bills, one dollar bills, quarters, dimes , nickels, and pennies
 * 
 * Parameters: 
 *      float change: A number of type float that represents the amount of change left from the 
 *                    purchase that we have to format
 * 
 * Returns:
 *      A formatted string with the distributions of bills/coins that the user recieves according to 
 *      their amount of change left
 */
void print_formatted(float change);

int main(){
    float total;
    printf("Input purchase total:\n");
    scanf("%f", &total); // initializes float total to the user input

    float paid;
    printf("Input amount paid:\n");
    scanf("%f", &paid); // initializes float paid to the user input

    float change = paid - total; //calculates the change to input for print_formatted
    if(check_amount(total, paid) == 1){ // if check_amount came out to be true that means the user has paid at least in full if not more
        print_formatted(change); // takes the remainder that we owe the user and puts it as the input into print_formatted
    }
    else{
        printf("Insufficient payment.\n"); // will only print if the user didn't pay as much as they owed
    }
    return 0;
}

/**
 * int check_amount (float total, float paid)
 * 
 * This fuction's purpose is to take the user inputted numbers and check them against each other 
 * comparing to see if the amount paid is greater than or equal to the cost.
 * 
 * Parameters: 
 *      float total: A number of type float that represents the total cost 
 *      float paid: A number of type float that represents how much the user has paid
 * 
 * Returns: 
 *      If the amount paid is greater than the total cost then returns 1.
 *      If the amount paid is not greater than the total cost then it will return 0
 */
int check_amount(float total, float paid){
    int check_index = 0; // default case of o (false)
    if(paid >= total){ //if the user paid an amount greater than or equal to the total they owe
        check_index = 1; // set to 1 (true)
    }
    return check_index;
}

/**
 * void print_formatted(float change)
 * 
 * This fuction's purpose is to format the remainder of change left in terms of:
 * five dollar bills, one dollar bills, quarters, dimes , nickels, and pennies
 * 
 * Parameters: 
 *      float change: A number of type float that represents the amount of change left from the 
 *                    purchase that we have to format
 * 
 * Returns:
 *      A formatted string with the distributions of bills/coins that the user recieves according to 
 *      their amount of change left
 */
void print_formatted(float change){
    // ALL CONST VARIABLES CREATED FOR CLARITY PURPOSES WHEN DOING CALCULATIONS LATER ON
    const int CENTS = 100; // creates a const variable representing the conversion factor from dollars to cents (pennies) for easier general calculations
    const int FIVE_DOLLARS = 500; // creates a const variable representing the conversion factor from five dollars to cents (pennies)
    const int ONE_DOLLAR = 100; // creates a const variable representing the conversion factor from one dollars to cents (pennies)
    const int QUARTER = 25; // creates a const variable representing the penny value of a quarter
    const int DIME = 10;  // creates a const variable representing the penny value of a dime
    const int NICKEL = 5;  // creates a const variable representing the penny value of a nickel

    int total_change_in_pennies = change * CENTS; // converts the total change left into a penny value for easier calculations
    
    int fives = total_change_in_pennies/FIVE_DOLLARS; // initializes an int variable which represents the amount of five dollar bills needed as part of the change given to the customer
    total_change_in_pennies %= FIVE_DOLLARS; // sets the new value of total_change_in_pennies to the remainder of change after the five dollar bills were distributed

    int ones = total_change_in_pennies/ONE_DOLLAR; // initializes an int variable which represents the amount of one dollar bills needed as part of the change given to the customer
    total_change_in_pennies %= ONE_DOLLAR; // sets the new value of total_change_in_pennies to the remainder of change after the one dollar bills were distributed

    int quarters = total_change_in_pennies/QUARTER; // initializes an int variable which represents the amount of quarters needed as part of the change given to the customer
    total_change_in_pennies %= QUARTER; // sets the new value of total_change_in_pennies to the remainder of change after the quarters were distributed

    int dimes = total_change_in_pennies/DIME; // initializes an int variable which represents the amount of dimes needed as part of the change given to the customer
    total_change_in_pennies %= DIME; // sets the new value of total_change_in_pennies to the remainder of change after the dimes were distributed

    int nickels = total_change_in_pennies/NICKEL; // initializes an int variable which represents the amount of nickels needed as part of the change given to the customer
    total_change_in_pennies %= NICKEL; // sets the new value of total_change_in_pennies to the remainder of change after the nickels were distributed

    int pennies = total_change_in_pennies; // initializes an int variable using the remainder of any change left which represents the amount of pennies we owe the customer

    printf("Your change is $%.2f\n" , change);
    /**formats the print statement to not print out any data that isn't relevant
    EX: change of 5.71, won't print any data about one dollar bills or nickels just that we have
    one five dollar bill, two quarters, two times, and one penny
    **/
    if(fives != 0){
        printf("  %d - 5D\n", fives);
    }
    if(ones != 0){
        printf("  %d - 1D\n", ones);
    }
    if(quarters != 0){
        printf("  %d - Q\n", quarters);
    }
    if(dimes != 0){
        printf("  %d - D\n", dimes);
    }
    if(nickels != 0){
        printf("  %d - N\n", nickels);
    }
    if(pennies != 0){
        printf("  %d - P\n", pennies);
    }
}