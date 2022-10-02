// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to find sum of digits
int digitSum(long n)
{
	long sum = 0;
	while (n) {
		sum += (n % 10);
		n /= 10;
	}
	return sum;
}

// Function to find maximum sum pair
// having the same sum of digits
void findMax(vector<int> arr, int n)
{
	// Map to store the sum of digits
	// in a number as the key and
	// the maximum number having
	// that sum of digits as the value
	unordered_map<int, int> mp;
	int ans = -1, pairi = 0, pairj = 0;
	for (int i = 0; i < n; i++) {

		// Store the current sum of digits
		// of the number in temp
		int temp = digitSum(arr[i]);

		// If temp is already present
		// in the map then update
		// ans if the sum is greater
		// than the existing value
		if (mp[temp] != 0) {
			if (arr[i] + mp[temp] > ans) {
				pairi = arr[i];
				pairj = mp[temp];
				ans = pairi + pairj;
			}
		}

		// Change the value in the map
		mp[temp] = max(arr[i], mp[temp]);
	}

	cout << pairi << " " << pairj
		<< " " << ans << endl;
}

// Driver Code Starts.
int main()
{
	vector<int> arr = { 55, 23, 32, 46, 88 };
	int n = arr.size();
	findMax(arr, n);
	return 0;
}
