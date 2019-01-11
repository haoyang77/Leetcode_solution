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


vector<vector<int>> fourSum(vector<int>& nums, int target);


int main()
{




	return 0;
}


vector<vector<int>> fourSum(vector<int>& nums, int target)
{
	vector<vector<int>> res;
	if (nums.size() < 4) return res;
	
	sort(nums.begin(), nums.end());
	



	for (int i = 0; i < nums.size() - 3; ++i)
	{
		int three_sum = target - nums[i];
		for (int j = i + 1; j < nums.size() - 2; ++j)
		{
			int back = nums.size() - 1;
			int front = j + 1;

			int two_sum = three_sum - nums[j];

			while (front < back)
			{
				if (two_sum < nums[back] + nums[front])
				{
					while (front < back&&nums[back] == nums[back - 1]) --back;

					--back;
				}
				else if (two_sum > nums[back] + nums[front])
				{
					while (front < back&&nums[front] == nums[front + 1]) ++front;

					++front;
				}
				else
				{
					vector<int> candidate = { nums[i],nums[j],nums[front],nums[back] };
					res.push_back(candidate);

					while (front < back&& nums[front] == nums[front + 1]) ++front;
					++front;

					while (front < back&&nums[back] == nums[back - 1]) --back;
					--back;
				}
			}

			while (j < nums.size() - 2 && nums[j] == nums[j + 1]) ++j;

		}

		while (i < nums.size() - 3 && nums[i] == nums[i + 1]) ++i;
	}




	return res;



}