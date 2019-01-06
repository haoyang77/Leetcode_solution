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


bool isPalindrome(int x);

int main()
{
	bool test = isPalindrome(6);



	if (test) std::cout << "true";
	
	else std::cout << "false";


	std::cout << std::endl;


	char a;
	std::cin >> a;

	return 0;
}



/*****
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

*****/

bool isPalindrome(int x)
{
	/*****
	//Negetive numbers are not palindrome
	if (x < 0) return false;

	if (x >= 0 && x < 10) return true;
	
	std::map<int, int> number;
	int count = 0;

	while (x / 10 != 0)
	{
		int current = x % 10;
		x = x / 10;
		number[count] = current;
		++count;
	}

	number[count] = x;

	int iter = (number.size() / 2)-1;
	int max_ele = number.size() - 1;

	for (int i = 0; i <= iter; ++i)
	{
		if (number[i] != number[max_ele - i]) return false;
	}

	return true;
	********/

	//A much better solution by gaurav5

	if (x < 0 || (x != 0 && x % 10 == 0)) return false;
	int sum = 0;
	while (x > sum)
	{
		sum = sum * 10 + x % 10;
		x = x / 10;
	}
	return (x == sum) || (x == sum / 10);
}

//Test