#include "FibHeap.h"
#include <cmath>

// Node constructor
FibNode::FibNode(int k) {
    key = k;
    degree = 0;
    mark = false;
    parent = child = nullptr;
    left = right = this;
}

FibHeap::FibHeap() : min_node(nullptr), n(0) {}

// O(1) - Just adding to the root list
void FibHeap::Insert(FibNode* node) {
    if (min_node == nullptr) {
        min_node = node;
        node->left = node->right = node;
    } else {
        node->left = min_node->left;
        node->right = min_node;
        min_node->left->right = node;
        min_node->left = node;
        if (node->key < min_node->key) min_node = node;
    }
    n++;
}

// O(1) - Merging by joining circular lists
void FibHeap::Merge(FibHeap& other) {
    if (other.min_node == nullptr) return;
    if (min_node == nullptr) {
        min_node = other.min_node;
        n = other.n;
    } else {
        FibNode* L1 = min_node->left;
        FibNode* L2 = other.min_node->left;
        L1->right = other.min_node;
        other.min_node->left = L1;
        min_node->left = L2;
        L2->right = min_node;
        if (other.min_node->key < min_node->key) min_node = other.min_node;
        n += other.n;
    }
    other.min_node = nullptr;
    other.n = 0;
}

// Helper to link node y as child of x
void FibHeap::Link(FibNode* y, FibNode* x) {
    y->left->right = y->right;
    y->right->left = y->left;
    y->parent = x;
    if (x->child == nullptr) {
        x->child = y;
        y->right = y->left = y;
    } else {
        y->left = x->child;
        y->right = x->child->right;
        x->child->right->left = y;
        x->child->right = y;
    }
    x->degree++;
    y->mark = false;
}

// Consolidate: combine trees of same degree until all degrees unique
void FibHeap::Consolidate() {
    int max_deg = (int)(std::log2(n + 1) * 1.618) + 2;
    FibNode** A = new FibNode*[max_deg];
    for (int i = 0; i < max_deg; i++) A[i] = nullptr;

    // Snapshot of roots to avoid infinite loops during linking
    int num_roots = 0;
    FibNode* curr = min_node;
    if (curr != nullptr) {
        do { num_roots++; curr = curr->right; } while (curr != min_node);
    }

    FibNode** roots = new FibNode*[num_roots];
    curr = min_node;
    for (int i = 0; i < num_roots; i++) {
        roots[i] = curr;
        curr = curr->right;
    }

    for (int i = 0; i < num_roots; i++) {
        FibNode* x = roots[i];
        int d = x->degree;
        while (A[d] != nullptr) {
            FibNode* y = A[d];
            if (x->key > y->key) {
                FibNode* t = x; x = y; y = t;
            }
            Link(y, x);
            A[d] = nullptr;
            d++;
        }
        A[d] = x;
    }

    // Rebuild root list
    min_node = nullptr;
    for (int i = 0; i < max_deg; i++) {
        if (A[i] != nullptr) {
            if (min_node == nullptr) {
                min_node = A[i];
                min_node->left = min_node->right = min_node;
            } else {
                A[i]->left = min_node->left;
                A[i]->right = min_node;
                min_node->left->right = A[i];
                min_node->left = A[i];
                if (A[i]->key < min_node->key) min_node = A[i];
            }
        }
    }
    delete[] roots;
    delete[] A;
}

int FibHeap::ExtractMin() {
    FibNode* z = min_node;
    if (z == nullptr) return -1;

    if (z->child != nullptr) {
        FibNode* c = z->child;
        FibNode* start = c;
        do {
            FibNode* next = c->right;
            c->parent = nullptr;
            c->left = min_node->left;
            c->right = min_node;
            min_node->left->right = c;
            min_node->left = c;
            c = next;
        } while (c != start);
    }

    z->left->right = z->right;
    z->right->left = z->left;
    int res = z->key;

    if (z == z->right) min_node = nullptr;
    else {
        min_node = z->right;
        Consolidate();
    }
    n--;
    delete z;
    return res;
}

// Decrease Key: O(1) amortized
void FibHeap::DecreaseKey(FibNode* x, int new_key) {
    if (new_key > x->key) return; // Only decreasing
    x->key = new_key;
    FibNode* y = x->parent;
    if (y != nullptr && x->key < y->key) {
        Cut(x, y);
        CascadingCut(y);
    }
    if (x->key < min_node->key) min_node = x;
}

void FibHeap::Cut(FibNode* x, FibNode* y) {
    // Remove x from y's child list
    if (x->right == x) y->child = nullptr;
    else {
        x->left->right = x->right;
        x->right->left = x->left;
        if (y->child == x) y->child = x->right;
    }
    y->degree--;

    // Add x to root list
    x->left = min_node->left;
    x->right = min_node;
    min_node->left->right = x;
    min_node->left = x;

    x->parent = nullptr;
    x->mark = false;
}

void FibHeap::CascadingCut(FibNode* y) {
    FibNode* z = y->parent;
    if (z != nullptr) {
        if (!y->mark) y->mark = true;
        else {
            Cut(y, z);
            CascadingCut(z);
        }
    }
}
