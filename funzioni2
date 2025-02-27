#ifndef FUNZIONI_H
#define FUNZIONI_H
#include <string>
using namespace std;

// Prototipi delle funzioni
string leggiMessaggio();
void scritturaMessaggio(const string& nomeFile, const string& contenuto);
string charToBin(char c);
string stringToBin(const string& str);
string binarioAStringa(const string& bin);

// Funzioni per il calcolo del checksum e CRC
unsigned short ipChecksum(const unsigned short *buf, int length);
unsigned int crc32(const string& data);

// Struttura IpHeader
struct IpHeader {
    string dsap;
    string ssap;
    int ethertype;
    int vers;
    int hlen;
    int precedence;
    int delay;
    int throughput;
    int reliability;
    int cost;
    int total_length;
    int id;
    int df;
    int mf;
    int fragment_offset;
    int ttl;
    int protocol;
    string header_checksum;
    string source_ip;
    string dest_ip;
    string copy_flag;
    string option_class;
    string option_number;
};

// Funzione per creare il datagram
IpHeader creaDatagram();
#endif
