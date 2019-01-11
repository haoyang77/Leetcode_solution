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

bool isValid(string s);

int main()
{
	bool check = isValid("([)]");

	if (check) cout << "true" << endl;
	else cout << "false" << endl;



	char a;
	cin >> a;


	return 0;
}
/***************
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true

Input: "{([])}"
Output: true
*********************/


bool isValid(string s)
{

	if (s.empty()) return true;

	if (s.length() % 2 == 1) return false;

	if (s[0] == ')' || s[0] == '}' || s[0] == ']') return false;
	vector<char> order;

	
	

	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == ')')
		{
			if (order.back() != '(') return false;
			else order.pop_back();
		}

		else if (s[i] == '}')
		{
			if (order.back() != '{') return false;
			else order.pop_back();
		}

		else if (s[i] == ']')
		{
			if (order.back() != '[') return false;
			else order.pop_back();
		}
		else order.push_back(s[i]);
	}


	return order.empty();



}