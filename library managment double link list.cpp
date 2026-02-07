#include <iostream>
#include <string>
using namespace std;

struct Node{
	int isbn;          
	string title;      
	string author;
	int year;
	bool status;       
	Node *p, *n;
};

class Library{
	private:
		Node *start, *tem, *curn;
	public:
		int bN;

		Library(){
			start = NULL;
			bN = 0;
		}

	
	void insert(){
		bN++;
		tem = new Node;

		cout << "\n\t LIBRARY SYSTEM \t\n";
		cout << "Enter Book Title:\n";
		cin.ignore();
		getline(cin, tem->title);

		cout << "Enter Author Name:\n";
		getline(cin, tem->author);

		cout << "Enter Publication Year:\n";
		cin >> tem->year;

		tem->isbn = bN;
		tem->status = false;
		tem->p = NULL;
		tem->n = NULL;

		if(start == NULL){
			start = tem;
		}
		else{
			curn = start;
			while(curn->n != NULL){
				curn = curn->n;
			}
			tem->p = curn;
			curn->n = tem;
		}
	}

	
	void display(){
		if(start == NULL){
			cout << "No books available\n";
			return;
		}

		curn = start;
		while(curn->n != NULL)
			curn = curn->n;

		cout << "\n LIBRARY BOOK LIST \n";
	cout << "\n--------------------------------------------------------------\n";
cout << " Status     ISBN     Book Title        Author          Year\n";
cout << "--------------------------------------------------------------\n";

		while(curn != NULL){
		if(curn->status){
	cout << " Issued     ";
}else{
	cout << " Available  ";
}

cout << curn->isbn << "       "
     << curn->title << "        "
     << curn->author << "        "
     << curn->year << endl;


			curn = curn->p;
		}
	}

	
	void modify(){
		int mid;
		cout << "\nEnter ISBN to issue book:\n";
		cin >> mid;

		curn = start;
		while(curn != NULL){
			if(curn->isbn == mid){
				curn->status = true;
				cout << "Book issued successfully\n";
				return;
			}
			curn = curn->n;
		}
	}

	void deletet(){
		if(start == NULL){
			cout << "Library is empty\n";
			return;
		}

		int did;
		cout << "\nEnter ISBN to delete book:\n";
		cin >> did;

		curn = start;
		tem = NULL;

		while(curn != NULL){
			if(curn->isbn == did){
				if(curn == start){
					start = start->n;
					delete curn;
					return;
				}else{
					tem->n = curn->n;
					delete curn;
					return;
				}
			}
			tem = curn;
			curn = curn->n;
		}
	}
};
int main(){
	Library lib;
	int choice;

	do{
		cout << "\n1.Insert Book";
		cout << "\n2.Display Books";
		cout << "\n3.Issue Book";
		cout << "\n4.Delete Book";
		cout << "\n5.End\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch(choice){
			case 1:
				lib.insert();
				break;
			case 2:
				lib.display();
				break;
			case 3:
				lib.display();
				lib.modify();
				break;
			case 4:
				lib.display();
				lib.deletet();
				break;
			case 5:
				cout << "End\n";
				break;
		}
	}while(choice != 5);

	return 0;
}

