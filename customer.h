#pragma once
#include<iostream>
#include<queue>
#include"book.h"
using namespace std;

const double GST = 0.13;

class customer {
public:
    string id; //unique order ID
    string name; //customer name
    string address; //customer delivery address
    bool phtype; //true for mobile, false for landline
    string phno; //customer phno
    bool paymet; //true for COD, false for card
    string billad; //customer billing address
    string city; //customer's city 
    bool deltype; //type of delivery: false - fast (few hours) or true - normal (3-4 working days)
    bool delivered; //is delivered or not
    book* ordered[15]; //acc of order
    bool checkedout; //checked or not
    int booksInCart;
    string status;
    int level;
    double total;
    double finaltotal;
    double disc;

    customer();
    customer(string n, string add, string bill, bool pay, string cty, bool type);
    void setID();
    void setlandline();
    void edit();
    void cart(book* b);
    void display();
    void displayCart();
    void displayOrder();
    void checkout(); //C - checkout
    //void displayQueue(queue<customer> q); //E - display all orders
    void setinfo(); //C - for taking customer info for order checkout
    void updatestatus();
    bool operator<(const customer& other) const; //for priority queue
};