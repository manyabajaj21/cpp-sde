#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

void registerUser() {
    string name, password0, age;

    cout << "Please enter Username: ";
    cin >> name;
    cout << "Please enter password: ";
    cin >> password0;
    cout << "Please enter your age: ";
    cin >> age;

    ofstream of1("file.txt");
    if (of1.is_open()) {
        of1 << name << "\n" << password0 << "\n";
        of1.close();
        cout << "Registration Successful" << endl;
    } else {
        cout << "Error opening file for writing" << endl;
    }
}

void loginUser() {
    string name, pass, fileName = "file.txt";
    string storedName, storedPass;

    cout << "Please enter Username: ";
    cin >> name;
    cout << "Please enter password: ";
    cin >> pass;

    ifstream of2(fileName);
    if (of2.is_open()) {
        getline(of2, storedName);
        getline(of2, storedPass);
        of2.close();

        if (name == storedName && pass == storedPass) {
            cout << "---Login Successful---" << endl;
            cout << "Details: " << endl;
            cout << "Username: " << name << endl;
            cout << "Password: " << pass << endl;
        } else {
            cout << "Incorrect Credentials" << endl;
        }
    } else {
        cout << "Error opening file for reading" << endl;
    }
}

void changePassword() {
    string oldPassword, newPassword1, newPassword2;
    string storedName, storedPass, fileName = "file.txt";

    cout << "Enter old password: ";
    cin >> oldPassword;

    ifstream of0(fileName);
    if (of0.is_open()) {
        getline(of0, storedName);
        getline(of0, storedPass);
        of0.close();

        if (oldPassword == storedPass) {
            cout << "Enter your new password: ";
            cin >> newPassword1;
            cout << "Enter your new password again: ";
            cin >> newPassword2;

            if (newPassword1 == newPassword2) {
                ofstream of1(fileName);
                if (of1.is_open()) {
                    of1 << storedName << "\n" << newPassword1 << "\n";
                    of1.close();
                    cout << "Password changed successfully" << endl;
                } else {
                    cout << "Error opening file for writing" << endl;
                }
            } else {
                cout << "Passwords do not match" << endl;
            }
        } else {
            cout << "Invalid old password" << endl;
        }
    } else {
        cout << "Error opening file for reading" << endl;
    }
}

int main() {
    int choice;
    cout << "      Security System                " << endl;
    cout << "_____________________________________" << endl << endl;
    cout << "                1.Register           " << endl;
    cout << "                2.Login              " << endl;
    cout << "                3.Change Password    " << endl;
    cout << "________________4.End Program________" << endl;

    do {
        cout << endl << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                changePassword();
                break;
            case 4:
                cout << "____________Thank You!________________" << endl;
                break;
            default:
                cout << "Enter a valid choice" << endl;
        }
    } while (choice != 4);

    return 0;
}
