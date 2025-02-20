#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include "funzioni.h"

using namespace std;
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

string stringToBin(const string& str) {
    string binario="";
    char c;
    string linea;
    for(int i;i<str.length();i++){
        c=linea[i];
        binario+=bitset<8>(c).to_string()+" ";
    }
    scritturaMessaggio(binario);
    return binario;
}

IpHeader creaDatagram() {
    IpHeader header;
    IpHeader.dsap= 111111110000100000000000110000100101010001111011;
    IpHeader.ssap= 1111111110000000101011000101001011101011;
    IpHeader.thertype=0x8000;
    IpHeader.vers=4;
    IpHeader.hlen=5;
    IpHeader.precedence=3;
    IpHeader.delay=0;
    IpHeader.throughput=0;
    IpHeader.reliability=1;
    IpHeader.cost=1;
    IpHeader.total_length=1500;
    IpHeader.id=1;
    IpHeader.df=0;
    IpHeader.mf=0;
    IpHeader.fragment_offset=0;
    IpHeader.ttl=64;
    IpHeader.protocol=6;
    IpHeader.header_checksum=0000;
    IpHeader.source_ip= 11000000101010000110010011001000;
    IpHeader.dest_ip=11000000101010000000000100000001;
    IpHeader.copy_flag=0;
    IpHeader.option_class=0;
    IpHeader.option_number=0;
    return IpHeader;
}
