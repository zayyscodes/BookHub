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
    for (int i = 0; i < maxbooks; ++i) {
        ordered[i] = nullptr;
    }
}

customer::customer(string n, string add, string bill, bool pay, string cty, bool type, customer& cust) :name(n), address(add), billad(bill), paymet(pay), city(cty), deltype(type), booksInCart(0) {
    customer::setID();
    checkedout = false;
    delivered = false;
    for (int i = 0; i < maxbooks; ++i) {
        ordered[i] = nullptr;
    }
}

void customer::setID() {
    if (city == "Lahore" || city == "lahore") {
        id += "PKLHR00";
    }
    else if (city == "Karachi" || city == "karachi") {
        id += "PKKHI00";
    }
    else if (city == "Peshawar" || city == "peshawar") {
        id += "PKPEW00";
    }
    else if (city == "Islamabad" || city == "islamabad") {
        id += "PKISB00";
    }
    else if (city == "Quetta" || city == "quetta") {
        id += "PKUET00";
    }
    int idnum = rand() % 4237;
    string str = to_string(idnum);
    id += str;
}

void customer::edit() {
    int ch;
menu:
    cout << "What would you like to edit?" << endl << "1, Name" << endl << "2, Address" << endl << "3, Delivery type" << endl << "Enter choice: ";
    cin >> ch;

    if (ch == 1) {
        string name;
        cout << endl << "Enter name to edit: ";
        getline(cin, name);
        fflush(stdin);
        this->name = name;
        cout << endl << "Name has been edited.";
        display();
    }
    else if (ch == 2) {
        string add, cty;
        cout << endl << "Enter your city: ";
        cin >> city;
        cout << endl << "Enter your complete address: ";
        getline(cin, add);
        fflush(stdin);
        this->address = add;
        cout << endl << "Address has been edited.";
        display();
    }
    else if (ch == 3) {
        string type;
        cout << endl << "Choose delivery type, Fast or Normal: ";
        cin >> type;
        fflush(stdin);
        if (type == "FAST" || type == "Fast" || type == "fast")
            this->deltype = true;
        else if (type == "NORMAL" || type == "Normal" || type == "normal")
            this->deltype = false;
        cout << endl << "Delivery type has been edited.";
        display();
    }
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

    // Display book information only if newBook is not null
    cout << endl;
    newBook->display();
    cout << endl;

    if (newBook->noofavail == 0 && !newBook->avail) {
        cout << "Book is currently out of stock." << endl;
        return;
    }

    if (booksInCart >= maxbooks) {
        cout << "Cart full, please proceed to checkout." << endl;
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
                cout << endl << "Book added to cart." << endl;
            }
            else {
                cout << "Book not available for order." << endl;
            }
            bookExists = true;
            break; // No need to continue checking
        }
    }

    // If the book doesn't exist in the cart, add it
    if (!bookExists) {
        ordered[booksInCart] = newBook;
        cout << endl << "Book added to cart." << endl;
        booksInCart++;
        newBook->setordered();
        newBook->editavail();
    }

    // Increase booksInCart after adding a book
    pause(2);
}



void customer::checkout(queue<customer>& customersQueue) {
    customersQueue.push(*this);
}

void customer::display() {
    cout << endl << "Cust. ID: " << id;
    cout << endl << "Name: " << name;
    cout << endl << " Address: " << address << ", " << city;
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

void customer::displayQueue(queue<customer> q) {
    cout << "Customers in the queue:" << std::endl;

    // Use a temporary queue to hold the elements for display
    queue<customer> tempQueue = q;

    while (!tempQueue.empty()) {
        customer cust = tempQueue.front();
        cust.display();
        cout << endl << endl;
        tempQueue.pop();
    }
}