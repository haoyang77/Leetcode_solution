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


int maxArea(vector<int>& height);

int main()
{

	char a;
	cin >> a;

	return 0;
}


int maxArea(vector<int>& height)
{
	int area = 0;
	int left = 0;
	int right = height.size() - 1;

	while (right > left)
	{
		area = max(area, (min(height[right], height[left])*(right - left)));

		if (height[right] > height[left]) ++left;
		else --right;
	}
	

	return area;

	
	



}


