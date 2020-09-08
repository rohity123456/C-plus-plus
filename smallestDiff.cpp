#include <bits/stdc++.h>
using namespace std;
struct diffpair
{
    int first, second;
};

struct diffpair getSmallestDiffPair(vector<int> &first, vector<int> &second)
{
    int smallest = INT_MAX, diff;
    int firstPointer = 0, secondPointer = 0;
    struct diffpair p;
    while (firstPointer < first.size() && secondPointer < second.size())
    { //{5,2,3,4} {4 5 3 5 2}
        diff = abs(first[firstPointer] - second[secondPointer]);
        if (diff < smallest)
        {
            smallest = diff;
            p.first = first[firstPointer];
            p.second = second[secondPointer];
        }
        if (first[firstPointer] == second[secondPointer])
        {
            p.first = firstPointer;
            p.second = secondPointer;
            return p;
        }
        else if (first[firstPointer] < second[secondPointer])
        firstPointer++;
        else
            secondPointer++;
            
        
        //cout << first[firstPointer] << "," << second[secondPointer] << endl;
        //cout<<"diff : "<<diff<<endl;
        
    }
    return p;
}

int main()
{
    int n, m, inp;
    vector<int> first, second;
    cin >> n;
    cin >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> inp;
        first.push_back(inp);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> inp;
        second.push_back(inp);
    }

    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    struct diffpair p = getSmallestDiffPair(first, second);
    cout << "The smallest difference pair is : [ " << p.first << " , " << p.second << " ]";
}
