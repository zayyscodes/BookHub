#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"customer.h"
#include"book.h"
#include<chrono>
#include<thread>
#include<iomanip>
#include<string>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include <windows.h> 
#include <stdlib.h>
#include<queue>
using namespace std;

const int maxbooks = 12;

customer::customer() {
    total = 0.00;
    finaltotal = 0.00;
    booksInCart = 0;
    level = 0;
    paymet = true;
    status = "Order has not been placed yet.";
    for (int i = 0; i < 15; ++i) {
        ordered[i] = nullptr; // Initialize all elements to nullptr
    }
}

customer::customer(string n, string add, string bill, bool pay, string cty, bool type) :name(n), address(add), billad(bill), paymet(pay), city(cty), deltype(type) {
    customer::setID();
    total = 0.00;
    finaltotal = 0.00;
    booksInCart = 0;
    level = 0;
    checkedout = false;
    delivered = false;
    booksInCart = 0;
    for (int i = 0; i < 15; ++i) {
        ordered[i] = nullptr; // Initialize all elements to nullptr
    }
}

void customer::setID() {
    id = "";
    if (city == "Lahore" || city == "lahore" || city == "lhr" || city == "LHR" || city == "Lhr") {
        id += "PKLHR00";
    }
    else if (city == "Karachi" || city == "karachi" || city == "khi" || city == "KHI" || city == "Khi") {
        id += "PKKHI00";
    }
    else if (city == "Peshawar" || city == "peshawar" || city == "PEW" || city == "pew" || city == "Pew") {
        id += "PKPEW00";
    }
    else if (city == "Islamabad" || city == "islamabad" || city == "ISB" || city == "isb" || city == "Isb") {
        id += "PKISB00";
    }
    else if (city == "Quetta" || city == "quetta" || city == "UET" || city == "Uet" || city == "uet") {
        id += "PKUET00";
    }
    else if (city == "Hyderabad" || city == "hyderabad" || city == "HYD" || city == "hyd" || city == "Hyd") {
        id += "PKHYD00";
    }
    else if (city == "Multan" || city == "multan" || city == "MUX" || city == "mux" || city == "Mux") {
        id += "PKMUX00";
    }
    int idnum = rand() % 4237;
    string str = to_string(idnum);
    id += str;
}

void customer::setlandline() {
phnos:
    phno = "";
    if (city == "Lahore" || city == "lahore" || city == "lhr" || city == "LHR" || city == "Lhr") {
        phno += "042";
    }
    else if (city == "Karachi" || city == "karachi" || city == "khi" || city == "KHI" || city == "Khi") {
        phno += "021";
    }
    else if (city == "Peshawar" || city == "peshawar" || city == "PEW" || city == "pew" || city == "Pew") {
        phno += "091";
    }
    else if (city == "Islamabad" || city == "islamabad" || city == "ISB" || city == "isb" || city == "Isb") {
        phno += "051";
    }
    else if (city == "Quetta" || city == "quetta" || city == "UET" || city == "Uet" || city == "uet") {
        phno += "081";
    }
    else if (city == "Hyderabad" || city == "hyderabad" || city == "HYD" || city == "hyd" || city == "Hyd") {
        phno += "022";
    }
    else if (city == "Multan" || city == "multan" || city == "MUX" || city == "mux" || city == "Mux") {
        phno += "061";
    }

    string num = "";
    cout << "Enter next few digits: " << phno;
    cin >> num;
    phno += num;
    if (phno.length() < 11 && phno.length() > 13) {
        cout << "Invalid number, try again." << endl;
        goto phnos;
    }
}

void customer::edit() {
    int ch;
menu:
    cout << "What would you like to edit?" << endl << "1, Name" << endl << "2, Address" << endl << "3, Billing Address" << endl << "4, Contact Number" << endl << "5, Delivery type" << endl << "6, Payment Method" << endl << "7, Return" << endl << "Enter choice: ";
    cin >> ch;
    //option to change name on order.
    if (ch == 1) {
        string n;
        cout << endl << "Previously entered name: " << name << endl;
        cout << endl << "Enter name to edit: ";
        cin.ignore();
        getline(cin, n);
        this->name = n;
        cout << endl << "Name has been edited." << endl;
        cout << endl << "Updated Information: " << endl;
        display();
    }
    //choice to update address.
    else if (ch == 2) {
        string add, cty;
        cout << endl << "Previous entered address: " << address << ", " << city << endl;
        cout << endl << "Enter City: ";
        cin >> city;
        this->city = city;
        setID();
        cout << endl << "Enter your complete address: ";
        cin.ignore();
        getline(cin, add);
        this->address = add;
        if (paymet) {
            char c;
        bill:
            cout << "Billing Address same as Delivery Address? (Y/N) ";
            cin >> c;
            if (c == 'N' || c == 'n') {
                cout << "Enter Billing Address: ";
                cin.ignore();
                getline(cin, billad);
                this->billad = billad;
            }
            else if (c == 'Y' || c == 'y') {
                this->address = add;
                // Assign delivery address to 'billad'
                this->billad = add;
            }
            else {
                cout << "Invalid option." << endl;
                goto bill;
            }
        }
        if (!phtype) {
            cout << "Previous entered contact number: " << phno << endl;
            setlandline();
        }
        cout << endl << "Updated Information: " << endl;
        display();
    }
    //choice to update billing address.
    else if (ch == 3) {
        if (paymet) {
            string type;
            cout << endl << "Previous Billing Address: " << billad << endl;
            cout << endl << "Enter new Billing Address: ";
            cin >> billad;
            this->billad = billad;
            cout << endl << "Billing Address has been edited." << endl;
            cout << endl << "Updated Information: " << endl;
            display();
        }
        else {
            cout << endl << "Your payment method is 'by Card'. Billing address not required for specific method." << endl;
            goto menu;
        }
    }
    //choice to change phno
    else if (ch == 4) {
        cout << "Previous entered contact number: " << phno << endl;
        char opt;
        string ph;
    phno:
        cout << "For contact number: Enter M for mobile, L for landline";
        cin >> opt;
        if (opt == 'M' || opt == 'm') {
            phtype = true;
            cout << "Enter mobile number (format: XXXXXXXXXXX): ";
            cin.ignore();
            getline(cin, ph);
            if (ph.length() != 12) {
                cout << "Invalid number, try again" << endl;
                goto phno;
            }
            this->phno = ph;
        }
        else if (opt == 'P' || opt == 'p') {
            phtype = false;
            setlandline();
        }
        else {
            cout << endl << "Invalid option, try again." << endl;
            goto phno;
        }
        cout << endl << "Updated Information: " << endl;
        display();
    }
    //choice to update delivery type.
    else if (ch == 5) {
        string type;
    editmet:
        cout << endl << "Previous Delivery type: ";
        if (!deltype)
            cout << "Fast Delivery";
        else
            cout << "Normal Delivery";
        cout << endl << endl << "Choose delivery type, Fast or Normal: ";
        cin >> type;
        if (type == "FAST" || type == "Fast" || type == "fast")
            this->deltype = false;
        else if (type == "NORMAL" || type == "Normal" || type == "normal")
            this->deltype = true;
        else {
            cout << "Invalid option, try again" << endl;
            goto editmet;
        }
        cout << endl << "Delivery type has been edited." << endl;
        cout << endl << "Updated Information: " << endl;
        display();
    }
    //choice to update payment method.
    else if (ch == 6) {
        string type;
    editpay:
        cout << endl << "Previous Payment Method: ";
        if (paymet)
            cout << "Cash On Delivery (COD)";
        else
            cout << "Payment by card.";
        cout << endl << endl << "Choose Payment Method, Card or COD: ";
        cin >> type;
        if (type == "COD" || type == "Cod" || type == "cod")
            this->paymet = true;
        else if (type == "CARD" || type == "Card" || type == "card")
            this->paymet = false;
        else {
            cout << endl << "Invalid option, try again." << endl;
            goto editpay;
        }
    billadd:
        if (paymet) {
            char c;
            cout << "Billing Address same as Delivery Address? (Y/N) ";
            cin >> c;
            if (c == 'N' || c == 'n') {
                cout << "Enter Billing Address: ";
                cin.ignore();
                getline(cin, billad);
                this->billad = billad;
            }
            else if (c == 'Y' || c == 'y') {
                // Assign delivery address to 'billad'
                this->billad = address;
            }
            else {
                cout << "Invalid option." << endl;
                goto billadd;
            }
        }
        else
            billad = "N/A";

        cout << endl << "Payment method has been edited." << endl;
        cout << endl << "Updated Information: ";
        display();
    }
    //choice to return
    else if (ch == 7) {
        cout << endl << "Returning..." << endl;
        pause(2);
        return;
    }
    //invalid option
    else {
        cout << endl << "Wrong choice.";
        goto menu;
    }
}

void customer::cart(book* newBook) {
    if (newBook == nullptr) {
        cout << "Book unavailable." << endl;
        return;
    }

    if (newBook->noofavail == 0 && !newBook->avail) {
        cout << "Book is currently out of stock." << endl;
        return;
    }

    if (booksInCart >= maxbooks) {
        cout << "Cart full, please proceed to checkout." << endl;
        pause(2);
        return;
    }

    // Check if the book already exists in the customer's cart
    bool bookExists = false;
    for (int i = 0; i < booksInCart; i++) {
        if (ordered[i] == newBook) {
            // Book exists in the cart; set flags and update book properties
            if (newBook->noofavail != 0) {
                newBook->setordered();
                newBook->editavail();
                total = total + newBook->price;
                cout << endl << "Book added to cart." << endl;
                pause(2);
            }
            else {
                cout << "Book not available for order." << endl;
                pause(2);
            }
            bookExists = true;
            break; // No need to continue checking
        }
    }

    // If the book doesn't exist in the cart, add it
    if (!bookExists) {
        ordered[booksInCart] = newBook;
        booksInCart = booksInCart + 1; // Increment booksInCart by 1
        cout << endl << "Book added to cart." << endl;
        pause(2);
        total = total + newBook->price;
        newBook->setordered();
        newBook->editavail();
    }
}

void customer::displayOrder() {
    cout << "-----------------------------------------" << endl;
    for (int i = 0; i < booksInCart; i++) {
        ordered[i]->displayorder();
        cout << endl;
    }
    cout << endl << "-----------------------------------------" << endl;
    cout << "Total: Rs." << fixed << setprecision(2) << total;
    finaltotal = (total * GST) + total;
    cout << endl << "Total after GST: Rs." << fixed << setprecision(2) << finaltotal << endl;
    if (!paymet) {
        finaltotal = finaltotal - (finaltotal * 0.1);
        cout << endl << "After 'Card Discount' : Rs." << fixed << setprecision(2) << finaltotal << endl;
    }
}

void customer::display() {
    cout << endl;
    cout << endl << "Cust. ID: " << id;
    cout << endl << "Name: " << name;
    cout << endl << "Contact Number: " << phno;
    cout << endl << "Address: " << address << ", " << city;
    if (paymet)
        cout << endl << "Billing Address: " << billad << ", " << city;
    cout << endl << "Payment Method: ";
    if (paymet)
        cout << "Cash On Delivery (COD)";
    else
        cout << "Payment by card.";
    cout << endl << "Type of Delivery: ";
    if (!deltype)
        cout << "Fast Delivery";
    else
        cout << "Normal Delivery";
    if (!(booksInCart < 2)) {
        cout << endl << "Books Ordered: " << endl;
        for (int i = 0; i < booksInCart; i++) {
            ordered[i]->display();
        }
        cout << endl << "Status: ";
        if (delivered)
            cout << "Delivered";
        else
            cout << "*order in process*";
    }
}

/*void customer::displayQueue(queue<customer> q) {
    cout << "Customers in the queue:" << endl;

    // Use a temporary queue to hold the elements for display
    queue<customer> tempQueue = q;

    while (!tempQueue.empty()) {
        customer cust = tempQueue.front();
        cust.display();
        cout << endl << endl;
        tempQueue.pop();
    }
}*/

void customer::setinfo() {
    string name, add, billad, city, ph;
    char p, c, d;
    cout << "Enter Full Name: ";
    cin.ignore();
    getline(cin, name);
    this->name = name;
    cout << "Enter City: ";
    getline(cin, city);
    this->city = city;
    setID();
    cout << "Enter Delivery Address: ";
    getline(cin, add);
    this->address = add;
    char opt;
phno:
    cout << "(Enter M for mobile, L for landline) For contact number: ";
    cin >> opt;
    if (opt == 'M' || opt == 'm') {
        phtype = true;
        cout << "Enter mobile number (format: XXXXXXXXXXX): ";
        cin.ignore();
        getline(cin, ph);
        if (ph.length() < 11 && ph.length() > 13) {
            cout << "Invalid number, try again" << endl;
            goto phno;
        }
        this->phno = ph;
    }
    else if (opt == 'L' || opt == 'l') {
        phtype = false;
        setlandline();
    }
    else {
        cout << endl << "Invalid option, try again." << endl;
        goto phno;
    }
pay:
    cout << "Payment by card? (Y/N) ";
    cin >> p;
    if (p == 'N' || p == 'n')
        paymet = true;
    else if (p == 'Y' || p == 'y')
        paymet = false;
    else {
        cout << "Invalid option." << endl;
        goto pay;
    }
bill:
    if (paymet) {
        cout << "Billing Address same as Delivery Address? (Y/N) ";
        cin >> c;
        if (c == 'N' || c == 'n') {
            cout << "Enter Billing Address: ";
            cin.ignore();
            getline(cin, billad);
            this->billad = billad;
        }
        else if (c == 'Y' || c == 'y') {
            this->address = add;
            // Assign delivery address to 'billad'
            this->billad = add;
        }
        else {
            cout << "Invalid option." << endl;
            goto bill;
        }
    }
    else
        billad = "N/A";

type:
    cout << "Normal Delivery (in 8-9 working days)? (Y/N) ";
    cin >> d;
    if (d == 'Y' || d == 'y') {
        deltype = true;
    }
    else if (d == 'N' || d == 'n')
        deltype = false;
    else {
        cout << "Invalid option." << endl;
        goto type;
    }

    cout << endl << endl;
    customer::display();
}

bool customer::operator<(const customer& other) const {
    if (deltype != other.deltype) {
        // Sort by delivery type, fast delivery first
        return deltype > other.deltype;
    }
    else {
        // If delivery types are the same, prioritize by books in cart (less books first)
        return booksInCart > other.booksInCart;
    }
}

void customer::updatestatus() {
    level = level + 1;
    if (level == 1) {
        status = "Order placed, added to cart.";
    }
    else if (level == 2) {
        status = "Order is being processed.";
    }
    else if (level == 3) {
        status = "Order has been dispatched, you will receive it";
        if (deltype) {
            status += " by next week.";
        }
        else {
            status += " in a few days.";
        }
    }
}