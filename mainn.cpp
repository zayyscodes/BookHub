#include<iostream>
#include<chrono> // for pause function
#include<thread> // for pause function
#include<iomanip> // formatting
#include<string> //string functions
#include<cstring> //string functions
#include<cstdlib>
#include<fstream> // filing
#include<queue> // for queue procedures
#include <windows.h> // to open website
#include <stdlib.h>
#include"book.h" // book class declared
#include"customer.h" // customer class declared
#include"inventory.h" //inventory declard
#include"node.h" // node for inventory declared
using namespace std;

const int num = 50;
const int n = 10;

int main() {
    int i = 0;
    queue<customer> customersQueue;
    i1.addbook(b1); i1.addbook(a1); i1.addbook(d1); i1.addbook(e1); i1.addbook(e0); i1.addbook(b2); i1.addbook(e9); i1.addbook(d9);
    i1.addbook(a2); i1.addbook(d2); i1.addbook(f2); i1.addbook(e2); i1.addbook(b3); i1.addbook(a3); i1.addbook(d3); i1.addbook(f3);
    i1.addbook(e3); i1.addbook(b4); i1.addbook(a4); i1.addbook(d4); i1.addbook(e4); i1.addbook(b5); i1.addbook(a5);
    i1.addbook(d5); i1.addbook(e5); i1.addbook(b6); i1.addbook(a6); i1.addbook(d6); i1.addbook(e6); i1.addbook(b7); i1.addbook(a7);
    i1.addbook(d7); i1.addbook(e7); i1.addbook(b8); i1.addbook(a8); i1.addbook(d8); i1.addbook(e8); i1.addbook(b9); i1.addbook(a9);

    logIN:
    system("CLS");
    int login;
    cout << "\t\t\t\tLogin as:" << endl;
    cout << "\t\t\t1, As a customer\n\t\t\t2, As Admin" << endl;
    cout << "\n\t\t\t\tEnter choice: ";
    cin >> login;
    if (login == 1) {
    menu:
        system("CLS");
        customer cust;
        cout << endl << endl << "MAIN MENU: ";
        cout << endl << "1, Order\n2, Search Book(s)\n3, Display Sorted\n4, Checkout\n5, Log Out";
        cout << endl << "Enter Choice: ";
        int choose;
        cin >> choose;
        switch (choose) {
        case 1: { //add book to order
            system("CLS");
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
                system("CLS");
                pause(1);
                i1.getbook(ch);
                char opt;
                if (ch >= 1 && ch <= num) {
                    char opt;
                opt1:
                    cout << endl << "Add book to cart? (Y/N) ";
                    cin >> opt;
                    if (opt == 'Y' || opt == 'y') {
                        book* bookToAdd = i1.getbookfororder(ch);
                        //cust.cart(bookToAdd);
                        pause(1);
                        goto menu;
                    }
                    else if (opt == 'N' || opt == 'n')
                        goto choice;
                    else {
                        cout << "Invalid Choice." << endl;
                        pause(1);
                        goto opt1;
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
            system("CLS");
            pause(1);
            char c;
            int i = 0;
            char opt;
            string input, key;
            int ch;
            // Initialize 'i1' and 'cust' objects if needed

        menutwo:
            system("CLS");
            cout << "\t\t\tS E A R C H" << endl;
            cout << "Search by: " << endl << "A, Book Name\nB, Author Name\nC, Genre\nE, Go to Main Menu" << endl;
            cin >> opt;

            if (opt == 'A' || opt == 'a') {
                system("CLS");
                cout << endl << "\t\t\tS E A R C H  B Y  N A M E" << endl;
                input = "name";
                cout << "Enter book name: ";
                cin.ignore();
                getline(cin, key);
                cout << endl;
                pause(2);
                i1.displaynode(i1.binarySearch(key, input));
            opt2a:
                char o;
                cout << endl << "Add book to cart? (Y/N) ";
                cin >> o;
                if (o == 'Y' || o == 'y')
                    ; //cust.cart();
                else if (o == 'N' || o == 'n')
                    goto menutwo;
                else {
                    cout << "Invalid Choice." << endl;
                    pause(1);
                    goto opt2a;
                }
                goto menu;
            }
            else if (opt == 'B' || opt == 'b') {
                string author;
                system("CLS");
                cout << endl << "\t\t\tS E A R C H  B Y  A U T H O R" << endl;
                cout << "Enter Author's name: ";
                cin.ignore();
                getline(cin, author);

                i1.searchauthor(author, cust);
            opt2b:
                char o;
                cout << endl << "Add book to cart? (Y/N) ";
                cin >> o;
                if (o == 'Y' || o == 'y')
                    ; //cust.cart();
                else if (o == 'N' || o == 'n')
                    goto menutwo;
                else {
                    cout << "Invalid Choice." << endl;
                    pause(1);
                    goto opt2b;
                }
                goto menu;
            }
            else if (opt == 'C' || opt == 'c') { //display all book of certain genre
                string g;
                string genre;
            optg:
                system("CLS");
                cout << endl << "\t\t\tS E A R C H  B Y  G E N R E";
                cout << endl << "Genres:\nRM - Romance\nDR - Dark Romance\nDC - Dark Contemporary Romance\nNC - New Adult Contemporary Romance\nDK - Dark Rom-Com\nYF - Young Adult Fantasy\nYM - Young Adult Mystery\nCA - Coming of Age\nPT - Psychological Thriller\nMT - Mystery Thriller\nSH - Self Help" << endl;
                cout << "Enter genre choice: ";
                fflush(stdin);
                getline(cin, g);
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
            opt2c:
                char o;
                cout << endl << "Add book to cart? (Y/N) ";
                cin >> o;
                if (o == 'Y' || o == 'y')
                    ; //cust.cart();
                else if (o == 'N' || o == 'n')
                    goto menutwo;
                else {
                    cout << "Invalid Choice." << endl;
                    pause(1);
                    goto opt2c;
                }
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
            system("CLS");
            int sort;
            cout << "\t\t\tS O R T  I N V E N T O R Y" << endl;
            cout << "Sort:\n1, Aphabetically\n2, By Author\n3, Genre\n4, From higher to lower prices\n5, From lower to higher prices\n\n(Enter 0 to exit) ";
            cin >> sort;
            if (sort == 0)
                goto menu;
            else if (sort == 1)
                i1.sortbyauthor();
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
            i1.display();
            int ch;
            pause(2);
            cout << endl << endl << "Enter the 'Sno.' to add the book to the cart or review it. (Enter '0' to exit) ";
            cin >> ch;
            if (ch == 0)
                goto menu;
            else {
            choice3:
                system("CLS");
                pause(1);
                i1.getbook(ch);
                char o;
            opt3:
                cout << endl << "Add book to cart? (Y/N) ";
                cin >> o;
                if (o == 'Y' || o == 'y') {
                    book* bookToAdd = i1.getbookfororder(ch);
                    if (bookToAdd) {
                        //cust.cart(bookToAdd);
                        cout << endl << "Book added to cart." << endl;
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
        info:
            system("CLS");
            string name, add, billad, city;
            char p, c, d;
            bool pm, type;
            cout << "Enter Full Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter city: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Delivery Address: ";
            fflush(stdin);
            getline(cin, add);
        pay:
            cout << "Payment by card? (Y/N) ";
            cin >> p;
            if (p == 'N' || p == 'n')
                pm = true;
            else if (p == 'Y' || p == 'y')
                pm = false;
            else {
                cout << "Invalid option." << endl;
                goto pay;
            }
        bill:
            if (pm) {
                cout << "Billing Address same as Delivery Address? (Y/N)";
                cin >> c;
                if (c == 'N' || c == 'n') {
                    cout << "Enter Billing Address: ";
                    fflush(stdin);
                    getline(cin, billad);
                }
                else if (c == 'Y' || c == 'y')
                    billad = add;
                else {
                    cout << "Invalid option." << endl;
                    goto bill;
                }
            }
            else
                billad = "N/A";

        type:
            cout << "Fast Delivery (in 2-3 working days)? (Y/N)";
            cin >> d;
            if (d == 'N' || d == 'n') {
                type = true;
            }
            else if (d == 'Y' || d == 'y')
                type = false;
            else {
                cout << "Invalid option." << endl;
                goto type;
            }
            customer c1(name, add, billad, pm, city, type, cust);
            c1.display();
            break;
        }

        case 5: {
            logout:
                system("CLS");
                cout << "Are you sure you want to log out? Your cart will be emptied. (Y/N) ";
                char log;
                cin >> log;
                if (log == 'y' || log == 'Y') {
                    cout << endl << "\n\n\t\t\t**L O G G I N G   O F F**";
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

}
