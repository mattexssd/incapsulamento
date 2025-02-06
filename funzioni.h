#ifndef FUNZIONI_H
#define FUNZIONI_H
#include <string>
using namespace std;
//prototipi funzioni
string leggiMessaggio();
void scritturaMessaggio(const string& nomeFile, const string& contenuto);
string charToBin(char c);
string stringToBin(const string& str);
string binarioAStringa(const string& bin);
//struct IpHeader
struct IpHeader {
    string versione;
    string headerLength;
    string typeOfService;
    string totalLenght;
    string identificatore;
    string flag;
    string offset;
    string timeToLive;
    string protocollo;
    string checksum;
    string indirizzoMit;
    string indirizzoDest;
    void creaDatagram();
};

#endif
