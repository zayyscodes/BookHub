#pragma once
#include<iostream>
using namespace std;

void pause(int x);

class book {
public:
    string name; //bookname
    string authorname; //authorname
    string genre; //book's main genre 
    int publishdate; //date of publishing
    bool special; //special edition or normal
    bool type; //true for paperback, false for hardback
    bool avail; //if stock present or not
    int noofavail; //no of books available
    double price; //price of book
    int ordered; //how many books were ordered by customer
    char* url;

    book();
    book(string n, string a, string g, int date, bool s, bool t, bool av, int avn, double pr, const char* web);
    void editdate();
    void editprice();
    void editavail();
    void setordered();
    void displayDate(int publishdate);
    void display();
    void displayorder();
    void openreads();
};

extern book b1;
extern book b2;
extern book b3;
extern book b4;
extern book b5;
extern book b6;
extern book b7;
extern book b8;
extern book b9;
extern book a1;
extern book a2;
extern book a3;
extern book a4;
extern book a5;
extern book a6;
extern book a7;
extern book a8;
extern book a9;
extern book d1;
extern book d2;
extern book d3;
extern book d4;
extern book d5;
extern book d6;
extern book d7;
extern book d8;
extern book d9;
extern book e1;
extern book e2;
extern book e3;
extern book e4;
extern book e5;
extern book e6;
extern book e7;
extern book e8;
extern book e9;
extern book e0;
extern book f2;
extern book f3;