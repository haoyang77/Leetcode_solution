#include <iostream>
#include <cassert> //assert
#include <cstddef> //NULL
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);


int main()
{
	ListNode* l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(4);

	ListNode* l2 = new ListNode(1);
	l2->next = new ListNode(3);
	l2->next->next = new ListNode(4);




	ListNode* res = mergeTwoLists(l1, l2);
	return 0;
}


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	//Dealing with empty list
	if (!l2 || !l1)
	{
		if (l1) return l1;
		else return l2;
	}

	ListNode* res;

	if (l1->val > l2->val)
	{
		res = l2;
		l2 = l2->next;
	}
	else
	{
		res = l1;
		l1 = l1->next;
	}

	ListNode* iter;
	iter = res;



	while (l1&&l2)
	{
		if(l1->val>l2->val)
		{
			iter->next = l2;
			l2 = l2->next;
		}
		else if(l2->val>l1->val)
		{
			iter->next = l1;
			l1 = l1->next;
		}
		else
		{
			iter->next = l1;
			l1 = l1->next;
			iter = iter->next;
			iter->next = l2;
			l2 = l2->next;
		}

		if (iter->next) iter = iter->next;
	}

	//if (!l1) iter->next = l2;
	//else iter->next = l1;



	!l1 ? iter->next = l2 : iter->next = l1;


	return res;


}


