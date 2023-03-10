#include<iostream>
#include<string>
using namespace std;
#include "queue.h" // include queue.h or equivalent such as <queue>

//----------------------------------------------
// CS421 HW1 
// Write a generator in C++ for L = {x | x is any combination of a's and b's}.
// Your name: Zachary Mekaelian
//----------------------------------------------
// Copy the recognizer function here from the other file.
bool recognizer(string s)
{
	bool isAB;// a boolean parameter used to check if a char is a or b

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'a' || s[i] == 'b') {
			isAB = true; // if the char is a or b, set value to true
		}
		else {
			isAB = false; // otherwise set the value to false and break
			break;
		}
	}
	return isAB; // return the result
}// end of the recognizer



// main: It should create each string over E = {a,b,c} systematically
//   (short to long) and pass each string to the recognizer function
//   created in Part a).  Hint: use a queue to generate strings
//   Only those strings for which the recognizer returned TRUE
//   should be displayed. 
//   Keeps on going until the queue overflows but the user can 
//   terminate the program with control-C 
//   after about 20 strings have been displayed.
int main()//main function in which to test out our program
{
	string E[] = { "a", "b", "c" }; // the set of E
	string str;//str to push into recognizer function
	string newStr;// the new str created
	queue myStr;// the queue to hold all the numbers
	int counter = 0;//counter and userInput to see how many times we have called our functions so we can give 
	string userInput = "continue";//the user the chance to discontinue after 20 counter increments

	for (int i = 0; i < sizeof(E) / sizeof(E[0]); i++) {
		myStr.add(E[i]);
	}
	cout << "The letters generated by the set {a,b,c}: " << endl;
	try {
		while (userInput == "continue") {
			myStr.remove(str);//remove current str from myStr
			if (recognizer(str)) { //push num into the recognizer function
				cout << str << endl; // if recognizer function returns true, display the result
				
			 }
			if (!myStr.isFull()) { // if myStr is not full, create new str and add into myStr
				for (int i = 0; i < sizeof(E) / sizeof(E[0]); i++) {
					newStr = str + E[i];
					myStr.add(newStr);
				}
			}
			counter++; // after these loops/conditionals, increment the counter to see if 20 iterations have occured 
			if(counter==20) { // give the user a chance to break out of the loop after 20 iterations by entering 'yes'
				cout << "To continue enter 'continue', else enter 'exit': ";
				cin >> userInput;
			}
		}// end of while
	}
	catch (queue::Underflow) { //catch any underflow/ overflow errors and exit the program when caught
		cerr << "[ERROR]: myNumbers is empty." << endl;
		return 0;
	}
	catch (queue::Overflow) {
		cerr << "[ERROR]: myNumbers is full." << endl;
		return 0;
	}
}// end of the main tester funtion 