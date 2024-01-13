#include <iostream>
#include <iomanip>
#include <string>
#include <thread>
#include <chrono>
#include <sstream>
#include <vector>
#include <windows.h>

using namespace std;

void displayStage(){
    cout << R"(
                                             __..----..__
                                     __..--""            ""--..__
                                    :           stage            :
                                    |                            |
                                    |           .-""-.           |
                                    |          :      :          |
                                    |          |______|          |
                                    |          |      |          |
                                   _:__________|      |__________:_
                                  .'                                `.
                             /I_.'  I'-..-''-..-''-..-''-..-''-..-'I '-.I\
                             //|___/|______________________________|\___|\\
                                    | |   | |         | |   | |  
                                    | |   !_!         !_!   | |   
                                    | |                     | |    
                                    | |                     | |     
                                    | |                     | |      
                                    !_!                     !_!)";
cout << endl;
};



// Function to display the current seating layout with enhancements
void displaySeats(char seats[14][10], char zones[14][10]) {
    // Display the stage layout
    displayStage();
    cout << "\n\t   |EXIT|                        \t\t                                    |ENTRANCE|   " << endl;
    cout << "\n\n\t\t          0       1        2        3        4 "  << setw(48) << right <<  "  5        6        7        8        9 " << endl;

    // Loop through each row of seats
    for (int i = 0; i < 14; ++i) {
        // Add column numbers before the row starts if it's a two-digit row number
        if (i == 10) {
            cout << "\t\t    "; // Adjust initial spacing for alignment
            for (int col = 0; col < 10; ++col) {
                if (col == 5) {
                    cout << "   "; // Adjust for the divider between sections
                }
                cout << "      " << col << "   "; // Adjust spacing between column numbers
            }
            cout << endl;
        }

        cout << "\t\t";
        cout << "Row" << setfill(' ') << setw(2) << i << " "; // Display the row number
    
       // Loop through each seat in the row
        for (int j = 0; j < 10; ++j) {
            if (j == 5) {
                cout << " | "; // Divider between sections
            }
            
            // Check if the seat is not reserved
            if (seats[i][j] != 'X') {
                // Display seat number with zone info, color-coded for clarity
                cout << "[" <<"\033[1;32m" << zones[i][j] << i << j << "\033[0m" << "]" << "    "; // Green for available seats
            } else {
                if (i >= 10)
                {
                    cout << "[" <<"\033[1;31m X\033[0m" << "  ]" << "    ";
                }
                else
                {
                    cout << "[" <<"\033[1;31m X\033[0m" << " ]" << "    ";
                }
                
                // Red 'X' for reserved seats
            }
        }
        cout << "\n\n"; // New line after each row

        // Visual dividers after specific zones
        if (i == 4 || i == 9) {
            cout << setw(60) << setfill('-') << "\n" << setfill(' ');
        }
    }

    // Display symbols and colors
    cout << "\033[1;32mGreen\033[0m - Available Seat\n";
    cout << "\033[1;31mRed 'X'\033[0m - Reserved Seat\n";
    cout << "Numbers - Seat Position (ZoneRowSeat)\n";
}



