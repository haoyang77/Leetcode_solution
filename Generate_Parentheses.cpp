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


vector<string> generateParenthesis(int n);
void algorithm_func(int n, int left, int right, vector<string>& res, string current_pare);
bool checkpare(string pare);

int main()
{



	return 0;
}


vector<string> generateParenthesis(int n)
{
	vector<string> res;

	if (n == 0) return res;

	string pare;
	pare.push_back('(');

	algorithm_func(n, 0, 1, res, pare);

	sort(res.begin(), res.end());

	return res;



}

void algorithm_func(int n, int left, int right, vector<string>& res, string current_pare)
{
	if (left + right == 2*n)
	{
		if (checkpare(current_pare)) res.push_back(current_pare);
		return;
	}

	if (left + right == 2*n - 1)
	{
		current_pare.push_back(')');
		algorithm_func(n, left + 1, right, res, current_pare);
		return;
	}

	if (right < n)
	{
		string copy;
		copy = current_pare;
		copy.push_back('(');
		algorithm_func(n, left, right + 1, res, copy);
	}

	if (left < n - 1)
	{
		string copy;
		copy = current_pare;
		copy.push_back(')');
		algorithm_func(n, left + 1, right, res, copy);
	}

}
bool checkpare(string pare)
{
	string current;
	for (int i = 0; i < pare.size(); ++i)
	{
		if (pare[i] == '(') current.push_back(pare[i]);
		else
		{
			if (current.back() != '(') return false;
			else current.pop_back();
		}
	}

	return current.empty();


}