#pragma 
#include <string>

namespace std {
	string ROT(char message[99], int rotate) {
		string rotatedmsg;
		for (int i = 0; i < 99; i++) {
			if (!isdigit(message[i])){
				if (isupper(message[i])) {
					rotatedmsg += (message[i] - 'A' + rotate) % 26 + 'A';
				}
				else if (islower(message[i])) {
					rotatedmsg += (message[i] - 'a' + rotate) % 26 + 'a';
				}
			}
		}
		return rotatedmsg;
	}
}