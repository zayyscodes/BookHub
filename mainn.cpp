#include<iostream>
#include<chrono> // for pause function
#include<thread> // for pause function
#include<iomanip> // formatting
#include<string> //string functions
#include<cstring> //string functions
#include<cstdlib>
#include<fstream> // filing
#include<queue> // for queue procedures
#include<conio.h> // for password; window getch()
#include <windows.h> // to open website
#include <stdlib.h>
#include"book.h" // book class declared
#include"customer.h" // customer class declared
#include"inventory.h" //inventory declard
#include"node.h" // node for inventory declared
#include"word.h"
using namespace std;

void generateebill(customer& cust);
void generatebill(customer& cust, int billno);
void announcement();

const int num = 50;
const int n = 10;

int main() {
    int i = 23;
    int billno = 0;
    priority_queue<customer> customerQueue;
    i1.addbook(b1); i1.addbook(a1); i1.addbook(d1); i1.addbook(e1); i1.addbook(e0); i1.addbook(b2); i1.addbook(e9); i1.addbook(d9);
    i1.addbook(a2); i1.addbook(d2); i1.addbook(f2); i1.addbook(e2); i1.addbook(b3); i1.addbook(a3); i1.addbook(d3); i1.addbook(f3);
    i1.addbook(e3); i1.addbook(b4); i1.addbook(a4); i1.addbook(d4); i1.addbook(e4); i1.addbook(b5); i1.addbook(a5);
    i1.addbook(d5); i1.addbook(e5); i1.addbook(b6); i1.addbook(a6); i1.addbook(d6); i1.addbook(e6); i1.addbook(b7); i1.addbook(a7);
    i1.addbook(d7); i1.addbook(e7); i1.addbook(b8); i1.addbook(a8); i1.addbook(d8); i1.addbook(e8); i1.addbook(b9); i1.addbook(a9);

logIN:
    header();
    int login;
    cout << "\t\t\t\t\t\t L O G  I N" << endl;
    cout << "\t\t\t\t\t       1, As a customer\n\t\t\t\t\t        2, As Admin" << endl;
    cout << "\n\t\t\t\tEnter choice: ";
    cin >> login;
    if (login == 1) {
        customer cust;
    menu:
        header();
        getwod(words, i);
        announcement();
        cout << endl << endl << "\n\t\t\t\t\t\tM A I N   M E N U";
        cout << endl << "1, Order\n2, Search Book(s)\n3, Display Sorted\n4, View Cart\n5, Checkout\n6, Check Order Status\n7, Log Out";
        cout << endl << "Enter Choice: ";
        int choose;
        cin >> choose;
        switch (choose) {
        case 1: { //add book to order
        opt1:
            header();
            pause(1);
            i1.display();
            int ch;
            pause(2);
            cout << endl << endl << "Enter the 'Sno.' to add the book to the cart or review it. (Enter '0' to exit) ";
            cin >> ch;
            if (ch == 0)
                goto menu;
            else {
            choice:
                header();
                pause(1);
                i1.getbook(ch);
                char opt;
                if (ch >= 1 && ch <= num) {
                    char opt;
                    cout << "Add book to cart? (Y/N) ";
                    cin >> opt;
                    if (opt == 'Y' || opt == 'y') {
                        book* bookToAdd = i1.getbookfororder(ch);
                        cust.cart(bookToAdd);
                        pause(1);
                        goto opt1;
                    }
                    else if (opt == 'N' || opt == 'n')
                        goto opt1;
                    else {
                        cout << "Invalid Choice." << endl;
                        pause(1);
                        goto choice;
                    }
                }
                else {
                    {
                        cout << "Invalid book position entered." << endl;
                        pause(1);
                        goto opt1;
                    }
                }
            }
            break;
        }

        case 2: {
            header();
            pause(1);
            char c;
            int i = 0;
            char opt;
            string input, key;
            int ch;

        menutwo:
            header();
            cout << "\n\t\t\t\t\tS E A R C H" << endl;
            cout << "Search by: " << endl << "A, Book Name\nB, Author Name\nC, Genre\nE, Go to Main Menu" << endl;
            cin >> opt;

            if (opt == 'A' || opt == 'a') {
                header();
                cout << endl << "\n\t\t\t\t\tS E A R C H  B Y  N A M E" << endl;
                input = "name";
                cout << "Enter book name: ";
                cin.ignore();
                getline(cin, key);
                cout << endl;
                pause(2);
                Node* n = i1.binarySearch(key, input);
                if (n == NULL) {
                    i1.displaynode(n);
                    pause(1);
                    goto menutwo;
                }
                else {
                opt2a:
                    char o;
                    i1.displaynode(n);
                    cout << "Add book to cart? (Y/N) ";
                    cin >> o;
                    if (o == 'Y' || o == 'y') {
                        cust.cart(&(n->b));
                        pause(1);
                        goto menu;
                    }
                    else if (o == 'N' || o == 'n')
                        goto menutwo;
                    else {
                        cout << "Invalid Choice." << endl;
                        pause(1);
                        goto opt2a;
                    }
                    goto menu;
                }
            }
            else if (opt == 'B' || opt == 'b') {
                string author;
                header();
                cout << endl << "\n\t\t\t\t\tS E A R C H  B Y  A U T H O R" << endl;
                cout << "Enter Author's name: ";
                cin.ignore();
                getline(cin, author);

                i1.searchauthor(author, cust);
                goto menu;
            }
            else if (opt == 'C' || opt == 'c') { //display all book of certain genre
                string g;
                string genre;
            optg:
                header();
                cout << endl << "\n\t\t\t\t\tS E A R C H  B Y  G E N R E";
                cout << endl << "Genres:\nRM - Romance\nDR - Dark Romance\nDC - Dark Contemporary Romance\nNC - New Adult Contemporary Romance\nDK - Dark Rom-Com\nYF - Young Adult Fantasy\nYM - Young Adult Mystery\nCA - Coming of Age\nPT - Psychological Thriller\nMT - Mystery Thriller\nSH - Self Help" << endl;
                cout << "Enter genre choice: ";
                cin >> g;
                if (g == "RM" || g == "Rm" || g == "rm")
                    genre = "Romance";
                else if (g == "DR" || g == "Dr" || g == "dr")
                    genre = "Dark Romance";
                else if (g == "DC" || g == "Dc" || g == "dc")
                    genre = "Dark Contemporary Romance";
                else if (g == "DK" || g == "Dk" || g == "dk")
                    genre = "Dark Rom-Com";
                else if (g == "NC" || g == "Nc" || g == "nc")
                    genre = "NA Contemporary Romance";
                else if (g == "YF" || g == "Yf" || g == "yf")
                    genre = "YA Fantasy";
                else if (g == "YM" || g == "Ym" || g == "ym")
                    genre = "YA Mystery";
                else if (g == "CA" || g == "Ca" || g == "ca")
                    genre = "Coming of Age";
                else if (g == "PT" || g == "Pt" || g == "pt")
                    genre = "Psychological Thriller";
                else if (g == "MT" || g == "Mt" || g == "mt")
                    genre = "Mystery Thriller";
                else if (g == "SH" || g == "Sh" || g == "sh")
                    genre = "Self Help";
                else {
                    cout << "Invalid Choice, try again." << endl;
                    pause(1);
                    goto optg;
                }

                i1.searchgenre(genre, cust);
                goto menu;
            }
            else if (opt == 'E' || opt == 'e')
                goto menu;
            else {
                cout << "Invalid option, try again.";
                pause(1);
                goto menutwo;
            }
            break;
        }

        case 3: {
        menusort:
            header();
            int sort;
            cout << "\n\t\t\t\t\tS O R T  I N V E N T O R Y" << endl;
            cout << "Sort:\n1, Aphabetically\n2, By Author\n3, Genre\n4, From higher to lower prices\n5, From lower to higher prices\n\n(Enter 0 to exit) ";
            cin >> sort;
            if (sort == 0)
                goto menu;
            else if (sort == 1)
                i1.sortbyname();
            else if (sort == 2)
                i1.sortbyauthor();
            else if (sort == 3)
                i1.sortbygenre();
            else if (sort == 4)
                i1.sortbyprice(true);
            else if (sort == 5)
                i1.sortbyprice(false);
            else {
                cout << "Invalid option, try again.";
                pause(1);
                goto menusort;
            }
        choice3:
            i1.display();
            int ch;
            pause(2);
            cout << endl << endl << "Enter the 'Sno.' to add the book to the cart or review it. (Enter '0' to exit) ";
            cin >> ch;
            if (ch == 0)
                goto menu;
            else {
                header();
                pause(1);
                i1.getbook(ch);
                char o;
            opt3:
                cout << "Add book to cart? (Y/N) ";
                cin >> o;
                if (o == 'Y' || o == 'y') {
                    book* bookToAdd = i1.getbookfororder(ch);
                    if (bookToAdd) {
                        cust.cart(bookToAdd);
                        pause(1);
                        goto menu;
                    }
                    else {
                        cout << endl << "Invalid book selection." << endl;
                        // Handle invalid book selection case
                    }
                }
                else if (o == 'N' || o == 'n')
                    goto choice3;
                else {
                    cout << "Invalid Choice." << endl;
                    pause(1);
                    goto opt3;
                }
            }
            break;
        }

        case 4: {
            header();
            if (cust.booksInCart == 0) {
                cout << "Cart is empty." << endl;
                pause(1);
            }
            else {
                cout << "\n\t\t\t\t\t** D I S P L A Y I N G   C A R T **" << endl << endl;
                cust.displayOrder();
                cout << endl;
                system("pause");
            }
            goto menu;
            break;
        }

        case 5: {
        info:
            header();
            if (cust.booksInCart == 0) {
                cout << "Cart is empty. Add books to cart to check out." << endl;
                pause(2);
                goto menu;
            }
            else {
                cust.setinfo();
                char yn;
            opt5:
                cout << endl << endl << "Are you sure the entered information is correct? (Y/N) ";
                cin >> yn;
                if (yn == 'Y' || yn == 'y') {
                    cout << "Great! Proceeding to checkout." << endl;
                    customerQueue.push(cust);
                    cust.updatestatus();
                    pause(1);
                    cout << "Order has been added to queue." << endl << "Returning to main menu...";
                    pause(1);
                    goto menu;
                }
                else if (yn == 'N' || yn == 'n') {
                    cust.edit();
                    goto opt5;
                }
                else {
                    cout << "Invalid option, try again.";
                    goto opt5;
                }
                break;
            }
        }
        case 6: {
            header();
            if (cust.level == 0) {
                cout << endl << cust.status;
                cout << "First check out in order to track order." << endl;
            }
            else {
                string id;
                cout << "\n\t\t\t\t\tT R A C K  O R D E R" << endl;
                fflush(stdin);
                cout << "Enter your customer/order ID (Enter E to exit): ";
                cin.ignore();
                getline(cin, id);
                if (id == "E" || id == "e") {
                    cout << endl << endl << "Returning to main menu...";
                    pause(1);
                    goto menu;
                }
                priority_queue<customer> copyQueue = customerQueue;
                bool found = false;
                while (!copyQueue.empty()) {
                    customer curr = copyQueue.top();
                    // Perform your search operations here
                    if (curr.id == id) {
                        found = true;
                        curr.display();
                        header();
                        cout << "Status of order: " << curr.status << endl;
                        char peek;
                    opt6:
                        cout << "Do you want to view your cart? (Y/N) " << endl;
                        cin >> peek;
                        if (peek == 'y' || peek == 'Y') {
                            cout << "\n\t\t\t\t\t** D I S P L A Y I N G   C A R T **" << endl << endl;
                            curr.displayOrder();
                            cout << endl;
                            system("pause");
                            cout << endl << endl << "Returning to main menu...";
                            pause(1);
                            goto menu;
                        }
                        else if (peek == 'n' || peek == 'N') {
                            cout << endl << endl << "Returning to main menu...";
                            pause(1);
                            goto menu;
                        }
                        else {
                            cout << "Invalid Option, try again." << endl;
                            goto opt6;
                        }
                    }
                    if (found)
                        break;
                    else
                        copyQueue.pop();
                }
            }
            pause(1);
            goto menu;
            break;
        }
        case 7: {
        logout:
            header();
            cout << "Are you sure you want to log out? Your cart will be emptied. (Y/N) ";
            char log;
            cin >> log;
            if (log == 'y' || log == 'Y') {
                cout << endl << "\n\n\t\t\t\t\t**L O G G I N G   O F F**";
                pause(2);
                goto logIN;
            }
            else if (log == 'n' || log == 'N') {
                goto menu;
            }
            else {
                cout << "Invalid option, try again." << endl;
                pause(2);
                goto logout;
            }
            break;
        }

        default:

            break;
        } //end switch
    } // end user-based program
    else if (login == 2) {
    loginpw:
        header();
        string username;
        char password[50];
        const char correctpw[] = "dsproject";
        bool user;
        bool access = false;
        cout << "\n\t\t\t\tENTER USER NAME:\n\t\t\t\t";
        cin >> username;

        cout << "\n\t\t\t\tENTER PASSWORD:\n\t\t\t\t";
        int i = 0;
        char ch;
        while ((ch = _getch()) != '\r' && i < 49) { // Read characters until Enter (Enter has ASCII value of 13)
            if (ch == '\b' && i > 0) { // Check for Backspace (ASCII value of 8)
                cout << "\b \b"; // Move cursor back, erase last character, move cursor back again
                i--;
            }
            else if (ch != '\b') {
                password[i++] = ch;
                cout << '*'; // Display * for each character
            }
        }
        password[i] = '\0'; // Null-terminate the password string

        if ((username == "ZahabJay" || username == "Zayys") && (std::strcmp(password, correctpw) == 0)) {
            if (username == "ZahabJay")
                user = true;
            else if (username == "Zayys")
                user = false;
            access = true;
        }
        else {
            cout << "\n\t\t\t\tIncorrect Username or Password." << endl;
            pause(2);
            goto logIN;
        }

        if (access) {
            cout << "\n\t\t\t\tAccess granted!" << endl;
            if (user)
                cout << "\n\t\t\t  Welcome back, Zahab!" << endl;
            else if (!user)
                cout << "\n\t\t\t  Welcome back, Zehra!" << endl;
        }
    }

}//end main program

void generatebill(customer& cust, int billno) {
    ofstream MyFile("Bill.txt");
    MyFile << "\n\t\t\t\t\t\t       THE BOOK HUB" << endl;
    MyFile << "\t\t\t\t\t\t --Online Order Receipt--" << endl;
    MyFile << "Receipt Number: " << setw(4) << setfill('0') << billno << endl;
    MyFile << "Name: " << cust.name << endl << "Address: " << cust.address << endl << "Phone Number: " << cust.phno << endl;
    MyFile << "Channel: Online" << endl;

    MyFile << endl << "-----------------------------------------" << endl;
}

void announcement() {
    string arr[] = { "Due to fluctuation in exchange rates, the prices of the books might variate.", "\t\t\t\t\t NEW YEAR EVE Sale coming soon!", "Additional 10% discount on payment by card!"};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    srand(static_cast<unsigned int>(time(0)));
    int x = generateRandomNumber(0, arrSize - 1); // Adjust the range to prevent potential out-of-bounds access
    cout << endl << "\n\t\t\t\t\t   A N N O U N C E M E N T S" << endl;
    cout << arr[x];
}
