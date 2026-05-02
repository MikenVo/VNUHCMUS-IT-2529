#include "BinomialHeap.h"
#include <climits>

BinomialNode::BinomialNode(int k) {
    key = k;
    degree = 0;
    parent = child = sibling = nullptr;
}

BinomialHeap::BinomialHeap() : head(nullptr) {}

// Merges two binomial trees of the same degree
void LinkTrees(BinomialNode* y, BinomialNode* z) {
    y->parent = z;
    y->sibling = z->child;
    z->child = y;
    z->degree++;
}

// Merges two root lists in increasing order of degree
BinomialNode* MergeLists(BinomialNode* h1, BinomialNode* h2) {
    if (!h1) return h2;
    if (!h2) return h1;
    BinomialNode* res = nullptr;
    if (h1->degree <= h2->degree) {
        res = h1; h1 = h1->sibling;
    } else {
        res = h2; h2 = h2->sibling;
    }
    BinomialNode* curr = res;
    while (h1 && h2) {
        if (h1->degree <= h2->degree) {
            curr->sibling = h1; h1 = h1->sibling;
        } else {
            curr->sibling = h2; h2 = h2->sibling;
        }
        curr = curr->sibling;
    }
    curr->sibling = h1 ? h1 : h2;
    return res;
}

void BinomialHeap::Merge(BinomialHeap& other) {
    BinomialNode* h = MergeLists(this->head, other.head);
    other.head = nullptr;
    if (!h) { this->head = nullptr; return; }

    BinomialNode* prev = nullptr;
    BinomialNode* x = h;
    BinomialNode* next = x->sibling;

    while (next) {
        if ((x->degree != next->degree) || (next->sibling && next->sibling->degree == x->degree)) {
            prev = x;
            x = next;
        } else {
            if (x->key <= next->key) {
                x->sibling = next->sibling;
                LinkTrees(next, x);
            } else {
                if (!prev) h = next;
                else prev->sibling = next;
                LinkTrees(x, next);
                x = next;
            }
        }
        next = x->sibling;
    }
    this->head = h;
}

void BinomialHeap::Insert(int key) {
    BinomialHeap temp;
    temp.head = new BinomialNode(key);
    this->Merge(temp);
}

int BinomialHeap::ExtractMin() {
    if (!head) return -1;
    BinomialNode* minNode = head;
    BinomialNode* minPrev = nullptr;
    BinomialNode* curr = head->sibling;
    BinomialNode* prev = head;

    while (curr) {
        if (curr->key < minNode->key) {
            minNode = curr;
            minPrev = prev;
        }
        prev = curr;
        curr = curr->sibling;
    }

    if (minPrev) minPrev->sibling = minNode->sibling;
    else head = minNode->sibling;

    BinomialNode* childList = nullptr;
    BinomialNode* c = minNode->child;
    while (c) {
        BinomialNode* next = c->sibling;
        c->sibling = childList;
        c->parent = nullptr;
        childList = c;
        c = next;
    }

    BinomialHeap temp;
    temp.head = childList;
    this->Merge(temp);

    int res = minNode->key;
    delete minNode;
    return res;
}

void BinomialHeap::DecreaseKey(BinomialNode* x, int new_key) {
    if (new_key > x->key) return;
    x->key = new_key;
    BinomialNode* y = x;
    BinomialNode* z = y->parent;
    while (z && y->key < z->key) {
        int temp = y->key;
        y->key = z->key;
        z->key = temp;
        y = z;
        z = y->parent;
    }
}
