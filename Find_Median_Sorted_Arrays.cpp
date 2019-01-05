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
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);


int main()
{
	



	char a;
	cin >> a;





	return 0;

}

/********
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Ex. 
nums1 = [1, 3]
nums2 = [2]

The median is 2.0

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5





*****/

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

	vector<int> store;

	for (vector<int>::iterator i = nums1.begin(); i != nums1.end(); ++i)
	{
		store.push_back(*i);
	}

	for (vector<int>::iterator a = nums2.begin(); a != nums2.end(); ++a)
	{
		store.push_back(*a);
	}

	sort(store.begin(), store.end());

	int size = store.size();

	if (size % 2 == 1)
	{
		return store[size / 2];
	}
	else
	{	
		double first = store[size / 2];
		double second = store[(size / 2) - 1];
		double median = (first + second) / 2.0;




		//double median = (store[size / 2] + store[(size / 2) - 1])/2;
		return median;
	}



}





