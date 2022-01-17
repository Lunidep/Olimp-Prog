#include <vector>
#include <iostream>
#include <intrin.h>
#include <algorithm>
using namespace std;
 
int main()
{
	int res = 0, n, k;
	cin >> n >> k;
	vector<int> nums(n);
	vector<int> results;
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	for (int mask = 0; mask < (1 << n); mask++)
	{
		res = 0;
		if (__popcnt(mask) != k)
			continue;
		for (int i = 0; i < n; i++)
		{
			if ((1 << i) & mask)
				res ^= nums[i];
		}
		results.push_back(res);
	}
	for (int i = 0; i < results.size(); i++)
		res = max(res, results[i]);
	cout << res;
}