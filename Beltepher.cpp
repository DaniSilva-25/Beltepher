#include <iostream>
#include <fstream>
#include "Beltepher.h"
using namespace std;

void welcome(){
	cout << ">=>>=>               >=>   >=>\n";
	cout << ">>   >=>             >=>   >=>                      >=>\n";
	cout << ">>    >=>   >==>     >=> >=>>==>   >==>    >=> >=>  >=>        >==>    >> >==> \n";
	cout << ">==>>=>   >>   >=>   >=>   >=>   >>   >=>  >>   >=> >=>>=>   >>   >=>   >=>\n";
	cout << ">>    >=> >>===>>=>  >=>   >=>   >>===>>=> >>   >=> >=>  >=> >>===>>=>  >=>\n";
	cout << ">>     >> >>         >=>   >=>   >>        >=> >=>  >>   >=> >>         >=>\n";
	cout << ">===>>=>   >====>   >==>    >=>   >====>   >=>      >=>  >=>  >====>   >==>\n";
	cout << "                                           >=>\n";
	system("pause");
}

int main() {
	Beltepher bt;
	ofstream out;
	out.open("RecentStrings.txt", ios::out|ios::app);
	system("title Beltepher - Beltech Corporation");
	welcome();
	char msg[99];
	string rotmsg, input, encrypted, shift;
	int rots, pos, sz;

	cout << "Enter a word: ";
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
	out << input << "\t" << shift << "\n";
	out.close();
	
	system("pause > null");
	return 0;
}