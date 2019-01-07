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


string longestCommonPrefix(vector<string>& strs);

int main()
{





	char a;
	cin >> a;

	return 0;
}

string longestCommonPrefix(vector<string>& strs)
{

	string c;
	//Common base case
	if (strs.size() == 0) return c;

	if (strs.size() == 1) return strs[0];
	





	int max = strs[0].length();


	if (max == 0) return c;

	


	for (size_t i = 1; i < strs.size(); ++i)
	{
		if (max == 0) return c;
		if (strs[i].empty()) return strs[i];
		for (int j = 0; j < max; ++j)
		{
			if (strs[0][j] != strs[i][j])
			{
				max = j;
				break;
			}

		}

	}

	
	c = strs[0].substr(0, max);

	return c;




}