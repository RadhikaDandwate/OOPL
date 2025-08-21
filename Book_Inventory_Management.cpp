/* Book */
#include <iostream>
#include <cstring>
using namespace std;

int n = 0; // Number of books entered

class Book
{
public:
    char *title, *author, *publisher;
    int price, stock;

    // Constructor
    Book()
    {
        title = new char;
        author = new char;
        publisher = new char;
        price = 0;
        stock = 0;
        strcpy(title,"");
        strcpy(author,"");
        strcpy(publisher,"");
    }
    ~Book()
    {
    delete title;
    delete author;
    delete publisher;
    cout<<"\nDestructor is called";
        
    }
    

    // Accept book details
    void accept()
    {
        cout << "\nEnter Title: ";
        cin.ignore();
        cin.getline(title, 50);
        cout << "Enter Author: ";
        cin.getline(author, 50);
        cout << "Enter Publisher: ";
        cin.getline(publisher, 50);
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Stock Position: ";
        cin >> stock;
    }

    // Display book details
    void display()
    {
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nPublisher: " << publisher;
        cout << "\nPrice: " << price;
        cout << "\nStock Position (copies available): " << stock;
        cout << "\n";
    }

    // Search for a book
    int search(char t[], char a[])
    {
        return (strcmp(title, t) == 0 && strcmp(author, a) == 0);
    }
} b[100];

int main()
{
    int ch;
    do
    {
    
        cout << "\n\nBOOK MENU";
        cout << "\n1. Add Book";
        cout << "\n2. Display All Books";
        cout << "\n3. Search and Buy Book";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            b[n++].accept();
            break;

        case 2:
            for (int i = 0; i < n; i++)
                b[i].display();
            break;

        case 3:
        {
            char t[50], a[50];
            cout << "\nEnter Title of the book: ";
            cin.ignore();
            cin.getline(t, 50);
            cout << "Enter Author of the book: ";
            cin.getline(a, 50);

            int found = 0;
            for (int i = 0; i < n; i++)
            {
                if (b[i].search(t, a))
                {
                    found = 1;
                    cout << "\nBook Found!";
                    b[i].display();
                    int copies;
                    cout << "\nEnter number of copies required: ";
                    cin >> copies;
                    if (copies <= b[i].stock)
                    {
                        cout << "Total Cost = " << copies * b[i].price;
                        b[i].stock -= copies; // reduce stock after purchase
                    }
                    else
                        cout << "Required copies not in stock";
                    break;
                }
            }
            if (!found)
                cout << "Book not available";
        }
        break;

        case 4:
            cout << "\nExiting...";
            break;

        default:
            cout << "\nInvalid choice!";
        }

    } while (ch != 4);

    return 0;
}
