#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* pNext;
};

struct List {
    Node* pHead;
};

void createNode(List* &l, int val) {
    Node* newnode = new Node();
    newnode->data = val;
    newnode->pNext = nullptr;

    if (l->pHead == nullptr) {
        l->pHead = newnode;
        return;
    }

    Node* temp = l->pHead;
    while (temp->pNext != nullptr) {
        temp = temp->pNext;
    }
    temp->pNext = newnode;
}

void printlist(List* l) {
    Node* temp = l->pHead;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->pNext;
    }
    cout << endl;
} 

Node* mergeTwoLists(List* &l, List* &l2, int n, int m) {
    Node* head = l->pHead;
    Node* temp = l->pHead;
    Node* head2 = l2->pHead;

    while (temp->pNext != nullptr) {
        temp = temp->pNext;
    }

    temp->pNext = head2;

    bool swapped = false;
    Node* previous = head;
    Node* next = head->pNext;

    for (int i = 0; i < n + m; i++) {
        swapped = false;
        previous = head;
        next = head->pNext;
        for (int j = 0; j < (n + m) - i - 1; j++) {
            if (previous->data > next->data) {
                int temp2 = previous->data;
                previous->data = next->data;
                next->data = temp2;
                swapped = true;
            }

            previous = previous->pNext;
            next = next->pNext;

            if (!next) break;
        }

        if (!swapped) {
            break;
        }
    }
    return head;
}

void deletion(List* &l) {
    Node* temp = nullptr;
    while (l != nullptr) {
        temp = l->pHead;
        l->pHead = l->pHead->pNext;
        delete temp;
    }
}

int main() {
    List* l;
    List* l2;

    l->pHead = nullptr;
    l2->pHead = nullptr;

    int n; cout << "1. Number of elements: "; cin >> n;
    for (int i = 0; i < n; i++) {
        int newnum; cin >> newnum;
        createNode(l, newnum);
    }

    int m; cout << "2. Number of elemets: "; cin >> m;
    for (int i = 0; i < m; i++) {
        int newnum; cin >> newnum;
        createNode(l2, newnum);
    }

    mergeTwoLists(l, l2, n, m);

    cout << "Printing list: ";
    printlist(l);

    deletion(l);

    return 0;
}