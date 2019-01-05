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

int reverse(int x);



int main()
{

	cout << reverse(-3355);



	char a;
	cin >> a;
	return 0;
}

/***
Given a 32 - bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
	Output : 321
	Example 2 :

	Input : -123
	Output : -321
	Example 3 :

	Input : 120
	Output : 21
	Note :
	Assume we are dealing with an environment which could only store integers within the 32 - bit signed integer range : [−231, 231 − 1].For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

	****/



int reverse(int x)
{
	


	try {


		string a = to_string(x);
		std::reverse(a.begin(), a.end());
		int b = stoi(a);

		if (x < 0)
		{
			b = -b;
		}
		return b;
	}
	catch (const out_of_range &a)
	{
		return 0;
	}


}