#include<iostream>
#include<chrono>
#include<thread>
#include<windows.h>
#include "drawman.cpp"
#include "timer.cpp"
#include "format.cpp"
using namespace std;

const int players=2;
const int duration = 45;
int sp1=0, sp2=0;

int main(){
	string word, genre; // for word to guess, and genre hint
	char guess; // each char guess
	char ch; // yes or no
	int rounds; // no of rounds
	string p1, p2; // player's name
	int sp1, sp2; // player's individual score
	bool turn=true; //true for p1's, false for p2's
	
	//intro
	header();
	cout << "Enter total rounds: ";
	cin >> rounds;
	cout << "Enter your name, player 1: ";
	fflush(stdin);
	getline(cin, p1);
	cout << "Enter your name, player 2: ";
	fflush(stdin);
	getline(cin, p2);
	pause(1);
	Beep(1000,500);
	pause(1);
	
	//rules
	clr();
	cout << endl << endl << "Welcome, " << p1 << " & " << p2 << "!" << endl;
	cout << endl << "Here are the rules: " << endl;
	cout << "1, The game will be based upon "  << rounds << " rounds, as chosen by you." << endl;
	cout << "2, Each player will enter the word to guess and the genre as hint\nfor the other player to guess." << endl;
	cout << "3, The 'Guess-er' will have a total of five chances AND 45-secs to guess the word correctly." << endl;
	cout << "If unable to do so, point will be assigned to the other player." << endl;
	cout << "\n\nPoints deduction is as followed:\n- 100 points for guessing without any misguesses.\n- 15 points will be deducted for each misguess.\n- 0 points to the Guesser if they run out of time and/or chances.\n   50 will be appointed to the opponent in such case." << endl;
	pause(3);
	cout << endl << "Remember, it is not only about guessing the word..." << endl;
	pause(2);
	cout  << "...but also about setting a difficult level for the next." << endl;
	pause(2);
	drama();
	pause(1);	
	
	//game
	for (int x=0; x<rounds; x++){ // for rounds
		for (int i=0; i<2; i++){ // for each player's turn
		turn:
			clrscn(rounds);
			cout << endl << p1 << ", your turn first. Hide the screen." << endl;
			pause(1);
			cout << "Enter the word: ";
			getline(cin, word);
			fflush(stdin);
			cout << "Enter the genre: ";
			getline(cin, genre);
			fflush(stdin);
			cout << endl << endl << "Is the word '" << word << "', and genre '" << genre << "'? (Y-yes, N-no): ";
			cin >> ch; 
				if (ch=='Y'||ch=='y')
					continue;
				else if (ch=='N'||ch=='n')
					goto turn;
				else {
					cout << "Invalid choice, going to the beginning.";
					pause(1);
					goto turn;
				}
			clrscn(rounds);
			cout << endl << p2 << ", it's your turn to guess:" << endl;
			cout << "Remember you have 5 chances, and 45-secs.\nPress Enter when you'ready to begin." << endl;
		    cin.get();
		    turn=!turn;
			hangman(word, genre, turn);
		}
	}
	return 0;
}

void hangman(string word, string genre, bool turn){
	bool end;
	char alphabets[26];
	int chances=5;
	const char* w1=word;
	if (turn==false){
		//p2 is guessing
		for (char &c : word) {
	        word = tolower(word);
	    }
		int length = strlen(word);
		char arr[length];
		strcpy(arr, w1);
		char empty[length];
	    for (x=0; x<length; x++){
	        if (word[x]==' '){
		        empty[x]=' ';
	        } else {
	            empty[x]='_';
	        }
	    } // end for _
	    
	    for (y=0; y<26; y++)
	        alphabets[y]='_';
	        
    	for (char &c : genre) {
	        genre = toupper(genre);
	    }
        cout << "HINT: " << genre << endl << endl;
        draw(0);
        for (int i=0; i<length; i++)
        	cout << empty[i] << " ";
        
        cout << "Your time begins now: " << endl;
        auto startTime = chrono::high_resolution_clock::now();
        do{
        	bool found=false;
        	bool ffound=false;
        	int drawman=0;
        	draw(drawman);
	        for (int i=0; i<length; i++)
	        	cout << empty[i] << " ";
	        cout << "Tries remaining: " << chances;
	        cout << "Enter guess: ";
	        fflush(stdin);
	        cin >> guess;
	        for(int i=0; i<length; i++){
	        	if (guess==arr[i]){
	        		empty[i]=guess;
	        		found=true;
				}
			} //end find guess
			if (!found){
				chances--;
				auto endTime-=chrono::seconds(10);
				auto currentTime = chrono::high_resolution_clock::now();
    			auto elapsedTime = chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();

			} else if (found){
				for(int i=0; i<length; i++){
	        		if (empty[i]=='_'){
	        			bool x=0;
	        			break;
					}
				} 
				if (!x)
					ffound=false;
				else if(x)
					ffound=true;
			}
			
	    } while (chances>=0 || ffound==true || elapsedTime > 0);
	    
	}
}
