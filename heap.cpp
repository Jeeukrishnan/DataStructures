
// A C++ program to demonstrate common Binary Heap Operations
#include<iostream>
#include<climits>
using namespace std;

// Prototype of a utility function to swap two integer
void swap(int *x, int *y);

// A class for Max Heap
class MaxHeap
{
        int *harr; // pointer to array of elements in heap
        int capacity; // maximum possible size of max heap
        int heap_size; // Current number of elements in max heap
public:
        // Constructor
        MaxHeap(int capacity);

        // to heapify a subtree with the root at given index
        void MaxHeapify(int );

        int parent(int i) { return (i-1)/2; }

        // to get index of left child of node at index i
        int left(int i) { return (2*i + 1); }

        // to get index of right child of node at index i
        int right(int i) { return (2*i + 2); }

        // to extract the root which is the maxmum element
        int extractMax();


        // Returns the maximum key (key at root) from max heap
        int getMax() { return harr[0]; }

        // Inserts a new key 'k'
        void insertKey(int k);

        void printHeap();
        void buildHeap();
};

// Constructor: Builds a heap from a given array a[] of given size
MaxHeap::MaxHeap(int cap)
{
        heap_size = 0;
        capacity = cap;
        harr = new int[cap];
}

// Inserts a new key 'k'
void MaxHeap::insertKey(int k)
{
        if (heap_size == capacity)
        {
                cout << "\nOverflow: Could not insertKey\n";
                                return;
        }

        // First insert the new key at the end
        heap_size++;
        int i = heap_size - 1;
        harr[i] = k;

        // Fix the max heap property if it is violated
        while (i != 0 && harr[parent(i)] <harr[i])
        {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
        }
}

// Method to remove maximum element (or root) from max heap
int MaxHeap::extractMax()
{
        if (heap_size <= 0)
                return INT_MAX;
        if (heap_size == 1)
        {
                heap_size--;
                return harr[0];
        }

        // Store the maximum value, and remove it from heap
        int root = harr[0];
        harr[0] = harr[heap_size-1];
        heap_size--;
        MaxHeapify(0);

        return root;
}


// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MaxHeap::MaxHeapify(int i)
{
        int l = left(i);
        int r = right(i);
        int largest = i;
        if (l < heap_size && harr[l] > harr[i])
                largest = l;
        if (r < heap_size && harr[r] > harr[largest])
                largest = r;
        if (largest != i)
        {
                swap(&harr[i], &harr[largest]);
                MaxHeapify(largest);
        }
}

// A utility function to swap two elements
void swap(int *x, int *y)
{
        int temp = *x;
        *x = *y;
        *y = temp;
}
// Function to build a Max-Heap from the given array
void MaxHeap::buildHeap()
{
                int n;
        cout<<"Enter the number of elements->";
        cin>>n;
        heap_size=n;
        for(int i=0;i<n;i++)
                cin>>harr[i];
      // Index of last non-leaf node
    int startIdx = (n / 2) - 1;

    // Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
    for (int i = startIdx; i >= 0; i--) {
        MaxHeapify(i);
    }
}
void MaxHeap::printHeap()
{
    cout << "Array representation of Heap is:\n";

    for (int i = 0; i < heap_size; ++i)
        cout << harr[i] << " ";
    cout << "\n";
}

int main()
{
        int n,ch=1;
        MaxHeap h(30);
        do{
        cout<<"Enter your choice-\n 1.insert\n2.heapify\n3.maximum\n4.extract-max\n5.build heap\n 6.printheap\n";
        cin>>n;
        switch(n)
        {

                case 1: cout<<"Enter the element to insert->";
                                cin>>n;
                                h.insertKey(n);
                                break;
                case 2: cout<<"enter the index where heapify operation should be done->";
                                cin>>n;
                                h.MaxHeapify(n);
                                h.printHeap();
                                break;
                case 3: cout<<"Maximum element ->"<<h.getMax()<<endl;
                                break;
                case 4:cout<<"Maximum element->"<<h.extractMax();
                              cout<<endl;
                                h.printHeap();
                                break;
                case 5: h=MaxHeap(30);
                                h.buildHeap();
                                h.printHeap();
                                break;

                case 6: h.printHeap();
                        break;
                default:cout<<"Wrong choice";


        }

        cout<<"Do you want to enter more?(Y-1,N-0)";
        cin>>ch;

        }
        while(ch==1);

}                                                                                  
