#include <bits/stdc++.h>
using namespace std;
void populateSpiraledarray(vector<vector<int>> &matrix, int startrow, int endrow, int startcol, int endcol, vector<int> &output)
{
    if (startrow > endrow || startcol > endcol)
        return;
    for (int i = startcol; i <= endcol; i++)
        output.push_back(matrix[startrow][i]);

    for (int i = startrow + 1; i <= endrow; i++)
        output.push_back(matrix[i][endcol]);

    for (int i = endcol - 1; i >= startcol; i--)
        output.push_back(matrix[endrow][i]);

    for (int i = endrow - 1; i > startrow; i--)
        output.push_back(matrix[i][startcol]);

    populateSpiraledarray(matrix, ++startrow, --endrow, ++startcol, --endcol, output);
}
int main()
{
    int n, m, inp;
    cin >> n >> m;
    vector<vector<int>> matrix;
    vector<int> output;
    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int j = 0; j < m; j++)
        {
            cin >> inp;
            row.push_back(inp);
        }
        matrix.push_back(row);
    }
    populateSpiraledarray(matrix, 0, n - 1, 0, m - 1, output);
    cout << output.size() << endl;
    for (auto itr : output)
    {
        cout << itr << " ";
    }
}