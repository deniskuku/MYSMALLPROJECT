#include <iostream>
#include <iomanip>
#include <string> 
#include <chrono>//sleep for timer
#include <thread>//sleep for timer  
#include <sstream>
#include <vector>
#include <cstdlib>//system clear screen
#include <windows.h> // text color
#include <limits> //ignore incorrect input
#include <regex> //check if the username and password are in right format
#include <conio.h>
#include "src/displayseats.h" 
#include "src/view_total_payment.h"
#include "ticket/orderTicket.h"
#include "src/make_payment.h"
#include "ticket/generate_ticket.h"
#include "ticket/generate_daily_sales_report.h"
#include "src/display_logo_menu.h"
#include "ticket/refund_ticket.h"
#include "login/login.h"
#include "login/feedback.h"



using namespace std;


// Main function of the ticket sales management system
int main()
{   
    // Variable declarations
    int ticket_count = 0;
    int choice;

    string name = " ";

    int zoneA_count = 0;
    int zoneB_count = 0; 
    int zoneC_count = 0;
    char heart = 3; // Heart character for display
    
    vector<TicketSale> sales;// Vector to store ticket sales data
    vector<Feedback> feedbacks; //vector to store feedbacks
    TicketSale userSale;// Represents the user's cumulative bookings

    
    char seats[14][10] = {}; // Seat layout

    // Initialize the seats array
    for (int i = 0; i < 14; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            seats[i][j] = ' ';
        }
        
    }

    double total = 0;

    const char ZONE_A = 'A';
    const char ZONE_B = 'B';
    const char ZONE_C = 'C';

    // Zone layout for the seating
    char zones[14][10] = {
    {ZONE_A, ZONE_A, ZONE_A, ZONE_A, ZONE_A, ZONE_A, ZONE_A, ZONE_A, ZONE_A, ZONE_A},
    {ZONE_A, ZONE_A, ZONE_A, ZONE_A, ZONE_A, ZONE_A, ZONE_A, ZONE_A, ZONE_A, ZONE_A},
    {ZONE_A, ZONE_A, ZONE_A, ZONE_A, ZONE_A, ZONE_A, ZONE_A, ZONE_A, ZONE_A, ZONE_A},
    {ZONE_A, ZONE_A, ZONE_A, ZONE_A, ZONE_A, ZONE_A, ZONE_A, ZONE_A, ZONE_A, ZONE_A},
    {ZONE_B, ZONE_B, ZONE_B, ZONE_B, ZONE_B, ZONE_B, ZONE_B, ZONE_B, ZONE_B, ZONE_B},
    {ZONE_B, ZONE_B, ZONE_B, ZONE_B, ZONE_B, ZONE_B, ZONE_B, ZONE_B, ZONE_B, ZONE_B},
    {ZONE_B, ZONE_B, ZONE_B, ZONE_B, ZONE_B, ZONE_B, ZONE_B, ZONE_B, ZONE_B, ZONE_B},
    {ZONE_B, ZONE_B, ZONE_B, ZONE_B, ZONE_B, ZONE_B, ZONE_B, ZONE_B, ZONE_B, ZONE_B},
    {ZONE_B, ZONE_B, ZONE_B, ZONE_B, ZONE_B, ZONE_B, ZONE_B, ZONE_B, ZONE_B, ZONE_B},
    {ZONE_C, ZONE_C, ZONE_C, ZONE_C, ZONE_C, ZONE_C, ZONE_C, ZONE_C, ZONE_C, ZONE_C},
    {ZONE_C, ZONE_C, ZONE_C, ZONE_C, ZONE_C, ZONE_C, ZONE_C, ZONE_C, ZONE_C, ZONE_C},
    {ZONE_C, ZONE_C, ZONE_C, ZONE_C, ZONE_C, ZONE_C, ZONE_C, ZONE_C, ZONE_C, ZONE_C},
    {ZONE_C, ZONE_C, ZONE_C, ZONE_C, ZONE_C, ZONE_C, ZONE_C, ZONE_C, ZONE_C, ZONE_C},
    {ZONE_C, ZONE_C, ZONE_C, ZONE_C, ZONE_C, ZONE_C, ZONE_C, ZONE_C, ZONE_C, ZONE_C},
    };

    // Setting up ticket prices based on zones
    double prices[14][10];
    for (int i = 0; i < 14; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            switch (zones[i][j])
            {
            case ZONE_A:
                prices[i][j] = 300;
                break;
            case ZONE_B:
                prices[i][j] = 200;
                break;
            case ZONE_C:
                prices[i][j] = 100;
                break;
        
            }
        }
        
    };

    char enter;
    
    TicketSale cumulativeSale;
    cumulativeSale.ticketPrice = 0;
    cumulativeSale.quantity = 0;
    cumulativeSale.seats.clear();

    int row, col;

   
    // Main program loop
    while(true){

    int count = 0; // Counter to limit the number of animation cycles
    
        // Run animation until a key is pressed or until 10 cycles are completed
        while(!_kbhit() && count < 10) { 
            clearScreen();
            display_coolPlay_logo();
            this_thread::sleep_for(chrono::milliseconds(500));

            clearScreen();
            display_logo_batman_night();
            this_thread::sleep_for(chrono::milliseconds(500));

            count++;
        }

        // If a key was pressed during the animation, clear the input buffer
        if(_kbhit()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // After animation or key press, clear screen and prompt to continue
        
        clearScreen();
        display_coolPlay_logo();
        display_logo_batman_night();

        cout << "\n\n" << setw(20) << "Press enter to continue...";
        string input;
        getline(cin, input); // Wait for Enter

        if (input.empty()) {
            // The user pressed Enter without any extra input
            // Continue with the rest of your program
        } 
        else {
            // The user entered some text or numbers before pressing Enter
            cout << "Error: Invalid input. Please press Enter only.\n";
            // Handle the error or prompt again as necessary
        }



        system("cls");   
        string email = login(); // User login
        bool continueProgram = true;

    while(continueProgram){
        char continueBooking = 'y'; 
        
        // Display menu and get user choice
        display_menu(heart);
        cout << setfill(' ') <<setw(39) << right<<"Please enter your choice(1-6): ";
        cin >> choice ;
        // Input validation to handle incorrect input types
        if(cin.fail()) 
        {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore the incorrect input
        cout << "Invalid input. Please enter a number." << endl;
        } 
        
        cout << "\n";

        // Variables to hold the current sale and payment status
        TicketSale sale;
        bool payment_Successful;
        bool ordercompleted;
        
        // Switch case to handle different menu choices
        switch(choice)
        {
            case 1:
            // Ticket booking process
            system("cls");
            while(continueBooking == 'y') {
            cout << "Current Seating Layout: " << endl;
            displaySeats(seats, zones);

            cout << "\n";
            cout << "ZoneA : RM100 /pax" << endl;
            cout << "ZoneB : RM200 /pax" << endl;
            cout << "ZoneC : RM300 /pax" << endl;
            
            

            sale = orderTicket(seats, zones, prices, zoneA_count, zoneB_count, zoneC_count, ticket_count, userSale);
            ordercompleted = true;


            if (sale.quantity == 0 && sale.ticketPrice == 0)
            {
                break;
            }
            

            sales.push_back(sale);
           

            if (sale.quantity != 0) {
            cumulativeSale.ticketPrice += sale.ticketPrice;
            cumulativeSale.quantity += sale.quantity;
            cumulativeSale.seats.insert(cumulativeSale.seats.end(), sale.seats.begin(), sale.seats.end());
}

            total += sale.ticketPrice;

            cout << "\nWould you like to book another ticket? (y/n): ";
            cin >> continueBooking;

            while (continueBooking != 'y' && continueBooking != 'n') {
                //cout << "Invalid input. Please enter 'y' or 'n': ";
                cin >> continueBooking;
            }

            if (continueBooking == 'n')
            {
                cout << "Updated Seating Layout: " << endl;
                displaySeats(seats, zones);
                cout << endl;
                break;
            }
            
            }
            cout << "\nPress Enter to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
            cin.get();// Wait for Enter
            system("cls");
            break;

        
            case 2:
            // View total payment
            system("cls");
            view_total_payment(heart, total, ticket_count);
            cout << "Enter your name: ";
            cin.ignore();
            getline(cin, name);
            system("cls");
            break;

            case 3:
            // Make payment
            system("cls");
            if (ordercompleted)
            {
               payment_Successful = make_payment(total);
            }
            else {
            cout << "ORDER TICKETS FIRST :) Please try again." << endl;
                }
            
            
            break;

            case 4:
            // Generate ticket
            system("cls");
            if (payment_Successful)
            {
               generate_ticket(name, zoneA_count, zoneB_count, zoneC_count, cumulativeSale);
            }
            else 
            {
                cout << "MAKE PAYMENT FIRST :) Please try again." << endl;
            }
            
            
            break;

            
            case 5:
            // Refund ticket
            double refunded_amount;
            system("cls");
            refunded_amount = refund_ticket(total, cumulativeSale, row, col, seats, zones);

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nPress Enter to continue...";
            cin.get(); 

            system("cls");
           
            break;

            case 6:
            // Generate daily sales report
            system("cls");
            admin_page_logo();

            cout << "Press enter to continue...." << endl;
            cin.get();
            enter = cin.get();

            if (enter == '\n')
            {
                         
                generate_daily_sales_report(sales, refunded_amount);
            }
            else
            {
                cout << "Invalid input. Please press enter.\n\n" << endl;
            }

            cout << "\nPress Enter to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
            cin.get();// Wait for Enter
            system("cls");
            break;


            case 7:
            // Exit the program
            system("cls");
            cout << "Thank you for using the ticket ordering system. See you again!"<< "\n";
            cout << "\nExiting" << endl;

            this_thread::sleep_for(chrono::seconds(1));
            
            cout << "=======>" << endl;
            continueProgram = false;
            zoneA_count = 0;
            zoneB_count = 0;
            zoneC_count = 0;
            total = 0;
            ticket_count = 0;
            refunded_amount = 0;
            cin.ignore();
            break;

            case 8:
            // Submit feedback
            system("cls");

            int feedback_choice;
            cout << "1. Submit Feedback" << endl;
            cout << "2. View Previous Feedbacks" << endl;
            cout << "Enter your choice: ";
            cin >> feedback_choice;
            
            if(feedback_choice == 1){
            system("cls");    
            submitFeedback(email, feedbacks);
            }
            else if(feedback_choice == 2)
            {
            displayFeedbacks(feedbacks);
            cout << "\nPress Enter to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any previous input
            cin.get(); // Wait for Enter
            }
            else
            {
                cout << "Invalid choice. Please try again." << endl;
                cout << "\nPress Enter to continue...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any previous input
                cin.get(); // Wait for Enter
            }

            system("cls");
            break;


            default:
            // Handle invalid choice
            system("cls");
            cout << "Invalid choice. Please try again." << endl;





        }


    }

            

    }


    return 0;
}







