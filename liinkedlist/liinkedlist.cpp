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