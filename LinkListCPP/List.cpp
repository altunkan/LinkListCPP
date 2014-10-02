#include "List.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

List::List(string listName) {
	head = NULL;
	current = NULL;
	temp = NULL;
	this->listName = listName;
}

void List::addItem(int data) {
	cout << "Trying to add " << data << " into list: ";
	printRed(listName);
	cout << "\n";
	node *newNode = new node;
	newNode->data = data;
	newNode->next = NULL;

	if (head == NULL) {
		head = newNode;
	}
	else {
		current = head;
		while (current->next != NULL) {
			current = current->next;
		}

		current->next = newNode;
	}
	cout << data << " is added into the list: ";
	printRed(listName);
	cout << "\n";
}

void List::printList() {
	cout << "\n";
	cout << "Printing the list: ";
	printRed(listName);
	cout << "\n";
	cout << "--------------\n";
	current = head;
	while (current != NULL) {
		cout << current->data << "\n";
		current = current->next;
	}
	cout << "\n";
}

void List::printRed(std::string text) {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO defaultScreenInfo;
	GetConsoleScreenBufferInfo(out, &defaultScreenInfo);
	SetConsoleTextAttribute(out,
		FOREGROUND_RED | FOREGROUND_INTENSITY
		);

	cout << text;
	SetConsoleTextAttribute(out, defaultScreenInfo.wAttributes);
}

void List::deleteItem(int data) {
	if (head == NULL) {
		cout << "List is empty!\n";
		return;
	}

	cout << "Trying to delete " << data << " from list: ";
	printRed(listName);
	cout << "\n";
	node *deleteNode = new node;

	current = head;
	temp = head;

	while (current != NULL && current->data != data) {
		temp = current;
		current = current->next;
	}

	if (current == NULL) {
		cout << data << " is not found in the list: ";
		printRed(listName);
		cout << "\n";
		return;
	}

	deleteNode = current;
	current = current->next;
	temp->next = current;
	if (head == deleteNode) {
		head = head->next;
	}
	delete deleteNode;

	cout << data << " is deleted from list: ";
	printRed(listName);
	cout << "\n";
}

void List::deleteAllItems() {
	current = head;
	while (current != NULL) {
		temp = current;
		current = current->next;
		delete temp;
	}
	temp = NULL;
	head = NULL;
	cout << "All items are deleted from list: ";
	printRed(listName);
	cout << "\n";
}

void List::reverseList() {
	if (head == NULL) {
		cout << "List is empty!\n";
		return;
	}

	node *prev = new node;
	prev = NULL;
	current = head;
	while (current != NULL) {
		temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
	}
	head = prev;
}