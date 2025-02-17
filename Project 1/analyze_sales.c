#include <stdio.h>
#include <stdlib.h>
#include "sales_functions.h"

int main (void){
    int program_to_run;
    char name[100];
    int item_code;

    puts("Which program would you like to run:");
    puts("(1) Calculate overall revenue");
    puts("(2) Calculate overall profit");
    puts("(3) Report on a single item");

    if (scanf("%d", &program_to_run) != 1 || program_to_run < 1 || program_to_run > 3) { // checks if the user input is a valid number that we can run according to options listed above
        puts("This option is not valid.");
        return 1;
    }

    puts("Please enter an input file:");
    scanf("%s", name);

    FILE *f1 = fopen(name, "r"); // open user inputted file

    switch (program_to_run){ // runs the respective case based on the options above and the user inputted number
        case 1:{ // if user inputted 1, call the overall_revnue function from sales_functions.c
            float total_revenue = overall_revenue(f1);
            printf("The overall revenue in %s is $%0.2f.\n", name, total_revenue);
            break;
        }
        case 2:{ // if user inputted 2, call the overall_profit function from sales_functions.c
            float total_profit = overall_profit(f1);
            printf("The overall profit in %s is $%0.2f.\n", name, total_profit);
            break;
        }
        case 3:{ // if user inputted 3, promt them to input a number representing the item they want us to generate a report for and then call the report_one function from sales_functions.c
            puts("Which item to analyze?");
            scanf("%d", &item_code);
            report_one(f1, item_code);
            break;
        }
        default: {
            printf("This option is not valid.\n"); // Default case if somehow an unvalid number slipped by earlier if statement
            break;
        }
    }
    fclose(f1); //close file
    return 0;
}