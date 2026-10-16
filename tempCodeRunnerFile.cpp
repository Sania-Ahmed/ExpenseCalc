#include <bits/stdc++.h>
using namespace std;

// Structure to hold expense details
struct Expense
{
    string date;
    string description;
    string category;
    double amount;
};

// Function to add an expense
void addExpense(vector<Expense> &expenses)
{
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
void displayExpenses(vector<Expense> &expenses)
{
    if (expenses.empty())
    {
        cout << "No expenses recorded yet!" << endl;
        return;
    }

    cout << "\n----- All Expenses -----\n";

    for (int i = 0; i < expenses.size(); i++)
    {
        cout << "\nExpense " << i + 1 << endl;
        cout << "Date: " << expenses[i].date << endl;
        cout << "Description: " << expenses[i].description << endl;
        cout << "Category: " << expenses[i].category << endl;
        cout << "Amount: " << expenses[i].amount << endl;
    }
}

void deleteExpense(vector<Expense> &expenses)
{
    if (expenses.empty())
    {
        cout << "No Expense To Delete!";
        return;
    }
    // replacing this with the displayExpenses function to avoid code duplication
    // cout << ("\n===== All Expenses =====\n");
    // for(int i=0; i<expenses.size(); i++){
    //     cout << i+1 <<"."
    //     <<expenses[i].description
    //     <<" | " << expenses[i].category
    //     <<" | " << expenses[i].amount
    //     <<" | " << expenses[i].date << endl;
    // }

    displayExpenses(expenses);
    int choice;
    cout << "\nEnter the number of the expense to delete: ";
    cin >> choice;

    if (choice < 1 || choice > expenses.size())
    {
        cout << "\nInvalid  Choice!" << endl;
        return;
    }
    cout << "Are you sure you want to delete: "
         << expenses[choice - 1].description
         << "? (Y/N): ";

    char confirm;
    cin >> confirm;
    if (confirm == 'Y' || confirm == 'y')
    {
        expenses.erase(expenses.begin() + (choice - 1));
        cout << "Expense deleted successfully!" << endl;
    }
    else
    {
        cout << "Deleteion cancelled!" << endl;
    }
}

void searchExpense(vector<Expense> &expenses)
{
    if (expenses.empty())
    {
        cout << "No expenses recorded yet!" << endl;
        return;
    }

    string searchTerm;
    cout << "Enter a search term (category): ";
    cin.ignore();
    getline(cin, searchTerm);

    bool found = false;
    cout << "\n----- Search Results -----\n";
    for (const auto &expense : expenses)
    {
        if (
            expense.category.find(searchTerm) != string::npos)
        {
            cout << "Date: " << expense.date << endl;
            cout << "Description: " << expense.description << endl;
            cout << "Category: " << expense.category << endl;
            cout << "Amount: " << expense.amount << endl;
            cout << "--------------------------\n";
            found = true;
        }
    }

    if (!found)
    {
        cout << "No matching expenses found!" << endl;
    }
}

void viewSummary(const vector<Expense> & expenses){
    if(expenses.empty()){
      cout << "No expense to summarize!"  << endl;
      return;
    }
    double total = 0;
    map <string, double> categoryTotals;

    for(const auto &expense: expenses){
        total += expense.amount;
        categoryTotals [expense.category] += expense.amount;
    }
    cout << "\n===== Spending Summary =====\n";
    cout << "Number of expenses: " << expenses.size() << endl;
    cout << "Total spending: " << total << endl;
 
    cout << "\n----- Spending by Category -----\n";

    for(const auto &item : categoryTotals){
        cout << item.first << ": " << item.second << endl;
    }
    auto highest = categoryTotals.begin();
    
    for(auto it = categoryTotals.begin(); it!= categoryTotals.end(); it++){
        if(it->second > highest->second){
            highest = it;
        }
    }
    cout << "\nHighest Spending Category: " << highest->first <<" (" << highest->second <<")\n";

}

int main()
{
    vector<Expense> expenses;
     
    expenses.push_back({"2026-10-12", "Lunch", "Food", 150});
    expenses.push_back({"2026-10-12", "Bus fare", "Transport", 50});
    expenses.push_back({"2026-10-12", "Groceries", "Food", 500});
    
    int choice;

    // Just to test the addExpense and displayExpenses functions!!
    do {
        cout << "\n===== Expense Tracker =====\n";
        cout << "1. Add Expense\n";
        cout << "2. Display Expenses\n";
        cout << "3. Search Expenses\n";
        cout << "4. Delete Expense\n";
        cout << "5. Get Summary\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addExpense(expenses);
                break;

            case 2:
                displayExpenses(expenses);
                break;

            case 3:
                searchExpense(expenses);
                break;

            case 4:
                deleteExpense(expenses);
                break;
            
            case 5:
                viewSummary(expenses);
                break;

            case 6:
                cout << "Exiting Expense Tracker..." << endl;
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

  

  
    return 0;
}
