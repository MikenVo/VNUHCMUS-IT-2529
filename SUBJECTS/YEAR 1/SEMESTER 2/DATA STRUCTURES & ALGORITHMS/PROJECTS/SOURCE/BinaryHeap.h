#ifndef BINARYHEAP_H
#define BINARYHEAP_H

struct BinaryHeap {
    int* data;
    int capacity;
    int size;

    BinaryHeap(int cap);
    ~BinaryHeap();
    void Insert(int key);
    int ExtractMin();
    void DecreaseKey(int index, int new_key); // Standard binary heap version
    void Merge(BinaryHeap& other);           // O(N) merge
    void MinHeapify(int i);
};

#endif
