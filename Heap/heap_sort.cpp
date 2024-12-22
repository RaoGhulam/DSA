#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class maxHeap
{
    vector<int> heap;

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int leftChild(int i)
    {
        return (2 * i + 1);
    }

    int rightChild(int i)
    {
        return (2 * i + 2);
    }

    void heapifyDown(int i)
    {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < heap.size() && heap[left] > heap[largest])
        {
            largest = left;
        }

        if (right < heap.size() && heap[right] > heap[largest])
        {
            largest = right;
        }

        if (largest != i)
        {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(int i)
    {
        while (i != 0 && heap[parent(i)] < heap[i])
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

public:
    void insert(int value)
    {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void deleteMax()
    {
        if (heap.empty())
        {
            throw runtime_error("Heap is empty");
        }
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty())
        {
            heapifyDown(0);
        }
    }

    int getMax()
    {
        if (heap.empty())
        {
            throw runtime_error("Heap is empty");
        }
        return heap[0];
    }

    vector<int> heapSort()
    {
        vector<int> sorted;
        vector<int> originalHeap = heap; // Preserve original heap for reuse

        while (!heap.empty())
        {
            sorted.push_back(getMax());
            deleteMax();
        }

        heap = originalHeap;                   // Restore original heap
        reverse(sorted.begin(), sorted.end()); // Reverse for ascending order
        return sorted;
    }
};