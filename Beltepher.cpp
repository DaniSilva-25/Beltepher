#include <iostream>
#include "ROT.h"
using namespace std;

int main() {
	char msg[99];
	string rotmsg;
	int rots;
	cout << "What do you want to encrypt? ";
	cin.getline(msg, 99);
	cout << "By how many spaces? ";
	cin >> rots;
	rotmsg = ROT(msg, rots);
	cout << rotmsg << "\n";
	return 0;
}