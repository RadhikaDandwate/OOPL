#include <iostream>
using namespace std;

class Bank
{
public:
    int acc_number, balance;
    string acc_holder;

    void accept();        // To accept depositor details
    void display();       // To display depositor info
    void withdraw();      // To withdraw amount
    void check_balance(); // To check balance
    void search();        // To search a depositor
} B[100];

int n; // number of depositors

void Bank::accept()
{
    // to accept depositor details
    cout << "\nEnter Depositor Name : ";
    cin.ignore();
    getline(cin, acc_holder); // to accept full name

    cout << "Enter Account Number : ";
    cin >> acc_number;

    cout << "Enter Balance : ";
    cin >> balance;
}

void Bank::display()
{
    // to display all details
    cout << "\nDepositor Name :" << acc_holder;
    cout << "\nAccount Number :" << acc_number;
    cout << "\nCurrent Balance :" << balance;
}

void Bank::withdraw()
{
    int acc, amount;

    // to withdraw amount
    cout << "\nEnter Account Number for Withdrawal : ";
    cin >> acc;

    for (int i = 0; i < n; i++) // linear search
    {
        if (B[i].acc_number == acc)
        {
            cout << "Enter Amount to Withdraw : ";
            cin >> amount;

            if (B[i].balance >= amount)
            {
                B[i].balance -= amount;
                cout << "Withdrawal Successful. New Balance = " << B[i].balance;
            }
            else
            {
                cout << "Insufficient Balance!";
            }
            return;
        }
    }

    cout << "Depositor Not Found!";
}

void Bank::check_balance()
{
    int acc;

    // to check balance
    cout << "\nEnter Account Number to Check Balance : ";
    cin >> acc;

    for (int i = 0; i < n; i++) // linear search
    {
        if (B[i].acc_number == acc)
        {
            cout << "Current Balance = " << B[i].balance;
            return;
        }
    }

    cout << "Depositor Not Found!";
}

void Bank::search()
{
    int acc;

    // to search depositor
    cout << "\nEnter Account Number to Search : ";
    cin >> acc;

    for (int i = 0; i < n; i++) // linear search
    {
        if (B[i].acc_number == acc)
        {
            cout << "\nDepositor Found!";
            B[i].display();
            return;
        }
    }

    cout << "Depositor Not Found!";
}

int main()
{
    int choice;

    // to accept number of depositors
    cout << "Enter Number of Depositors : ";
    cin >> n;

    do
    {
        // menu driven program
        cout << "\n\nBank Menu";
        cout << "\n1. Accept Depositor Details";
        cout << "\n2. Display All Depositors";
        cout << "\n3. Withdraw Amount";
        cout << "\n4. Check Balance";
        cout << "\n5. Search Depositor";
        cout << "\n6. Exit";
        cout << "\nEnter Your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // to accept depositor details
            for (int i = 0; i < n; i++)
            {
                cout << "\nDepositor " << i+1 << ":\n";
                B[i].accept();
            }
            break;

        case 2:
            // to display depositor details
            for (int i = 0; i < n; i++)
            {
                B[i].display();
            }
            break;

        case 3:
            // to withdraw amount
            B[0].withdraw();
            break;

        case 4:
            // to check balance
            B[0].check_balance();
            break;

        case 5:
            // to search depositor
            B[0].search();
            break;

        case 6:
            // to exit program
            cout << "Exiting Program...";
            break;

        default:
            cout << "Invalid Choice!";
        }

    } while (choice != 6);

    return 0;
}
