#include <iostream>
#include <vector>
using namespace std;

// Selection Sort
void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i <= n - 2; i++)
    {
        int mini = i;
        for (int j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[mini])
            {
                mini = j;
            }
        }
        swap(arr[mini], arr[i]);
    }
}

// Time Complexity: O(n^2)

// Bubble Sort
void bubbleSort(vector<int> &arr, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        bool didswap = false;
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                didswap = true;
            }
        }
        if (didswap == 0)
        {
            break;
        }
    }
}
// Time Complexity: O(n^2) Avg
// Time Complexity: O(n) Best

// Insertion Sort
void insertionSort(int arr[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }
}
// Time Complexity: O(n^2) Avg
// Time Complexity: O(n) Best