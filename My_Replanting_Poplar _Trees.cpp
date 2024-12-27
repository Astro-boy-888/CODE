#include <bits/stdc++.h>

using namespace std;
/*(# 补种未成活胡杨

## **题目描述**

近些年来，我国防沙治沙取得显著成果。某沙漠新种植N棵胡杨（编号1-N），排成一排。

一个月后，有M棵胡杨未能成活。

现可补种胡杨K棵，请问如何补种（只能补种，不能新种），可以得到最多的连续胡杨树？

## **输入描述**

N 总种植数量，1 <= N <= 100000

M 未成活胡杨数量，M 个空格分隔的数，按编号从小到大排列，1 <= M <= N

K 最多可以补种的数量，0 <= K <= M

## **输出描述**

最多的连续胡杨棵树

## **示例1**

输入

```
5
2
2 4
1
```

输出

```
3
```

说明

> 补种到2或4结果一样，最多的连续胡杨棵树都是3。
> 

## **示例2**

输入

```
10
3
2 4 7
1
```

输出

```
6
```

说明

> 种第7棵树，最多连续胡杨树棵数位6（5，6，7，8，9，10）
> 

## **解题思路**

这道题目主要是考察如何通过补种胡杨树，使得胡杨树形成【最长的连续序列】。

### **示例解释**

### **示例1**

输入：

```
5
2
2 4
1
```

解释：

- 胡杨树总共有 5 棵，编号分别是 1, 2, 3, 4, 5。
- 未成活的胡杨树编号是 2 和 4。
- 只能补种 1 棵树。

选择补种位置：

- 可以补种编号为2的树，得到序列 `1, 2, 3`，最多连续 3 棵树。
- 或者补种编号为4的树，得到序列 `3, 4, 5`，同样可以得到最多连续 3 棵树。

因此，输出结果为 `3`。

### **示例2**

输入：

```
10
3
2 4 7
1
```

解释：

- 胡杨树总共有 10 棵，编号分别是 1 到 10。
- 未成活的胡杨树编号是 2, 4, 7。
- 只能补种 1 棵树。

选择补种位置：

- 如果补种编号为7的树，可以形成最长连续序列 `5, 6, 7, 8, 9, 10`，连续的胡杨树棵数为 `6`。
- 其他补种选择（如2或4）得到的最长连续胡杨树棵数较少。

因此，输出结果为 `6`。

### **代码思路**

基本与下题一致：

[1004. 最大连续1的个数 III](https://leetcode.cn/problems/max-consecutive-ones-iii/)

参考题解：https://leetcode.cn/problems/max-consecutive-ones-iii/solutions/608931/zui-da-lian-xu-1de-ge-shu-iii-by-leetcod-hw12/)
*/
/*
    TODO:
    1.根据题设设置输入 设置一个 vector<int> dead(M) 接收未成活胡杨的编号
        max_length 记录当前最长连续胡杨树长度
        replacements 记录当前窗口内需要补种的胡杨树数量
    2.设置 left right 为窗口左右边界 右边界从1扩展到N 左开右闭
        右边界遇到未成活 replacements++ 
            若 replacements > K 
                左边界遇到未成活 replacements--
                左边界未遇到未成活 移动左边界 left++
                    注意一开始 left=0 检查的应该是 left+1 是不是未成活的胡杨树 
            若 replacements <= K
                更新 max_length
    3.输出结果
*/
int main()
{   
    int N,M;
    vector<int> dead(M);
    int K;
    cin >> N >> M;
    for (size_t i = 0; i < M; i++)
    {
        cin >> dead[i];
    }
    cin >> K;
    sort(dead.begin(), dead.end());
    int max_length = 0;
    int replacements = 0;
    int left = 0;

    for (int right = 1; right <= N; right++)
    {
        if(binary_search(dead.begin(),dead.end(),right))
        {
            replacements++;
        }

        while(replacements > K)
        {
            if(binary_search(dead.begin(),dead.end(),left+1))
            {
                replacements --;
            }
            left ++;
        }
        max_length = max(max_length,right-left);
    }
    
    cout << max_length << endl;
    return 0;
}