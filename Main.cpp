#include "snowman.hpp"

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
	cout<<"Let's build a now man!" << endl;
	cout<<"For the input 42133244 we get:"<<endl;
	cout <<ariel::snowman(42133244) << endl; 
	cout<<"For the input 24132413 we get:"<<endl;
	cout <<ariel::snowman(24132413) << endl; 
	cout<<"For the input 11332211 we get:"<<endl;
	cout <<ariel::snowman(11332211) << endl; 
	cout<<"For the input 44223311 we get:"<<endl;
	cout <<ariel::snowman(44223311) << endl; 
	cout<<"For the input 24112342 we get:"<<endl;
	cout <<ariel::snowman(24112342) << endl; 
	cout<<"For the input 11223343 we get:"<<endl;
	cout <<ariel::snowman(11223343) << endl; 
	
	cout<<"Now lets check if we get errors correctly." << endl;
	cout<<"with the input 12123 we should get execption for being to short lets try!" <<endl;
	try {
		cout << ariel::snowman(12123) << endl; 
	} catch (exception& ex) {
	 	cout << "   caught exception: " << ex.what() << endl;  // should print "Invalid code '5'"
	}
	cout<<"Now lets check with too long instructions with 123412341"<<endl;
	try {
		cout << ariel::snowman(123412341) << endl;   // Exception - not a valid code
	} catch (exception& ex) {
	 	cout << "   caught exception: " << ex.what() << endl;  // should print "Invalid code '5'"
	cout<<"Lastly, last check if it finds a wrong instructions with 23115422"<<endl;
	}
	try {
		cout << ariel::snowman(23115422) << endl;   // Exception - not a valid code
	} catch (exception& ex) {
	 	cout << "   caught exception: " << ex.what() << endl;  // should print "Invalid code '5'"
	}
	cout<<"All done! hope you enjoyed!"<<endl;

}