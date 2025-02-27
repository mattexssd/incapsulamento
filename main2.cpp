#include <iostream>
#include <string>
#include "funzioni.cpp"

using namespace std;

int main() {
    string input;
    cout << "Inserisci una stringa: ";
    cin >> input;
    
    // Conversione della stringa in binario
    string output = stringToBin(input);
    cout << "Stringa originale: " << input << endl;
    cout << "Stringa in binario: " << output << endl;

    // Lettura e scrittura del messaggio
    string messaggio = leggiMessaggio();
    cout << "Messaggio letto: " << messaggio << endl;

    scritturaMessaggio("frame_output.txt", output);  // Salva il messaggio binario su un file
    return 0;
}
