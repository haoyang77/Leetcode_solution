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

vector<string> letterCombinations(string digits);
void algorithm(vector<string> &res, const vector<string> &mapping, string digit, int current, string final);


int main()
{
	vector<string> res;

	res = letterCombinations("23");

	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}

	char a;
	cin >> a;



	return 0;
}


vector<string> letterCombinations(string digits)
{
	vector<string> letterComb;

	if (digits.length() == 0) return letterComb;

	
	vector<string> mapping = { "0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };

	string store;

	algorithm(letterComb, mapping, digits, 0, store);

	return letterComb;

}


void algorithm(vector<string> &res, const vector<string> &mapping, string digit, int current, string final)
{
	if (current == digit.length())
	{
		res.push_back(final);
		return;
	}

	string num_string = mapping[digit[current]-'0'];

	for (int i = 0; i < num_string.length(); ++i)
	{
		string temp = final;
		temp.push_back(num_string[i]);

		algorithm(res, mapping, digit, current+1, temp);
	}

}