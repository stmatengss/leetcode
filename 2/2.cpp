#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head = ListNode(0);
        ListNode *res = &head;
        ListNode *ptr = res;
		
		int val1 = 0, val2 = 0;
		int sum = 0, flag = 0;
		
		while(l1 != NULL||l2 != NULL) {
			val1 = 0;
			if(l1 != NULL) {
				val1 = l1->val;
				l1 = l1->next;
			}
			val2 = 0;
			if(l2 != NULL) {
				val2 = l2->val;
				l2 = l2->next;
			}
			sum = val1+val2;
			if(flag == 1) {
				sum++;
			}
			flag = 0;
			if(sum > 9) {
				flag = 1;
				sum = sum -10;
			}
			ptr->next = new ListNode(sum);
			ptr = ptr->next;
		}
		if (flag == 1)
		{
			ptr->next = new ListNode(1);
		}
		return res->next;
    }
};

void test()
{
	ListNode *l1 = new ListNode(2);
	ListNode *ptr1 = l1;
	ptr1->next = new ListNode(4);
	ptr1 = ptr1->next;
	ptr1->next = new ListNode(3);
	ptr1 = ptr1->next;
	
	ListNode *l2 = new ListNode(5);
	ListNode *ptr2 = l2;
	ptr2->next = new ListNode(6);
	ptr2 = ptr2->next;
	ptr2->next = new ListNode(4);
	ptr2 = ptr2->next;
	Solution t = Solution();
	ListNode *res = t.addTwoNumbers(l1, l2);
	
	while(res != NULL) {
		cout<<(res->val)<<endl;
		res = res->next;
	}
}

int main()
{
	test();
	return 0;
}
