#include "Admin.h"
#include<iostream>
using namespace std;

queue<pair<string, string>> SupportRespones;

//void Admin::FareManagement(Ride& ride) {
//
//    int stageNumber;
//    double newPrice;
//
//    cout << "Enter the stage number :" << endl;
//    cin >> stageNumber;
//
//    cout << "Enter the new fare:" << endl;
//    cin >> newPrice;
//    ride.UpdateStagePrice(stageNumber, newPrice);
//
//}

void Admin::StationManagement() {
    int choice;
    string stationName;

    cout << "Write The Station Name :" << endl;
    cin >> stationName;

    cout << "===============================" << endl;
    cout << "Choose :" << endl;
    cout << "===============================" << endl;
    cout << "1.Daily Income" << endl;
    cout << "2.Weekly Income" << endl;
    cout << "3.Monthly Income" << endl;
    cout << "4.Yearly Incom" << endl;
    cout << "===============================" << endl;
    cin >> choice;

    switch (choice) {

    case 1:
        metro->mapGraph[stationName].first.calculateDailyIncome();
        break;
    case 2:
        metro->mapGraph[stationName].first.calculateWeeklyIncome();
        break;

    case 3:
        metro->mapGraph[stationName].first.calculateMonthlyIncome();
        break;

    case 4:
        metro->mapGraph[stationName].first.calculateYearlyIncome();
        break;

    }
}
void Admin::write(ofstream* f)
{
  


      
        while (!SupportRespones.empty()) {
            (*f) << SupportRespones.front().first << "," << SupportRespones.front().second;
            SupportRespones.pop();
            (*f) << "\n";
        }
    


}
void Admin::read(ifstream* f) {
    string line;
    while (getline(*f, line)) {
        stringstream ss(line);
        string question, replay;
        getline(ss, question, ',');
        getline(ss, replay, ',');
       
      
        cout << question << " " << replay;
        SupportRespones.push(make_pair(question,replay));
    }

}

//void Admin::UserManagement() {
//
//    int choice;
//    bool exitMenu = false;
//
//    do {
//        cout << "-------------------- User Management Menu --------------------" << endl;
//        cout << endl;
//        cout << "1. View all users\n";
//        cout << "2. Edit a user\n";
//        cout << "3. Remove a user\n";
//        cout << "4. Back to main menu\n";
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        string username1;
//        string username2;
//
//        switch (choice) {
//        case 1:
//            User.viewUsers();
//            break;
//        case 2:
//            cout << "enter the username of the user you want to edit" << endl;
//            cin >> username1;
//            User.editUser(username1);
//            break;
//        case 3:
//            cout << "enter the username of the user you want to delete" << endl;
//            cin >> username2;
//            User.deleteAccount(username2);
//            break;
//        case 4:
//            exitMenu = true;
//            break;
//        default:
//            cout << "Invalid choice. Please try again." << endl;
//        }
//    } while (!exitMenu);
//}
void Admin::MetroManagement() {
    int choice;
    do {
        cout << "-------------------- Metro Management Menu --------------------" << endl;
        cout << "1. Add Metro Station" << endl;
        cout << "2. Edit Metro Station" << endl;
        cout << "3. Remove Metro Station" << endl;
        cout << "4. Back to Admin Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            int line;
            cout << "Enter the name of the metro station: ";
            cin >> name;
            cout << "Enter the line number it belongs to (1/2/3): ";
            cin >> line;
            bool line1 = false, line2 = false, line3 = false;
            if (line == 1) {
                line1 = true;
            }
            else if (line == 2) {
                line2 = true;
            }
            else if (line == 3) {
                line3 = true;
            }
            else {
                cout << "Invalid line number." << endl;
                break;
            }
            metro->addStation(name, line1, line2, line3);
            break;
        }
        case 2: {
            string name;
            int line;
            cout << "Enter the name of the metro station to edit: ";
            cin >> name;
            cout << "Enter the new line number for the station (1/2/3): ";
            cin >> line;
            bool line1 = false, line2 = false, line3 = false;
            if (line == 1) {
                line1 = true;
            }
            else if (line == 2) {
                line2 = true;
            }
            else if (line == 3) {
                line3 = true;
            }
            else {
                cout << "Invalid line number." << endl;
                break;
            }
            // metro.editStation(name, line1, line2, line3);
            break;
        }
        case 3: {
            string name;
            cout << "Enter the name of the metro station to remove: ";
            cin >> name;
            metro->deleteStation(name);
            break;
        }
        case 4:
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (true);
}

void Admin::CustomerServiceMenu(stack<string>Questions) {

    int choice;


    cout << "1. Display All Questions\n";
    cout << "2. Reply to the Questions\n";
    cin >> choice;

    switch (choice) {

    case 1:
        while (!Questions.empty()) {
            UserQuestions.push(Questions.top());
            Questions.pop();
        }
        while (!UserQuestions.empty()) {

            cout << UserQuestions.top() << endl;
            UserQuestions.pop();
        }
        break;

    case 2:
        GetQuestion(Questions);
        break;
    }

}
void Admin::GetQuestion(stack<string>Questions) {

    while (!Questions.empty()) {
        UserQuestions.push(Questions.top()); // push it into another stack
        Questions.pop();
    }

    string reply;

    while (!UserQuestions.empty()) {

        string question = UserQuestions.top();
        cout << question << endl;
        cin >> reply;
        SupportRespones.push(make_pair(question, reply)); // push it into queue
        UserQuestions.pop();

    }

    SendReplies();

}
queue<pair<string, string>> Admin::SendReplies() {

    return SupportRespones;

}


void Admin::handleBreakdown(int trainID, bool isBroken) {
    // Find the train with the given ID
    auto it = find_if(trains.begin(), trains.end(), [trainID](Train* train) {
        return train->trainID == trainID;
        });

    // If the train is found, set its breakdown status
    if (it != trains.end()) {
        (*it)->setBreakdown(isBroken);
    }
    else {
        cout << "Train with ID " << trainID << " not found." << endl;
    }
}
void Admin::addTrainToLine() {
    int trainID;
    cout << "Enter train ID: ";
    cin >> trainID;

    // Check if the train with the given ID already exists
    auto it = find_if(trains.begin(), trains.end(), [trainID](Train* train) {
        return train->trainID == trainID;
        });



    if (it != trains.end()) {
        cout << "Train with ID " << trainID << " already exists." << endl;
        return;
    }

    int line;
    cout << "Choose a line for the new train (1, 2, or 3): ";
    cin >> line;

    // Assuming you have a function to retrieve stations for a specific line from the Metro class
    vector<Station*> stations = metro->getStationsForLine(line);
    if (stations.empty()) {
        cout << "No stations found for line " << line << endl;
        return;
    }

    // Display available stations for the chosen line 
    //عشان اتأكد انها شغاله صح و ممكن نشيلها بعدين
    cout << "Available stations for line " << line << ":" << endl;
    for (Station* station : stations) {
        cout << station->getName() << endl;
    }

    int capacity;
    cout << "Enter capacity of the train: ";
    cin >> capacity;

    // Create a new train object with the provided info
    Train* newTrain = new Train(trainID, capacity, stations);
    trains.push_back(newTrain);
    cout << "Train with ID " << trainID << " added to Line " << line << "." << endl;
}

void Admin::TrainManagement() {
    int choice;
    do {
        cout << "-------------------- Train Management Menu --------------------" << endl;
        cout << "1. Add Train " << endl;
        cout << "2. Edit Train" << endl;
        cout << "3. Handle Break down " << endl;
        cout << "4. Back to Admin Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addTrainToLine();
            break;
        case 2: {
            int id;
            cout << "Enter the ID of the train you want to edit: ";
            cin >> id;

            // Find the train with the specified ID
            auto it = find_if(trains.begin(), trains.end(), [id](Train* train) {
                return train->trainID == id;
                });

            if (it != trains.end()) {
                // Train found, provide options to edit train attributes
                Train* trainToEdit = *it;
                int editChoice;
                cout << "What would you like to edit?" << endl;
                cout << "1. Capacity" << endl;
                cout << "Enter your choice: ";
                cin >> editChoice;

                switch (editChoice) {
                case 1: {
                    int newCapacity;
                    cout << "Enter the new capacity: ";
                    cin >> newCapacity;
                    trainToEdit->capacity = newCapacity;
                    cout << "Capacity updated successfully." << endl;
                    break;
                }

                default:
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
            else {
                cout << "Train with ID " << id << " not found." << endl;
            }
            break;
        }

        case 3: {
            int id;
            bool isBroken;
            cout << "Enter the ID of the train you want to set a breakdown: ";
            cin >> id;
            cout << "Enter 1 if the train is broken down, 0 otherwise: ";
            cin >> isBroken;
            handleBreakdown(id, isBroken);
            break;
        }
        case 4:
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (true);


}



