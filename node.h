#pragma once
#include<iostream>
#include"book.h"
using namespace std;

class Node {
public:
    static int counter;
    int sno;
    book b;
    Node* next;

    Node();
    Node(book b);
};