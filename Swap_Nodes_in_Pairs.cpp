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


int main()
{





	return 0;
}


ListNode* swapPairs(ListNode* head) {

	if (!head||!head->next) return head;


	ListNode* res = head->next;

	bool change = true;

	factory(head,change);




	return res;


	








}

void factory(ListNode* tail, bool change)
{
	//Space: O(n) Time O(n) 
	if (!change)
	{
		if (!tail->next->next || !tail->next) return;
	}


	if (change)
	{
		ListNode* second = tail->next;

		tail->next = second->next;
		second->next = tail;
		change = !change;
		factory(tail, change);
	}
	else
	{
		ListNode* recursive = tail->next;
		tail->next = recursive->next;
		change = !change;

		factory(recursive, change);
	}
	



}