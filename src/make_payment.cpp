#include <iostream>
#include <iomanip>
#include <string>
#include <thread>
#include <chrono>
#include <sstream>
#include <vector>
#include <limits>
#include <cstdlib>
#include <algorithm>


using namespace std;



void qr_code() {
    cout << R"(
##############      ##  ########    ####    ##############
##          ##  ##  ##    ########  ##      ##          ##
##  ######  ##          ####  ##    ####    ##  ######  ##
##  ######  ##  ######  ##  ####        ##  ##  ######  ##
##  ######  ##    ##          ####    ####  ##  ######  ##
##          ##  ####  ####              ##  ##          ##
##############  ##  ##  ##  ##  ##  ##  ##  ##############
                  ######    ##  ##    ####
##########  ########  ##        ##    ##  ##  ##  ##  ##  
##      ####  ####  ##  ########      ####  ##############
##      ##  ##  ##  ##    ############    ##  ##  ##      
      ######  ####      ####  ##    ##    ######  ##      
    ####    ####  ####  ##  ####                    ######
####  ####      ####          ##########  ##########    ##
      ##  ####  ####  ####                  ##    ##      
  ##  ##        ########    ##  ##  ######    ######      
##    ##  ####        ##        ##  ####            ####  
##    ##                ########  ########################
##  ####  ######  ##      ##########    ####        ##    
##  ##  ####        ##  ####  ##  ########    ##  ##  ##  
##    ####  ##          ##  ####      ##################  
                ####          ####  ##  ##      ####      
##############  ##  ######          ######  ##  ##        
##          ##    ######    ##  ##    ####      ##    ####
##  ######  ##  ########        ##  ##  ##########  ######
##  ######  ##  ####    ########  ##  ##
##  ######  ##  ######    ##########    ##  ######    ##
##          ##  ##      ####  ##  ####  ##    ######  ##
##############  ##      ##  ####      ##  ##        ##
)" << endl;
}



bool make_payment(double total){
    int payment_Option;
    
    cout << "\n\n"<<"@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@" << endl;
    cout << "@ Please choose your payment method @ " << endl;
    cout << "@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@\n" << endl;
    cout << "1. Credit Card" << endl;
    cout << "2. Debit Card" << endl;
    cout << "3. Cash" << endl;
    cout << "4. Touch n Go" << endl;
    cout << "Enter your choice (1-4):";
    cin >> payment_Option;

     
    
    string cardNumber;
    string expiryDate;
    string sec_code;

    double change;
    double payment;

   stringstream total_ss, payment_ss, change_ss;
   string total_str, payment_str, change_str;
  
   

   
   switch(payment_Option){
            case 1:
            system("cls");
            do{
            cout << "\n" <<"##################################\n";
            cout << "#                                #\n";
            cout << "#   1111 2222 3333 4444          #\n";
            cout << "#    CARD NUMBER                 #\n";
            cout << "#                                #\n";
            cout << "##################################\n";
            cout << "Please enter your credit card number (16digits):";
            cin >> cardNumber;
            if (cardNumber.length() != 16)
            {
                cout << "Invalid input! Credit card number should be 16 digits!" << endl;
            }
            }while(cardNumber.length() != 16);

            cout << "\n" <<"##################################\n";
            cout << "#                                #\n";
            cout << "#                                #\n";
            cout << "#                                #\n";
            cout << "#            Expiry Date  XX/XX  #\n";
            cout << "##################################\n";
            cout << "Please enter your expiry date:";
            cin >> expiryDate;
            
            cout << "\n" <<"##################################\n";
            cout << "#                                #\n";
            cout << "#                   =======      # BACK OF YOUR CARD\n" ;
            cout << "#    Security code  | 055 |      #\n";
            cout << "#                   =======      #\n";
            cout << "##################################\n";
            cout << "Please enter your security code:";
            cin >> sec_code;

            cout << "\nProcessing Credit Card Payment....." << endl;
            this_thread::sleep_for(chrono::seconds(1));
            cout << "\n............" << endl;
            this_thread::sleep_for(chrono::seconds(3));
            cout << "\nApproving the transaction....\n\n" << endl;
            this_thread::sleep_for(chrono::seconds(3));
            cout << "**************************************************************\n" << endl;
            cout << "Payment Successful! Thank you for your purchase! See you soon!\n\n" << endl;
            cout << "**************************************************************\n" << endl;
            cout << "\n\nPress Enter to continue...";
            
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
            cin.get();// Wait for Enter
            system("cls");
            return true;
            break;

            case 2:
            system("cls");
            do{
            cout << "\n" <<"##################################\n";
            cout << "#    NAME XXX                    #\n";
            cout << "#   1111 2222 3333 4444          #\n";
            cout << "#    CARD NUMBER                 #\n";
            cout << "#                                #\n";
            cout << "##################################\n";
            cout << "Please enter your debit card number (16digits):";
            cin >> cardNumber;
            if (cardNumber.length() != 16)
            {
                cout << "Invalid input! Debit card number should be 16 digits!" << endl;
            }
            }while(cardNumber.length() != 16);

            cout << "\n" <<"##################################\n";
            cout << "#                                #\n";
            cout << "#                                #\n";
            cout << "#                                #\n";
            cout << "#            Expiry Date  XX/XX  #\n";
            cout << "##################################\n";
            cout << "Please enter your expiry date:";
            cin >> expiryDate;
            
            cout << "\n" <<"##################################\n";
            cout << "#                                #\n";
            cout << "#                   =======      # BACK OF YOUR CARD\n" ;
            cout << "#    Security code  | 055 |      #\n";
            cout << "#                   =======      #\n";
            cout << "##################################\n";
            cout << "Please enter your security code:";
            cin >> sec_code;

            cout << "\nProcessing Debit Card Payment....." << endl;
            this_thread::sleep_for(chrono::seconds(1));
            cout << "\n............" << endl;
            this_thread::sleep_for(chrono::seconds(3));
            cout << "\nApproving the transaction....\n\n" << endl;
            this_thread::sleep_for(chrono::seconds(3));
            cout << "**************************************************************\n" << endl;
            cout << "Payment Successful! Thank you for your purchase! See you soon!\n\n" << endl;
            cout << "**************************************************************\n" << endl;
            cout << "\n\nPress Enter to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
            cin.get();// Wait for Enter
            system("cls");
            return true;
            break;

            case 3:
            do{
            system("cls");
            cout << "\nYou have chosen the Cash payment option." << endl;
            cout << "\nPlease ensure you have sufficient cash.\n" << endl;
            cout << "Enter the amount you are paying(RM): ";
            cin >> payment;
            if (payment < total)
            {
                cout << "\nInsufficient payment. The total is: RM" << total << endl;
                cout << "\nWould like to try again or quit? Enter 'q' to quit or any other key to try again: ";
                string response;
                cin >> response;
                if (response == "q")
                {
                return false;
                }
                

            }
            }while(payment < total);

            change = payment - total;

            
            total_ss << fixed << setprecision(2) << total;
            total_str = total_ss.str();

            payment_ss << fixed << setprecision(2) << payment;
            payment_str = payment_ss.str();

            
            change_ss << setprecision(2) << fixed << change;
            change_str = change_ss.str();

            cout << "Proceeding with the transaction.....\n";
            this_thread::sleep_for(chrono::seconds(1));
            cout << "\n............" << endl;
            this_thread::sleep_for(chrono::seconds(3));
            cout << "\nApproving the transaction....\n\n" << endl;
            this_thread::sleep_for(chrono::seconds(3));
            cout << "**************************************************************\n" << endl;
            cout << "Payment Successful! Thank you for your purchase! See you soon!\n\n" << endl;
            cout << "**************************************************************\n" << endl;

          


            cout << "\t*************************************" << endl;
            cout << "\t*               Receipt             *" << endl;
            cout << "\t*************************************" << endl;
            cout << "\t* Total amount due: RM" << total_str << setw(15 - total_str.length()) << setfill(' ') <<"*"<<endl;
            cout << "\t* Amount paid: RM" <<  payment_str << setw(20 - payment_str.length()) << setfill(' ') <<"*"<< endl;
            cout << "\t* Change: RM" <<  change_str << setw(25 - change_str.length()) << setfill(' ') <<"*"<< endl;
            cout << "\t=====================================" << endl;
            cout << "\t=    Thank you for your purchase!   =" << endl;
            cout << "\t=====================================\n\n" << endl;
            cout << "\n\nPress Enter to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
            cin.get();// Wait for Enter
            system("cls");
            return true;
            break;

            case 4:{

            qr_code();
            cout << "Scan the QR code to proceed with the payment." << endl;

            cout << "\n\nPress Enter to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
            cin.get();// Wait for Enter
            system("cls");
            return true;
            break;
            }

            default:
            if(cin.fail()) 
            {
            cin.clear(); //clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore the incorrect input
            cout << "Invalid input. Please enter a number." << "\n\n";
            }
            cout << "Please enter a number between 1 and 3.\n\n";
            return false;
            break;
    }


}