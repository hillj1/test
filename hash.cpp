//Implementation file of "Hash" class constructed according to
//the "hash.h" header file. See file "hash.h" for further details
//on the purpose and functionality of the Hash class.
//
//Written by Jacob Hill
//May 2 2017
//Language: C++ (target: g++)
//

/*
Generic comment inserted for TEST
purposes
*/

#include <iostream>
#include <vector>
#include <string>

#include "hash.h"

//for setting size and capacity of vector
#define SIZE 23
#define ZERO 0
#define ONE 1

using namespace std;

//Constructor function for class "Hash"
//
//Written by Jacob Hill
//May 2 2017
//Language: C++ (target: g++)
//
Hash::Hash ():words(SIZE) {
	int i;

	def_element = "?*?";
	index = SIZE + ONE;

	//Populates vector with default element "?*?"
	for (i = 0; i < SIZE; ++i) {
		words[i] = def_element;
	}

}

//Function to check if vector is "full," i.e. populated
//entirely with elements other than the default element
//("def_element").
//
//Written by Jacob Hill
//April 26 2017
//Language: C++ (target: g++)
//
bool Hash::full (void) {
	int i;
	bool filled;

	//Vector is assumed to be "filled" until
	//proven otherwise
	filled = true;

	for (i = 0; (i < SIZE) && filled; ++i) {
		if (words[i] == def_element) {
			filled = false;
		}
	}

	return filled;
}

//Function to insert a string into an element of the
//vector in the class "Hash".
//
//Written by Jacob Hill
//May 2 2017
//Language: C++ (target: g++)
//
void Hash::insert (string & input) {
	int i;
	bool filled;

	i = 0;
	filled = false;

	//Hashing of provided string; first letter of string
	//(returned by "[ZERO]") is added to the last letter
	//of the string (returned by "string.length() - 1") and
	//then the resulting sum is subjected to modular division
	//based on the specified size of the vector (default size
	//is "23").
	i = ( (input[ZERO]) + (input[input.length() - ONE]) ) % SIZE;

	//Checking to see if vector is full, i.e. has no
	//default elements ("?*?"), indicating that the
	//total capacity of the vector has been filled
	filled = full();

	if ( (words[i] != def_element) && (!filled) ) {
		//Checking to see if the selected vector
		//position is equal to the last position in
		//the vector; if so, position is reset to
		//"0" to begin checking vector from beginning
		if (i == (SIZE - 1)) {
			i = ZERO;
		}
		else {
			++i;
		}
		while (words[i] != def_element) {
			++i;
			if (i == SIZE) {
				i = ZERO;
			}
		}
		words[i] = input;
	}
	else if (!filled) {
		words[i] = input;
	}
	else {
		cout<<"\n\n***Can't add any more strings! Vector is "\
		"full.***\n\n";
	}

	return;
}

//Function to display the contents of the entire vector to
//the user, in a specific format. Each element of the vector
//is printed to the screen.
//
//Written by Jacob Hill
//May 2 2017
//Language: C++ (target: g++)
//
void Hash::display (void) {
	int i;

	cout<<endl;

	for (i = 0; i < SIZE; ++i) {
		cout<<"\n\tContents of vector 'words["<<i<<"]': "<<words[i];
	}

	cout<<endl;

	return;
}

//Function to search vector for a match against a user-provided
//string. If match is found, a boolean value of "true" (non-zero
//integer) is returned, else a "false" value (0) is returned.
//
//
//Written by Jacob Hill
//May 2 2017
//Language: C++ (target: g++)
//
bool Hash::search (string & input) {
	int i1, i2;
	bool found;

	i1 = 0;
	i2 = 0;
	found = false;

	//User-provided string is hashed
	i1 = ( (input[ZERO]) + (input[input.length() - ONE]) ) % SIZE;
	i2 = i1;

	if (words[i1] == input) {
		found = true;
		index = i1; //Position of element within the
			    //vector where match was found
	}
	else {
		//Case in which current position in vector
		//is equal to the final position within the
		//vector; if so, position is reset to "0"
		//to search vector from beginning
		if (i1 == (SIZE - 1)) {
                        i1 = ZERO;
                }
		else {
			++i1;
		}
                while ( (!found) && (i1 != i2) ) {
			index = i1;

			//Checking to see if current
			//vector element is a match
			//against user-provided string
			if (words[i1] == input) {
				found = true;
			}
			//Position within vector is
			//reset to the beginning of the
			//vector if the final position
			//within the vector is reached;
			//infinite loop doesn't occur
			//because loop ends when a
			//match is found or when the
			//current position within the
			//vector matches the initial
			//vector position at which
			//the loop began ("i2")
			if (i1 == (SIZE - 1)) {
				i1 = ZERO;
			}
			else {
				++i1;
			}
                }
	}

	return found;
}


//Function written to return the current position within
//the vector. Note that the function is overloaded; two
//versions of the function exist, one in which an argument
//is provided and one in which an argument is not provided.
//The function defined below is written in the case that
//an argument IS provided.
//
//Written by Jacob Hill
//May 2 2017
//Language: C++ (target: g++)
//
int Hash::position (int & i) {
	i = index;
	return i;
}

//Function written to return the current position within
//the vector. This function is an overloaded version of
//the previously defined function ".position()". The
//function defined below is written in the case that an
//argument is NOT provided.
//
//Written by Jacob Hill
//May 2 2017
//Language: C++ (target: g++)
//
int Hash::position (void) {
	return index;
}
