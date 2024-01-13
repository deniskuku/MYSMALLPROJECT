#include <iostream>
#include <iomanip>
#include <string>
#include <thread>
#include <chrono>
#include <sstream>
#include <vector>
#include <limits>
#include <algorithm>
#include "TicketSale.h"

using namespace std;


void displayBookedSeats(const TicketSale& sale) {
    
    cout << "Your booked seats are: ";
    for (const auto& seat : sale.seats) {
        cout << seat << " ";
    }
    cout << "\n\n";
}

bool isValidSeat(int row, int col) {
    return row >= 0 && row < 14 && col >= 0 && col < 10;
}

bool processRefund(TicketSale& sale, int row, int col, char seats[14][10], char zones[14][10], double& total) {
    // Retrieve the original zone symbol for the seat
    char originalZone = zones[row][col];

    // Check if the seat is marked as booked ('X')
    if (seats[row][col] != 'X') {
        cout << "The seat " << row << col << " is not currently booked.\n";
        return false;  // Return false as the seat is not booked
    }

    // Reset the seat to show it as available by setting it to its original zone symbol
    seats[row][col] = originalZone;

    // Construct a string that uniquely identifies the refunded seat
    string seatRefunded = string(1, originalZone) + to_string(row) + to_string(col);

    // Search for this seat in the list of booked seats
    auto it = find(sale.seats.begin(), sale.seats.end(), seatRefunded);

    // Check if the seat was found in the list of booked seats
    if (it == sale.seats.end()) {
        cout << "The seat " << row << col << " was not found in your booked seats.\n";
        return false;  // Return false as the seat is not in the list of booked seats
    }

    // Remove the seat from the list of booked seats
    sale.seats.erase(it);

    // Inform the user that the refund will be processed
    cout << "\n\n\tWe apologize for any inconvenience caused. We'll process your refund shortly.\n\n";

    // Display the refund amount to the user
    cout << setw(28) << "Refund for you: RM" << setprecision(2) << fixed << total << "\n\n\n";

    // Indicate to the user that the seat is now available
    cout << "The seat " << row << col << " in Zone " << originalZone << " is now available." << endl;

    // Return true to indicate the refund was processed successfully
    return true;
}


// Function to process a ticket refund
double refund_ticket(double total, TicketSale& sale,int row, int col, char seats[14][10], char zones[14][10]) {
    int reason;
    string custom_reason;
    if (sale.seats.empty()) {
        cout << "You have no booked seats to refund." << endl;
        return 0.0;  // Return 0.0 to indicate no refund was processed
    }

    // Display a message asking the user for the reason for refund
    cout << "We're sorry to hear that you want to refund your ticket. Can you please tell us the reason?\n\n";
    cout << "1. I can't attend the event.\n";
    cout << "2. I bought the wrong ticket.\n";
    cout << "3. I'm not satisfied with the service.\n";
    cout << "4. Other reasons.\n";
    cout << "Please enter the number corresponding to your reason: ";
    cin  >> reason;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Input validation
    if (cin.fail()) {
        cin.clear(); // Clear the error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the incorrect input
        cout << "Invalid input. Please enter a number." << endl;
    }
    
    cout << "\n";


    // Process the refund based on the reason provided
    switch (reason) {
    case 1:
    case 2:
    case 3:
        // Refund the ticket for common reasons
        displayBookedSeats(sale);
        cout << "Enter the row of the seat to refund: ";
        cin >> row;

        if (cin.fail() || row < 0 || row >= 14) {
        cin.clear(); // Clear the error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the buffer
        cout << "Invalid row. Operation canceled." << endl;
        return 0.0;
        }

        cout << "Enter the column of the seat to refund: ";
        cin >> col;
        

        if (cin.fail() || col < 0 || col >= 14) {
        cin.clear(); // Clear the error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the buffer
        cout << "Invalid column. Operation canceled." << endl;
        return 0.0;
        }
         if (isValidSeat(row, col)) {
            if (processRefund(sale, row, col, seats, zones, total)) {
                return total; // Return the total amount for refund
            } else {
                return 0.0; // Refund was not processed because the seat was not booked
            }
        } else {
            cout << "Invalid seat position. No changes made to seat status." << endl;
            return 0.0;
        }
                
        break;

    case 4:
        // Handle other custom reasons
        cout << "Please type your reason: ";
        getline(cin, custom_reason); // Get the custom reason from the user
        cout << "We apologize for any inconvenience caused. Your reason: \"" << custom_reason << "\" will be reviewed by our team.\n";
        
        return 0.0; // No refund for custom reasons
        break;

    default:
        // Handle invalid option
        cout << "Invalid option. Please try again.\n";
        return 0.0; // Return zero indicating no refund
        break;
    }
}


