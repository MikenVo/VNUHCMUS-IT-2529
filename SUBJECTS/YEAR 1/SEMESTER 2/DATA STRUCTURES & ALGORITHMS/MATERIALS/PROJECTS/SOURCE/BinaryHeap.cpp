#include "BinaryHeap.h"

BinaryHeap::BinaryHeap(int cap) {
    capacity = cap;
    size = 0;
    data = new int[cap];
}

BinaryHeap::~BinaryHeap() { delete[] data; }

void BinaryHeap::Insert(int key) {
    if (size >= capacity) return;
    int i = size++;
    data[i] = key;
    while (i != 0 && data[(i - 1) / 2] > data[i]) {
        int temp = data[i];
        data[i] = data[(i - 1) / 2];
        data[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

void BinaryHeap::DecreaseKey(int i, int new_key) {
    data[i] = new_key;
    while (i != 0 && data[(i - 1) / 2] > data[i]) {
        int temp = data[i];
        data[i] = data[(i - 1) / 2];
        data[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// Binary Heap Merge is O(N). We copy everything and re-heapify.
void BinaryHeap::Merge(BinaryHeap& other) {
    for (int i = 0; i < other.size; i++) {
        this->Insert(other.data[i]);
    }
}

int BinaryHeap::ExtractMin() {
    if (size <= 0) return -1;
    int root = data[0];
    data[0] = data[--size];
    MinHeapify(0);
    return root;
}

void BinaryHeap::MinHeapify(int i) {
    int l = 2 * i + 1, r = 2 * i + 2, s = i;
    if (l < size && data[l] < data[s]) s = l;
    if (r < size && data[r] < data[s]) s = r;
    if (s != i) {
        int t = data[i]; data[i] = data[s]; data[s] = t;
        MinHeapify(s);
    }
}
