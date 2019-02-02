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

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseKGroup(ListNode* head, int k);
ListNode* reverse_linklist(ListNode* head, ListNode* tail, ListNode* &curcopy);

int main()
{
	
	ListNode* first = new ListNode(1);
	ListNode* iter = first;

	for (int i = 2; i < 6; ++i)
	{
		iter->next = new ListNode(i);
		iter = iter->next;
	}

	ListNode* out = reverseKGroup(first, 2);

	while (out)
	{

		cout << (out->val);
		out = out->next;
	}


	char a;

	cin >> a;



	return 0;


	
}

ListNode* reverseKGroup(ListNode* head, int k) {

	//Edge Cases
	if (k == 1 || head == nullptr || head->next == nullptr) return head;


	ListNode dummy(0);


	ListNode* cur = &dummy;
	ListNode* next = head;
	cur->next = head;



	while (next)
	{
		int count = 0;



		while (count != k && next)
		{
			next = next->next;
			++count;
		}

		if (count != k)
		{
			return (&dummy)->next;
		}

		ListNode* crucopy = nullptr;
		ListNode* newnext = reverse_linklist(cur->next, next, crucopy);
		cur->next = newnext;

		cur = crucopy;

	}

	return (&dummy)->next;

}


ListNode* reverse_linklist(ListNode* head, ListNode* tail, ListNode* &curcopy)
{
	curcopy = head;
	ListNode* next = nullptr;
	ListNode* prev = nullptr;




	while (head != tail)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}

	curcopy->next = tail;



	return prev;



}
