#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void MoveList(vector<int> &list, int toMove, int i, int j)
{
    if (i > j)
        return;
    while (i < j && list[j] == toMove)
        j--;
    if (list[i] == toMove)
        swap(list[i], list[j]);
    i++;
    MoveList(list, toMove, i, j);
}
int main()
{
    int n, toMove, inp;
    cin >> n >> toMove;
    vector<int> list;
    for (int i = 0; i < n; i++)
    {
        cin >> inp;
        list.push_back(inp);
    }

    MoveList(list, toMove, 0, n - 1);
    for (auto i : list)
    {
        cout << i << " ";
    }
}