#include <iostream>
using namespace std;

void shellSort(int arr[], int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            int key = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > key)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = key;
        }
    }
}