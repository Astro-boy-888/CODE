#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a ;
        s.insert(a);
    }
    
    for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << endl;
    }
}