/*
3.从尾到头打印链表
题目描述
输入一个链表，从尾到头打印链表每个节点的值。
思路

本题比较简单, 函数返回一个vector<int>, 我们只需要将链表按序写入一个vector, 然后使用反向迭代器返回一个从尾到头的vector即可.
*/

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(struct ListNode* head) {
        vector<int> v;
                        
        ListNode *p = head;
        while (p != nullptr) {
           v.push_back(p->val);
           p = p->next;
        }
        //反向迭代器创建临时对象
        return vector<int>(v.rbegin(), v.rend());
    }
};
