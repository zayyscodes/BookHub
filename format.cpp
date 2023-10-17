#include<iostream>
using namespace std;

void header(){
	cout << "\t\t\t   H A N G M A N" << endl;
	cout << "\t\t\t(Two-Player Version)" << endl;
}

void pause(int x){
	this_thread::sleep_for(chrono::seconds(x));
}

void clr(){
	system("CLS");
	header();
}

void clrscn(int rounds){
	system("CLS");
	header();
	cout << "R O U N D   #" << rounds << endl;
}

void drama(){
	cout << endl << endl << "\t\t\tLET ";
	pause(1);
	cout << "THE ";
	pause(1);
	cout << "GAME ";
	pause(1);
	cout << "BEGIN";
	pause(1);
	cout << ".";
	pause(1);
	cout << ".";
	pause(1);
	cout << ".";
	pause(1);
	cout << " :)";
	pause(1);	
}