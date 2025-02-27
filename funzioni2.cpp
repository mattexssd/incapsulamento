#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include "funzioni.h"
#include <bitset>

using namespace std;

string leggiMessaggio(){
    ifstream file("messaggio.txt");
    if (!file) {
        cout << "Errore nell'apertura del file " << endl;
        return "";
    }
    string message, line;
    while (getline(file, line)) {
        message += line + "\n";
    }
    file.close();
    return message;
}

void scritturaMessaggio(const string& nomeFile, const string& contenuto) {
    ofstream file(nomeFile);
    if (!file) {
        cout << "Errore nella scrittura del file " << nomeFile << endl;
        return;
    }
    file << contenuto;
    file.close();
}

string stringToBin(const string& str) {
    string binario = "";
    for (size_t i = 0; i < str.length(); i++) {
        binario += bitset<8>(str[i]).to_string() + " ";
    }
    scritturaMessaggio("frame.txt", binario);
    return binario;
}

// Funzione per calcolare il checksum IP (somma dei 16 bit)
unsigned short ipChecksum(const unsigned short *buf, int length) {
    unsigned long sum = 0;
    while (length > 1) {
        sum += *buf++;
        length -= 2;
    }
    if (length == 1) {
        sum += *(unsigned char *)buf;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    return ~sum;
}

// Funzione per calcolare il CRC (Cyclic Redundancy Check)
unsigned int crc32(const string& data) {
    unsigned int crc = 0xFFFFFFFF;
    for (char c : data) {
        crc ^= (unsigned char)c;
        for (int i = 0; i < 8; i++) {
            if (crc & 1) {
                crc = (crc >> 1) ^ 0xEDB88320;
            } else {
                crc >>= 1;
            }
        }
    }
    return ~crc;
}

IpHeader creaDatagram() {
    IpHeader header;
    
    // Esempio di frame Ethernet
    header.dsap = "0xAA";  // DSAP esempio
    header.ssap = "0xAB";  // SSAP esempio
    header.ethertype = 0x8000;  // Type per IPv4
    
    // Impostazioni IP Header
    header.vers = 4;
    header.hlen = 5;
    header.precedence = 3;
    header.delay = 0;
    header.throughput = 0;
    header.reliability = 1;
    header.cost = 1;
    header.total_length = 1500;
    header.id = 1;
    header.df = 0;
    header.mf = 0;
    header.fragment_offset = 0;
    header.ttl = 64;
    header.protocol = 6;  // TCP
    header.header_checksum = "0";  // Verrà calcolato
    header.source_ip = "192.168.0.1";  // Esempio di IP
    header.dest_ip = "192.168.0.2";  // Esempio di IP
    header.copy_flag = "0";
    header.option_class = "0";
    header.option_number = "0";
    
    // Calcolo checksum
    unsigned short checksum = ipChecksum((unsigned short*)&header, sizeof(header));
    header.header_checksum = to_string(checksum);
    
    // Restituisci l'header IP
    return header;
}
