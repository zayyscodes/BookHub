#include<iostream>
#include<unistd.h>
#include<iomanip>
#include<string>
using namespace std;

class book{
	public:
		string name; //bookname
		string authorname; //authorname
		string genre; //book's main genre 
		int publishdate; //date of publishing
		bool special; //special edition or normal
		bool type; //true for paperback, false for hardback
		bool avail; //if stock present or not
		static int noofavail; //no of books available
		int price; //price of book
        int ordered; //how many books were ordered by customer

        book(){}
		book(string n, string a, string g, int date, bool s, bool t, bool av, int avn, int pr):name(n), authorname(a), genre(g), publishdate(date), special(s), type(t), avail(av), price(pr){
            if(av){
                setavail(avn);
            } else 
                ;
            ordered=0;
        }
		
        //set no of avail
        static void setavail(int x){
            noofavail=x;
        }

		void editdate(){
            int date;
            char ch;
            date:
            cout << "Enter the new date of publishing (format: ddmmyy): ";
            cin >> date;
            fflush(stdin);
            chd:
            cout << endl << "Is " << date << " the new date of publishing? (Y-yes, N-no): ";
            cin >> ch;
            if (ch=='Y'||ch=='y'){
                cout << endl << "Okay, date of publishing has been edited.";
                publishdate=date;
                display();
            } else if (ch=='N'||ch=='n'){
                cout << endl << "Please enter the correct date.";
                goto date;
            } else {
                cout << endl << "Please enter right choice";
                goto chd;
            }
        }

		void editprice(){
            int pr;
            char ch;
            date:
            cout << "Enter the new selling price for " << name << ": ";
            cin >> pr;
            fflush(stdin);
            chd:
            cout << endl << "Is Rs." << pr << " the new selling price? (Y-yes, N-no): ";
            cin >> ch;
            if (ch=='Y'||ch=='y'){
                cout << endl << "Okay, selling price for " << name << " has been edited.";
                price=pr;
                display();
            } else if (ch=='N'||ch=='n'){
                cout << endl << "Please enter the correct price.";
                goto date;
            } else {
                cout << endl << "Please enter right choice.";
                goto chd;
            }
        }

		static void editavail(){ //assuming sold
            noofavail--;
        }

        void display(){
            cout << endl << endl << "Book Name: " << name;
            cout << endl << "Author: " << authorname;
            cout << endl << "Genre: " << genre;
            cout << endl << "Date of Publish: " << setw(2) << setfill('0') << publishdate/10000 << "/" << setw(2) << setfill('0') << (publishdate/100)%100 << "/20" << setw(2) << setfill('0') << publishdate%100;
            cout << endl << "Type: ";
            if (type)
                cout << "Paperback";
            else
                cout << "Hardback";
            cout << endl << "Price: Rs." << price;
            cout << endl << "Available? ";
            if (avail)
                cout << "Yes | Place Order";
            else
                cout << "Out of Stock";
            
        }

        void setordered(){
            ordered++;
        }

        void displayorder(){
            cout << endl << endl << "Book Name: " << name;
            cout << endl << "Author: " << authorname;
            cout << endl << "Genre: " << genre;
            cout << endl << "Date of Publish: " << publishdate;
            cout << endl << "Date of Publish: " << setw(2) << setfill('0') << publishdate/10000 << "/" << setw(2) << setfill('0') << (publishdate/100)%100 << "/20" << setw(2) << setfill('0') << publishdate%100;
            if (type)
                cout << "Paperback";
            else
                cout << "Hardback";
            cout << endl << "Price: Rs." << price;
            cout << endl << "No. of copies ordered: " << ordered;
        }
};

int book::noofavail=0;

class Node{
    public:
        book b;
        Node* next;

        Node():next(NULL){}
        Node(book b):b(b), next(NULL){}
};

class inventory{ //Singly linked list
	Node* head;
    Node* tail;

    public:
        inventory(){}

        void addbook(book b){
            Node* n=new Node(b);
            if(head==NULL){
                head=n;
                tail=n;
                return;
            }
            tail->next=n;
            n->next=NULL;
            tail=n;
        }

        void sortbyname(){
            if (head == NULL || head->next == NULL)
                return;

            bool swapped;
            Node* temp;
            Node* end = NULL;

            do {
                swapped = false;
                temp = head;

                while (temp->next != end){
                    if (temp->b.name > temp->next->b.name){
                        swap(temp->b, temp->next->b);
                        swapped = true;
                    }
                    temp = temp->next;
                }
                end = temp;
            } while (swapped);
        }

        void sortbyauthor(){
            if (head == NULL || head->next == NULL)
                return;

            bool swapped;
            Node* temp;
            Node* end = NULL;

            do {
                swapped = false;
                temp = head;

                while (temp->next != end){
                    if (temp->b.authorname > temp->next->b.authorname){
                        swap(temp->b, temp->next->b);
                        swapped = true;
                    }
                    temp = temp->next;
                }
                end = temp;
            } while (swapped);
        }

        void sortbyprice(){
            if (head == NULL || head->next == NULL)
                return;

            bool swapped;
            Node* temp;
            Node* end = NULL;

            do {
                swapped = false;
                temp = head;

                while (temp->next != end){
                    if (temp->b.price > temp->next->b.price){
                        swap(temp->b, temp->next->b);
                        swapped = true;
                    }
                    temp = temp->next;
                }
                end = temp;
            } while (swapped);
        }

        Node* binarySearch(string n, string input){
            if (input == "author name" || input == "author" || input == "Author name" || input == "Author"){
                if (!head)
                    return NULL;

                string target=n;
                Node* left = head;
                Node* right = NULL;
                Node* mid = NULL;
                
                while (left->next) {
                    right = left;
                    left = left->next;
                }

                while (left && right && left != right) {
                    mid = left;
                    string midData = mid->b.authorname;

                    if (midData == target) {
                        return mid;
                    } else if (midData > target) {
                        right = mid;
                        left = left->next;
                    } else {
                        left = mid;
                        right = right->next;
                    }
                }
                if (left && left->b.name == target) {
                    return left;
                } else {
                    return NULL; // Element not found
                }
            } else if (input == "name" || input == "book name" || input == "Book name" || input == "Name"){
                if (!head)
                    return NULL;

                string target=n;
                Node* left = head;
                Node* right = NULL;
                Node* mid = NULL;
                
                while (left->next) {
                    right = left;
                    left = left->next;
                }

                while (left && right && left != right) {
                    mid = left;
                    string midData = mid->b.name;

                    if (midData == target) {
                        return mid;
                    } else if (midData > target) {
                        right = mid;
                        left = left->next;
                    } else {
                        left = mid;
                        right = right->next;
                    }
                }
                if (left && left->b.name == target) {
                    return left;
                } else {
                    return NULL; // Element not found
                }
            } else if (input == "Genre" || input == "genre"){
                if (!head)
                    return NULL;

                string target=n;
                Node* left = head;
                Node* right = NULL;
                Node* mid = NULL;
                
                while (left->next) {
                    right = left;
                    left = left->next;
                }

                while (left && right && left != right) {
                    mid = left;
                    string midData = mid->b.genre;

                    if (midData == target) {
                        return mid;
                    } else if (midData > target) {
                        right = mid;
                        left = left->next;
                    } else {
                        left = mid;
                        right = right->next;
                    }
                }
                if (left && left->b.genre == target) {
                    return left;
                } else {
                    return NULL; // Element not found
                }
            }
        } //a= search by author name or book name

        void display(){
		    Node* temp=head;
		    while(temp!=NULL){
                temp->b.display();
                cout << endl;
                temp=temp->next;
            }
        }

        void displaynode(Node* n){
            n->b.display();
        }
};

class customer{ //Queue
	private:
		string id=""; //unique order ID
		string name; //customer name
		string address; //customer address
		string city; //customer's city 
		bool deltype; //type of delivery: true = fast (few hours) or false = normal (3-4 working days)
		bool delivered; //is delivered or not
		book* ordered[10]; //customer's order, restricted to ten books
        int n;

	public:
		customer(){}
		customer(string n, string add, string cty, bool type):name(n), address(add), city(cty), deltype(type), n(1){}

		void setID(){
            if (city=="Lahore" || city == "lahore"){
                id+="PKLHR00";
            } else if (city=="Karachi" || city == "karachi"){
                id+="PKKHI00";
            } else if (city=="Peshawar" || city == "peshawar"){
                id+="PKPEW00";
            } else if (city=="Islamabad" || city == "islamabad"){
                id+="PKISB00";
            } else if (city=="Quetta" || city == "quetta"){
                id+="PKUET00";
            }
            int idnum = rand() % 4237;
            string str = to_string(idnum);
            id+=str;
        }

		void edit(){
            int ch;
            menu:
            cout << "What would you like to edit?" << endl << "1, Name" << endl << "2, Address" << endl << "3, Delivery type" << endl << "Enter choice: ";
            cin >> ch;

            if (ch==1){
                string name;
                cout  << endl <<  "Enter name to edit: ";
                getline(cin, name);
                fflush(stdin);
                this->name=name;
                cout  << endl << "Name has been edited.";
                display();
            } else if (ch==2){
                string add, cty;
                cout  << endl <<  "Enter your city: ";
                cin >> city;
                cout  << endl <<  "Enter your complete address: ";
                getline(cin, add);
                fflush(stdin);
                this->address=add;
                cout  << endl << "Address has been edited.";
                display();
            } else if (ch==3){
                string type;
                cout  << endl <<  "Choose delivery type, Fast or Normal: ";
                cin >> type;
                fflush(stdin);
                if (type =="FAST" || type == "Fast" || type == "fast")
                    this->deltype=true;
                else if (type =="NORMAL" || type == "Normal" || type == "normal")
                    this->deltype=false;
                cout  << endl << "Delivery type has been edited.";
                display();
            } else {
                cout << endl << "Wrong choice.";
                goto menu;
            }
        }

		void cart(book* b){
            bool flag=false;
            for (int i=0; i<n; i++){
                if (b->name==ordered[i]->name){
                    flag=true;
                    break;
                }
            }
            if (flag)
                b->setordered();
            else {
                int no=n-1;	
                fflush(stdin);
                this->ordered[no]=b;
                n++;
                b->setordered();
                b->editavail();
            }
        }

        void display(){
            cout << endl << "Cust. ID: " << id;
            cout << endl << "Name: " << name;
            cout << endl << " Address: " << address << ", " << city;
            cout << endl << "Type of Delivery: ";
            if (deltype)
                cout << "Fast Delivery";
            else 
                cout << "Normal Delivery";
            cout << endl << "Books Ordered: " << endl;
            for (int i=0; i<n; i++){
                ordered[i]->displayorder();
            }
            cout << endl << "Status: ";
            if (delivered)
                cout << "Delivered";
            else 
                cout << "*order in process*";
        }
};

class Queue{
	public:
		int front, rear, capacity;
		customer* queue;
		
		Queue(int c){
            front = rear = 0;
            capacity = c;
            queue = new customer;
        }

		void enqueue(customer c){
            if (capacity == rear){
                cout << endl << "**QUEUE IS FULL**";
                return;
            } else {
                queue[rear] = c;
                rear++;
            }
            return;
        }

		void dequeue(){
            if (front == rear){
                cout << endl << "**QUEUE IS EMPTY**";
                return;
            } else {
                for (int i=0; i<rear-1; i++){
                    queue[i]=queue[i+1];
                }
                rear--;
            }
            return;
        }

		void queuedisplay(){
            if (front == rear){
                cout << endl << "**QUEUE IS EMPTY**";
                return;
            } else {
                cout << "\t\t*******************************" << endl;
                cout << "\t\t  DISPLAYING CUSTOMERS DETAILS" << endl;
                cout << "\t\t*******************************" << endl;
                for (int i = front; i < rear; i++){
                    queue[i].display();
                    cout << endl;
                }
            }
        }
};

int main() {
	inventory i1;
	book b1("Twisted Love", "Ana Huang", "Dark Romance", 220421, false, true, true, 15, 2295);
    book b2("Twisted Games", "Ana Huang", "NA Contemporary Romance", 290721, true, true, true, 10, 2395);
	book b3("Twisted Hate", "Ana Huang", "NA Contemporary Romance", 270122, false, true, false, 0, 2445);
	book b4("Twisted Lies", "Ana Huang", "Dark Romance", 300622, true, true, true, 25, 2345);
	book b5("King of Wrath", "Ana Huang", "Dark Romance", 201022, true, true, true, 15, 2345);
	book b6("King of Pride", "Ana Huang", "Dark Romance", 250423, false, true, true, 15, 2445);
	book b7("King of Greed", "Ana Huang", "Dark Romance", 241023, true, true, true, 10, 2545);
	book b8("The Fine Print", "Lauren Asher", "Romance", 80721, false, true, true, 14, 2345);
	book b9("Terms and Conditions", "Lauren Asher", "Romance", 240222, true, true, true, 14, 2395);
	book a1("Final Offer", "Lauren Asher", "Romance", 310123, true, false, false, 14, 2345);
	book a2("Love Redesigned", "Lauren Asher", "Romance", 071123, true, true, true, 14, 2595);
	book a3("Six Of Crows", "Leigh Bardugo", "YA Fantasy", 290915, true, false, true, 5, 4545);
	book a4("Crooked Kingdom", "Leigh Bardugo", "YA Fantasy", 200916, true, false, false, 6, 4545);
	book a5("A Good Girl's Guide to Murder", "Holly Jackson", "YA Mystery", 20519, true, true, false, 0, 3945);
	book a6("Good Girl, Bad Blood", "Holly Jackson", "YA Mystery", 300420, false, true, true, 5, 1645);
	book a7("As Good As Dead", "Holly Jackson", "YA Mystery", 50821, false, true, true, 10, 2045);
	book a8("If He Had Been With Me", "Laura Nowlin", "Romance", 20413, false, true, true, 15, 1895);
	book a9("The Kite Runner", "Khaled Hosseini", "Coming of Age", 290503, true, false, true, 10, 4895);
	book d1("And The Mountains Echoed", "Khaled Hosseini", "Coming of Age", 210513, false, true, false, 10, 1295);
	book d2("A Thousand Splendid Suns", "Khaled Hosseini", "Coming of Age", 220507, false, true, true, 10, 2095);
	book d3("Butcher & Blackbird", "Brynn Weaver", "Dark Rom-Com", 150823, false, true, false, 5, 1585);
	book d4("The Silent Patient", "Alex Michaelides", "Psychological Thriller", 50219, true, true, true, 6, 2295);
	book d5("Sharp Objects", "Gillian Flynn", "Psychological Thriller", 260906, true, true, true, 6, 2045);
	book d6("The Girl on the Train", "Paula Hawkins", "Psychological Thriller", 130115, false, true, false, 5, 1895);
	book d7("A Flicker in the Dark", "Stacy Willingham", "Mystery Thriller", 110122, false, true, true, 10, 1945);
	book d8("Pretty Girls", "Karin Slaughter", "Psychological Thriller", 260416, false, true, false, 15, 2245);
	book d9("Murder in the Family", "Cara Hunter", "Mystery Thriller", 220623, false, true, true, 15, 2195);
	book e1("Atomic Habits", "James Clear", "Self Help", 161018, false, true, true, 20, 4045);
	book e2("The Subtle Art of Not Giving a F*ck", "Mark Manson", "Self Help", 130916, false, true, false, 20, 1895);
	
	book e3("The 48 Laws of Power", "Robert Greene", "Self Help", 10900, false, true, true, 20, 4045);
	book e4("The 5AM Club", "Robin Sharma", "Self Help", 41218, false, true, false, 20, 2545);
	book e5("Son of the Mob", "Gordon Korman", "Dark Rom-Com", 10904, false, true, true, 20, 1995);
	book e6("The Predator", "Runyx", "Dark Contemporary Romance", 10620, false, true, true, 20, 1845);
	book e7("The Reaper", "Runyx", "Dark Contemporary Romance", 161018, false, true, true, 20, 1845);
	book e8("The Emperor", "Runyx", "Dark Contemporary Romance", 60121, false, true, true, 20, 1945);
	book e9("The Finisher", "Runyx", "Dark Contemporary Romance", 161018, false, true, true, 20, 2025);
	book e0("The Annihilator", "Runyx", "Dark Contemporary Romance", 10722, false, true, true, 20, 2125);
	book f1("The Syndicator", "Runyx", "Dark Contemporary Romance", 10124, false, true, true, 20, 2445);
	book f2("The Fourth Wing", "Rebecca Yarros", "YA Fantasy", 50423, false, true, true, 20, 2495);
	book f3("Iron Flame", "Rebecca Yarros", "YA Fantasy", 71123, false, true, true, 20, 2545);
	book f4("King of Sloth", "Ana Huang", "Contemporary Romance", 300424, false, true, true, 20, 2595);


    i1.addbook(b1);
    i1.addbook(a1);
    i1.addbook(d1);
    i1.addbook(f1);
    i1.addbook(e1);
    i1.addbook(e0);
    i1.addbook(b2);
    i1.addbook(a2);
    i1.addbook(d2);
    i1.addbook(f2);
    i1.addbook(e2);
    i1.addbook(b3);
    i1.addbook(a3);
    i1.addbook(d3);
    i1.addbook(f3);
    i1.addbook(e3);
    i1.addbook(b4);
    i1.addbook(a4);
    i1.addbook(d4);
    i1.addbook(e4);
    i1.addbook(f4);
    i1.addbook(b5);
    i1.addbook(a5);
    i1.addbook(d5);
    i1.addbook(e5);
    i1.addbook(b6);
    i1.addbook(a6);
    i1.addbook(d6);
    i1.addbook(e6);
    i1.addbook(b7);
    i1.addbook(a7);
    i1.addbook(d7);
    i1.addbook(e7);
    i1.addbook(b8);
    i1.addbook(a8);
    i1.addbook(d8);
    i1.addbook(e8);
    i1.addbook(b9);
    i1.addbook(a9);
    i1.addbook(d9);
    i1.addbook(e9);
    
    i1.display();
}
