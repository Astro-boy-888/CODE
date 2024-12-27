#include <bits/stdc++.h>

using namespace std;

// 删除数组元素
// 暴力删除
// class removeVectorElement //暴力删除数组元素 两层循环O(n^2)
// {
// public:
//     int removeElement(int val,vector<int> &nums)
//     {   
//         int size = nums.size();
//         for (size_t i = 0; i < size; i++)
//         {
//             if(nums[i] == val)
//             {
//                 for (size_t j = i; j < size; j++)
//                 {
//                     nums[j] = nums[j+1];
//                 }
//                 i--; // 因为下标i以后的数值都向前移动了一位，所以i也向前移动一位
//                 size--; // 此时数组的大小-1
//             }
//         }
//     return size;
//     }
// };
//
// 双指针删除 => erase()
// class removeVectorElement //双指针删除数组元素 O(n)
// {
// public:
//     int removeElement(int val,vector<int> &nums)
//     {   
//         int size = nums.size();
//         int slow = 0;
// 				for (int fast = 0;fast < size ;fast ++)
// 				{
// 						if(nums[fast]!=val)
// 						{
// 								nums[slow] = nums[fast];
// 								slow ++;
// 						}
// 				}
// 		    return slow;
//     }
// };

// class Square_of_sorted_array
// {
// public:
// 		vector<int> Sorted_Square_Array(vector<int> &A)
// 		{
// 				vector<int> result(A.size(), 0);
// 				int k = A.size() -1;
// 				for(int i =0,j=A.size()-1;i<=j;)
//                 {
//                     if(A[i]*A[i] < A[j]*A[j])
//                     {
//                         result[k--] = A[j]*A[j];
//                         j--;
//                     }
//                     else
//                     {
//                         result[k--] = A[i]*A[i];
//                         i++;
//                     }
//                 }
// 		return result;
// 		}		
// };

/*
    TODO:
    1.滑动窗口的思想：不断的调节子序列的起始位置和终止位置，得出我们要想的结果。
    2.i 代表滑动窗口的起始位置  j 代表滑动窗口的终止位置
    3.result 存储结果 一开始设置为INT32_MAX
    4.设置 sum 表示当前窗口内的元素和 subLength 表示当前窗口大小
    5.一次循环进行对终止位置的修改 滑动窗口调整初始位置进行窗口大小修改
*/
// class minsubarray
// {
// public:
//     int Min_Sub_Array(int s,vector<int>& nums)
//     {
//         int result = INT32_MAX;
//         int i = 0;
//         int sum =0;
//         int subLength =0;
//         for (int j = 0; j < nums.size(); j++)
//         {
//             sum += nums[j];
//             while (sum >= s)
//             {
//                 subLength = j-i+1;
//                 result = result > subLength ? subLength:result;
//                 sum -=nums[i++];
//             }
//         }
//         return result == INT32_MAX ? 0:result;
//     }
// };

//螺旋矩阵
/*
    TODO:
    1.设置结果二维数组 vector<vector<int>> result  并确定结果的大小 n^2
    2.设置以下变量
        a.startx = 0 starty=0 
            => 每一圈开始的位置
        b.offset = 1 
            => 找到每一边该遍历的长度 n-offest 每一圈 offest+1 每一边长度 -1
        c.loop = n/2
            => 总共要循环的圈数
        d.count = 1
            => 每次该插入的元素
        e.mid = n/2
            => 若n为奇数需要对最中间的元素最后单独插入
        f.i,j 
            => 定位当前插入的指针 这里不做初始化 每一圈由 startx starty 来确定 i,j
    3.只要loop大于0 就进行四边循环 每一圈结束 loop-- 
    => 推荐用while循环 => 一个很好的写法 while(loop--)
        a.四次循环始终遵守左闭右开 对最后一个元素不做处理 将其留给下一边处理
                        i                                      j
            i.        startx                      [starty -> starty+(n-offest)) 
            ii.   [startx -> startx+(n-offest))          starty+(n-offest)
            iii.   startx+(n-offest)              [starty+(n-offest) -> starty) 
            iiii. [startx+(n-offest) -> startx)             starty
        b.每结束完四次循环 代表一圈结束 修改 startx starty offset
    4.处理n为奇数情况 最中间元素
*/

// class Solution
// {
// public:
//     vector<vector<int>> generateMatrix(int n)
//     {
//         vector<vector<int>> result(n,vector<int>(n,0));
//         int startx = 0,starty =0;
//         int offset = 1;
//         int loop = n/2;
//         int count = 1;
//         int mid = n/2;
//         int i,j;
//         while (loop --)
//         {
//             i = startx; //第 i 行
//             j = starty; //第 j 列
//             for (;j < (n - offset);j++)
//             {
//                 result[i][j] = count;
//                 count ++;
//             }
//             for (;i < (n - offset); i++)
//             {
//                 result[i][j] = count;
//                 count ++;
//             }
//             for (;j > starty ;j--)
//             {
//                 result[i][j] = count;
//                 count ++;
//             }
//             for (;i > startx; i--)
//             {
//                 result[i][j] = count;
//                 count ++;
//             }
//             startx ++;
//             starty ++;
//             offset ++;
//         }
//         if(n%2)
//         {
//             result[mid][mid] = count;
//         }
//         return result;
//     }   
// };

//链表移除元素：头结点删除需要另做处理
//无虚拟头结点
/*
    1.判断头结点非空 且 头结点所含的数值正是Target => 删除头结点
        head = head -> next 并释放内存
        注意：若每个节点都相同且都为Target => 一直删除头结点 => while循环
    2.非删除头结点的情况  => 设置 cur = head 删的是 cur -> next => 同样也是while循环
*/

// struct ListNode
// {   
//     int val;
//     ListNode* next;
// };

// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) 
//     {
//         while (head != NULL && head->val==val)
//         {
//             ListNode* tmp = head;
//             head = head->next;
//             delete tmp;
//         }
        
//         ListNode* cur = head;
//         while (cur != NULL && cur->next != NULL)
//         {
//             if(cur->next->val ==val)
//             {
//                 ListNode* tmp = cur->next;
//                 cur->next = cur->next->next;
//                 delete tmp;
//             }
//             else
//             {
//                 cur = cur->next;
//             }
//         }
//         return head;
//     }
// };

//有虚拟头结点

// struct ListNode
// {   
//     int val;
//     ListNode* next;
//     ListNode(int val)
//     {
//         this->val = val;
//     }
// };

// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) 
//     {
//         ListNode* dummyHead = new ListNode(0);
//         dummyHead->next = head;
//         ListNode* cur = dummyHead;
//         while (cur->next != NULL)
//         {
//             if(cur->next->val == val)
//             {
//                 ListNode* tmp = cur;
//                 cur->next = cur->next->next;
//                 delete tmp;
//             }
//             else
//             {
//                 cur = cur->next;
//             }
//         }
//         head = dummyHead->next;
//         delete dummyHead;
//         return head;
//     }
// };

// class MyLinkedList {
// public:
//     struct LinkedNode //3
//     {
//         int val;
//         LinkedNode* next;
//         LinkedNode(int val):val(val),next(nullptr){} 
//     };
    
//     MyLinkedList() //2
//     {
//         _dummyHead = new LinkedNode(0);
//         _size = 0;
//     }
    
//     int get(int index) //4 
//     {
//         if(index < 0 || index >_size-1)
//         {
//             return;
//         }
//         LinkedNode* cur = _dummyHead;
//         while (index --)
//         {
//             cur = cur->next;
//         }
//         return cur->val;
//         }
    
//     void addAtHead(int val) //4
//     {
//         LinkedNode* newNode = new LinkedNode(val);
//         newNode->next = _dummyHead->next;
//         _dummyHead->next = newNode;
//         _size++;
//     }
    
//     void addAtTail(int val) //5
//     {
//         LinkedNode* newNode = new LinkedNode(val);
//         LinkedNode* cur = _dummyHead;
//         while (cur->next != nullptr)
//         {
//             cur = cur->next;
//         }
//         cur->next = newNode;
//         _size ++;
//     }
    
//     void addAtIndex(int index, int val) //8
//     {
//         if(index > _size) return;
//         if (index < 0) index = 0; 
//         LinkedNode* newNode = new LinkedNode(val);
//         LinkedNode* cur = _dummyHead;
//         while (index --)
//         {
//             cur = cur->next;
//         }
//         newNode->next = cur->next;
//         cur->next = newNode;
//         _size ++;
//     }
    
//     void deleteAtIndex(int index) //8
//     {
//         if (index < 0 || index >_size-1)
//         {
//             return;
//         }
//         LinkedNode* cur = _dummyHead;
//         while (index --)
//         {
//             cur = cur->next;
//         }
//         LinkedNode* tmp = cur->next;
//         cur->next = cur->next->next;
//         delete tmp;
//         tmp = nullptr; 
//         //delete命令指示释放了tmp指针原本所指的那部分内存，
//         //被delete后的指针tmp的值（地址）并非就是NULL，而是随机值。也就是被delete后，
//         //如果不再加上一句tmp=nullptr,tmp会成为乱指的野指针
//         //如果之后的程序不小心使用了tmp，会指向难以预想的内存空间
//         _size --;
//     }

// private:
//     int _size;
//     LinkedNode* _dummyHead;
// };

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
