#include <bits/stdc++.h>

using namespace std;
/*
给定一个链表的头节点  `head` ，返回链表开始入环的第一个节点。 *如果链表无环，则返回 `null`。*

如果链表中有某个节点，可以通过连续跟踪 `next` 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 `pos` 来表示链表尾连接到链表中的位置（**索引从 0 开始**）。如果 `pos` 是 `-1`，则在该链表中没有环。**注意：`pos` 不作为参数进行传递**，仅仅是为了标识链表的实际情况。

**不允许修改** 链表。

**示例 1：**

!https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png

```
输入：head = [3,2,0,-4], pos = 1
输出：返回索引为 1 的链表节点
解释：链表中有一个环，其尾部连接到第二个节点。

```

**示例 2：**

!https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test2.png

```
输入：head = [1,2], pos = 0
输出：返回索引为 0 的链表节点
解释：链表中有一个环，其尾部连接到第一个节点。

```

**示例 3：**

!https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test3.png

```
输入：head = [1], pos = -1
输出：返回 null
解释：链表中没有环。

```

**提示：**

- 链表中节点的数目范围在范围 `[0, 104]` 内
- `105 <= Node.val <= 105`
- `pos` 的值为 `1` 或者链表中的一个有效索引

**进阶：**你是否可以使用 `O(1)` 空间解决此题？

*/

/*
    TODO:
    1.设置fast slow指针 
        只要fast ！= NULL && fast-> next != NULL
            fast 进两个
            slow 进一个
            fast == slow
                index1 = fast
                index2 = head
                while index1 != index2
                    index1 进一个
                    index2 进一个
                index1 == index2 => 返回 index1
    2.返回NULL
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                ListNode* index1 = head;
                ListNode* index2 = fast;
                while (index1 != index2)
                {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }
        return NULL;
    }
};