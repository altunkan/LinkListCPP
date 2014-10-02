#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream> 
#include "List.h"

using namespace std;

template <typename T>
string NumberToString(T Number)
{
	stringstream ss;
	ss << Number;
	return ss.str();
}

template <typename T>
T StringToNumber(const string &Text)
{                             
	stringstream ss(Text);
	T result;
	return ss >> result ? result : 0;
}

string getChoiceFromUser() {
	string choice;
	cout << "\n";
	cout << "Menu\n";
	cout << "------------\n";
	cout << "\t1.Add\n";
	cout << "\t2.Delete\n";
	cout << "\t3.Reverse\n";
	cout << "\t4.Print\n";
	cout << "\t5.Delete All Items\n";
	cout << "\t0.Exit\n";
	while (1) {
		cout << "Please Select: ";
		getline(cin, choice);
		if (choice.compare("1") != 0 && choice.compare("2") != 0 && choice.compare("3") != 0 && choice.compare("4") != 0 && choice.compare("5") != 0
			&& choice.compare("0") != 0) {
			cout << "Please Just Enter 1,2,3,4,5 as Your Choice!\n";
		}
		else {
			break;
		}
	}
	return choice;
}

int main() {
	string listName;
	string input;
	int item;
	cout << "Enter a list name: ";
	getline(cin, listName);
	List l(listName);
	cout << "List is created!\n";
	string choice;
	while (choice.compare("0") != 0) {
		choice = getChoiceFromUser();
		if (choice.compare("1") == 0) {
			cout << "Enter an integer: ";
			getline(cin, input);
			item = StringToNumber<int>(input);
			if (item == 0) {
				cout << "\n" << input << " is not an integer!\n";
			}
			else {
				l.addItem(item);
			}
		}
		else if (choice.compare("2") == 0) {
			cout << "Enter an integer: ";
			getline(cin, input);
			item = StringToNumber<int>(input);
			if (item == 0) {
				cout << "\n" << input << " is not an integer!\n";
			}
			else {
				l.deleteItem(item);
			}
		}
		else if (choice.compare("3") == 0) {
			l.reverseList();
		}
		else if (choice.compare("4") == 0) {
			l.printList();
		}
		else if (choice.compare("5") == 0) {
			l.deleteAllItems();
		}
		else {
			break;
		}
	}
	
}

