#ifndef BINOMIALHEAP_H
#define BINOMIALHEAP_H

// Node for Binomial Heap
struct BinomialNode {
    int key;
    int degree;
    BinomialNode *parent, *child, *sibling;

    BinomialNode(int k);
};

struct BinomialHeap {
    BinomialNode* head;

    BinomialHeap();
    void Insert(int key);
    int ExtractMin();
    void DecreaseKey(BinomialNode* x, int new_key);
    void Merge(BinomialHeap& other);

    // Helpers
    BinomialNode* ReverseList(BinomialNode* h);
    BinomialNode* Union(BinomialNode* h1, BinomialNode* h2);
};

#endif
