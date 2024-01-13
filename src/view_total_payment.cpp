#include <iostream>
#include <iomanip>
#include <string>
#include <thread>
#include <chrono>
#include <sstream>
#include <vector>


using namespace std;




void view_total_payment(char heart, double total, int& ticket_count){

cout << "\n\t\t" << setw(40) << setfill(heart) << heart ;
cout << "\n\n\n\t\tTotal payment: RM" << setprecision(2) << fixed << total << endl;
cout << "\t\tTicket Quantity: " << ticket_count << endl;
cout << "\n";
cout << "\t\t" <<setw(40) << setfill(heart) << heart << "\n\n\n";

}