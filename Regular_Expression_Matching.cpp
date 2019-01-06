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

bool isMatch(std::string s, std::string p);

int main()
{

	if (isMatch("abcdefg", ".*.*"))
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
	
	/*******
	//Some base case
	if (p.empty()) return s.empty();


	if (p[1] == '*')
	{
		return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p));
	}
	else
		return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
	******/

	//DP method

	int m = s.length();
	int n = p.length();

	vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

	dp[0][0] = true;

	for (int i = 0; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (p[j - 1] == '*')
			{
				dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
			}
			else
			{
				dp[i][j] = (i>0)&&(s[i - 1] == p[j - 1] || p[j - 1] == '.') && dp[i - 1][j - 1];
			}
		}
	}


	return dp[m][n];













	/******
	int m = s.length(), n = p.length();
	vector<vector<bool> > dp(m + 1, vector<bool>(n + 1, false));
	dp[0][0] = true;
	for (int i = 0; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (p[j - 1] == '*')
				dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
			else dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
	return dp[m][n];
	****/
}