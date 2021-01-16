#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

class Bst
{
public: 
	Bst* sag;
	Bst* sol;
	int data;
	int soysayisi;

	Bst* elemanEkle(Bst* agac,int sayi);
	Bst* elemanSil(Bst* agac, int sayi);
	void veriYazdir(Bst* agac);
	void yazdir(Bst* agac, string agacAdi, int benimS, int rakipS, int sonuc);
	void cizik();
	void soyHesapla(Bst* agac);
	int max(Bst* agac);
	int min(Bst* agac);
	int toplamHesapla(Bst* agac);
	int karsilastir(Bst* benim, Bst* rakip);
	void odullendir(Bst* benim, Bst* rakip, int sonuc);
	void kazananAcikla(int benimSkor, int rakipSkor, int tur);
	void soySifirla(Bst* agac);
};

#endif

