#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* pNext;
};

struct List {
	Node* pHead;
};

Node* CreateNode(int val) {
	Node* newnode = new Node();
	newnode->data = val;
	newnode->pNext = nullptr;

	return newnode;
}

void AddTail(List& l, int val) {
	Node* newnode = CreateNode(val);

	if (l.pHead == nullptr) {
		l.pHead = newnode;
		return;
	}

	Node* temp = l.pHead;
	while (temp->pNext != nullptr) {
		temp = temp->pNext;
	}
	temp->pNext = newnode;
}

void printList(Node* head) {
	cout << "[";
	if (head != nullptr) {
		Node* cur = head;
		while (cur != nullptr) {
			cout << cur->data;
			if (cur->pNext != nullptr) {
				cout << " -> ";
			}
			cur = cur->pNext;
		}
	}
	cout << "]";
}

void deleteList(Node*& head) {
	Node* cur = head;
	while (head != nullptr) {
		head = head->pNext;
		delete cur;
		cur = head;
	}
}

bool isCoprime(int num1, int num2) {
	// Euclidean Algorithm
	int modulo;
	if (num1 > num2) {
		modulo = num1 % num2;
		while (modulo != 0) {
			num1 = num2;
			num2 = modulo;
			modulo = num1 % num2;
		}

		if (num2 == 1) {
			return true;
		}
	}
	else if (num1 == num2 || num1 == 0 || num2 == 0) {
		if (num1 == 1 && num2 == 1) {
			return true;
		}
		return false;
	}
	else {
		modulo = num2 % num1;
		while (modulo != 0) {
			num2 = num1;
			num1 = modulo;
			modulo = num2 % num1;
		}

		if (num1 == 1) {
			return true;
		}
	}

	return false;
}

void removeCoprimeNodes(List& l, int x) {
	Node* cur = l.pHead;

	// Erase all the coprime numbers if it is the head of the list
	while (true) {
		if (l.pHead != nullptr) {
			if (isCoprime(l.pHead->data, x)) {
				l.pHead = l.pHead->pNext;
				delete cur;
				cur = l.pHead;
			}
			else if (!isCoprime(l.pHead->data, x)) {
				break;
			}
		}
		else {
			return;
		}
	}

	// Erase the coprime numbers in the middle of the linked list
	Node* cur2 = l.pHead;
	cur = l.pHead->pNext;

	while (cur != nullptr) {
		if (isCoprime(cur->data, x)) {
			cur2->pNext = cur->pNext;
			delete cur;
			cur = cur2->pNext;
		}
		else {
			cur = cur->pNext;
			cur2 = cur2->pNext;
		}
	}
}

int main() {
	List l;
	l.pHead = nullptr;

	// Input
	int n; cout << "Type the number of numbers: "; cin >> n;
	int m;
	cout << "Type the numbers: ";
	for (int i = 0; i < n; i++) {
		cin >> m;
		AddTail(l, m);
	}

	int x; cout << "Type the check integer: "; cin >> x;
	removeCoprimeNodes(l, x);

	printList(l.pHead);

	deleteList(l.pHead);

	return 0;

}