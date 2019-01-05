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

int lengthOfLongestSubstring(string s);

int main()
{


	return 0;
}

/******
Given a string, find the length of the longest substring without repeating characters.

Ex. 
Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
			 Note that the answer must be a substring, "pwke" is a subsequence and not a substring.




******/



int lengthOfLongestSubstring(string s)
{
	int length = 0;
	map<char, int> set;
	int left = 0;

	for (int right = 0; right < s.size(); right++)
	{
		if (set.find(s[right]) != set.end())
		{
			left = max(left, set[s[right]] + 1);
		}



		set[s[right]] = right;
		length = max(length, right - left + 1);


	}


	return length;


}