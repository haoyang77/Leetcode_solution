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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);



int main()
{



	return 0;
}

/***
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Ex. 
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

**/

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* v;
	ListNode* v_copy;

	int carry = 0;
	int sum;
	bool first = true;

	while (l1 || l2)
	{
		if (l1&&l2)
		{
			sum = (l1->val + l2->val + carry) % 10;
			carry = (l1->val + l2->val + carry) / 10;


			if (first)
			{
				v_copy = v = new ListNode(sum);
				first = false;
			}
			else
			{
				v->next = new ListNode(sum);
				v = v->next;
			}

			l1 = l1->next;
			l2 = l2->next;
		}
		else if (!l2)
		{
			sum = (l1->val + carry) % 10;
			carry = (l1->val + carry) / 10;
			v->next = new ListNode(sum);
			v = v->next;

			l1 = l1->next;
		}
		else if (!l1)
		{
			sum = (l2->val + carry) % 10;
			carry = (l2->val + carry) / 10;
			v->next = new ListNode(sum);
			v = v->next;

			l2 = l2->next;
		}
	}

	if (carry == 1)
	{
		v->next = new ListNode(carry);
	}

	return v_copy;



}


/****
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode *v;

	int count = 0;
	int carry = 0;
	int add = 0;
	int sum = 0;

	ListNode* l1_copy = l1;
	ListNode* l2_copy = l2;



	while (l1_copy || l2_copy)
	{

		if (l1_copy&&l2_copy)
		{
			sum = l1_copy->val + l2_copy->val + carry;
			add = sum % 10;
			if (count == 0)
			{
				v = new ListNode(add);
				carry = sum / 10;

				l1_copy = l1_copy->next;
				l2_copy = l2_copy->next;
				++count;

			}
			else
			{
				ListNode* copy = v;
				for (int i = 0; i < count - 1; i++)
				{
					copy = copy->next;
				}

				copy->next = new ListNode(add);
				carry = sum / 10;

				l1_copy = l1_copy->next;
				l2_copy = l2_copy->next;
				++count;

			}
		}
		else if (!l1_copy)
		{
			sum = l2_copy->val + carry;
			add = sum % 10;
			ListNode* copy = v;
			for (int i = 0; i < count - 1; i++)
			{
				copy = copy->next;
			}
			copy->next = new ListNode(add);
			carry = sum / 10;

			l2_copy = l2_copy->next;
			++count;


		}
		else
		{
			sum = l1_copy->val + carry;
			add = sum % 10;
			ListNode* copy = v;
			for (int i = 0; i < count - 1; i++)
			{
				copy = copy->next;
			}
			copy->next = new ListNode(add);
			carry = sum / 10;

			l1_copy = l1_copy->next;
			++count;
		}
	}

	if (carry == 1)
	{
		ListNode* copy = v;
		for (int i = 0; i < count - 1; i++)
		{
			copy = copy->next;
		}
		copy->next = new ListNode(1);
	}



	return v;
}

*****/