#include <iostream>
#include <iomanip>
#include <string>
#include <thread>
#include <chrono>
#include <sstream>
#include <vector>
#include <windows.h>

using namespace std;


void display_menu(char heart){
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout << setfill(' ') <<setw(70) << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
        cout << setw(70) << "*- Cool Play Concert Ticket Ordering System-*" << endl;
        cout << setw(70) << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << setw(42) << "1. Order Tickets\n";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << setw(47) << "2. View Total Payment\n";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN |FOREGROUND_INTENSITY);
        cout << setw(41) << "3. Make Payment\n";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_INTENSITY);
        cout << setw(44) << "4. Generate Ticket\n";
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN |FOREGROUND_INTENSITY);
        cout << setw(43) << "5. Refund Ticket \n";
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        cout << setw(35) << "6. Admin \n";
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED );
        cout << setw(33) << "7. Exit\n";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        cout << setw(37) << "8. Feedback\n";
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN |FOREGROUND_INTENSITY);
        cout << "\n" <<setw(86) << setfill(heart) << heart << "\n\n";

}


void display_coolPlay_logo(){
cout << R"(      ::::::::   ::::::::   ::::::::  :::           :::::::::  :::            :::   :::   ::: 
    :+:    :+: :+:    :+: :+:    :+: :+:           :+:    :+: :+:          :+: :+: :+:   :+:  
   +:+        +:+    +:+ +:+    +:+ +:+           +:+    +:+ +:+         +:+   +:+ +:+ +:+    
  +#+        +#+    +:+ +#+    +:+ +#+           +#++:++#+  +#+        +#++:++#++: +#++:      
 +#+        +#+    +#+ +#+    +#+ +#+           +#+        +#+        +#+     +#+  +#+        
#+#    #+# #+#    #+# #+#    #+# #+#           #+#        #+#        #+#     #+#  #+#         
########   ########   ########  ##########    ###        ########## ###     ###  ###
          
      ::::::::   ::::::::  ::::    :::  ::::::::  :::::::::: ::::::::: :::::::::::            
    :+:    :+: :+:    :+: :+:+:   :+: :+:    :+: :+:        :+:    :+:    :+:                 
   +:+        +:+    +:+ :+:+:+  +:+ +:+        +:+        +:+    +:+    +:+                  
  +#+        +#+    +:+ +#+ +:+ +#+ +#+        +#++:++#   +#++:++#:     +#+                   
 +#+        +#+    +#+ +#+  +#+#+# +#+        +#+        +#+    +#+    +#+                    
#+#    #+# #+#    #+# #+#   #+#+# #+#    #+# #+#        #+#    #+#    #+#                     
########   ########  ###    ####  ########  ########## ###    ###    ###)";

cout << endl;
}


void display_logo_batman_night(){
        cout << R"(
          .  .
          |\_|\
          | a_a\
          | | "]
      ____| '-\___
     /.----.___.-'\
    //        _    \
   //   .-. (~v~) /|
  |'|  /\:  .--  / \
 // |-/  \_/____/\/~|
|/  \ |  []_|_|_] \ |
| \  | \ |___   _\ ]_}
| |  '-' /   '.'  |
| |     /    /|:  | 
| |     |   / |:  /\
| |     /  /  |  /  \
| |    |  /  /  |    \
\ |    |/\/  |/|/\    \
 \|\ |\|  |  | / /\/\__\
  \ \| | /   | |__
       / |   |____)
       |_/)";

}

void clearScreen() {
    // Clear the screen
    #if defined _WIN32
        system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
    #endif
}
