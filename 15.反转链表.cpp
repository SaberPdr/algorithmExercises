/*
题目描述
输入一个链表，反转链表后，输出链表的所有元素。

思路
链表的结点间一个指向一个, 只有头结点有一个指针可用,  如果丢失头结点或者改变链表中某一个结点的指针, 就会使链表全部或者部分丢失.

要反转链表, 就是把所有的指针反向, 要用两个指针分别记录当前操作结点的上一个结点和下一个结点, 以保证链表安全.

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        //在原链表上反转
        if(pHead == NULL||pHead->next == NULL)
            return pHead;
        ListNode* a = pHead;	//a记录当前结点的上一结点, 也是反转后链表的头结点
        ListNode* b = NULL;	//b记录当前结点的下一结点
        pHead = pHead->next;
        a -> next = NULL;
        while(pHead)
        {
            b = pHead -> next;
            pHead -> next = a;
            a = pHead;
            pHead = b;
        }
        pHead = a;
        return pHead;
		/*创建新链表保持旧链表不变
        if(pHead == NULL||pHead->next == NULL)
            return pHead;
        ListNode* a = pHead;
        ListNode* b = new ListNode(a->val);
        ListNode* c = b;
        a = a -> next;
        while(a != NULL)
        {
            b = new ListNode(a->val);
            b -> next = c;
            c = b;
            a = a -> next;
        }
        return c;
        */
    }
};
