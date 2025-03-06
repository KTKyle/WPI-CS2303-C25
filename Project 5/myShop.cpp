#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>
#include "Barista.h"
#include "order.h"
#include "shopQueue.h"

using namespace std;

int main(int argc, char* argv[]){
    if(argc != 5){ // Checks if we have adequate amount of command line arguments
        cout << "Error: Wrong number of arguments!" << endl;
        cout << "Usage: ./run_simulation <inputFile> <numBaristas> <outputFile> <totalTime>" << endl;
        return 1;
    }

    string inputFile = argv[1];       // first command line input: input file
    int numBaristas = stoi(argv[2]);  // second command line input: number of baristas
    string outputFile = argv[3];      // third command line input: output file
    int totalTime = stoi(argv[4]);    // fourth command line input: total time

    ShopQueue shopQueue; // create a ShopQueue object
    vector<Barista> baristas(numBaristas); // create a vector of Barista objects
    vector<shared_ptr<Order>> completedOrders; // create a vector of shared pointers to Order objects to store completed orders

    ifstream file(inputFile); // Open the input file
    if (!file) {
        cout << "Error can't open file" << endl;
        return 1;
    }

    int id, arrival, cookTime; // Initialize variables to store the order information
    while (file >> id >> arrival >> cookTime) { // Read the input file
        shopQueue.addNewOrder(id, arrival, cookTime, -1, -1); // Add the order to the shop queue
    }
    file.close(); // Close the input file

    cout << "Welcome to Gompei's Coffee Shop!" << endl;
    cout << "------ # of Baristas: " << numBaristas << " ------" << endl;

    for (int time = 0; time < totalTime; ++time) { // Loop through the time
        for (auto& barista : baristas) {  // Check if baristas are busy
            if (barista.getBusy() && (time >= barista.getStart() + barista.getDuration())) { // Check if the barista is done with the order
                barista.setBusy(0); // Set the barista to free
            }
        }

        for (auto& barista : baristas) { // Check if baristas are free and there are orders in the queue
            while (!barista.getBusy() && !shopQueue.isEmpty() && shopQueue.peekFrontOrder()->getArrival() <= time) { // Check if there are orders in the queue
                shared_ptr<Order> order = shopQueue.removeFrontOrder();   // Remove the order from the queue
                order->setStart(time);                                    // Set the start time of the order
                order->setWait(time - order->getArrival());               // Set the wait time of the order
                barista.setBusy(1);                                       // Set the barista to busy
                barista.setStart(time);                                   // Set the start time of the barista
                barista.setDuration(order->getCook());                    // Set the duration of the barista
                completedOrders.push_back(order);                         // Add the order to the completed orders vector
            }
            if (!barista.getBusy()) { // If the barista is free, increase the free time
                barista.increaseFree(); // Increase the free time of the barista
            }
        }
    }

    ofstream outFile(outputFile); // Open the output file
    if (!outFile) { // Check if the output file is open
        cout << "Error can't open file" << endl; // Print error message
        return 1;
    }
    outFile << "      ID Arrival    Cook   Start    Wait" << endl; // Print the header of the output file
    
    for (const auto& order : completedOrders) {
        outFile << *order << endl;
    }
    
    int customersInLine = shopQueue.getLength(); // Get the number of customers waiting
    int ordersCompleted = completedOrders.size(); // Get the number of customers served
    float totalWaitTime = 0;                      // Initialize the total wait time
    for (const auto& order : completedOrders) {   // Calculate the total wait time
        totalWaitTime += order->getWait();        // of the customers served
    }


    float averageWaitTime; // Initialize the average wait time
    if (ordersCompleted > 0) { // If we have completed at least one order
        averageWaitTime = totalWaitTime / ordersCompleted; // Calculate the average wait time
    } else {
        averageWaitTime = 0; // Set the average wait time to 0
    }

    cout << customersInLine << " customers are waiting for their order." << endl;
    cout << ordersCompleted << " customers have been served." << endl;
    printf("The average wait time was %0.2f minutes.\n", averageWaitTime);

    for (int i = 0; i < (int)baristas.size(); ++i) { // Print the idle percentage of each barista
        float idleTime = (float)baristas[i].getFreeTime() / totalTime * 100; // Calculate the idle percentage
        printf("Barista %d was idle %0.2f", i, idleTime);
        cout << "% of the time." << endl;
    }
    return 0;
}