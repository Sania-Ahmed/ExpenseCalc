#include<bits/stdc++.h>
using namespace std;
struct Expense{
    string date;
    string description;
    string category;
    double amount;
};

void addExpense(vector<Expense> & expenses){
 Expense e;

    cout << "Enter Date: ";
    cin >> e.date;
    cin.ignore();

    cout << "Enter Description: ";
        getline(cin , e.description);
    
    cout << "Enter Category: ";
    getline(cin, e.category);

    cout << "Enter Amount: ";
    cin >> e.amount;

    expenses.push_back(e);

    cout <<  "Expense added successfully!" << endl;
}