#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<chrono> // for pause function
#include<thread> // for pause function
#include<iomanip> // formatting
#include<string> //string functions
#include<cstring> //string functions
#include<cstdlib>
#include<fstream> // filing
#include<queue> // for queue procedures
#include<stack> //for stack procedures
#include<conio.h> // for password; window getch()
#include<windows.h> // to open website
#include<stdlib.h>
#include"book.h" // book class declared
#include"customer.h" // customer class declared
#include"inventory.h" //inventory declard
#include"node.h" // node for inventory declared
#include"word.h"
using namespace std;

struct Genre {
    string code;
    string name;
};

const int numGenres = 14; // Number of genres
Genre genres[numGenres] = {
    {"RM", "Romance"},
    {"DR", "Dark Romance"},
    {"DC", "Dark Contemporary Romance"},
    {"DK", "Dark Rom-Com"},
    {"NC", "NA Contemporary Romance"},
    {"YF", "YA Fantasy"},
    {"YM", "YA Mystery"},
    {"CA", "Coming of Age"},
    {"PT", "Psychological Thriller"},
    {"MT", "Mystery Thriller"},
    {"SH", "Self Help"},
    {"DY", "Dystopian Fantasy"},
    {"HR", "Horror"},
    {"SF", "Science Fiction"}
};

class employee {
public:
    string name;
    string username;
    char password[50];
    employee() {}
    employee(string name, string uname, const char pw[50]) : name(name), username(uname) {
        std::strncpy(password, pw, sizeof(password));
        password[sizeof(password) - 1] = '\0'; // Ensures null-termination
    }
};

const int maxsize = 100;
string arr[maxsize] = { "Due to fluctuation in exchange rates, the prices of the books might variate.", "\t\t\t\t\t NEW YEAR EVE Sale coming soon!", "Additional 10% discount on payment by card!" };

const int empnum = 20;
employee emp[empnum];

void generateebill(customer& cust);
void generatebill(customer& cust, int billno);
void announcement();

const int num = 50;
const int n = 10;

int main() {
    int i = 23;
    int billno = 0;
    priority_queue<customer> customerQueue;
    stack<customer> dispatchedorders; // orders sent out to be delivered
    stack<customer> dispatchorders; // orders set aside; ready to be delivered
    i1.addbook(b1); i1.addbook(a1); i1.addbook(d1); i1.addbook(e1); i1.addbook(e0); i1.addbook(b2); i1.addbook(e9); i1.addbook(d9);
    i1.addbook(a2); i1.addbook(d2); i1.addbook(f2); i1.addbook(e2); i1.addbook(b3); i1.addbook(a3); i1.addbook(d3); i1.addbook(f3);
    i1.addbook(e3); i1.addbook(b4); i1.addbook(a4); i1.addbook(d4); i1.addbook(e4); i1.addbook(b5); i1.addbook(a5);
    i1.addbook(d5); i1.addbook(e5); i1.addbook(b6); i1.addbook(a6); i1.addbook(d6); i1.addbook(e6); i1.addbook(b7); i1.addbook(a7);
    i1.addbook(d7); i1.addbook(e7); i1.addbook(b8); i1.addbook(a8); i1.addbook(d8); i1.addbook(e8); i1.addbook(b9); i1.addbook(a9);

logIN:
    header();
    int login;
    cout << "\t\t\t\t\t\t L O G  I N" << endl;
    cout << "\t\t\t\t\t      1, As a customer\n\t\t\t\t\t        2, As Admin" << endl;
    cout << "\n\t\t\t\tEnter choice: ";
    cin >> login;
    if (login == 1) {
        customer cust;
    menu:
        header();
        getwod(words, i);
        announcement();
        cout << endl << endl << "\n\t\t\t\t\t\tM A I N   M E N U" << "You are recommended to proceed in the order given:";
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
                        int nob;
                        cout << "How many copies? ";
                        cin >> nob;
                        int x = bookToAdd->ordered + nob;
                        if (x <= bookToAdd->noofavail) {
                            for (int i = 1; i <= nob; i++) {
                                cust.cart(bookToAdd);
                            }
                        }
                        else
                            cout << "Book not added, insufficient stock." << endl;
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
                        int nob;
                        cout << "How many copies? ";
                        cin >> nob;
                        int x = n->b.ordered + nob;
                        if (x <= n->b.noofavail) {
                            for (int i = 1; i <= nob; i++) {
                                cust.cart(&(n->b));
                            }
                        }
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
                bool found = false;
            optg:
                header();
                cout << endl << "\n\t\t\t\t\tS E A R C H  B Y  G E N R E";
                cout << endl << endl << "Genres:" << endl;
                for (int x = 0; x < numGenres; x++) {
                    cout << genres[x].code << " - " << genres[x].name << endl;
                }
                cout << endl << "Enter the code for the genre you want to search: ";
                cin >> g;
                for (int x = 0; x < numGenres; x++) {
                    for (char& c : g) {
                        c = std::toupper(c);
                    }
                    if (genres[x].code == g) {
                        found = true;
                        genre = genres[x].name;
                        break;
                    }
                }
                if (found) {
                    i1.searchgenre(genre, cust);
                    pause(1);
                    goto menu;
                }
                else {
                    cout << "Invalid Choice, try again." << endl;
                    pause(1);
                    goto optg;
                }
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
                    if (bookToAdd != NULL) {
                        int nob;
                        cout << "How many copies? ";
                        cin >> nob;
                        int x = bookToAdd->ordered + nob;
                        if (x <= bookToAdd->noofavail) {
                            for (int i = 1; i <= nob; i++) {
                                cust.cart(bookToAdd);
                            }
                        }
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
                cout << "\n\t\t\t\t\t** D I S P L A Y I N G   C A R T **";
                cust.displayCart();
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
                    header();
                    cust.displayOrder();
                    cout << endl;
                    system("pause");
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
            cout << "Invalid option, try again" << endl;
            pause(1);
            goto menu;
            break;
        } //end switch
    } // end user-based program



    else if (login == 2) {
        emp[0] = employee("Zahab Jahangir", "ZahabJay", "zazzyjazzy");
        emp[1] = employee("Zehra Waqar", "Zayys", "zehrathebest");
        int empi = 2;
    loginpw:
        header();
        string username;
        char password[50];
        char correct[50];
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
        string empname;
        bool found = false;
        int user;
        for (int i = 0; i < empi; i++) {
            if ((username == emp[i].username) && (std::strcmp(password, emp[i].password) == 0)) {
                found = true;
                user = i;
                break;
            }
        }
        if (!found) {
            cout << "\n\t\t\t\tIncorrect Username or Password." << endl;
            pause(2);
            goto logIN;
        }

        header();
        cout << "Welcome back, " << emp[user].name << endl;
        pause(2);
    menuemp:
        header();
        cout << endl << endl << "\n\t\t\t\t\t\tM A I N   M E N U";
        cout << endl << "1, Add book to inventory\n2, Register new hire\n3, Process order & dispatch\n4, Get Day's Summary\n5, Log Out";
        cout << endl << "Enter Choice: ";
        int choose;
        cin >> choose;
        switch (choose) {
            case 1: {
            again:
                header();
                inventory temp;
                string n, an, g;
                int date, avn;
                char sp, t, av;
                bool s, type, avail;
                char* url = new char[250];
                double pr;
                cout << endl << "\t\t\tI N P U T  B O O K   I N F O" << endl;
                cout << "Enter Book Name: ";
                cin.ignore();
                getline(cin, n);
                cout << "Enter Author's Name: ";
                getline(cin, an);
                cout << endl << endl << "Possible genres:" << endl;
                for (int x = 0; x < numGenres; x++) {
                    cout << genres[x].code << " - " << genres[x].name << endl;
                }
                cout << "Enter Book Genre: ";
                getline(cin, g);
                cout << "Enter Publish date (DDMMYY): ";
                cin >> date;
                cout << "Is it a special edition? (Y/N): ";
                cin >> sp;
                if (sp == 'y' || sp == 'Y') {
                    s = true;
                } else if (sp == 'n' || sp == 'N') {
                    s = false;
                }
                cout << "Is it a paperback? (Y/N): ";
                cin >> t;
                if (t == 'y' || t == 'Y') {
                    type = true; //paperback
                }
                else if (t == 'n' || t == 'N') {
                    type = false; //hardback
                }
                cout << "Is it a available for sale? (Y/N): ";
                cin >> av;
                if (av == 'y' || av == 'Y') {
                    avail = true;
                }
                else if (av == 'n' || av == 'N') {
                    avail = false;
                }
                if (avail) {
                    cout << "Enter total copies available: ";
                    cin >> avn;
                }
                else
                    avn = 0;
                cout << "Enter selling price: Rs.";
                cin >> pr;
                cout << "Enter goodreads link for the book: " << endl;
                cin.ignore();
                cin.getline(url, 250);
                //book name, author name, genre, date of publish, special edition, paperback or hardback, avail, no of books, price, url
                temp.addbook(book(n, an, g, date, s, type, av, avn, pr, url));
                cout << endl << endl << "Book information has been taken." << endl;
                pause(1);
                header();
                temp.displaynode(temp.head);
                char choice;
            chooseb:
                cout << endl << "Is this the book you want to add? (Y/N)(Enter E to exit) ";
                cin >> choice;
                if (choice == 'y' || choice == 'Y') {
                    cout << endl << "Book has been added to inventory";
                    i1.addbook(book(n, an, g, date, s, type, av, avn, pr, url));
                }
                else if (choice == 'n' || choice == 'N') {
                    cout << "Going to beginning again...";
                    pause(1);
                    goto again;
                }
                else if (choice == 'e' || choice == 'E') {
                    cout << "Returning to main menu...";
                    pause(1);
                    goto menuemp;
                }
                else {
                    cout << "Invalid option, try again." << endl;
                    goto chooseb;
                }
            }
            case 2: {
                header();
            input:
                string name, username;
                char pw[50];
                cout << "Enter Full Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Username: ";
                getline(cin, username);
            pwenter:
                cout << "Set Password: ";
                cin.getline(pw, 50);
                char choice;
            choicepw:
                cout << "Is '" << pw << "' the password you want to set? (Y/N) ";
                cin >> choice;
                if (choice == 'Y' || choice == 'y') {
                    cout << "Employee ID created, and saved!" << endl;
                    cout << endl << "Employee Name: " << name << endl;
                    cout << "Employee Username: " << username << endl;
                    cout << "Employee Access Password: " << pw << endl;
                    cout << "Are these the correct credentials? (Y/N) ";
                    cin >> choice;
                    if (choice == 'Y' || choice == 'y') {
                        emp[empi] = employee(name, username, pw);
                        empi++;
                        pause(1);
                        goto menuemp;
                    }
                    else if (choice == 'N' || choice == 'n') {
                        goto input;
                    }
                } else if (choice == 'N' || choice == 'n') {
                    pause(1);
                    goto pwenter;
                }
                else {
                    cout << "Invalid option, try again." << endl;
                    pause(1);
                    goto choicepw;
                }
                break;
            }

                  
            case 3: {
                if (!customerQueue.empty()) {
                    priority_queue<customer> copyQueue = customerQueue;
                    while (!copyQueue.empty()) {
                        customer curr = copyQueue.top();
                        curr.displayOrder();
                        cout << endl;
                        copyQueue.pop(); // Remove the top element
                    }
                    char orderch;
                    for (int i = 0; i < customerQueue.size(); i++) {
                    optch:
                        cout << "Would you like to process the top order? (Y/N) ";
                        cin >> orderch;
                        if (orderch == 'Y' || orderch == 'y') {
                            header();
                            customer curr = customerQueue.top();
                            curr.updatestatus();
                            curr.displayOrder();
                            cout << endl << "\t\t\t\t **P R O C E S S I N G**" << endl;
                            pause(2);
                            char disor;
                            cout << endl << "Do you want to dispatch order right now? (Y/N) (Enter E to exit) ";
                            cin >> disor;
                            if (disor == 'E' || disor == 'e') {
                                cout << endl << "Returning to main menu...";
                                pause(1);
                                goto menuemp;
                            }
                            else if (disor == 'Y' || disor == 'y') { //dispatch order
                                billno = billno + 1;
                                generatebill(curr, billno, emp[user].name);
                                dispatchedorders.push(curr);
                                customerQueue.pop();
                                curr.updatestatus();
                                pause(1);
                            } else if (disor == 'N' || disor == 'n') { //keep in storage only if type is normal delivery
                                if (!curr.deltype) {
                                    cout << "The order is fast delivery, thus procrastinating not possible." << endl;
                                    billno = billno + 1;
                                    generatebill(curr, billno, emp[user].name);
                                    dispatchedorders.push(curr);
                                    customerQueue.pop();
                                    curr.updatestatus();
                                    pause(1);
                                } else {
                                    billno = billno + 1;
                                    generatebill(curr, billno, emp[user].name);
                                    dispatchorders.push(curr);
                                    customerQueue.pop();
                                    curr.updatestatus();
                                    pause(1);
                                }
                            } 
                        }
                        else if (orderch == 'N' || orderch == 'n') {
                            cout << endl << "Returning to main menu...";
                            pause(1);
                            goto menuemp;
                        }
                        else {
                            cout << "Invalid option, try again." << endl;
                            pause(1);
                            goto optch;
                        }
                    }
                }
                else {
                    cout << "Queue empty right now." << endl;
                    pause(1);
                    goto menuemp;
                }
                break;
            }
            case 4: {
                getdaysummary(customerQueue, dispatchedorders, dispatchorders);
                header();
                cout << endl << "'DaySummary.txt' has been created." << endl;
                system("pause");
                goto menuemp;
                break;
            }
            case 5: {
                cout << endl << "\n\n\t\t\t\t\t\t**L O G G I N G   O F F**";
                pause(2);
                goto logIN;
                break;
            }
        }

        
    } //employee access code

}//end main program

void generatebill(customer& cust, int billno, string name) {
    string file = "";
    file += "billno00";
    file+= to_string(billno);
    file += ".txt";
    ofstream MyFile(file);
    MyFile << "\n\t\t\t\t\t\t       THE BOOK HUB" << endl;
    MyFile << "\t\t\t\t\t\t --Online Sale Receipt--" << endl;
    MyFile << "Receipt Number: " << setw(4) << setfill('0') << billno << endl;
    MyFile << "Order ID: " << cust.id << endl;
    MyFile << "Customer Name: " << cust.name << endl << "Customer Phone Number: " << cust.phno << endl << "Customer Address: " << cust.address << ", " << cust.city << endl ;
    MyFile << "User: " << name;
    MyFile << "Channel: Online" << endl;

    MyFile << endl << "-----------------------------------------" << endl;
    MyFile << "\t\t\t**O R D E R**";
    MyFile << endl << "-----------------------------------------" << endl;
    for (int i = 0; i < cust.booksInCart; i++) {
        MyFile << i + 1 << ") " << endl;
        MyFile << endl << "Book Name: " << cust.ordered[i]->name;
        if (cust.ordered[i]->special)
            MyFile << " (special edition)";
        MyFile << endl << "Author: " << cust.ordered[i]->authorname;
        MyFile << endl << "Genre: " << cust.ordered[i]->genre;
        MyFile << endl << "Date of Publish: ";
        cust.ordered[i]->displayDate(cust.ordered[i]->publishdate);
        MyFile << endl << "Type: " << (cust.ordered[i]->type ? "Paperback" : "Hardback");
        MyFile << endl << "Price: Rs." << cust.ordered[i]->price;
        MyFile << endl << "No. of copies ordered: " << cust.ordered[i]->ordered;
    }
    MyFile << endl << "-----------------------------------------" << endl;
    MyFile << "Total: Rs." << fixed << setprecision(2) << cust.total;
    cust.finaltotal = (cust.total * GST) + cust.total;
    MyFile << endl << "Total after GST: Rs." << fixed << setprecision(2) << cust.finaltotal << endl;
    if (!cust.paymet) {
        cust.finaltotal = cust.finaltotal - (cust.finaltotal * 0.1);
        MyFile << endl << "After 'Card Discount': Rs." << fixed << setprecision(2) << cust.finaltotal << endl;
        cust.disc = cust.total - cust.finaltotal;
        MyFile << endl << "Discounted off: Rs." << fixed << setprecision(2) << cust.disc << endl;
    }
    MyFile << endl << "Thank you for shopping at The Book Hub!";
    MyFile.close();
}



void getdaysummary(priority_queue<customer> customerQueue, stack<customer> dispatchedOrder, stack<customer> dispatchorder) {
    ofstream MyFile("DaySummary.txt");

    MyFile << "Queue contents:" << std::endl;
    if (!customerQueue.empty()) {
        while (!customerQueue.empty()) {
            customer cust = customerQueue.top();
            MyFile << "Cust. ID: " << cust.id << endl;
            MyFile << "Name: " << cust.name << endl << "Address: " << cust.address << ", " << cust.city << endl;
            customerQueue.pop();
        }
    }
    else
        MyFile << "Customer Queue is empty!" << endl;

    MyFile << endl << "Orders processed:" << endl;
    if (!dispatchorder.empty()) {
        while (!dispatchorder.empty()) {
            customer cust = dispatchorder.top();
            MyFile << "Cust. ID: " << cust.id << endl;
            MyFile << "Name: " << cust.name << endl << "Address: " << cust.address << ", " << cust.city << endl;
            dispatchorder.pop();
        }
    }
    else
        MyFile << endl << "No orders to be dispatched.";
    
    MyFile << "Orders dispatched:" << endl;
    if (!dispatchedOrder.empty()) {
        while (!dispatchedOrder.empty()) {
            customer cust = dispatchedOrder.top();
            MyFile << "Cust. ID: " << cust.id << endl;
            MyFile << "Name: " << cust.name << endl << "Address: " << cust.address << ", " << cust.city << endl;
            dispatchedOrder.pop();
        }
    }
    else
        MyFile << "No orders have been dispatched yet.";

    MyFile.close();
}

void announcement() {
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    srand(static_cast<unsigned int>(time(0)));
    int x = generateRandomNumber(0, arrSize - 1); // Adjust the range to prevent potential out-of-bounds access
    cout << endl << "\n\t\t\t\t\t   A N N O U N C E M E N T S" << endl;
    cout << arr[x];
}

void addString(const std::string& newann) {
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    if (arrSize >= maxsize) {
        cout << "Announcement array is full. Cannot add more announcements." << endl;
        return;
    }
    arr[arrSize++] = newann;
}