#pragma once
#include<iostream>
#include"book.h"
using namespace std;

class Node {
public:
    int sno;
    book b;
    Node* next;

    Node();
    Node(book b);
    void setsno(int counter);
};