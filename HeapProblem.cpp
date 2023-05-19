#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void percolateUp(vector<int>& heap, int i) {
    int parent = (i - 1) / 2;
    if (i > 0 && heap[i] < heap[parent]) {
        swap(heap[i], heap[parent]);
        percolateUp(heap, parent);
    }
}

void percolateDown(vector<int>& heap, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;

    if (left < heap.size() && heap[left] < heap[smallest]) {
        smallest = left;
    }

    if (right < heap.size() && heap[right] < heap[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        percolateDown(heap, smallest);
    }
}

void insertElement(vector<int>& heap, int element) {
    heap.push_back(element);
    percolateUp(heap, heap.size() - 1);
}

void deleteElement(vector<int>& heap, int element) {
    int i = find(heap.begin(), heap.end(), element) - heap.begin();
    heap[i] = heap.back();
    heap.pop_back();
    percolateDown(heap, i);
}

int getMin(vector<int>& heap) {
    return heap.front();
}

int main() {
    int q;
    cin >> q;

    vector<int> heap;
    while (q--) {
        int select, element;
        cin >> select;

        if (select == 1) {
            cin >> element;
            insertElement(heap, element);
        }
        else if (select== 2) {
            cin >> element;
            deleteElement(heap, element);
        }
        else if (select == 3) {
            cout << getMin(heap) << endl;
        }
    }

    return 0;
}