#include <iostream>
using namespace std;

string ROT(string message, string rotatedmsg, int rotate) {
	for(int i = 0; i < message.length(); i++){
		if (isupper(message[i])) {
			rotatedmsg += (message[i] - 'A' + rotate) % 26 + 'A';
		} else if (islower(message[i])) {
			rotatedmsg += (message[i] - 'a' + rotate) % 26 + 'a';
		}
	}
	return rotatedmsg;
}

int main() {
	string msg, rotmsg;
	int rots;
	cout << "What do you want to encrypt? ";
	cin >> msg;
	cout << "By how many spaces? ";
	cin >> rots;
	cout << ROT(msg, rotmsg, rots) << "\n";
	return 0;
}