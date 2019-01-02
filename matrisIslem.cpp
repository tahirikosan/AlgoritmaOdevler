#include<iostream>
using namespace std;



void matrisYaz(int matris[][10]);
void matrisOku(int matris[][10]);
void matrisCarp(int matris_1[][10], int matris_2[][10], int matrisCarpimi[][10]);

int main() {


	int matris_1[10][10] = {};
	int matris_2[10][10] = {};
	int matrisCarpimi[10][10] = {};

	cout << "Birinci Matris icin degerler\n";
	matrisOku(matris_1);
	cout << "Ýkinci Matris icin degerler\n";
	matrisOku(matris_2);

	matrisCarp(matris_1, matris_2, matrisCarpimi);
	cout << "********Matrisler carpimi********\n";
	matrisYaz(matrisCarpimi);

		system("PAUSE");
		return 0;
}

//Kullanýcýdan deðerleri alarak matris yapar 10x10'luk matris yapar.
void matrisOku(int matris[10][10]) {
	int n;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << "Lutfen " << i + 1 << ".satirin  " << j + 1 << ".sutun degerini giriniz:";
			cin >> n;
			matris[i][j] = n;
		}
	}
}

//10x10'luk matris_1 ile 10x10'luk matris_2'yi çarpar ve 3. parametre olarak girilen 10x10'luk matrise deðerleri atar.
void matrisCarp(int matris_1[][10], int matris_2[][10], int matrisCarpimi[][10]) {
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			matrisCarpimi[i][j] = 0;
		}
	}

	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			for (int z = 0; z < 10; z++) {
				matrisCarpimi[x][y] += matris_1[x][z] * matris_2[z][y];
			}
		}
	}
}

//Parametre olarak girilen 10x10 luk matrisi ekrana yazdýrýr.
void matrisYaz(int matris[][10]){

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << matris[i][j] << " ";
		}
		cout << "\n";
	}
}