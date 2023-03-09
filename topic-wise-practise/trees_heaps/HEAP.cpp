/**
Problem Link: https://www.codingninjas.com/codestudio/problems/build-min-heap_1171167
Date: 2023-03-05 09:36:12
Level: 
Notes:
    - 
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class heap {
    public:
        int arr[100];
        int size=0;

        heap() {
            arr[0] = -1;
            size = 0;
        }

        void insert(int val) {
            size = size + 1;
            int index = size;
            arr[index] = val;

            while(index > 1) {
                int parent = index/2;
                if(arr[parent] < arr[index]) {
                    swap(arr[parent], arr[index]);
                    index = parent;
                } else {
                    return ;
                }
            }
        }

        void deleteFromHeap() {
            if(size == 0) {
                cout << "Nothing to delete" << endl;
                return ;
            }
            //step 1
            arr[1] = arr[size];
            //step 2
            size = size - 1;
            //step 3: take root to its correct position
            int i=1;
            while(i < size) {
                int leftChild = 2*i;
                int rightChild = 2*i + 1;
                if(leftChild < size && arr[i] < arr[leftChild]) {
                    swap(arr[i], arr[leftChild]);
                    i = leftChild;
                } else if(rightChild < size && arr[i] < arr[rightChild]) {
                    swap(arr[i], arr[rightChild]);
                    i = rightChild;
                } else {
                    return ;
                }
            }
        }

        void print() {
            for(int i=1; i<=size; i++) {
                cout << arr[i] << " ";
            } cout << endl;
        }
};

void heapify(int arr[], int n, int i) {
    /**
     * arr: is the heap stored as array
     * n:   is the total no of elements in the heap
     * i:   is the index of the element we want to heapify
     * assuming 1 based indexing, for zero based changed left < n...
    */
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;
    if(left <= n && arr[largest] < arr[left]) {
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]) {
        largest = right;
    }
    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n) {
    int size = n;
    while(size > 1) {
        swap(arr[1], arr[size]);
        size--;
        heapify(arr, size, 1);
    }
}

int main() {
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deleteFromHeap();
    h.print();


    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n=5;
    //heap creation
    for(int i=n/2; i>=1; i--) {
        heapify(arr, n, i);
    }
    cout << "\n\nPrinting array after heapify: ";
    for(int i=1; i<=n; i++) {
        cout << arr[i] << " ";
    }cout << endl;

    //heapsort
    heapsort(arr, n);
    cout << "\n\nPrinting array after heapsort: ";
    for(int i=1; i<=n; i++) {
        cout << arr[i] << " ";
    }cout << endl;

    //using priority queue
    cout << "Using priority queue here: ";
    priority_queue<int> pq; //max heap
    pq.push(1);
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);
    cout << "Element at the top: " << pq.top() << endl;
    pq.pop();
    cout << "Element at the top: " << pq.top() << endl;

    priority_queue<int, vector<int>, greater<int> > minheap;
    minheap.push(1);
    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);
    cout << "Element at the top: " << minheap.top() << endl;
    minheap.pop();
    cout << "Element at the top: " << minheap.top() << endl;
    return 0;
}