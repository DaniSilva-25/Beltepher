#include <iostream>
using namespace std;

int main(){
    char message[99];
    cin.get(message, 99);
    message[99] = '\n';
    cout << message;
}