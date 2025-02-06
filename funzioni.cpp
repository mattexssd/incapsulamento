#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include "funzioni.h"

using namespace std;

string charToBin(char c) {
    return bitset<8>(c).to_string();
}

string stringToBin(const string& str) {
    string binary;
    for (char c : str) {
        binary += charToBin(c) + " ";
    }
    return binary;
}

string leggiMessaggio(){
    ifstream file("messaggio.txt");
    if (!file) {
        cout << "Errore nell'apertura del file " <<endl;
        return "";
    }
    string message, line;
    while (getline(file, line)) {
        message += line + "\n";
    }
    file.close();
    return message;
}

void scritturaMessaggio(string& binaryMessage) {
    ofstream file("frame.txt");
    if (!file) {
        cout << "Errore nella scrittura del file " << "frame.txt" << endl;
        return;
    }
    file << binaryMessage;
    file.close();
}

IpHeader creaDatagram() {
    IpHeader header;
    header.versione;
    header.headerLength;
    header.typeOfService;
    header.totalLenght;
    header.identificatore;
    header.flag;
    header.offset;
    header.ttl;
    header.protocollo;
    header.checksum;
    header.indirizzoMit;
    header.indirizzoDest;
    return header;
}
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
