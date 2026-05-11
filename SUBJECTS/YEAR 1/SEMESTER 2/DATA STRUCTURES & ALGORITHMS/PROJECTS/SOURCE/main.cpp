#include <iostream>
#include <chrono>
#include <ctime>
#include "FibHeap.h"
#include "BinaryHeap.h"
#include "BinomialHeap.h"

using namespace std;
using namespace std::chrono;

void runTest(const char* label, int* testData, int size) {
    cout << "\n==============================================" << endl;
    cout << " TEST CASE: " << label << " (" << size << " items)" << endl;
    cout << "==============================================" << endl;

    BinaryHeap bh1(size * 2), bh2(size);
    BinomialHeap bnh1, bnh2;
    FibHeap fh1, fh2;

    // We store pointers to test DecreaseKey
    BinomialNode** bnNodes = new BinomialNode*[size];
    FibNode** fibNodes = new FibNode*[size];

    // 1. MEASURE INSERT
    auto s_bins = high_resolution_clock::now();
    for(int i=0; i<size; i++) bh1.Insert(testData[i]);
    auto e_bins = high_resolution_clock::now();

    auto s_bnins = high_resolution_clock::now();
    for(int i=0; i<size; i++) {
        bnNodes[i] = new BinomialNode(testData[i]);
        // Note: Manual insert for binomial to keep node pointers
        BinomialHeap temp; temp.head = bnNodes[i];
        bnh1.Merge(temp);
    }
    auto e_bnins = high_resolution_clock::now();

    auto s_fins = high_resolution_clock::now();
    for(int i=0; i<size; i++) {
        fibNodes[i] = new FibNode(testData[i]);
        fh1.Insert(fibNodes[i]);
    }
    auto e_fins = high_resolution_clock::now();

    cout << "Insert: Binary=" << duration<double, milli>(e_bins-s_bins).count()
         << "ms | Binomial=" << duration<double, milli>(e_bnins-s_bnins).count()
         << "ms | Fib=" << duration<double, milli>(e_fins-s_fins).count() << "ms" << endl;

    // 2. MEASURE MERGE
    for(int i=0; i<size; i++) {
        bh2.Insert(testData[i] + 5);
        bnh2.Insert(testData[i] + 5);
        fh2.Insert(new FibNode(testData[i] + 5));
    }

    auto s_bm = high_resolution_clock::now(); bh1.Merge(bh2); auto e_bm = high_resolution_clock::now();
    auto s_bnm = high_resolution_clock::now(); bnh1.Merge(bnh2); auto e_bnm = high_resolution_clock::now();
    auto s_fm = high_resolution_clock::now(); fh1.Merge(fh2); auto e_fm = high_resolution_clock::now();

    cout << "Merge:  Binary=" << duration<double, milli>(e_bm-s_bm).count()
         << "ms | Binomial=" << duration<double, milli>(e_bnm-s_bnm).count()
         << "ms | Fib=" << duration<double, milli>(e_fm-s_fm).count() << "ms" << endl;

    // 3. MEASURE DECREASE KEY
    auto s_bdk = high_resolution_clock::now(); bh1.DecreaseKey(size/2, -1); auto e_bdk = high_resolution_clock::now();
    auto s_bndk = high_resolution_clock::now(); bnh1.DecreaseKey(bnNodes[size/2], -1); auto e_bndk = high_resolution_clock::now();
    auto s_fdk = high_resolution_clock::now(); fh1.DecreaseKey(fibNodes[size/2], -1); auto e_fdk = high_resolution_clock::now();

    cout << "DecKey: Binary=" << duration<double, milli>(e_bdk-s_bdk).count()
         << "ms | Binomial=" << duration<double, milli>(e_bndk-s_bndk).count()
         << "ms | Fib=" << duration<double, milli>(e_fdk-s_fdk).count() << "ms" << endl;

    // 4. MEASURE EXTRACT MIN
    auto s_bex = high_resolution_clock::now(); bh1.ExtractMin(); auto e_bex = high_resolution_clock::now();
    auto s_bnex = high_resolution_clock::now(); bnh1.ExtractMin(); auto e_bnex = high_resolution_clock::now();
    auto s_fex = high_resolution_clock::now(); fh1.ExtractMin(); auto e_fex = high_resolution_clock::now();

    cout << "ExMin:  Binary=" << duration<double, milli>(e_bex-s_bex).count()
         << "ms | Binomial=" << duration<double, milli>(e_bnex-s_bnex).count()
         << "ms | Fib=" << duration<double, milli>(e_fex-s_fex).count() << "ms" << endl;

    delete[] bnNodes;
    delete[] fibNodes;
}

int main() {
    srand(time(0));
    int small = 1000, large = 250000;

    int* randSmall = new int[small];
    int* sortSmall = new int[small];
    for(int i=0; i<small; i++) { randSmall[i] = rand()%10000; sortSmall[i] = i; }
    int* randLarge = new int[large];
    int* sortLarge = new int[large];
    for(int i=0; i<large; i++) { randLarge[i] = rand()%100000; sortLarge[i] = i; }

    runTest("Small Random", randSmall, small);
    runTest("Large Random", randLarge, large);
    runTest("Small Sorted", sortSmall, small);
    runTest("Large Sorted", sortLarge, large);

    delete[] randSmall; delete[] sortSmall;
    delete[] randLarge; delete[] sortLarge;

    cout << "\nBenchmark complete. Press Enter to exit..." << endl;
    cin.ignore(); // Clears any leftover characters
    cin.get();    // Waits for a key press

    return 0;
}
