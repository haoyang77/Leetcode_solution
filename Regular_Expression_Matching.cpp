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


bool isMatch(std::string s, std::string p);

int main()
{

	if (isMatch("aaa", "a*a"))
	{
		std::cout << "true";
		std::cout << std::endl;
	}
	else
	{
		std::cout << "false";
		std::cout << std::endl;
	}




	char a;

	std::cin >> a;
	return 0;
}

/*****
Given an input string(s) and a pattern(p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string(not partial).

Note:

s could be empty and contains only lowercase letters a - z.
p could be empty and contains only lowercase letters a - z, and characters like . or *.
Example 1 :

	Input :
	s = "aa"
	p = "a"
	Output : false
	Explanation : "a" does not match the entire string "aa".
	Example 2 :

	Input :
	s = "aa"
	p = "a*"
	Output : true
	Explanation : '*' means zero or more of the precedeng element, 'a'.Therefore, by repeating 'a' once, it becomes "aa".
	Example 3 :

	Input :
	s = "ab"
	p = ".*"
	Output : true
	Explanation : ".*" means "zero or more (*) of any character (.)".
	Example 4 :

	Input :
	s = "aab"
	p = "c*a*b"
	Output : true
	Explanation : c can be repeated 0 times, a can be repeated 1 time.Therefore it matches "aab".
	Example 5 :

	Input :
	s = "mississippi"
	p = "mis*is*p*."
	Output : false

	*******////



bool isMatch(std::string s, std::string p)
{
	//Some base case
	if (p.empty()) return s.empty();

	if (p == ".*") return true;

	//simplified p
	if (p.size() >= 4)
	{
		if (p[0] == p[2] && p[1] == p[3]=='*') return isMatch(s, p.substr(2));
	}

	

	if (s.empty())
	{
		if (p.size() / 2 == 1) return false;
		
		int count = 0;
		for (auto i : p)
		{
			i == '*';
			++count;
		}

		if (count == p.size() / 2) return true;
		else return false;
	}

	if (p[0] == '.'&&p[1] != '*') return isMatch(s.substr(1), p.substr(1));

	/////////
	


	if (p[1] == '*')
	{
		if (p[0] == '.')
		{
			for (int i = 0; i < s.size(); i++)
			{
				if (isMatch(s.substr(i), p.substr(2)))
				{
					return true;
				}
				else return false;
			}


		}
		else
		{
			if (p[0] != s[0]) return isMatch(s, p.substr(2));
			else
			{
				std::string copy_s = s;
				while (copy_s[0] == p[0]&&!copy_s.empty())
				{
					copy_s = copy_s.substr(1);
				}
				return isMatch(copy_s, p.substr(2));
				

			}
		}
	}
	else
	{
		if (p[0] == '.')
		{
			return isMatch(s.substr(1), p.substr(1));
		}
		else
		{
			if (p[0] != s[0]) return false;
			else
			{
				return isMatch(s.substr(1), p.substr(1));
			}
		}
	}







}