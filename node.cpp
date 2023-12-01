#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"node.h"
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
using namespace std;

Node::Node() : next(NULL) {}
Node::Node(book b) : b(b), next(NULL) {}

void Node::setsno(int counter) {
	sno = counter;
}