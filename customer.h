#pragma once
#include<iostream>
#include<queue>
#include"book.h"
using namespace std;

class customer {
public:
    string id; //unique order ID
    string name; //customer name
    string address; //customer delivery address
    bool paymet; //true for COD, false for card
    string billad; //customer billing address
    string city; //customer's city 
    bool deltype; //type of delivery: fast (few hours) or normal (3-4 working days)
    bool delivered; //is delivered or not
    book* ordered[15]; //acc of order
    bool checkedout; //checked or not
    int booksInCart;

    customer();
    customer(string n, string add, string bill, bool pay, string cty, bool type, customer& cust);
    void setID();
    void edit();
    void cart(book* b);
    void display();
    void checkout(queue<customer>& customersQueue);
    void displayQueue(queue<customer> q);
};