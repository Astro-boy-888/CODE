#include <bits/stdc++.h>

using namespace std;

/*
反转链表
给你单链表的头节点head，请你反转链表，并返回反转后的链表。
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]

输入：head = [1,2]
输出：[2,1]

输入：head = []
输出：[]

**提示：**

- 链表中节点的数目范围是 `[0, 5000]`
- `5000 <= Node.val <= 5000`
*/

//双指针
/*
    1.pre cru 两个指针 pre 指向 cru 前一个元素 
        一开始 cru 指向 head ，pre 指向 NULL
    2.while遍历 当 cru 指向空指针时 整个遍历操作结束
        需要设置一个临时指针 tmp 趁没赋值之前保存 cur->next
        修改方向
        pre cru 分别向后移
*/

// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* pre = NULL;
//         ListNode* cur = head;
//         ListNode* tmp; //保存cur的下一个节点
//         while (cur)
//         {
//             tmp = cur->next;
//             cur->next =pre; // 翻转操作
//             pre = cur;
//             cur = tmp;
//         }
//         return pre;
//     }
// };

// 递归算法

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverse(ListNode* cur ,ListNode* pre)
    {   
        if (cur == NULL)
        {
            return pre;
        }
        ListNode* tmp;
        tmp = cur->next;
        cur->next = pre;
        return reverse(tmp,cur);
    }
    ListNode* reverseList(ListNode* head) 
    {
        return reverse(head,NULL);
    }
};