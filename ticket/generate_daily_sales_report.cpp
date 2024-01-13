#include <iostream>
#include <iomanip>
#include <string>
#include <thread>
#include <chrono>
#include <sstream>
#include <vector>
#include "TicketSale.h"


using namespace std;

bool stafflogin(){
    string username;
    string password;

    cout << "Enter username:";
    getline(cin, username);

    cout << "Enter password:";
    cin >> password;

    if (username == "admin" && password == "1234")
    {
        return true;
    }
    else{
        return false;
    }
    
}

void print_bar(double percentage, string label){
    cout << label << ": " << setprecision(2) << fixed << percentage << "%" << endl;
    int bar_segments = static_cast<int>(percentage / 5); // Assuming each bar segment represents 5%

    // Print the top of the bar
    cout << " _______ " << endl;

    // Print the bar segments
    for (int i = 0; i < bar_segments; ++i) {
        cout << "|       |" << endl;
    }


    // Print the bottom of the bar
    cout << "------------------------------------------" << endl;
}


void generate_daily_sales_report(const vector<TicketSale>& sales, double refunded_amount){
    if (stafflogin()){
        static double totalRefunded = 0.0;
        totalRefunded += refunded_amount;

        double totalSales = 0.0;
        int total_tickets = 0;

        for (auto& sale: sales){
            totalSales += sale.ticketPrice * sale.quantity;
            total_tickets += sale.quantity;
        }

        // Ensure totalSales and totalRefunded are not negative
        totalSales = max(0.0, totalSales);
        totalRefunded = max(0.0, totalRefunded);

        // Calculate the final amount after refunds
        double final_amount = max(0.0, totalSales - totalRefunded);

        // Calculate percentages if there are sales
        double refunded_percent = (totalSales > 0) ? (totalRefunded / totalSales) * 100 : 0.0;
        double final_percent = (totalSales > 0) ? (final_amount / totalSales) * 100 : 0.0;

        // Generate report
        cout << "Generating''''''''" << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "----" << endl; 
        this_thread::sleep_for(chrono::seconds(1));
        cout << "\n\n\t\t------------------------------------------\n";
        cout << "\t\tSales Made for the day\n";
        cout << "\t\t------------------------------------------\n";
        cout << "\t\tTotal Sales: RM" << setprecision(2) << fixed << totalSales << endl;
        cout << "\t\tTotal tickets sold: " << total_tickets << endl;
        cout << "\t\t------------------------------------------\n\n\n";
        
        cout << "\t\tRefunded amount: RM" << refunded_amount << endl;
        cout << "\t\tFinal amount refunded: RM" << totalRefunded << endl;
        cout << "\t\tFinal amount received: RM" << final_amount << "\n\n";

        print_bar(refunded_percent, "Final amount refunded(%)");
        print_bar(final_percent, "Final amount received(%)");
    }
    else{
        cout << "Invalid login. Please try again later.\n\n\n";
    }
}



void admin_page_logo(){
    
cout<<"   _____       .___      .__         __________  " << endl;                      
cout<<"  /  _  \\    __| _/_____ |__| ____   \\______   \\_____     ____   ____" << endl;  
cout<<" /  /_\\  \\  / __ |/     \\|  |/    \\   |     ___/\\__  \\   / ___\\_/ __ \\ "<< endl;
cout<<"/    |    \\/ /_/ |  Y Y  \\  |   |  \\  |    |     / __ \\_/ /_/  >  ___/ " << endl;
cout<<"\\____|__  /\\____ |__|_|  /__|___|  /  |____|    (____  /\\___  / \\___ >" << endl;
cout<<"        \\/      \\/     \\/        \\/                  \\//_____/     \\/ " << endl;


}