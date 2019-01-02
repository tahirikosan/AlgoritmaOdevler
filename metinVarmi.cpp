#include<iostream>
#include<cstring>
using namespace std;



void diziYap(char dizi[2][6]);
bool metinVarmi(char metin[6], char dizi[2][6]);
int main() {


	char dizi[2][6] = {};
	char metin[6];

	diziYap(dizi);

	if (metinVarmi(metin, dizi) == 1) {
		cout << "Aradiginiz eleman bu dizide vardir";
	}
	else {
		cout << "Aradiginiz eleman bu dizide yoktur";
	}


    system("PAUSE");
	return 0;
}


void diziYap(char dizi[2][6]) {

	for (int i = 0; i < 2; i++) {
		cout << "Lutfen dizinin " << i+1 << ". elemanini giriniz:";
		cin >> dizi[i];
		cout << "\n";
	}
}

bool metinVarmi(char metin[6], char dizi[2][6]) {

	cout << "Lutfen aramak istediginiz kelimeyi giriniz.";
	cin >> metin[6];

	for (int i = 0; i < 2; i++) {
		if (strcmp(dizi[i], metin) == 0){
			return true;
		}
	}
	return false;
}



