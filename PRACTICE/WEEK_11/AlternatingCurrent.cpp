#include <iostream>
#include <cstring>
using namespace std;

struct Node {
	char data;
	Node* pNext;
};

struct List {
	Node* pHead;
	Node* top;
};

void Init(List& l) {
	l.pHead = nullptr;
	l.top = nullptr;
}

// Create a new node
Node* CreateNode(char data) {
	Node* newnode = new Node();
	newnode->data = data;
	newnode->pNext = nullptr;

	return newnode;
}

// Add the new node to head
void AddHead(List& l, char data) {
	Node* node = CreateNode(data);

	if (l.pHead == nullptr) {
		l.pHead = node;
		l.top = node;
		return;
	}

	node->pNext = l.pHead;
	l.pHead = node;
	l.top = node;
}

// Check if the stack is empty
bool isEmpty(List l) {
	if (l.pHead == nullptr && l.top == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

void deleteList(List& l) {
	while (l.pHead != nullptr) {
		l.pHead = l.pHead->pNext;
		delete l.top;
		l.top = l.pHead;
	}
}

int main() {
	char arr[100001] = { 0 };
	cin.getline(arr, 100001);

	bool untangled = false;

	List l;
	Init(l);

	int i = 0;
	while (arr[i] != '\0') {
		if (l.pHead == nullptr) {
			AddHead(l, arr[i]);
			i++;
		}
		else {
			if (arr[i] == l.top->data) {
				// Delete the node when matched
				l.pHead = l.pHead->pNext;
				delete l.top;
				l.top = l.pHead;
				i++;
			}
			else {
				AddHead(l, arr[i]);
				i++;
			}
		}
	}

	if (isEmpty(l)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
		deleteList(l);
	}

	return 0;
}