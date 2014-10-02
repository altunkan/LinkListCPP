#ifndef _LIST_H_
#define _LIST_H_
#include <string>

class List {
	private:
		struct node {
			int data;
			node *next;
		};
		std::string listName;
		node *head;
		node *temp;
		node *current;

	public:
		List(std::string listName);
		void printList();
		void addItem(int data);
		void printRed(std::string text);
		void deleteItem(int data);
		void deleteAllItems();
		void reverseList();
};

#endif