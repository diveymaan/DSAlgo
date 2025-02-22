// LinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
struct Node
{
	int data; 
	Node* next;
	};

void push(Node** head, int val)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = val;
	temp->next = *head;
	*head = temp;
}

void displayNode(Node **head)
{
	Node* temp = *head;
	while (temp != NULL)
	{
		cout << " " << temp->data;
		temp = temp->next;
	}
	cout << "  ..NullPtr \n";
}

void reverseList(Node **head)
{
	Node *prev = NULL;
	Node *curr = *head;
	//Node *next = curr->next;
	while (curr != NULL)
	{
		Node *next = curr->next;
		curr->next = prev;
		prev = curr;

		curr = next;
		//next = next->next;
	}
	*head = prev->next;
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	Node *head = NULL;
	for (int i = 9; i >=0; i--)
		push(&head, arr[i]);
	cout << "\n Before Reversal: ";
	//displayNode(&head);
	reverseList(&head);
	cout << "\n After Reversal: ";
	displayNode(&head);
	getchar();
    return 0;
}

