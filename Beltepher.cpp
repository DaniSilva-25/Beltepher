#include <iostream>
#include "Beltepher.h"
using namespace std;

int main() {
	Beltepher bt;
	char msg[99];
	string rotmsg, input;
	int rots;

	cout << "Enter the string: ";
	cin >> input;
	bt.analyzeString(input);
	
	system("pause");
	return 0;
}