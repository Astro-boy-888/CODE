#include <bits/stdc++.h>

using namespace std;
/*
# 孙悟空爱吃蟠桃
## **题目描述**
孙悟空爱吃蟠桃，有一天趁着蟠桃园守卫不在来偷吃。已知蟠桃园有 N 棵桃树，每颗树上都有桃子，守卫将在 H 小时后回来。
孙悟空可以决定他吃蟠桃的速度K（个/小时），每个小时选一颗桃树，并从树上吃掉 K 个，如果树上的桃子少于 K 个，则全部吃掉，并且这一小时剩余的时间里不再吃桃。
孙悟空喜欢慢慢吃，但又想在守卫回来前吃完桃子。
请返回孙悟空可以在 H 小时内吃掉所有桃子的最小速度 K（K为整数）。如果以任何速度都吃不完所有桃子，则返回0。
## **输入描述**
一行输入为 N 个数字，N 表示桃树的数量，这 N 个[数字表示](https://so.csdn.net/so/search?q=%E6%95%B0%E5%AD%97%E8%A1%A8%E7%A4%BA&spm=1001.2101.3001.7020)每颗桃树上蟠桃的数量。
第二行输入为一个数字，表示守卫离开的时间 H。
其中数字通过空格分割，N、H为正整数，每颗树上都有蟠桃，且 0 < N < 10000，0 < H < 10000。
## **输出描述**
吃掉所有蟠桃的最小速度 K，无解或输入异常时输出 0。
## **示例1**
输入
2 3 4 5
4
输出
5
## **示例2**
输入
2 3 4 5
3
输出
0
*/

/*
    TODO:
    1.设置一个函数用于判断该速度k下H小时内能否吃完所有桃子 
    2.主函数二分查找最小的速度
*/

int isEnough(const vector<int> &peaches,int k,int H)
{   
    if(peaches.empty() || k <= 0 ||H <=0)
    {
        return 0;
    }
    int result = 0;
    for (int  x:peaches)
    {
        result +=  (x-1)/k +1;
    }
    return result <= H;
}

int main()
{
    vector<int> peaches;
    string input;
    getline(cin,input);
    string peach;
    for(char c:input)
    {
        if(c ==' ')
        {
            peaches.push_back(stoi(peach));
            peach.clear();
        }
        else
        {
            peach += c;
        }
    }
    peaches.push_back(stoi(peach));

    int H = 0;
    cin >> H;
    if (H == 0 || peaches.empty() || peaches.size() > H)
    {
        cout << 0 << endl;
        return 0;
    }

    int left = 1;
    int right = 1e9;
    while (left <= right)
    {
        int mid = ( left + right )/2;
        if(isEnough(peaches,mid,H))
        {
            right = mid -1; 
        }
        else
        {
            left = mid +1;
        }
    }
    cout << left <<endl;
    return 0;
}