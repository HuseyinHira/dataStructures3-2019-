#include "Bst.h"

#include <iostream>
#include<fstream>
using namespace std;	

int main()
{
	ifstream txtOku("./doc/benim.txt");
	ifstream txtOku2("./doc/rakip.txt");
	int sayi;

	string benimID = "Benim";
	string rakipID = "Rakip";

	Bst* benim = NULL;
	Bst* rakip = NULL;
	
	int benimSkor = 0;
	int rakipSkor = 0;
	int sonuc = 0;
	int tur = 1;
	while (txtOku >> sayi)
	{
		benim = benim->elemanEkle(benim,sayi);
	}
	while (txtOku2 >> sayi)
	{
		rakip = rakip->elemanEkle(rakip, sayi);
	}

	while (tur < 21 && benimSkor < 5 && rakipSkor < 5)
	{
		benim->soyHesapla(benim);
		rakip->soyHesapla(rakip);

		sonuc = benim->karsilastir(benim, rakip);

		if (sonuc == 1)
		{
			benimSkor++;
		}
		else if (sonuc == 0)
		{
			rakipSkor++;
		}

		benim->yazdir(benim, benimID, benimSkor, rakipSkor, sonuc);
		rakip->yazdir(rakip, rakipID, benimSkor, rakipSkor, sonuc);

		benim->odullendir(benim, rakip, sonuc);
		
		benim->kazananAcikla(benimSkor, rakipSkor, tur);

		tur++;
		system("pause");
		system("cls");
	}

	txtOku.close();
	txtOku2.close();

	delete benim;
	delete rakip;

	return 0;
}