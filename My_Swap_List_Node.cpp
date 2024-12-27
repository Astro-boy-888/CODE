#include <bits/stdc++.h>

using namespace std;
/*# 两两交换链表节点

给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

**示例 1：**

!https://assets.leetcode.com/uploads/2020/10/03/swap_ex1.jpg

```
输入：head = [1,2,3,4]
输出：[2,1,4,3]

```

**示例 2：**

```
输入：head = []
输出：[]

```

**示例 3：**

```
输入：head = [1]
输出：[1]

```

**提示：**

- 链表中节点的数目在范围 `[0, 100]` 内
- `0 <= Node.val <= 100`*/

/*
    TODO:
    1. `dummyHead→next = head`  `cur = dummyHead` cur 要一直指向需要操作的两个节点的前一个结点
    2. `cur→next→next = NULL（奇） 或 cur → next = NULL（偶）`   遍历结束
        1. 注意要先判断 `cur→next≠NULL` 再判断`cur→next→next ≠ NULL` 
        2. 防止判断`cur→next→next ≠ NULL` 时 `cur→next = NULL` 会发生报错 空指针异常
    3. 需要设置两个temp 分别用于记录要交换的第一个节点和交换的两个节点的后一个节点
*/


//Definition for singly-linked list.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);// 注意设为0
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        
        //关键点：循环终止条件 注意两个条件的位置
        while (cur->next != nullptr && cur->next->next != nullptr) {
            // 关键点：设置两个临时指针用来保存后两个节点
            ListNode* firstNode = cur->next;
            ListNode* secondNode = cur->next->next;
            
            // Swap the nodes 
            cur->next = secondNode;
            firstNode->next = secondNode->next;
            secondNode->next = firstNode;
            
            // Move cur to the next pair
            cur = firstNode;
        }
        
        ListNode* result = dummyHead->next;
        delete dummyHead; // Avoid memory leak 别忘了删除dummyHead
        return result;
    }
};
