
#include <bits/stdc++.h>
using namespace std;


// Structure to hold expense details
struct Expense {
    string date;
    string description;
    string category;
    double amount;
};


// Function to add an expense
void addExpense(vector<Expense> &expenses) {
    Expense e;

    cout << "Enter Date: ";
    cin >> e.date;
    cin.ignore();

    cout << "Enter Description: ";
    getline(cin, e.description);

    cout << "Enter Category: ";
    getline(cin, e.category);

    cout << "Enter Amount: ";
    cin >> e.amount;

    expenses.push_back(e);

    cout << "Expense added successfully!" << endl;
}


// Function to display all expenses
void displayExpenses(vector<Expense> &expenses) {
    if (expenses.empty()) {
        cout << "No expenses recorded yet!" << endl;
        return;
    }

    cout << "\n----- All Expenses -----\n";

    for (int i = 0; i < expenses.size(); i++) {
        cout << "\nExpense " << i + 1 << endl;
        cout << "Date: " << expenses[i].date << endl;
        cout << "Description: " << expenses[i].description << endl;
        cout << "Category: " << expenses[i].category << endl;
        cout << "Amount: " << expenses[i].amount << endl;
    }
}

int main() {
    vector<Expense> expenses;
    int choice;

    // Just to test the addExpense and displayExpenses functions!!
    // do {
    //     cout << "\n===== Expense Tracker =====\n";
    //     cout << "1. Add Expense\n";
    //     cout << "2. Display Expenses\n";
    //     cout << "3. Exit\n";
    //     cout << "Enter your choice: ";
    //     cin >> choice;

    //     switch (choice) {
    //         case 1:
    //             addExpense(expenses);
    //             break;

    //         case 2:
    //             displayExpenses(expenses);
    //             break;

    //         case 3:
    //             cout << "Exiting Expense Tracker..." << endl;
    //             break;

    //         default:
    //             cout << "Invalid choice! Try again.\n";
    //     }

    // } while (choice != 3);

    return 0;
}
