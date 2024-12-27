#include <bits/stdc++.h>

using namespace std;

/*
    题目：
    # 组成最大数

    ## 题目描述

    小组中每位都有一张卡片，卡片上是6位以内的正整数。将卡片连起来可以组成多种数字，计算组成的最大数字。

    ## 输入描述

    `,`号分割的多个正整数字符串，不需要考虑非数字字符情况，小组最多25个人。

    ## 输出描述

    最大的数字字符串

    ## 示例1

    输入：

    ```
    22,221

    ```

    输出：

    ```
    22221

    ```

    说明： 将`22`和`221`组合成最大值的排列是`22221`。

    ## 示例2

    输入：

    ```
    4589,101,41425,9999

    ```

    输出：

    ```
    9999458941425101

    ```

    说明： 将`4589, 101, 41425, 9999`组合成最大值的排列是`9999458941425101`。
*/

/*
TODO:
    1.获取以','分隔数字的字符串，将每个数的子字符串插入vector<string> numbers
    2.自定义对比方法对 numbers 进行排序
        a.自定义对比方法 要以字符串的思维 字符串的+已经重构可以直接连接对比
*/

bool myCompare(const string &a,const string &b)
{
    return a+b > b+a;
}
int main()
{
    string input;
    getline(cin,input);
    
    vector<string> numbers;
    string number;
    for (char c:input)
    {
        if(c==',')
        {
            numbers.push_back(number);
            number.clear();
        }
        else
        {
            number += c;
        }
    }
    numbers.push_back(number);
    sort(numbers.begin(),numbers.end(),myCompare);

    for (vector<string>::iterator it = numbers.begin(); it != numbers.end(); it++)
    {
        cout << *it ;
    }
    cout << endl;

}