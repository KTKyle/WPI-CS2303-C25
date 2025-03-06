This program simulates running a coffee shop and managing your baristas with respect to the nature of the orders taken in a given day

This program is made up of 8 different files: 
    - Barista.h
        function headers for the functions implemented in Barista.cpp and used in myShop.cpp 
        also contains the constructor for the barista class
        
    - Barista.cpp
        implements the functions in the Barista.h file:
            - setters and getters for the member variables
            - incrementer for barista's free time
            - function to print the member variables of the barista class 
            - prints the Barista member variables to the ostream parameter

    - order.h 
        function headers for the functions implemented in order.cpp and used in myShop.cpp 
        also contains the constructor for the order class 

    - order.cpp 
        implments the functions from the order.h file: 
            - setters and getters for the member variables 
            - prints the order information to the ostream parameter
            - prints the order information to the terminal

    - shopQueue.h     
        function headers for the functions implemented in shopQueue.cpp and used in myShop.cpp
        also contains the constructor for the shopQueue class 

    - shopQueue.cpp
        implements the functions from the shopQueue.h file:
            - creates the node struct pointing to the current order and the next node in line 
            - contains a default constructor 
            - function to add an order to the queue 
            - getter for the length of queue 
            - a function to check if the queue is empty 
            - can peek at the front of the queue 
            - can remove the front node 

    - myShop.cpp 
        main:
            - checks for valid number of command line argument 
            - intitializes the command line arguments 
            - creates a queue and two vectors, one for the number of baristas and one for completed orders 
            - reads the data from the input file 
            - calculates the data needed for the output file 
            - prints a formatted version of the data to the output file 
    
    - make file 
        compiles all files above and creates an executable run_simulation to be used at the user's leisure 

To compile: 
    Use makefile command:
        make 

To run: 
    The program should be run with the following command line template:
        "./run_simulation inputFile numBaristas outputFile totalTime"
        - inputFile: name of the txt file containing the data 
        - numBaristas: the number (int) of baristas 
        - outputFile: the outputFile 
        - totalTime: the total amount of time (int) 

Sources: This program was written by Kyle Truong with the aid of:
    - https://stackoverflow.com 
The project was based on an assignment at WPI's 2303-Systems Programming Concepts taught by Professor Jennifer Mortensen    