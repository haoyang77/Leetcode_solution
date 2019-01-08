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



vector<vector<int>> threeSum(vector<int>& nums);
int main()
{
	vector<int> test = { -1, 0, 1, 2, -1, -4 };

	vector<vector<int>> res;
	res = threeSum(test);

	for (int i = 0; i < res.size(); ++i)
	{
		for (int j = 0; j < res[i].size(); ++j)
		{
			cout << res[i][j];
		}
		cout << endl;
	}






	char a;

	cin >> a;

	return 0;
}





/*************
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*************/

vector<vector<int>> threeSum(vector<int>& nums)
{

	vector<vector<int>> three_sum_return;

	if (nums.size() <= 2) return three_sum_return;


	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); ++i)
	{
		int front = i + 1;
		int back = nums.size() - 1;



		int sum = -nums[i];

		while (front < back)
		{
			int sum_fb = nums[front] + nums[back];

			if (sum > sum_fb)
			{
				while (nums[front] == nums[front+1] && front < back)
				{
					++front;
				}
				++front;
			}
			else if (sum < sum_fb)
			{
				while (nums[back] == nums[back-1] && front < back)
				{
					--back;
				}
				--back;
			}
			else
			{
				vector<int> tri = { nums[i],nums[front],nums[back] };
				three_sum_return.push_back(tri);

				while (tri[1] == nums[front] && front < back) { ++front; }

				while (tri[2] == nums[back] && front < back) { --back; }
			}

		}

		while (i+1 < nums.size()&&nums[i] == nums[i+1]) { ++i; }


	}

	return three_sum_return;




}