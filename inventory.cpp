#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"inventory.h"
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

const int num = 50;

inventory::inventory() :head(NULL), tail(NULL) {}

void inventory::addbook(book b) {
    Node* n = new Node(b);
    if (head == NULL) {
        head = n;
        tail = n;
        return;
    }
    tail->next = n;
    n->next = NULL;
    tail = n;
}

void inventory::addbook(Node* naya) {
    Node* n = naya;
    if (head == NULL) {
        head = n;
        tail = n;
        return;
    }
    tail->next = n;
    n->next = NULL;
    tail = n;
}

void inventory::sortbyname() {
    if (head == NULL || head->next == NULL)
        return;

    bool swapped;
    Node* temp;
    Node* end = NULL;

    do {
        swapped = false;
        temp = head;

        while (temp->next != end) {
            if (temp->b.name > temp->next->b.name) {
                swap(temp->b, temp->next->b);
                swapped = true;
            }
            temp = temp->next;
        }
        end = temp;
    } while (swapped);
}

void inventory::sortbyauthor() {
    if (head == NULL || head->next == NULL)
        return;

    bool swapped;
    Node* temp;
    Node* end = NULL;

    do {
        swapped = false;
        temp = head;

        while (temp->next != end) {
            if (temp->b.authorname > temp->next->b.authorname) {
                swap(temp->b, temp->next->b);
                swapped = true;
            }
            temp = temp->next;
        }
        end = temp;
    } while (swapped);
}

void inventory::sortbygenre() {
    if (head == NULL || head->next == NULL)
        return;

    bool swapped;
    Node* temp;
    Node* end = NULL;

    do {
        swapped = false;
        temp = head;

        while (temp->next != end) {
            if (temp->b.genre > temp->next->b.genre) {
                swap(temp->b, temp->next->b);
                swapped = true;
            }
            temp = temp->next;
        }
        end = temp;
    } while (swapped);
}

void inventory::sortbyprice(bool flag) {
    if (flag) { //true=ascending: lower to higher
        if (head == NULL || head->next == NULL)
            return;

        bool swapped;
        Node* temp;
        Node* end = NULL;

        do {
            swapped = false;
            temp = head;

            while (temp->next != end) {
                if (temp->b.price > temp->next->b.price) {
                    swap(temp->b, temp->next->b);
                    swapped = true;
                }
                temp = temp->next;
            }
            end = temp;
        } while (swapped);
    }
    else if (!flag) { //false=descending: higher to lower prices
        if (head == NULL || head->next == NULL)
            return;

        bool swapped;
        Node* temp;
        Node* end = NULL;

        do {
            swapped = false;
            temp = head;

            while (temp->next != end) {
                if (temp->b.price < temp->next->b.price) { // Change comparison operator to <
                    swap(temp->b, temp->next->b);
                    swapped = true;
                }
                temp = temp->next;
            }
            end = temp;
        } while (swapped);
    }
}

Node* inventory::binarySearch(string n, string input) {
    if (input == "name" || input == "book name" || input == "Book name" || input == "Name") {
        if (head == NULL) {
            return NULL; // Empty list, no search possible
        }

        string target = n;
        Node* left = head;
        Node* right = NULL;

        while (left != NULL) {
            Node* mid = left;
            right = left->next;

            string midData = mid->b.name;

            if (midData == target) {
                return mid;
            }
            else if (midData > target) {
                left = left->next;
            }
            else {
                left = right;
            }
        }

        return NULL; // Element not found
    }

    return NULL; // Handle other cases or invalid inputs
}
//a= search by author name or book name

void inventory::searchauthor(string input, customer& cust) {
    inventory iauthor; // Creating an instance of the inventory class

    if (head == NULL) {
        cout << "Empty list. No search possible." << endl;
        return; // Empty list, no search possible
    }

    Node* temp = head;

    while (temp != NULL) {
        if (temp->b.authorname == input) {
            Node* n = new Node(); // Create a new node for iauthor
            n->b = temp->b; // Copy the book details
            n->sno = temp->sno; // Copy the sno directly
            iauthor.addbook(n); // Assuming addbook() adds a book to 'iauthor'
        }
        temp = temp->next;
    }

getbookauthor:
    system("CLS");
    iauthor.display();
    int ch;

    cout << endl << endl << "Enter the 'Sno.' to add the book to the cart or review it. (Enter '0' to exit) ";
    cin >> ch;
    if (ch == 0) {
        return;
    }
    else {
        bool flag = false;
        Node* temp2 = iauthor.head;
        if (temp2 == NULL) {
            cout << "No book found by " << input << endl;
            return;
        }
        while (temp2 != NULL) {
            if (temp2->sno == ch) {
                iauthor.displaynode(temp2);
                flag = true;
                break;
            }
            temp2 = temp2->next;
        }
    choose:
        if (flag) {
            char choice;
            cout << "Would you like to order the book? (Y/N) ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y') {
                cust.cart(&(temp2->b));
            }
            else if (choice == 'N' || choice == 'n') {
                goto getbookauthor;
            }
            else {
                cout << "Invalid option, try again.";
                pause(1);

                goto choose;
            }
        }
        else {
            cout << "book not available in specific genre." << endl;
            goto getbookauthor;
        }
    }
}

void inventory::searchgenre(string input, customer& cust) {
    inventory igenre;
    if (head == NULL) {
        return; //Empty list, no search possible
    }
    Node* temp = head;
    while (temp != NULL) {
        if (temp->b.genre == input) {
            Node* n = new Node(); // Create a new node for iauthor
            n->b = temp->b; // Copy the book details
            n->sno = temp->sno; // Copy the sno directly
            igenre.addbook(n); // Assuming addbook() adds a book to 'iauthor'
        }
        temp = temp->next;
    }

getbookgenre:
    system("CLS");
    igenre.display();
    int ch;

    cout << endl << endl << "Enter the 'Sno.' to add the book to the cart or review it. (Enter '0' to exit) ";
    cin >> ch;
    if (ch == 0) {
        return;
    }
    else {
        bool flag = false;
        Node* temp2 = igenre.head;
        if (temp2 == NULL) {
            cout << "No book found by " << input << endl;
            return;
        }
        while (temp2 != NULL) {
            if (temp2->sno == ch) {
                igenre.displaynode(temp2);
                flag = true;
                break;
            }
            temp2 = temp2->next;
        }
    choose:
        if (flag) {
            char choice;
            cout << "Would you like to order the book? (Y/N) ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y') {
                cust.cart(&(temp2->b));
            }
            else if (choice == 'N' || choice == 'n') {
                goto getbookgenre;
            }
            else {
                cout << "Invalid option, try again.";
                pause(1);
                goto choose;
            }
        }
        else {
            cout << "book not available in specific genre." << endl;
            goto getbookgenre;
        }
    }
}

void inventory::getbook(int pos) {
    Node* temp = head;
    for (int i = 0; i < pos - 1; i++) {
        temp = temp->next; //traverse to book
    }
    system("CLS");
    displaynode(temp);
}

book* inventory::getbookfororder(int pos) {
    if (pos <= 0 || pos > num) {
        throw out_of_range("Invalid book position");
    }

    Node* temp = head;
    for (int i = 1; i < pos; i++) {
        if (temp == nullptr) {
            throw out_of_range("Book not found at position");
        }
        temp = temp->next; // Traverse to the desired position
    }

    return &(temp->b);
}

void inventory::display() {
    Node* temp = head;
    int i = 0;
    while (temp != NULL) {
        cout << endl << "Sno. " << ++i;
        temp->b.display();
        cout << endl;
        temp = temp->next;
    }
}

void inventory::displaynode(Node* n) {
    char ch;
    if (n == NULL) {
        cout << endl << "Node is empty." << endl;
        return;
    }
    n->b.display();
    pause(1);

choice:
    cout << endl << "Would you like to check the summary and reviews? (Y/N) ";
    cin >> ch;
    if (ch == 'y' || ch == 'Y') {
        cout << endl << "**O P E N I N G   G O O D R E A D S**" << endl;
        n->b.openreads();
    }
    else if (ch == 'n' || ch == 'N')
        return;
    else {
        cout << "Invalid Choice." << endl;
        pause(1);
        goto choice;
    }

    pause(2);
}

inventory i1;