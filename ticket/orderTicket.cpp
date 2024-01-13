#include <iostream>
#include <iomanip>
#include <string>
#include <thread>
#include <chrono>
#include <sstream>
#include <vector>
#include "TicketSale.h"



using namespace std;

bool isNumber(const string& str)
{
    for(char const &c : str)
    {
        if (isdigit(c) == 0)
        {
            return false;
        }
        
    }
    return true;
}

TicketSale orderTicket(char seats[14][10], char zones[14][10], double prices[14][10], int& zoneA_count, int& zoneB_count, int& zoneC_count, int& ticket_count, TicketSale& sale) {
    // Variable declarations
    string input;
    int row, column;

    // Default ticket sale if the process is not completed
    TicketSale defaultSale;
    defaultSale.ticketPrice = 0;
    defaultSale.quantity = 0;

    
    // Ask user to enter the row number or 'q' to quit
    cout << "\nEnter the row seats (0-13) or 'q' to quit: ";
    cin >> input;

    // Check if user wants to quit
    if (input == "q")
    {
        TicketSale quitsale;
        quitsale.ticketPrice = 0;
        quitsale.quantity = 0;// Return a sale with 0 quantity and price
       
        return quitsale; // Return a sale with 0 quantity and price
    }
    
    if (!isNumber(input)) {
    cout << "Invalid input, please enter a numeric value." << endl;
    return defaultSale;
    }
    
    row = stoi(input); //string to integer
    
    // Ask user to enter the column number or 'q' to quit
    cout << "\nEnter the column seats (0-9) or 'q' to quit: ";
    cin >> input;

    // Check if user wants to quit
    if (input == "q")
    {
        TicketSale quitsale;
        quitsale.ticketPrice = 0;
        quitsale.quantity = 0;
        
        return quitsale;// Return a sale with 0 quantity and price
    }
    
    if (!isNumber(input)) {
    cout << "Invalid input, please enter a numeric value." << endl;
    return defaultSale;
    }

    column = stoi(input); //string to integer


    // Validate the seat coordinates
    if (row < 0 || row > 14 || column < 0 || column > 9){
        cout << "Invalid input, please try again." << endl;
        return defaultSale;
    } 
    

    // Check if the seat is already taken
    if(seats[row][column] == 'X') {
        cout << "Sorry, this seat is already taken. Try another one." << endl;
        return defaultSale; // Return default sale if seat is taken
    } 
    else {
        // Mark the seat as taken
        seats[row][column] = 'X';
        // Increment the respective zone count
        if (zones[row][column] == 'A')
        {
            zoneA_count++;
        }
        else if (zones[row][column] == 'B')
        {
            zoneB_count++;
        }
        else if (zones[row][column] == 'C')
        {
            zoneC_count++;
        }
        cout << "Seat successfully booked!" << endl;
        // Increment the total ticket count
        ticket_count++;
       
        // Create a new ticket sale with the price of the selected seat
        TicketSale sale;
        sale.ticketPrice = prices[row][column];
        sale.quantity = 1;
        string seat = string(1, zones[row][column]) + to_string(row) + to_string(column);
        sale.seats.push_back(seat);
        
        char zone = zones[row][column];
        // Return the created ticket sale
        
        return sale;

    }
    }