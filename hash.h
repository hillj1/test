//The following header file was written to fulfill the requirements
//of GHP #7. This header file is for defining the class "Hash," which
//takes a series of user-provided strings (the number of which is set
//by default to 15 but can be modified) and stores those strings in a
//vector. Additional functionality within the class stems from a mutator
//function allowing the addition of elements to the vector, and several
//accessor functions which display the vector elements to the user and
//search the vector for a user-provided string.
//
//Written by Jacob Hill
//May 2 2017
//Language: C++ (target: g++)
//

#include <vector>
#include <string>
#include <iostream>

//include guards
#ifndef HASH
#define HASH

using namespace std;

class Hash
{
	public:
		//Member functions of class "Hash"
		Hash();
		bool full (void);
		void insert (string & input);
		void display (void);
		bool search (string & input);
		int position (int & i);
		int position (void);

	private:
		//Data members of class "Hash"
		vector<string> words;
		string def_element;
		int index;
};

#endif
