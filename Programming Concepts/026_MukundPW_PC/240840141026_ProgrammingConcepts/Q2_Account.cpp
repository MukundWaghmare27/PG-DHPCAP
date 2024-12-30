#include <iostream>
#include <string>
using namespace std;

// Account class to store account details
class Account {
public:
    int acid;         
    string name;       
    string address;   
    double balance;    

    Account(int a, string n, string ad, double b) {
        acid = a;
        name = n;
        address = ad;
        balance = b;
    }
};

int main() {
    Account* accounts[10];  
    int count = 0;          
    int choice;

    do {
        cout << "1. Add new account\n";
        cout << "2. Display all accounts\n";
        cout << "3. Search account by Account ID\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (count < 10) {
                    int acid;
                    string name, address;
                    double balance;
                    cout << "Enter Account ID: ";
                    cin >> acid;
                    cin.ignore();
                    cout << "Enter Name: ";
                    getline(cin, name);
                    cout << "Enter Address: ";
                    getline(cin, address);
                    cout << "Enter Balance: ";
                    cin >> balance;
                    accounts[count++] = new Account(acid, name, address, balance);  
                } else {
                    cout << "Account list is full.\n";
                }
                break;
            }

            case 2:
                if (count == 0) {
                    cout << "No accounts available.\n";
                } else {
                    for (int i = 0; i < count; i++) {
                        cout << "Account ID: " << accounts[i]->acid << "\n";
                        cout << "Name: " << accounts[i]->name << "\n";
                        cout << "Address: " << accounts[i]->address << "\n";
                        cout << "Balance: $" << accounts[i]->balance << "\n";
                        cout << "-----------------------------\n";
                    }
                }
                break;

            case 3: {
                int acid;
                cout << "Enter Account ID to search: ";
                cin >> acid;
                bool found = false;
                for (int i = 0; i < count; i++) {
                    if (accounts[i]->acid == acid) {
                        cout << "Account Found!\n";
                        cout << "Account ID: " << accounts[i]->acid << "\n";
                        cout << "Name: " << accounts[i]->name << "\n";
                        cout << "Address: " << accounts[i]->address << "\n";
                        cout << "Balance: $" << accounts[i]->balance << "\n";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account with ID " << acid << " not found.\n";
                }
                break;
            }

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice, please try again.\n";
        }

    } while (choice != 4);

    for (int i = 0; i < count; i++) {
        delete accounts[i];
    }

    return 0;
}
