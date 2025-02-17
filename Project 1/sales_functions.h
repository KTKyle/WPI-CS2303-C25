#include <stdio.h>
/**
 * float overall_revenue (FILE *f1)
 * 
 * This functions purpose is to take the user inputted file and parse through it taking all relevant data
 * and using that to calculate the total revenue of the day
 * 
 * Parameters: 
 *      FILE f1: The user inputted file that contains four different types of numbers:
 *          - an int that represents the item code of a specific item
 *          - an int that represents how many times that specific item has sold
 *          - a float that represents the menu price of that item
 *          - a float that represents the purchase cost of that item
 * 
 * Returns: 
 *      total_revenue: a value that represents the total revenue of the day
 */
float overall_revenue(FILE *f1);

/**
 * float overall_profit (FILE *f1)
 * 
 * This functions purpose is to take the user inputted file and parse through it taking all relevant data
 * and using that to calcualte the total profit of the day
 * 
 * Parameters: 
 *      FILE f1: The user inputted file that contains four different types of numbers:
 *          - an int that represents the item code of a specific item
 *          - an int that represents how many times that specific item has sold
 *          - a float that represents the menu price of that item
 *          - a float that represents the purchase cost of that item
 * 
 * Returns:
 *      total_profit: a value that represents the total profit of the day
 */
float overall_profit(FILE *f1);

/**
 * void report_one(FILE *f1, int item)
 * 
 * This functions purpose is to generate a report on a given item showing all relevant details
 * 
 * Parameters: 
 *      FILE f1: The user inputted file that contains four different types of numbers:
 *          - an int that represents the item code of a specific item
 *          - an int that represents how many times that specific item has sold
 *          - a float that represents the menu price of that item
 *          - a float that represents the purchase cost of that item
 *      int item: an integer that represents the item code we are generating a report for
 * 
 * Returns: 
 *      void
 */
void report_one(FILE *f1, int item);
