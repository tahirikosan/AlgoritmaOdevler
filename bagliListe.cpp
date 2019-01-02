#include<iostream>
#include<cstring>
#include<string>
using namespace std;

typedef struct n {
	char ad[10];
	char soyad[20];
	int x;
	n * next;
	n * prev;
}node;


void bastir(node *root);
node *siraliElemanEkle(node *r, int deger, char ad[10], char soyad[20]);
node *elemanSil(node *r, int deger);
int main() {

	node *root = NULL;
	int secenek;

	do {
		cout << "0)Cikis\n1)Ogrenci ekle\n2)Ogrenci sil\n3)Ogrenci sirala\n";
		cout << "Lutfen secenek giriniz : ";
		cin >> secenek;
		if (secenek == 0) {
			break;
		}
		else if (secenek == 1) 
		{
			int no;
			char ad[10];
			char soyad[20];

			cout << "Ogrenci no =  ";
			cin >> no;
			cout << "Ogrenci ad =  ";
			cin >> ad;
			cout << "Ogrenci soyad =  ";
			cin >> soyad;
			root = siraliElemanEkle(root, no, ad, soyad);
		}
		else if (secenek == 2) {
			int no;
			cout << "Silmek istedigin ogrenci no gir:";
			cin >> no;
			root = elemanSil(root, no);
		}
		else if (secenek ==3) {
			bastir(root);
		}
	} while (true);
	
	system("pause");
	return 0;

}

node *elemanSil(node *r, int deger) {

	node *iter = r;
	if (iter != NULL) {
		if (iter->x == deger) {
			node *temp = (node *)malloc(sizeof(node));
			temp = iter->next;
			free(iter);
			return temp;
		}
		node *temp;
		while (iter->next != NULL && iter->next->x != deger) {
			iter = iter->next;
		}
		if (iter->next == NULL) {
			cout << "The student you are looking for is not exist in the structure!\n";
			return r;
		}
		temp = iter->next;
		iter->next = iter->next->next;
		free(temp);
		if (iter->next != NULL) {
			iter->next->prev = iter;
		}
		return r;
	}
	cout << "The student you are looking for is not exist in the structure!\n";
}


node *siraliElemanEkle(node *r, int deger, char ad[10], char soyad[20]) {
	if (r == NULL) {
		node *r = (node *)malloc(sizeof(node));
		r->next = NULL;
		r->x = deger;
		strcpy_s(r->ad, ad);
		strcpy_s(r->soyad, soyad);
		return r;
	}
	if (r->x > deger) {
		node *temp = (node *)malloc(sizeof(node));
		temp->x = deger;
		strcpy_s(temp->ad, ad);
		strcpy_s(temp->soyad, soyad);
		temp->next = r;
		r->prev = temp;
		return temp;
	}
	node *iter = r;
	while (iter->next != NULL && iter->next->x < deger) {
		iter = iter->next;
	}
	node *temp = (node *)malloc(sizeof(node));
	temp->next = iter->next;
	iter->next = temp;
	temp->prev = iter;
	if (temp->next !=NULL) {
		temp->next->prev = temp;
	}
	temp->x = deger;
	strcpy_s(temp->ad, ad);
	strcpy_s(temp->soyad, soyad);
	return r;

}

void bastir(node *root) {
	int i = 1;
	while (root != NULL) {
		cout << "***************************************\n";
		cout << i << ".Student's Informations\n";
		cout << "Number: " << root->x << endl;
		cout << "Name: " << root->ad << endl;
		cout << "Surname: " << root->soyad << endl;
		cout <<"***************************************\n";
		root = root->next;
		i++;
	}

}


