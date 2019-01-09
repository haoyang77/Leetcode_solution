#include <iostream>
#include <cassert> //assert
#include <cstddef> //NULL
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>




using namespace std;

ListNode* removeNthFromEnd(ListNode* head, int n);

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


int main()
{




	return 0;
}


/**********

Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.



**************/

ListNode* removeNthFromEnd(ListNode* head, int n)
{
	int count = 0;

	ListNode* res = head;
	ListNode* iter = head;

	map<int, ListNode*> mapping;

	mapping[0] = head;


	while (head)
	{
		head = head->next;
		++count;
		mapping[count] = head;
	}

	int remove = count - n;

	if (remove == 0)
	{
		res = res->next;
		delete iter;

		return res;
	}

	ListNode* victim = mapping[remove];

	mapping[remove - 1]->next = victim->next;

	delete victim;


	return res;



	




}