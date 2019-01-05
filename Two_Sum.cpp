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


vector<int> twoSum(vector<int>& nums, int target);

int main()
{
	vector<int> input;
	input.push_back(2);
	input.push_back(7);
	input.push_back(11);
	input.push_back(15);
	vector<int> output;

	output = twoSum(input, 17);

	
	for (auto i : output)
	{
		cout << i << endl;
	}



	char a;
	cin >> a;
	
	return 0;
}
/**
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Ex. 
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
**/

vector<int> twoSum(vector<int>& nums, int target)
{
	map<int, int> store;
	vector<int> return_vect;
	
	int search;

	for (int i = 0; i < nums.size(); ++i)
	{
		int compare = target - nums[i];

		if (store.find(compare) != store.end())
		{
			return_vect.push_back(store.find(compare)->second);
			return_vect.push_back(i);
			return return_vect;
		}
		else
		{
			store[nums[i]] = i;
		}
	}


}