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


int threeSumClosest(vector<int>& nums, int target);

using namespace std;


int main()
{




	char a;

	cin >> a;

	return 0;
}


int threeSumClosest(vector<int>& nums, int target)
{
	if (nums.size() == 3) return nums[0] + nums[1] + nums[2];

	sort(nums.begin(), nums.end());

	int difference = INT_MAX;
	int candidate;



	for (int i = 0; i < nums.size()-2; ++i)
	{
		int front = i + 1;
		int back = nums.size() - 1;

		while (front < back)
		{
			int sum = nums[i] + nums[front] + nums[back];

			//Check the difference to judge if needs to change candidate
			if (abs(sum - target) < difference)
			{
				candidate = sum;
				difference = abs(sum - target);
			}


			if (sum > target)
			{
				while ((nums[back] == nums[back - 1]) && (front < back)) --back;

				--back;
			}
			else if (sum < target)
			{
				while ((nums[front] == nums[front + 1]) && (front < back)) ++front;

				++front;
			}
			else return target;
		}


		while (i < nums.size() - 2 && nums[i] == nums[i + 1]) ++i;


	}


	return candidate;

}