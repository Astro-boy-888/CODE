#include <bits/stdc++.h>

using namespace std;
/*
# **检查是否存在满足条件的数字组合**

给定一个正整数数组检查数组中是否存在满足规则的数组组合

规则： A=B+2C

输入描述

第一行输出数组的元素个数 接下来一行输出所有数组元素，用空格隔开 输出描述 如果存在满足要求的数 在同一行里依次输出 规则里 A/B/C的取值 用空格隔开 如果不存在输出0

示例1：

输入 

4

2 7 3 0 

输出 

7 3 2 

说明： 7=3+2*2

备注：

数组长度在3~100之间

数组成员为0~65535

数组成员可以重复但每个成员只能在结果算式中使用一次，如数组成员为 [0,0,1,5]

0出现两次允许，但结果0=0+2*0不允许 因为算式中使用了3个0

用例保证每组数字里最多只有一组符合要求的解
*/
/*
    3层循环暴力求解，找到解就输出
*/
int main()
{
    int n;
    cin >> n;
    cin.ignore();

    vector<int> nums;   
    for (size_t i = 0; i < n; i++)
    {
        int num ;
        cin >> num;
        nums.push_back(num);
    }

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            for (size_t k = 0; k < n; k++)
            {
                if( i!=j && i!=k && j!=k && (nums[i] == nums[j] + 2*nums[k]))
                {
                    cout << nums[i] << " " << nums[j] << " " << nums[k] <<endl;
                    return 0;
                }
            }
            
        }
        
    }
    
    cout << "0" << endl;
    return 0;
}