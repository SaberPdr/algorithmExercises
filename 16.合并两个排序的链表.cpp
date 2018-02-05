/*
题目描述
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

思路
非递归:

两个指针分别指向两个链表头, 比较两个指针所指结点对应值的大小, 用较小的值创建新链表的头结点, 并将较小链表的指针后移, 再次比较, 用较小的值创建新结点添加到新链表的尾部, 循环执行, 直到其中一个链表到达结尾, 将另一个链表接在新链表尾部.

递归:

比较两个链表头结点对应值的大小, 较小的结点为新链表头结点, 头结点的 next 结点是 Merge(头结点值较小链表的头结点->next, 另一个链表头结点);

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
//非递归
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == NULL && pHead2 == NULL)
            return NULL;
        else if(pHead1 != NULL && pHead2 == NULL)
            return pHead1;
        else if(pHead1 == NULL && pHead2 != NULL)
            return pHead2;
        else 
        {
            int val = (pHead1->val > pHead2->val) ? pHead2->val : pHead1->val;
            ListNode* head = new ListNode(val);
            ListNode* tail = head;
            if (pHead1->val < pHead2->val)
            	pHead1 = pHead1->next;
            else 
                pHead2 = pHead2->next;
            while(pHead1 != NULL && pHead2 != NULL)
            {
                val = (pHead1->val > pHead2->val) ? pHead2->val : pHead1->val;
            	ListNode* h = new ListNode(val);
                tail->next = h;
                tail = tail->next;
            	if (pHead1->val < pHead2->val)
            		pHead1 = pHead1->next;
            	else 
            	    pHead2 = pHead2->next;
            }
            if(pHead1 == NULL && pHead2 == NULL)
            	return head;
        	else if(pHead1 != NULL && pHead2 == NULL)
        	{
            	tail->next = pHead1;
                return head;
            }
        	else if(pHead1 == NULL && pHead2 != NULL)
            {
                tail->next = pHead2;
                return head;
            }
        }
        return NULL;
    }
};
//递归
class Solution {
public:
 ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
 {
       if(pHead1 == NULL){
           return pHead2;
       }
       if(pHead2 == NULL){
           return pHead1;
       }
       if(pHead1->val <= pHead2->val){
           pHead1->next = Merge(pHead1->next, pHead2);
           return pHead1;
       }else{
           pHead2->next = Merge(pHead1, pHead2->next);
           return pHead2;
       }      
 }
};
