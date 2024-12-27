#include <iostream>
#include <string>

using namespace std;

/*
    删除链表的倒数第 N 个结点
    给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
    示例 1：
    输入：head = [1,2,3,4,5], n = 2
    输出：[1,2,3,5]
    示例 2：
    输入：head = [1], n = 1
    输出：[]
    示例 3：
    输入：head = [1,2], n = 1
    输出：[1]
    提示：
    链表中结点的数目为 sz
    1 <= sz <= 30
    0 <= Node.val <= 100
    1 <= n <= sz
*/

/*
    TODO:
    1. 设置 dummyHead fast slow N+1 
    2. fast ≠ NULL fast 先移动
        1. N+1 次 fast = fast →next 
    3. fast ≠ NULL 开始同时移动
        1. fast = fast →next
        2. slow = slow →next
    4. slow 指向要删除的节点的前一个
        1. 删除操作 要手动释放内存
    5. 返回头结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 设置 dummyHead fast slow N+1 
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;
        n++;
        // fast ≠ NULL fast 先移动
        while (n-- && fast != NULL)
        {
            fast = fast->next;
        }
        // fast ≠ NULL 开始fast和slow同时移动
        while (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        // slow 指向要删除的节点的前一个
        ListNode* tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;// 要手动释放内存
        return dummyHead->next;
    }
};