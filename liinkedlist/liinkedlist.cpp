#include<iostream>
#include<string.h>
using namespace std;

class Node
{
public:
	int noMhs;
	char nama[20];
	Node* next;
};

class List
{
	Node* START;

public:
	List();
	void addNode();
	bool Search(int nim, Node** current, Node** previous);
	bool listEmpty();
	bool delNode(int element);
	void traverse();
};
List::List()
{
	START = NULL;
}
void List::addNode()/*Menambah sebuah Node kedalam list*/
{
	int nim;
	char nm[20];
	cout << "\nMasukkan Nomor Mahasiswa: ";
	cin >> nim;
	cout << "\nMasukkan Nama: ";
	cin >> nm;

	Node* nodeBaru = new Node;
	nodeBaru->noMhs = nim;
	strcpy_s(nodeBaru->nama, nm);

	if (START == NULL || nim <= START->noMhs)
	{
		if ((START != NULL) && (nim == START->noMhs))
		{
			cout << "\nDuplikasi noMhs tidak diijinkan\n";
			return;
		}
		nodeBaru->next = START;
		START = nodeBaru;
		return;
	}
	Node* privious, * current;

	current = START;
	privious = START;

	while ((current != NULL) && (nim >= current->noMhs))
	{
		if (nim == current->noMhs)
		{
			cout << "\nDuplikasi noMhs tidak diijinkan\n";
			return;
		}
		privious = current;
		current = current->next;

	}
	/*Jika loop diatas diekekusi, previous dan current akan menepati posisi dimana akan ditepatkan*/
	nodeBaru->next = current;
	privious->next = nodeBaru;

}

bool List::listEmpty()
{
	if (START == NULL)
		return true;
	else
		return false;
}
bool List::delNode(int nim)/*Mengahapus node dari dalam list*/
{
	Node* current, * previous;
	if (Search(nim, &previous, &current) == false)
		return false;
	previous->next = current->next;
	if (current == START)
		START = START->next;

	delete current;
	return true;
}
/*Check apakah node yang dimaksud ada didalam list atau tidak*/
bool List::Search(int nim, Node** privious, Node** current)
{
	*privious = START;
	*current = START;
	while ((*current != NULL) && (nim != (*current)->noMhs))
	{
		*privious = *current;
		*current = (*current)->next;
	}
	return (*current != NULL);
}
void List::traverse()/*Menggunjungi dan membaca data dalam list*/
{
	if (listEmpty())
		cout << "\nList Kosong\n";
	else
	{
		cout << endl << "Data didalam list adalah:" << endl;
		Node* currentNode;
		for (currentNode = START; currentNode != NULL; currentNode->next)
		{
			cout << currentNode->noMhs << " " << currentNode->nama << "\n";
		}
		cout << endl;

	}


}

int main()
{
	List mhs;
	int nim;
	char ch;
	while (1)
	{
		cout << endl << "Menu";
		cout << endl << "1. Menambah data kedalam list" << endl;
		cout << "2. Menghapus data dari dalam list" << endl;
		cout << "3. Menampilkan semua data didalam list" << endl;
		cout << "4. Mencari data dalam list" << endl;
		cout << "5. keluar" << endl;
		cout << endl << "Masukkan pilihan (1-5): ";
		cin >> ch;
		switch (ch)
		{
		case '1':
		{
			mhs.addNode();
		}
		break;

		case '2':
		{
			if (mhs.listEmpty())
			{
				cout << endl << "List Kosong" << endl;
				break;
			}
			cout << endl << "\nMasukkan no mahasiswa yang akan dihapus : ";
			cin >> nim;
			if (mhs.delNode(nim) == false)
				cout << endl << "Data tidak ditemukan" << endl;
			else
				cout << endl << "Data dengan nomor mahasiswa " << nim << "berhasil dihapus " << endl;
		}
		break;
		case '3':
		{
			mhs.traverse();
		}
		break;

		case '4':
		{
			if (mhs.listEmpty() == true)
			{
				cout << "\nList Kosong\n";
				break;
			}
			Node* previous, * current;
			cout << endl << "Masukkan no mahasiswa yang dicari : ";
			cin >> nim;
			if (mhs.Search(nim, &previous, &current) == false)
				cout << endl << "Data tidak ditemukan" << endl;
			else
			{
				cout << endl << "Data ditemukan" << endl;
				cout << "\nNo Mahasiswa: " << current->noMhs;
				cout << "\n\nNama: " << current->nama;
				cout << "\n";
			}
		}
		break;
		case '5':
		{
			exit(0);
		}
		break;
		default:
		{
			cout << "Pilihan salah !." << endl;
		}
		break;
		}
	}
}