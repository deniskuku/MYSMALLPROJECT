#include <iostream>
#include <iomanip>
#include <string>
#include <regex>
#include <thread>
#include <chrono>
#include <sstream>
#include <vector>

using namespace std;

// Function to check if the provided email is valid
bool isValidEmail(const string& email)
{
    // Regular expression pattern for validating an email
    // The pattern checks for a word character followed by an optional dot or underscore,
    // followed by optional word characters, an @ symbol, and a domain from a predefined list
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(gmail|hotmail|yahoo)\\.(com)");

    // Use regex_match to check if the email matches the pattern
    return regex_match(email, pattern);
}

// Function to check if the provided password is valid
bool isValidPassword(const string& password)
{
    // Check if the password length is less than 7 characters
    if(password.length() < 7)
    { 
        system("cls"); // Clear the console screen
        cout << "\t\t\tPassword at least 7 words." << endl;
        return false; // Return false if the password is too short
    }

    // Flags to track the presence of a capital letter and a symbol
    bool hasCapital = false, hasSymbol = false;

    // Iterate over each character in the password
    for (char c : password)
    {
        if(isupper(c)) hasCapital = true; // Check for uppercase character
        if(ispunct(c)) hasSymbol = true;  // Check for punctuation/symbol
    }
    
    // Return true if the password contains both a capital letter and a symbol
    return hasCapital && hasSymbol;
}


void graphic(){
    cout << R"(                        
                  .-----.                         
                .' -   - '.
               /  .-. .-.  \
               |  | | | |  |
                \ \o/ \o/ /
               _/    ^    \_                WELCOME!
              | \  '---'  / |
              / /`--. .--`\ \              LOGIN PAGE
             / /'---` `---'\ \
             '.__.       .__.'
                 `|     |`
                  |     \
                   \      '--.
                    '.        `\
                      `'---.   |
                            ) /
                            \/)";
 cout << "\n\n";

}


string login(){
    string email, password;

    while (true)
    {   
        graphic();
        cout << "\t\t\tEmail (gmail/hotmail/yahoo): ";
        cin >> email;
        cout << "\t\t\tPassword (At least 1 Capital, 1 symbol and 7 words): ";
        cin >> password;

        if (!isValidEmail(email))
        {
            system("cls");
            cout << "\t\t\tInvalid email format. Please try again." << "\n\n";

            continue;
        }

         if(!isValidPassword(password)) {
            system("cls");
            cout << "\t\t\tInvalid password format. Please try again.";

            continue;
        }
        break;
    }
    system("cls");
    cout << "\n\nLogin successful.\n\n";
    this_thread::sleep_for(chrono::seconds(3/4));
    cout << "loading..........." << endl;
    this_thread::sleep_for(chrono::seconds(1));
    system("cls");
    return email;
}


