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

string longestPalindrome(string s);

int main()
{
	string test = "cabbaew";

	cout << longestPalindrome(test);


	char a; 
	cin >> a;





	return 0;
}

string longestPalindrome(string s)
{
	//Initialize the first palindrome. 
	string palindrome;
	palindrome.push_back(s[0]);
	
	if (s[0] == s[1])
	{
		palindrome.push_back(s[1]);
	}

	int length = s.length();

	for (int i = 1; i < length; i++)
	{
		string test;
		test.push_back(s[i]);
		for (int count = 1; count < i + 1; ++count)
		{
			if (count + i >= length)	break;

			if (s[i + count] == s[i - count])
			{
				string front;
				front.push_back(s[i + count]);
				test.push_back(front[0]);
				test.insert(0, front);

				if (test.length() > palindrome.length())
				{
					palindrome = test;
				}
			}
			else break;

		}

		if (s[i] == s[i + 1])
		{
			string test1;
			test1.push_back(s[i]);
			test1.push_back(s[i]);

			if (test1.length() > palindrome.length())
			{
				palindrome = test1;
			}

			for (int count = 1; count < i + 1; ++count)
			{
				if (count + i + 1 >= length) break;

				if (s[i + 1 + count] == s[i - count])
				{
					string front;
					front.push_back(s[i - count]);
					test1.push_back(front[0]);
					test1.insert(0, front);

					if (test1.length() > palindrome.length())
					{
						palindrome = test1;
					}
				}
				else break;
			}
		}



	}



	return palindrome;





}