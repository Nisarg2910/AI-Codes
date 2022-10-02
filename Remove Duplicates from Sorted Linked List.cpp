//Problem Statement/:-https://workat.tech/problem-solving/practice/remove-duplicates-sorted-linked-list

/* This is the ListNode class definition

class ListNode {
public:
	int data;
	ListNode* next;

	ListNode(int data) {
		this->data = data;
		this->next = NULL;
	}
};
*/

int getMiddleElementOfLinkedList (ListNode* list) {
    if(!head)
		return NULL;
	else
	{
		ListNode *p = head;
		ListNode *q = head->next;
		while(q)
		{
			if(p->data != q->data)
			{
				p->next = q;
				p = p->next;
			}
			q = q->next;
		}
		p->next = NULL;
		return head;
	}
}