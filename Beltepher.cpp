#include <iostream>
#include "Beltepher.h"
using namespace std;

int main() {
	Beltepher bt;
	char msg[99];
	string rotmsg, input, encrypted, shift;
	int rots, pos, sz;

	cout << "Enter the string: ";
	cin >> input;
	cout << "By how many spaces would you like to rotate? ";
	cin >> rots;
	encrypted = bt.analyzeString(input);
	rotmsg = bt.ROT(encrypted, rots);
	sz = rotmsg.length();
	cout << "The rotated message is " << sz << " characters long, where would you like to hide the amount of characters rotated? ";
	cin >> pos;
	shift = bt.hideShift(rotmsg, rots, pos);
	cout << "Your Beltepher string is: ";
	cout << shift;
	
	system("pause > null");
	return 0;
}