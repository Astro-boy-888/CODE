#include<bits/stdc++.h>

using namespace std;

/*
数据分类
题目描述
对一个数据a进行分类，
分类方法是，此数据a(4个字节大小)的4个字节相加对一个给定值b取模，
如果得到的结果小于一个给定的值c则数据a为有效类型，其类型为取模的值。
如果得到的结果大于或者等于c则数据a为无效类型。

比如一个数据a = 0x01010101，b = 3
按照分类方法计算：(0x01 + 0x01 + 0x01 + 0x01) % 3 = 1
所以如果c等于2，则此a就是有效类型，其类型为1
如果c等于1，则此a是无效类型

又比如一个数据a = 0x01010103，b = 3
按分类方法计算：(0x01 + 0x01 + 0x01 + 0x03) % 3 = 0
所以如果c = 2则此a就是有效类型，其类型为0
如果c = 0则此a是无效类型

输入12个数据，
第一个数据为c，第二个数据为b，
剩余10个数据为需要分类的数据

请找到有效类型中包含数据最多的类型，
并输出该类型含有多少个数据

输入描述
输入12个数据用空格分割，
第一个数据为c，第二个数据为b，
剩余10个数据为需要分类的数据。

输出描述
请找到有效类型中包含数据最多的类型，
并输出该类型含有多少个数据。

示例一
输入
3 4 256 257 258 259 260 261 262 263 264 265
输出
3
说明
这10个数据4个字节相加后的结果分别是
1 2 3 4 5 6 7 8 9 10
故对4取模的结果为
1 2 3 0 1 2 3 0 1 2
c是3所以012都是有效类型
类型为1和2的有3个数据
类型为0和3的只有两个

示例二
输入
1 4 256 257 258 259 260 261 262 263 264 265
输出
2
*/

/*
    TODO：
    1.设置vector<int> data(10)接收原数据 int c,b 接收分类条件
    2.对data中每一个数据进行位运算
    例：(a >> 24) & 0xFF 
    (a >> 24)=>将a按位右移24位 与0xFF进行与运算=>只保留最高的有效8位
    3.设置 unordered_map<int,int> typeCount  
    first 代表类型编号 second 代表属于该类型数据的个数
    4.遍历data中所有数据 并按照分类条件进行分类加入 typeCount
    5.输出typeCount 中最大的 second
*/

int main()
{
    int c,b;
    vector<int> data(10);

    cin >> c >> b;
    for (size_t i = 0; i < 10; i++)
    {
        cin >> data[i];
    }
    
    unordered_map<int,int> typeCount;
    for (size_t i = 0; i < 10; i++)
    {
        int sum = ((data[i] >> 24)&0xFF)+((data[i] >> 16)&0xFF)+((data[i] >> 8)&0xFF)+((data[i])&0xFF);
        int mod = sum % b;
        if(mod < c)
        {
            typeCount[mod]++;
        }
    }
    
    int maxcount =0;
    for (auto &c:typeCount)
    {
        maxcount = max(maxcount,c.second);
    }
    
    cout << maxcount << endl;
}