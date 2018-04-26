//Driver file written to fulfill requirements of GHP #7.
//Used in conjunction with “hash.cpp” implementation file.
//Acquires strings from user, hashes strings and stores
//those strings in a vector, then allows user to indefinitely
//search for strings in the vector until a sentinel condition
//is fulfilled.
//
//Written by Jacob Hill
//May 2 2017
//Language: C++ (target: g++)
//

#include <iostream>
#include <vector>
#include <string>

#include "hash.h"

//number of words to be provided as input by the user
#define WORD_COUNT 15

using namespace std;

int main (void)
{
	Hash hashrun;
	string input, exit, e;
	int i;
	bool found;

	//Initialization of variables
	exit = "exit";
	e = "e";
	found = 0;

	//Introduction to user
	cout<<"\n\n\tHello. This program takes 15 words provided by you, the user, "\
	"and\n\tthen hashes and stores those words in a vector (entry procedure). "\
	"\n\tThe vector is then displayed to you; note that the symbol '?*?' refers\n"\
	"\tto an empty element within the vector (display procedure). You will\n\tthen "\
	"be queried to provide strings; each string entered will be\n\tsearched for "\
	"in the vector. You will then be notified if the string is\n\tfound in the "\
	"vector or not (search procedure). To stop entering words,\n\tsimply enter the "\
	"phrase 'exit' or 'e' (excluding the single quotes).\n"<<endl;

	cout<<"\n***Commencing entry procedure***\n\n";

	//Inserting strings into vector from user
	for (i = 0; i < WORD_COUNT; ++i) {
		cout<<"\nEnter a word: ";
		getline(cin,input);
		hashrun.insert(input);
	}

	cout<<"\n\n\n***Commencing display procedure***"<<endl;

	//Displaying the complete contents of the vector
	cout<<"\n\nContents of the vector 'words': \n";
	hashrun.display();

	//Resets the value of the user-provided string in
	//order to mitigate potential errors involving the
	//value of the user-provided string
	input = " ";

	cout<<"\n\n***Commencing search procedure***\n\n";

	cout<<"\nEnter a word to search for: ";
        getline(cin,input);

	//Searches vector "words<string>" for a match against
	//the user-provided string. Search continues indefinitely
	//until the user fulfills the sentinel condition (entering
	//the strings "exit" or "e" for short).
	while ( (input != exit) && (input != e) ) {
		found = hashrun.search(input);
		if (found) {
			cout<< "\n\t->'"<<input<<"' found at position '"
			<<hashrun.position(i)<<"' in vector 'words'.";
		}
		else {
			cout<<"\n\t->'"<<input<<"' not found.";
		}
		cout<<"\n\nEnter a word to search for: ";
                getline(cin,input);
	}

	cout<<"\n\n"<<endl;

	return 0;
}
