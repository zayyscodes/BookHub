#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"customer.h"
#include"book.h"
#include"node.h"
#include<chrono>
#include<thread>
#include<iomanip>
#include<string>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include <windows.h> 
#include <stdlib.h>
using namespace std;

class inventory { //linked list
public:
    Node* head;
    Node* tail;
    int counter;

    inventory();

    void addbook(book b);
    void addbook(Node* naya);
    void sortbyname();
    void sortbyauthor();
    void sortbygenre();
    void sortbyprice(bool flag);
    void getbook(int pos);
    book* getbookfororder(int pos);
    Node* binarySearch(string n, string input); //a= search author name or book name
    void searchauthor(string input, customer& cust);
    void searchgenre(string input, customer& cust);
    void display();
    void displaynode(Node* n);
};

extern inventory i1;