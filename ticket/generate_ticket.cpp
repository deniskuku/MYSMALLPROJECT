#include <iostream>
#include <iomanip>
#include <string>
#include <thread>
#include <chrono>
#include <sstream>
#include <vector>
#include "TicketSale.h"

using namespace std;



void generate_ticket(string name, int zoneA_count, int zoneB_count, int zoneC_count, const TicketSale& sale){
        cout << "Generating......" << endl;
        this_thread::sleep_for(chrono::seconds(3));
        cout << "\n.............." << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "\n\n\n\t\t=============================\n";
        cout << "\t\t=    COOL PLAY CONCERT      =\n";
        cout << "\t\t+++++++++++++++++++++++++++++\n";
        cout << "\t\t*****************************\n";
        cout << "\t\t*      || TICKET ||         *\n";
        cout << "\t\t*****************************\n";
        cout << "\t\t= Name: " << name << setfill(' ') << setw(21 - name.length()) <<  "=" << endl;
        cout << "\t\t| Time : 8.00p.m to 11.00p.m|\n";
        cout << "\t\t| Venue: MELAKA STADIUM     |\n";
        cout << "\t\t-----------------------------\n";
        cout << "\t\t* Zone A Tickets: x" << zoneA_count << setfill(' ') << setw(9)<< "*" <<endl;
        cout << "\t\t* Zone B Tickets: x" << zoneB_count << setfill(' ') << setw(9)<< "*" <<endl;
        cout << "\t\t* Zone C Tickets: x" << zoneC_count << setfill(' ') << setw(9)<< "*" <<endl;
        cout << "\t\t=============================\n";
        cout << "\t\t| Purchased Seats: ";
        for (const auto& seat : sale.seats) {
        cout << seat << " " ;
        }
        cout << "|\n\n";
};