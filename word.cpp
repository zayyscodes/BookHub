#include<iostream>
#include <algorithm>
#include<string>
using namespace std;

struct wod {
	string word;
	string pronun;
	string nav; // noun, adj or verb
	string origin;
	string def;
};

const int numw = 100;

struct wod words[numw] = {
	{"Bibliophile", "bi' blee' uh' file'", "n.", "Greek", "a person who collects or has a great love of books."},
	{"Book-Bosomed","buk' booz' uhmd'", "adj.", "English", " describe someone who carries a book at all times."},
	{"Bibliosmia", "bib' lee' oz' mee' ah", "n.", "Greek", "the habit of smelling the aroma of book pages."},
	{"Bibliobibuli", "bib' li' oh' bi' boo' li", "n.", "Greek", "the sort of people who read too much."},
	{"Bibliophage", "bib' lee' uh' fayj'", "n.", "Greek", "a person who loves to read books; a bookworm."},
	{"Hamartia", "huh' murr' tee' ah'", "n.", "Greek", "a fatal flaw leading to the downfall of a tragic hero or heroine."},
	{"Bibliolater", "bib' lee' oh' lay' tuh'", "n.", "Greek", "a person who is passionately enthusiastic about books."},
	{"Librocubicularist", "leh' bro' ku' bee' kuh' lay' riz'", "n.", "Latin", "(rare) someone who reads in bed."},
	{"Shelfrighteous", "shelf' rai' chas'", "adj.", "English", "a feeling of superiority about one’s bookshelf."},
	{"Scrollmate", "skrol' met'", "n.", "English", "an author the reader feels a deep connection with."},
	{"Readultery", "ree' dal' ta' ri'", "n.", "English", "the act of being unfaithful to one book by reading another simultaneously."},
	{"Sentranced", "sen' transt'", "adj.", "English", "the state of being captivated by a well-written sentence."},
	{"Perfictionist", "per' fik' sha' nist'", "n.", "English", "a fiction reader with high expectations."},
	{"Biblioclasm", "bib' li' oh' clasm'", "n.", "English", "the intentional destruction of books."},
	{"Perfictionist", "per' fik' sha' nist'", "n.", "English", "a fiction reader with high expectations."},
	{"Manuscriptify", "man' yuh' skrift' uh' fy'", "v.", "Latin", "to convert or transcribe spoken words or recordings into a written manuscript."},
	{"Bibliotaph", "bib' li' oh' taf'", "n.", "English", "a reader who hoards her books and protects them from others."},
	{"Shelf-fishing", "shelf' 'fish-ing", "v.", "English", "to methodically and patiently browse through shelves in search of hidden or less-known literary treasures."},
	{"Leaf-loping", "leef' low' ping'", "v.", "English", "to casually or randomly flip through the pages of a book while relaxing or daydreaming."},
	{"Libravore", "lee' bruh' vaw'", "v.", "English", "to voraciously consume or devour the contents of libraries through extensive reading."},
	{"Lexicoid", "lek' si' koyd'", "adj.", "Greek", "relating to or resembling the characteristics of a dictionary or lexicon."},
	{"Biblio-centric", "bib' lee' oh' sen' trik'", "adj.", "English", "focused on or revolving around books or the literary world."},
	{"Erudite", "er' yuh' dahyt'", "adj.", "Latin", "having or showing great knowledge, learning, or scholarship, commonly found in dedicated readers."},
};

bool compareByWord(const wod& a, const wod& b) {
	return a.word < b.word;
}

int generateRandomNumber(int start, int end) {
	int randno = (rand() % (end - start + 1)) + start;
	return randno;
}

void getwod(struct wod arr[], int i) {
	srand(static_cast<unsigned int>(time(0)));
	sort(arr, arr + i, compareByWord); // Sort the 'arr' array passed into the function, not 'words'
	int x = generateRandomNumber(0, i - 1); // Adjust the range to prevent potential out-of-bounds access
	cout << endl << "\t\t\t\tW O R D (s)  O F   T H E   D A Y" << endl;
	cout << '\t' << arr[x].word << endl << '\t' << "(" << arr[x].pronun << ")" << endl;
	cout << "  " << arr[x].nav << endl;
	cout << '\t' << arr[x].def << endl;
}