#include "user.h"
#include <iostream>
#include <list>
#include<string>

#include<regex>
using namespace std;


stack<string>questionStack;

user::user(string new_user_name, string new_user_email, string new_user_password, int point,int trips, double money, string type, string start, string end, int stages) {
    username = new_user_name;
    email = new_user_email;
    password = new_user_password;
    subscription =   Subscription(trips,money,type,start,end,stages);
    myReward->points = point;
}
void user:: writeUsers(user* write,ofstream* f)
{
   

        (*f) << write->toString() << "\n"; //writing the user data
        (*f) << write->subscription.toString() << "\n"; //writing the subscription data
        for (auto its = write->user_rides.begin(); its != write->user_rides.end(); its++) {
            (*f) << its->toString() << "\n"; //writing the rides data
        }

        (*f) <<'&' << "\n";
        while (!questionStack.empty()) {
            (*f) << questionStack.top()<<"\n";
            questionStack.pop();
        }
       
        (*f) << ';' << "\n";
    

}
string user::suggestRide()
{
    int max = 0;
    string stations;
    for (auto it = frequent_rides.begin(); it != frequent_rides.end(); it++) {
        if (it->second >= 3 && it->second > max) {
            max = it->second;
            stations = it->first;
        }
   }
    if (!max)
        return "false";
    else {
        
        return stations;
    }
}


void user::display_ride_history() {
    cout << "Stored Rides:" << endl;

    if (user_rides.empty()) {
        cout << "No ride history to show." << endl;
    }
    else {
        list<Ride>::reverse_iterator it;
        it = user_rides.rbegin();
        while (it != user_rides.rend()) {
            it->display();
            it++;
        }
    }
}
     user::user()
{
    username = "";
    email = "";
    password = "";
}

 user::user(string user_name, string user_email, string user_password)
 {
     username = user_name;
     email = user_email;
     password = user_password;
 }


 bool user:: is_valid_email(string Email) {
     if (Email.find('@') != string::npos) {
         //until the end of the string.
         size_t pos = Email.find('@');
         string beforePart = Email.substr(0, pos);
         string afterPart = Email.substr(pos + 1);

         if (!beforePart.empty() && regex_match(beforePart, std::regex(".*[a-zA-Z].*")) && afterPart == "gmail.com") {
             return true;
         }
     }
     return false;
 }

 bool user:: is_valid_password(string Password) {
     return Password.length() >= 8;
 }

 


void user::changeUsername()
{
    bool is_exist;
    string newUsername;

   
        cout << "Enter your new username please: " << endl;
        cin >> newUsername;

        if (newUsername == username) {
            cout << "The new username is the same as your current one." << endl;
            return; // Exit the function without making any changes
        }
      
    

    username = newUsername; // Update the username if it's different
    cout << "Username changed successfully!" << endl;
}

void user::changePassword()
{
    string newPassword;

    do {
        cout << "Please enter your new password: " << endl;
        cin >> newPassword;

        if (newPassword == password) {
            cout << "The new password is the same as your current one." << endl;
            return; // Exit the function without making any changes
        }

        if (!is_valid_password(newPassword)) {
            cout << "Password isn't valid, please enter a valid password (at least 8 characters)" << endl;
        }
    } while (!is_valid_password(newPassword));

    password = newPassword; // Update the password if it's different
    cout << "Password changed successfully!" << endl;
}

void user::changeEmail()
{
    bool is_exist;
    string newEmail;

  
        cout << "Enter your new email please: " << endl;
        cin >> newEmail;

        if (newEmail == email) {
            cout << "The new email is the same as your current one." << endl;
            return; // Exit the function without making any changes
        }

       
   

    email = newEmail; // Update the email if it's different
    cout << "Email changed successfully!" << endl;
}

string user::get_email() {
    return email;
}

string user::toString()
{
    return username + "," + email + "," + password+","+to_string(myReward->getPoints());
}

string user::get_username() {
    return username;
}

string user::get_password() {
    return password;
}

//void user::deleteAccount(string username) {
//    bool foundAcc = false;
//    for (auto it = users.begin(); it != users.end(); it++) {
//        if (it->get_username() == username) {
//            foundAcc = true;
//            break;
//        }
//    }
//    if (!foundAcc) {
//        cout << "Account not found " << endl;
//        return;
//    }
//
//    char choice;
//    cout << "Are you sure you want to delete the account with the username " << username << "? (Y/N): ";
//    cin >> choice;
//
//    if (toupper(choice) == 'Y') {
//        for (auto it = users.begin(); it != users.end(); it++) {
//            if (it->get_username() == username) {
//                it = users.erase(it);
//                cout << "Account deleted successfully!" << endl;
//                return;
//            }
//        }
//    }
//    else {
//        cout << "cancelled." << endl;
//    }
//}
//void user::viewUsers() {
//    if (users.empty()) {
//        cout << "No users found" << endl;
//        return;
//    }
//
//    cout << "List of all users:" << endl;
//    for (auto u : users) {
//        cout << "Username: " << u.get_username() << ", Email: " << u.get_email() << endl;
//    }
//}
//void user::editUser(string& Username) {
//    bool found = false;
//    for (auto it = users.begin(); it != users.end(); it++) {
//        if (it->get_username() == Username) {
//            found = true;
//            int editChoice;
//            cout << "What information do you want to edit for user " << Username << "?" << endl;
//            cout << "1. Username" << endl;
//            cout << "2. Email" << endl;
//            cout << "3. Password" << endl;
//            cout << "4. Cancel" << endl;
//            cout << "Enter your choice: ";
//            cin >> editChoice;
//
//            switch (editChoice) {
//            case 1: {
//                it->changeUsername();
//                cout << "Username updated successfully!" << endl;
//                break;
//            }
//            case 2: {
//                it->changeEmail();
//                cout << "Email updated successfully!" << endl;
//                break;
//            }
//            case 3: {
//                it->changePassword();
//                cout << "Password updated successfully!" << endl;
//                break;
//            }
//            case 4:
//                cout << "Editing cancelled." << endl;
//                break;
//            default:
//                cout << "Invalid choice." << endl;
//            }
//            break;
//        }
//    }
//    if (!found) {
//        cout << "User with username " << Username << " not found." << endl;
//    }
//}
void user::sendQuestion(string question) {
    questionStack.push(question);
    cout << "Question sent: " << question << endl;
}
void user::getReply(queue<pair<string, string>>* replies) {
    if (questionStack.empty() || replies->empty()) {
        cout << "No replies available" << endl;
        return;
    }
    while (!replies->empty()) {
        cout << "Question: " << replies->front().first << endl;
        cout << "Reply: " << replies->front().second << endl;
        replies->pop();
    }
}
void user::customerService(queue<pair<string, string>>* replies) {
    int choice;
    do {
        cout << "Customer service" << endl;
        cout << "1. Send a question" << endl;
        cout << "2. Get a reply" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        string question;
        switch (choice) {
        case 1:
            cout << "Enter your question: ";
            cin.ignore();
            getline(cin, question);
            sendQuestion(question);
            break;
        case 2:
            getReply(replies);
            break;
        case 3:
            cout << "Exiting Customer service" << endl;
            break;
        default:
            cout << "Invalid choice " << endl;
            break;
        }
    } while (choice != 3);
}