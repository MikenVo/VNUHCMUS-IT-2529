#ifndef FIBHEAP_H
#define FIBHEAP_H

struct FibNode {
    int key;
    int degree;
    bool mark;
    FibNode *parent, *child, *left, *right;
    FibNode(int k);
};

struct FibHeap {
    FibNode* min_node;
    int n;

    FibHeap();
    void Insert(FibNode* node);
    void Merge(FibHeap& other);
    int ExtractMin();
    void DecreaseKey(FibNode* x, int new_key);

    // Helpers
    void Link(FibNode* y, FibNode* x);
    void Consolidate();
    void Cut(FibNode* x, FibNode* y);
    void CascadingCut(FibNode* y);
};

#endif
