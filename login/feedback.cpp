#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <limits>
#include "feedback_struct.h"

using namespace std;

void printBoxedMessage(const string& message) {
    string border(message.length() + 4, '*'); // Create a string of asterisks for the top and bottom borders

    cout << endl << "\t\t" << border << endl;        // Top border
    cout << "\t\t" << "* " << message << " *" << endl;  // Message with side borders
    cout << "\t\t" << border << endl;        // Bottom border
}

void art(){
    cout << R"(
             .-"""-.
            /       \
            \       /
     .-"""-.-`.-.-.<  _
    /      _,-\ O_O-_/ ) 
    \     / ,  `   . `|
     '-..-| \-.,__~ ~ /        
           \ `-.__/  /         
          / `-.__.-\`-._    ,",
         / /|    ___\-._`-.;  , .----.  
        ( ( |.-"`   `'\ '-(     -.---' 
         \ \/    {}{}  |   \.__.-'
          \|           /     
           \        , /
           ( __`;-;'__`)
           `//'`   `||`
          _//       ||
  .-"-._,(__)     .(__).-""-.
 /          \    /           \
 \          /    \           /
  `'-------`      `--------'`
    )";     
    cout << "\n\n"; 
 
}

void submitFeedback(const string& userEmail, vector<Feedback>& feedbacks) {
    Feedback fb;
    fb.user_email = userEmail;
    cout << "Please enter your feedback: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear any leftover input
    getline(cin, fb.feedback);

    // Record current time
    fb.timestamp = time(nullptr);

    feedbacks.push_back(fb);
    printBoxedMessage("Thank you for your feedback!!!!!!");
    art();

    cout << "\nPress Enter to continue...";
    cin.get();
}

string censorEmail(const string& email) {
    size_t atPos = email.find('@');
    if (atPos == string::npos) {
        // '@' not found, return the original email
        return email;
    }

    // Keep the first character, replace the rest before '@' with asterisks
    string censoredEmail = email.substr(0, 1) + string(atPos - 1, '*');
    censoredEmail += email.substr(atPos); // Append the domain part

    return censoredEmail;
}

void displayFeedbacks(const vector<Feedback>& feedbacks) {
    for (const auto& fb : feedbacks) {
        string censoredEmail = censorEmail(fb.user_email);
        cout << "\t\tFeedback from " << censoredEmail << " at " << ctime(&fb.timestamp);
        cout << "\t\t" << "{"<< fb.feedback << "}"<< "\n\n";
    }
}



