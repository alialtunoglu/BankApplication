#ifndef BankLib_H_
#define BankLib_H_
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
class Banka {
public:
	int hesapNoo;
	string ad, soyad;
	int bakiye;
};
ostream& operator<<(ostream& cikti, Banka& obj1);
void hesapekle();
void hesapgoster(int hspNo);
void hesapguncelle(int hspNo);
void hesapsil(int hspNo);
void parayatir(int hspNo);
void paracek(int hspNo);
void tumlisteyigoster();

#endif