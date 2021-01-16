#include "Bst.h"

#include <iostream>
using namespace std;

Bst* Bst::elemanEkle(Bst* agac,int sayi)
{
	if (agac == NULL)
	{
		Bst* root = new Bst();
		root->sag = NULL;
		root->sol = NULL;
		root->data = sayi;
		root->soysayisi = 0;
		return root;
	}
	if (agac->data < sayi)
	{
		agac->sag = elemanEkle(agac->sag, sayi);
		return agac;
	}
	else
	{
		agac->sol = elemanEkle(agac->sol, sayi);
		return agac;
	}
}

void Bst::soyHesapla(Bst* agac)
{
	if (agac == NULL)
	{
		return;
	}

	soyHesapla(agac->sol);
	soyHesapla(agac->sag);

	if (agac->sag != NULL)
	{
		agac->soysayisi += agac->sag->soysayisi + 1;
	}
	if (agac->sol != NULL)
	{
		agac->soysayisi += agac->sol->soysayisi + 1;
	}
}

void Bst::soySifirla(Bst* agac)
{
	if (agac == NULL)
	{
		return;
	}
	soySifirla(agac->sol);
	soySifirla(agac->sag);
	agac->soysayisi = 0;
}

int Bst::toplamHesapla(Bst* agac)
{
	if (agac == NULL)
	{
		return 0;
	}
	int toplamSoy = agac->soysayisi;

	toplamSoy += toplamHesapla(agac->sol);
	toplamSoy += toplamHesapla(agac->sag);

	return toplamSoy;
}

void Bst::veriYazdir(Bst* agac)
{
	if (agac == NULL)
	{
		return;
	}
	
	veriYazdir(agac->sol);
	veriYazdir(agac->sag);

	cout << "<" << agac->data << "," << agac->soysayisi << "> ";
}

void Bst::cizik()
{
	cout << "--------------------------" << endl << endl;
}

void Bst::yazdir(Bst* agac, string agacAdi, int benimS, int rakipS, int sonuc)
{
	cout << agacAdi << " Agac Postorder :" << endl;
	int toplamSoy = 0;
	toplamSoy = toplamHesapla(agac);
	veriYazdir(agac);
	cout << endl;
	cout << agacAdi << " Agac Toplam Soy Sayisi : " << toplamSoy << endl;

	if (agacAdi == "Benim")
	{
		cizik();
	}
	else
	{
		cout << endl << endl;
		if (sonuc == 1)
		{
			cout << "-- TEBRIKLER TURU KAZANDINIZ --" << endl << endl;
		}
		else if (sonuc == 0)
		{
			cout << "-- MAALESEF TURU KAYBETTINIZ --" << endl << endl;
		}
		else
		{
			cout << "-- BERABERE --" << endl << endl;
		}

		cout << "SKOR" << endl;
		cout << "Benim : " << benimS << endl;
		cout << "Rakip : " << rakipS << endl << endl;
	}
}

int Bst::max(Bst* agac)
{
	while (agac->sag != NULL)
	{
		agac = agac->sag;
	}
	return agac->data;
}

int Bst::min(Bst* agac)
{
	while (agac->sol != NULL)
	{
		agac = agac->sol;
	}
	return agac->data;
}

Bst* Bst::elemanSil(Bst* agac, int sayi)
{
	if (agac == NULL)
	{
		return NULL;
	}
	else if (agac->data == sayi)
	{
		if (agac->sag == NULL && agac->sol == NULL)
		{
			return NULL;
		}
		if (agac->sol != NULL)   // kural olarak sol cocugun en sagina gidiliyor
		{
			agac->data = max(agac->sol);
			agac->sol = elemanSil(agac->sol, max(agac->sol));
			return agac;
		}
		else // gene de sol bulunamamasi durumu icin sag cocugun en soluna gidilme kodunu yazdim
		{
			agac->data = min(agac->sag);
			agac->sag = elemanSil(agac->sag, min(agac->sag));
			return agac;
		}
	}
	else if (agac->data < sayi)
	{
		agac->sag = elemanSil(agac->sag, sayi);
		return agac;
	}
	else
	{
		agac->sol = elemanSil(agac->sol, sayi);
		return agac;
	}
}

int Bst::karsilastir(Bst* benim, Bst* rakip)
{
	if (toplamHesapla(benim) > toplamHesapla(rakip))
	{
		return 0;
	}
	if (toplamHesapla(benim) < toplamHesapla(rakip))
	{
		return 1;
	}
	if (toplamHesapla(benim) == toplamHesapla(rakip))
	{
		return 2;
	}
}

void Bst::kazananAcikla(int benimSkor, int rakipSkor, int tur)
{
	if (benimSkor == 5)
	{
		cout << "-- KAZANDINIZ --" << endl;
	}
	else if (rakipSkor == 5)
	{
		cout << "-- KAYBETTTINIZ --" << endl;
	}
	else if (tur == 20)
	{
		if (benimSkor > rakipSkor)
		{
			cout << "-- KAZANDINIZ --" << endl;
		}
		else if (benimSkor < rakipSkor)
		{
			cout << "-- KAYBETTTINIZ --" << endl;
		}
		else
		{
			cout << "-- BERABERE -- " << endl;
		}
	}
}

void Bst::odullendir(Bst* benim, Bst* rakip, int sonuc) 
{
	if (sonuc == 1)
	{
		benim = benim->elemanEkle(benim, max(rakip));
		rakip = rakip->elemanSil(rakip, max(rakip));

		rakip = rakip->elemanEkle(rakip, benim->data);
		benim = benim->elemanSil(benim, benim->data);
		soySifirla(benim);
		soySifirla(rakip);
	}
	else if (sonuc == 0)
	{
		rakip = rakip->elemanEkle(rakip, max(benim));
		benim = benim->elemanSil(benim, max(benim));

		benim = benim->elemanEkle(benim, rakip->data);
		rakip = rakip->elemanSil(rakip, rakip->data);
		soySifirla(benim);
		soySifirla(rakip);
	}
	else
	{
		benim = benim->elemanEkle(benim, rakip->data);
		rakip = rakip->elemanSil(rakip, rakip->data);

		
		rakip = rakip->elemanEkle(rakip, benim->data);
		benim = benim->elemanSil(benim, benim->data);
		soySifirla(benim);
		soySifirla(rakip);
	}
}
