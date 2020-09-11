#include <bits/stdc++.h>
using namespace std;
void quicksort(vector<int> &unsortedArray, int start, int end)
{
    if (start >= end)
        return;
    int pivot = start;
    int left = pivot + 1;
    int right = end;
    while (left <= right)
    {
        if (unsortedArray[left] > unsortedArray[pivot] && unsortedArray[right] < unsortedArray[pivot])
        {
            swap(unsortedArray[left], unsortedArray[right]);
            left++;
            right--;
        }
        else if (unsortedArray[left] <= unsortedArray[pivot])
            left++;
        else if (unsortedArray[right] >= unsortedArray[pivot])
            right--;
    }
    swap(unsortedArray[pivot], unsortedArray[right]);
    if (((right - 1) - start) < (end - (right + 1)))
    {
        quicksort(unsortedArray, start, right - 1);
        quicksort(unsortedArray, right + 1, end);
    }
    else
    {
        quicksort(unsortedArray, right + 1, end);
        quicksort(unsortedArray, start, right - 1);
    }
}

int main()
{
    int n, inp;
    cin >> n;
    vector<int> unsortedArray;
    for (int i = 0; i < n; i++)
    {
        cin >> inp;
        unsortedArray.push_back(inp);
    }
    quicksort(unsortedArray, 0, n - 1);
    for (auto i : unsortedArray)
    {
        cout << i << " ";
    }
}