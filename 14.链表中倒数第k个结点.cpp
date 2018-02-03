/*
题目描述
输入一个链表，输出该链表中倒数第k个结点。

思路
使用两个指针, 初始时让它们都指向头结点, 第一个先向后移动 k-1 个结点, 两个指针再一起向后移动, 当第一个指针到达尾结点时, 第二个指针所指的就是倒数第 k 个结点. (例如, k = 2, 第一个指针先向后移动 1 个结点, 两个指针一起后移到尾部, 第二个指针就指向倒数第 2 个结点.)

注意边界条件, 当 k = 0 或者 k > 结点数, 或者链表为空链表时, 都要返回NULL.

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	if(pListHead == NULL || k == 0)
            return NULL;	//空链表或者k = 0
        //两个指针都指向头结点
        ListNode* a = pListHead;
        ListNode* b = pListHead;
        int p = k - 1;
        while(p > 0 && a->next != NULL){
            a = a->next;
            p--;
        }
        if(p >0)
            return NULL;	//链表结点数小于k个
        while(a->next){
            a = a->next;
            b = b->next;
        }
        return b;
    }
};
