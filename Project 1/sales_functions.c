#include <stdlib.h>
#include "sales_functions.h"

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
float overall_revenue(FILE *f1){
    int items_sold, item_code;
    float total_revenue = 0, menu_price, purchase_cost;

    while(fscanf(f1, "%d %d %f %f", &item_code, &items_sold, &menu_price, &purchase_cost) == 4){ //scans the file and initializes item_code, items_sold, menu_price, and purchase_cost to their respective value within the file
        total_revenue += items_sold * menu_price; // calculates total revenue
    }
    return total_revenue;
}

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
float overall_profit(FILE *f1){
    int items_sold, item_code;
    float total_profit = 0, menu_price, purchase_cost;

    while(fscanf(f1, "%d %d %f %f", &item_code, &items_sold, &menu_price, &purchase_cost) == 4){ //scans the file and initializes item_code, items_sold, menu_price, and purchase_cost to their respective value within the file
        total_profit += items_sold * (menu_price - purchase_cost); // calculates total profit
    }
    return total_profit;
}

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
void report_one(FILE *f1, int item){
    int items_sold, item_code;
    float menu_price, purchase_cost;

    rewind(f1);

    while(fscanf(f1, "%d %d %f %f", &item_code, &items_sold, &menu_price, &purchase_cost) == 4){
        if(item_code == item){
            float total_revenue = items_sold * menu_price;
            float total_profit = items_sold * (menu_price - purchase_cost);
            printf("Item %d sold %d times with a revenue of $%0.2f and a profit of $%0.2f.\n", item_code, items_sold, total_revenue, total_profit);
            return;
        }
    }
}