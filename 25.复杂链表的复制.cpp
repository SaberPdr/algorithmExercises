/*
题目描述

输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
思路

本题的难点在于同时如何复制 random 指针.

我们使用以下方法复制这个链表的同时方便的复制 random 指针:

第一步, 将新建结点插在原链表对应结点之后.

第二步, 新结点的 random 应该指向原链表中对应结点的 random 之后的那个结点,

例如, A->random = C, 那么 A'->random = C', 而 C' = C->next;

第三步, 新链表的结构已经有了, 将其拆分出来.

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead)
            return nullptr;
        RandomListNode* a = pHead;
        RandomListNode* b;
        while(a){        //第一步, 将新链表的每一个节点插入原链表对应结点之后
            b = new RandomListNode(a->label);
            b->next = a->next;
            a->next = b;
            a = b->next;
        }
        a = pHead;
        while(a){        //第二步, 复制 random 指针
            b = a->next;
            if(a->random)
                b->random = a->random->next;
            a = b->next;
        }
        a = pHead;
        RandomListNode* head = a->next;
        b = a->next;
        while(a){        //第三步, 拆分两个链表
            a->next = b->next;
            a = a->next;
            if(a){
		b->next = a->next;
		b = b->next;
            }
        }
        return head;
    }
};
