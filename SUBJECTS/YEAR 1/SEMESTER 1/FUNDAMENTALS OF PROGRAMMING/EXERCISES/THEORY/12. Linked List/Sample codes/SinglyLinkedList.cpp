#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

void NewNode(Node*& head, int value) {
	Node* newnode = new Node();
	newnode->data = value;
	newnode->next = nullptr;

	if (head == nullptr) {
		head = newnode;
		return;
	}

	Node* temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = newnode;
}

void printlist(Node* head) {
	Node* cur = head;
	while (cur != nullptr) {
		cout << cur->data << " ";
		cur = cur->next;
	}
}

int main() {
	Node* head = nullptr;

	NewNode(head, 10);
	NewNode(head, 20);
	NewNode(head, 30);

	printlist(head);

	return 0;
}