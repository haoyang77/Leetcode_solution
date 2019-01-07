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


string intToRoman(int num);

int main()
{
	cout << intToRoman(1994);




	char a;

	cin >> a;

	return 0;
}

/**********
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. 
Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. 
However, the numeral for four is not IIII. Instead, the number four is written as IV. 
Because the one is before the five we subtract it making four. 
The same principle applies to the number nine, which is written as IX. 
There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: 3
Output: "III"
Example 2:

Input: 4
Output: "IV"
Example 3:

Input: 9
Output: "IX"
Example 4:

Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 5:

Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.



***********/



string intToRoman(int num)
{
	int thousand = num / 1000;
	num = num % 1000;
	int hundred = num / 100;
	num = num % 100;
	int ten = num / 10;
	num = num % 10;

	string num_in_roman;

	//thousand

		for (int i = 0; i < thousand; ++i)
		{
			num_in_roman.push_back('M');
		}


	//hundred
	if (hundred > 0)
	{
		if (hundred < 5)
		{
			if (hundred == 4)
			{
				//num_in_roman.push_back('CD');
				num_in_roman.insert(num_in_roman.size(), "CD");
			}
			else
			{
				for (int i = 0; i < hundred; ++i)
				{
					num_in_roman.push_back('C');
				}
			}
		}
		else
		{
			if (hundred == 9)
			{
				//num_in_roman.push_back('CM');
				num_in_roman.insert(num_in_roman.size(), "CM");
			}
			else
			{
				num_in_roman.push_back('D');
				for (int i = 0; i < hundred - 5; ++i)
				{
					num_in_roman.push_back('C');
				}
			}
		}
	}

	//ten
	if (ten > 0)
	{
		if (ten < 5)
		{
			if (ten == 4)
			{
				//num_in_roman.push_back('XL');
				num_in_roman.insert(num_in_roman.size(), "XL");
			}
			else
			{
				for (int i = 0; i < ten; ++i)
				{
					num_in_roman.push_back('X');
				}
			}
		}
		else
		{
			if (ten == 9)
			{
				//num_in_roman.push_back('XC');
				num_in_roman.insert(num_in_roman.size(), "XC");
			}
			else
			{
				num_in_roman.push_back('L');
				for (int i = 0; i < ten - 5; ++i)
				{
					num_in_roman.push_back('X');
				}
			}
		}
	}

	//single

	if (num > 0)
	{
		if (num < 5)
		{
			if (num == 4)
			{
				//num_in_roman.push_back('IV');
				num_in_roman.insert(num_in_roman.size(), "IV");
			}
			else
			{
				for (int i = 0; i < num; ++i)
				{
					num_in_roman.push_back('I');
				}
			}
		}
		else
		{
			if (num == 9)
			{
				//num_in_roman.push_back('IX');
				num_in_roman.insert(num_in_roman.size(), "IX");
			}
			else
			{
				num_in_roman.push_back('V');
				for (int i = 0; i < num - 5; ++i)
				{
					num_in_roman.push_back('I');
				}
			}
		}
	}

	return num_in_roman;

}