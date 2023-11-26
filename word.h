#pragma once
#ifndef WORD_H
#define WORD_H
#include<string>
using namespace std;

struct wod {
	string word;
	string pronun;
	string nav; // noun, adj or verb
	string origin;
	string def;
};

extern const int numw;
extern struct wod words[];
bool compareByWord(const wod& a, const wod& b);
int generateRandomNumber(int start, int end);
void getwod(struct wod arr[], int i);

#endif