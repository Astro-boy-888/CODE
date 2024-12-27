#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    char a,b;
    int count=0;
    getline(cin,s);
    cin>>a;
    if(a > 96 && a < 123)
    {
        b = a - 32;
    }
    if(a > 64 && a < 91)
    {
        b = a + 32;
    }
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == a || s[i] == b)
        {
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}
