#include <iostream>
using namespace std;

struct Node {
	char data;
	int currentLen;
	Node* pNext;
};

struct List {
	Node* pHead;
	Node* top;
};

void init(List& l) {
	l.pHead = nullptr;
	l.top = nullptr;
}

Node* CreateNode(char data) {
	Node* newnode = new Node();
	newnode->data = data;
	newnode->currentLen = 0;
	newnode->pNext = nullptr;
	return newnode;
}

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

bool isEmpty(List l) {
	return (l.pHead == nullptr);
}

int main() {
	char arr[1000005];
	cin.getline(arr, 1000005);

	List l;
	init(l);

	int i = 0;
	int maxLen = 0;
	int count = 1;
	int baseLen = 0;

	while (arr[i] != '\0') {
		if (arr[i] == '(') {
			AddHead(l, '(');
		}
		else if (arr[i] == ')') {
			if (isEmpty(l)) {
				baseLen = 0;
			}
			else {
				Node* temp = l.pHead;
				int justClosedLen = 2 + temp->currentLen;

				l.pHead = l.pHead->pNext;
				delete temp;
				l.top = l.pHead;

				if (isEmpty(l)) {
					baseLen += justClosedLen;
					if (baseLen > maxLen) {
						maxLen = baseLen;
						count = 1;
					}
					else if (baseLen == maxLen) {
						count++;
					}
				}
				else {
					l.pHead->currentLen += justClosedLen;
					if (l.pHead->currentLen > maxLen) {
						maxLen = l.pHead->currentLen;
						count = 1;
					}
					else if (l.pHead->currentLen == maxLen) {
						count++;
					}
				}
			}
		}
		i++;
	}

	if (maxLen == 0) count = 1;
	cout << maxLen << " " << count << endl;

	return 0;
}