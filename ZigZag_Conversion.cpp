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

string convert(string s, int numRows);

int main()
{


	cout << convert("PAYPALISHIRING", 3);


	char a;
	cin >> a;
	return 0;
}

/****
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Ex. 

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Ex. 
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I


****/




string convert(string s, int numRows)
{
	//Check the length of the string 
	if (s.length() <= numRows||numRows<2) return s;



	vector<string> rows(numRows);

	for (int i = 0; i < s.length(); ++i)
	{
		int index = i % (2 * numRows - 2);
		if (index >= numRows)
		{
			index = 2 * numRows - 2 - index;
		}

		rows[index].push_back(s[i]);
	}

	string product;
	for (int i = 0; i < numRows; ++i)
	{

		product += rows[i];
	}

	return product;






}
