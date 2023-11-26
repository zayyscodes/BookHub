#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
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

void pause(int x) {
    this_thread::sleep_for(chrono::seconds(x));
}

book::book() {}
book::book(string n, string a, string g, int date, bool s, bool t, bool av, int avn, double pr, const char* web) :name(n), authorname(a), genre(g), publishdate(date), special(s), type(t), avail(av), price(pr) {
    url = new char[strlen(web) + 1];
    strcpy(url, web);
    if (av) {
        noofavail=avn;
    }
    else
        noofavail = 0;
    ordered = 0;
}

void book::editdate() {
    int date;
    char ch;
date:
    cout << "Enter the new date of publishing (format: ddmmyy): ";
    cin >> date;
    fflush(stdin);
chd:
    cout << endl << "Is " << date << " the new date of publishing? (Y-yes, N-no): ";
    cin >> ch;
    if (ch == 'Y' || ch == 'y') {
        cout << endl << "Okay, date of publishing has been edited.";
        publishdate = date;
        display();
    }
    else if (ch == 'N' || ch == 'n') {
        cout << endl << "Please enter the correct date.";
        goto date;
    }
    else {
        cout << endl << "Please enter right choice";
        goto chd;
    }
}

void book::editprice() {
    int pr;
    char ch;
date:
    cout << "Enter the new selling price for " << name << ": ";
    cin >> pr;
    fflush(stdin);
chd:
    cout << endl << "Is Rs." << pr << " the new selling price? (Y-yes, N-no): ";
    cin >> ch;
    if (ch == 'Y' || ch == 'y') {
        cout << endl << "Okay, selling price for " << name << " has been edited.";
        price = pr;
        display();
    }
    else if (ch == 'N' || ch == 'n') {
        cout << endl << "Please enter the correct price.";
        goto date;
    }
    else {
        cout << endl << "Please enter right choice.";
        goto chd;
    }
}

void book::editavail() { //assuming sold
    noofavail--;
}

void book::displayDate(int publishdate) {
    int year = publishdate % 100;
    publishdate /= 100;
    int month = publishdate % 100;
    publishdate /= 100;
    int day = publishdate;
    cout << setfill('0') << setw(2) << day << "/" << setw(2) << month << "/" << setw(2) << year;
}

void book::display() {
    cout << endl << "Book Name: " << name;
    cout << endl << "Author: " << authorname;
    cout << endl << "Genre: " << genre;
    cout << endl << "Date of Publish: ";
    displayDate(publishdate);
    cout << endl << "Type: " << (type ? "Paperback" : "Hardback");
    cout << endl << "Price: Rs." << price;
    cout << endl << "Available? " << (avail ? "Yes | Place Order" : "Out of Stock");
    cout << endl << "No of Available copies: " << noofavail;
}

void book::displayorder() {
    cout << endl << "Book Name: " << name;
    cout << endl << "Author: " << authorname;
    cout << endl << "Genre: " << genre;
    cout << endl << "Date of Publish: ";
    displayDate(publishdate);
    cout << endl << "Type: " << (type ? "Paperback" : "Hardback");
    cout << endl << "Price: Rs." << price;
    cout << endl << "No. of copies ordered: " << ordered;
}


void book::setordered() {
    ordered++;
}

void book::openreads() {
    ShellExecuteA(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);
    /*const char *command = "curl ";
    char full_command[1000];
    sprintf(full_command, "%s%s", command, url);
    system(full_command);*/
}


//book name, author name, genre, date of publish, special edition, paperback or hardback, avail, no of books, price, url
book b1("Twisted Love", "Ana Huang", "Dark Romance", 220421, false, true, true, 15, 2295, "https://www.goodreads.com/book/show/55817097-twisted-love");
book b2("Twisted Games", "Ana Huang", "NA Contemporary Romance", 290721, true, true, true, 10, 2395, "https://www.goodreads.com/book/show/56653002-twisted-games");
book b3("Twisted Hate", "Ana Huang", "NA Contemporary Romance", 270122, false, true, false, 0, 2445, "https://www.goodreads.com/book/show/56688531-twisted-hate");
book b4("Twisted Lies", "Ana Huang", "Dark Romance", 300622, true, true, true, 25, 2345, "https://www.goodreads.com/book/show/60217302-twisted-lies");
book b5("King of Wrath", "Ana Huang", "Dark Romance", 201022, true, true, true, 15, 2345, "https://www.goodreads.com/book/show/61229235-king-of-wrath");
book b6("King of Pride", "Ana Huang", "Dark Romance", 250423, false, true, true, 15, 2445, "https://www.goodreads.com/book/show/62994279-king-of-pride");
book b7("King of Greed", "Ana Huang", "Dark Romance", 241023, true, true, true, 10, 2545, "https://www.goodreads.com/book/show/124943221-king-of-greed");
book b8("The Fine Print", "Lauren Asher", "Romance", 80721, false, true, true, 14, 2345, "https://www.goodreads.com/book/show/74045390-the-fine-print");
book b9("Terms and Conditions", "Lauren Asher", "Romance", 240222, true, true, true, 14, 2395, "https://www.goodreads.com/book/show/86767939-terms-and-conditions");
book a1("Final Offer", "Lauren Asher", "Romance", 310123, true, false, false, 14, 2345, "https://www.goodreads.com/book/show/61681786-final-offer");
book a2("Love Redesigned", "Lauren Asher", "Romance", 071123, true, true, true, 14, 2595, "https://www.goodreads.com/book/show/199070596-love-redesigned");
book a3("Six Of Crows", "Leigh Bardugo", "YA Fantasy", 290915, true, false, true, 5, 4545, "https://www.goodreads.com/book/show/23437156-six-of-crows");
book a4("Crooked Kingdom", "Leigh Bardugo", "YA Fantasy", 200916, true, false, false, 6, 4545, "https://www.goodreads.com/book/show/22299763-crooked-kingdom");
book a5("A Good Girl's Guide to Murder", "Holly Jackson", "YA Mystery", 20519, true, true, false, 0, 3945, "https://www.goodreads.com/book/show/40916679-a-good-girl-s-guide-to-murder?ref=nav_sb_ss_1_22");
book a6("Good Girl, Bad Blood", "Holly Jackson", "YA Mystery", 300420, false, true, true, 5, 1645, "https://www.goodreads.com/book/show/51335759-good-girl-bad-blood");
book a7("As Good As Dead", "Holly Jackson", "YA Mystery", 50821, false, true, true, 10, 2045, "https://www.goodreads.com/book/show/56905097-as-good-as-dead");
book a8("If He Had Been With Me", "Laura Nowlin", "Romance", 20413, false, true, true, 15, 1895, "https://www.goodreads.com/book/show/15835031-if-he-had-been-with-me?ref=nav_sb_ss_1_15");
book a9("The Kite Runner", "Khaled Hosseini", "Coming of Age", 290503, true, false, true, 10, 4895, "https://www.goodreads.com/book/show/77203.The_Kite_Runner");
book d1("And The Mountains Echoed", "Khaled Hosseini", "Coming of Age", 210513, false, true, false, 10, 1295, "https://www.goodreads.com/book/show/16115612-and-the-mountains-echoed");
book d2("A Thousand Splendid Suns", "Khaled Hosseini", "Coming of Age", 220507, false, true, true, 10, 2095, "https://www.goodreads.com/book/show/128029.A_Thousand_Splendid_Suns");
book d3("Butcher & Blackbird", "Brynn Weaver", "Dark Rom-Com", 150823, false, true, false, 5, 1585, "https://www.goodreads.com/en/book/show/196915235");
book d4("The Silent Patient", "Alex Michaelides", "Psychological Thriller", 50219, true, true, true, 6, 2295, "https://www.goodreads.com/en/book/show/40097951");
book d5("Sharp Objects", "Gillian Flynn", "Psychological Thriller", 260906, true, true, true, 6, 2045, "https://www.goodreads.com/en/book/show/18045891");
book d6("The Girl on the Train", "Paula Hawkins", "Psychological Thriller", 130115, false, true, false, 5, 1895, "https://www.goodreads.com/book/show/22557272-the-girl-on-the-train?ref=nav_sb_ss_1_19");
book d7("A Flicker in the Dark", "Stacy Willingham", "Mystery Thriller", 110122, false, true, true, 10, 1945, "https://www.goodreads.com/book/show/57693172-a-flicker-in-the-dark?ref=nav_sb_ss_1_16");
book d8("Pretty Girls", "Karin Slaughter", "Psychological Thriller", 260416, false, true, false, 15, 2245, "https://www.goodreads.com/en/book/show/25574782");
book d9("Murder in the Family", "Cara Hunter", "Mystery Thriller", 220623, false, true, true, 15, 2195, "https://www.goodreads.com/en/book/show/63241097");
book e1("Atomic Habits", "James Clear", "Self Help", 161018, false, true, true, 20, 4045, "https://www.goodreads.com/en/book/show/40121378");
book e2("The Subtle Art of Not Giving a F*ck", "Mark Manson", "Self Help", 130916, false, true, false, 20, 1895, "https://www.goodreads.com/en/book/show/28257707");
book e3("The 48 Laws of Power", "Robert Greene", "Self Help", 10900, false, true, true, 20, 4045, "https://www.goodreads.com/en/book/show/1303");
book e4("The 5AM Club", "Robin Sharma", "Self Help", 41218, false, true, false, 20, 2545, "https://www.goodreads.com/en/book/show/37502596");
book e5("Son of the Mob", "Gordon Korman", "Dark Rom-Com", 10904, false, true, true, 20, 1995, "https://www.goodreads.com/en/book/show/22237");
book e6("The Predator", "Runyx", "Dark Contemporary Romance", 10620, false, true, true, 20, 1845, "https://www.goodreads.com/en/book/show/52871061");
book e7("The Reaper", "Runyx", "Dark Contemporary Romance", 161018, false, true, true, 20, 1845, "https://www.goodreads.com/book/show/53027547-the-reaper");
book e8("The Emperor", "Runyx", "Dark Contemporary Romance", 60121, false, true, true, 20, 1945, "https://www.goodreads.com/book/show/53473056-the-emperor");
book e9("The Finisher", "Runyx", "Dark Contemporary Romance", 161018, false, true, true, 20, 2025, "https://www.goodreads.com/book/show/53473067-the-finisher");
book e0("The Annihilator", "Runyx", "Dark Contemporary Romance", 10722, false, true, true, 20, 2125, "https://www.goodreads.com/book/show/54683187-the-annihilator");
book f2("The Fourth Wing", "Rebecca Yarros", "YA Fantasy", 50423, false, true, true, 20, 2495, "https://www.goodreads.com/book/show/61431922-fourth-wing");
book f3("Iron Flame", "Rebecca Yarros", "YA Fantasy", 71123, false, true, true, 20, 2545, "https://www.goodreads.com/book/show/90202302-iron-flame");