#include <bits/stdc++.h>
using namespace std;

int getFirstSmalleButGreaterThanMin(vector<int> &arr, int startIndex, int min)
{
    for (int i = startIndex + 1; i < arr.size(); i++)
    {
        if (arr[i] < arr[startIndex] && arr[i] >= min)
            return i;
    }
    return -1;
}
int getFirstBiggerButLessThanMax(vector<int> &arr, int startIndex, int max)
{
    for (int i = startIndex + 1; i < arr.size(); i++)
    {
        if (arr[i] >= arr[startIndex] && arr[i] < max)
            return i;
    }
    return -1;
}

bool IsSameBST(vector<int> &arr1, vector<int> &arr2, int rootIndex1, int rootIndex2, int min, int max)
{
    if (arr1[rootIndex1] != arr2[rootIndex2])
        return false;
    if (rootIndex1 == -1 || rootIndex2 == -1)
        return rootIndex1 == rootIndex2;

    int leftRootIdx1 = getFirstSmalleButGreaterThanMin(arr1, rootIndex1, min);
    int leftRootIdx2 = getFirstSmalleButGreaterThanMin(arr2, rootIndex2, min);
    int rightRootIdx1 = getFirstBiggerButLessThanMax(arr1, rootIndex1, max);
    int rightRootIdx2 = getFirstBiggerButLessThanMax(arr2, rootIndex2, max);
    cout << "arr1[rootIndex1] : " << arr1[rootIndex1] << " arr1[rootIndex2] : " << arr2[rootIndex1] << " leftRootIdx1 : " << leftRootIdx1 << " leftRootIdx2 : " << leftRootIdx2 << " rightRootIdx1 : " << rightRootIdx1 << " rightRootIdx2 : " << rightRootIdx2 << "|" << endl;
    bool isLeftSame = IsSameBST(arr1, arr2, leftRootIdx1, leftRootIdx2, min, arr1[rootIndex1]);
    bool isRightSame = IsSameBST(arr1, arr2, rightRootIdx1, rightRootIdx2, arr1[rootIndex1], max);
    return isLeftSame && isRightSame;
}

int main()
{
    int n, m, inp;
    cin >> n >> m;
    vector<int> arr1;
    vector<int> arr2;
    for (int i = 0; i < n; i++)
    {
        cin >> inp;
        arr1.push_back(inp);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> inp;
        arr2.push_back(inp);
    }
    if (IsSameBST(arr1, arr2, 0, 0, INT_MIN, INT_MAX))
    {
        cout << "Yes, They are same BST";
    }
    else
        cout << "No, They are not same BST";
}