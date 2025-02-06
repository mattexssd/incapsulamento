#include <iostream>
#include <string>
#include "funzioni.cpp"

using namespace std;

int main() {
    string input;
    cin>>input;
    string output = stringToBin(input);
    string binario;
    cout << "Stringa originale: " << input << endl;
    cout << "Stringa in binario: " << output << endl;
    leggiMessaggio();
    scritturaMessaggio(binario);
}
