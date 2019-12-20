"İLK ÇÖZÜM"
#include "stdafx.h"
#include <stdio.h>
#include <iostream>


using namespace std;

int main() 
{
	int arr[20], i, j, k, size;

	cout <<  "Dizinin eleman sayisini giriniz :" ;
    cin >> size;

	cout << "Elemanlari giriniz :" ;
	for (i = 0; i < size; i++)
		cin >> arr[i];

	cout << "Olusan yeni liste  :" ;
	for (i = 0; i < size; i++) 
	{
		for (j = i + 1; j < size;) 
		{
			if (arr[j] == arr[i]) 
			{
				for (k = j; k < size; k++) 
				{
					arr[k] = arr[k + 1];
				}
				size--;
			}
			else
				j++;
		}
	}

	for (i = 0; i < size; i++)
		cout << arr[i];
	
	system("pause");
	return (0);
}



"İKİNCİ VE ÜÇÜNCÜ ÇÖZÜM"
#include "pch.h"
#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* SortedMerge(Node* a, Node* b);
void FrontBackSplit(Node* source, Node** frontRef, Node** backRef);

// Bagli listeyi sirala
void MergeSort(Node** headRef)
{
	Node* head = *headRef;
	Node* a;
	Node* b;

	// Liste bos ya da tek elemanliysa siralama yapmadan donus yap
	if ((head == NULL) || (head->next == NULL)) {
		return;
	}

	// Verilen listeyi a ve b olmak uzere ikiye bol
	FrontBackSplit(head, &a, &b);

	// Ikiye bolunen listeleri recursive olarak MergeSort fonksiyonuna yolla
	MergeSort(&a);
	MergeSort(&b);

	// Verilen iki listeyi sirala
	*headRef = SortedMerge(a, b);
}

// Sirala ve birlestir
Node* SortedMerge(Node* a, Node* b)
{
	Node* result = NULL;

	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);

	if (a->data <= b->data) {
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else {
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return (result);
}

// Verilen listeyi ikiye bolen fonksiyon
void FrontBackSplit(Node* source, Node** frontRef, Node** backRef)
{
	Node* fast;
	Node* slow;
	slow = source;
	fast = source->next;

	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}

	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}

// Verilen bagli listeyi yazdiran fonksiyon
void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}

// Sirali olan bagli listeden tekrarli sayilari silen fonsksiyon
void removeDuplicatesInSortedList(Node* head)
{
	Node* current = head;
	Node* next_next;

	if (current == NULL)
		return;

	while (current->next != NULL)
	{
		if (current->data == current->next->data)
		{
			next_next = current->next->next;
			delete(current->next);
			current->next = next_next;
		}
		else
			current = current->next;
	}
}

// Sirali olmayan bagli listeden tekrarli sayilari silen fonsksiyon
void removeDuplicatesInUnsortedList(struct Node *start)
{
	struct Node *ptr1, *ptr2, *dup;
	ptr1 = start;

	// Sirasi ile elemanlari sec
	while (ptr1 != NULL && ptr1->next != NULL)
	{
		ptr2 = ptr1;

		// Secilen elemani geri kalan elemanlar ile karsilastir
		while (ptr2->next != NULL)
		{
			// Degeri ayni olan elemanlari sil
			if (ptr1->data == ptr2->next->data)
			{
				dup = ptr2->next;
				ptr2->next = ptr2->next->next;
				delete(dup);
			}
			else
				ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
}

// Bagli listeye eleman ekleme
void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

// Main fonksiyonu - Verilen degerler ile test edilen yer
int main()
{
	// Bos liste olustur
	Node* toBeUnsorted = NULL;
	Node* toBeSorted = NULL;
	
	/* Asagidaki veriler ile bagli listeyi olustur
		10->10->5->2->3->2 */
	push(&toBeUnsorted, 2);
	push(&toBeUnsorted, 3);
	push(&toBeUnsorted, 2);
	push(&toBeUnsorted, 5);
	push(&toBeUnsorted, 10);
	push(&toBeUnsorted, 10);

	push(&toBeSorted, 2);
	push(&toBeSorted, 3);
	push(&toBeSorted, 2);
	push(&toBeSorted, 5);
	push(&toBeSorted, 10);
	push(&toBeSorted, 10);

	cout << "Silme islemi olmadan onceki bagli liste : ";
	printList(toBeUnsorted);

	removeDuplicatesInUnsortedList(toBeUnsorted);

	cout << "\nSilme islemlerinden sonraki bagli liste : ";
	printList(toBeUnsorted);

	cout << "\nSiralamadan once bagli liste : ";
	printList(toBeSorted);

	// Bagli listeyi sirala (Merge Sort)
	MergeSort(&toBeSorted);

	cout << "\nSiralamadan sonra bagli liste : ";
	printList(toBeSorted);

	// Tekrarlananan sayilari sil
	removeDuplicatesInSortedList(toBeSorted);

	cout << "\nTekrarkli sayilarin silinmesinden sonraki bagli liste : ";
	printList(toBeSorted);

	return 0;
}
