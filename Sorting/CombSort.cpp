#include <iostream>
using namespace std;

void swap(int &x, int &y)
{
    int temp = y;
    y = x;
    x = temp;
}

void combSort(int arr[], int size)
{
    int gap = size;
    bool swapped = true;

    while (gap > 1 || swapped)
    {
        gap = (gap * 10) / 13;
        gap = (gap < 1) ? 1 : gap;

        swapped = false;
        for (int i = 0; i < size - gap; i++)
        {
            if (arr[i] > arr[i + gap])
            {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}
