#include <bits/stdc++.h>

using namespace std;

// v1
// int main(void) {
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	set<int> nums;

// 	int n = 0;
// 	cin >> n;
	
// 	for (int i = 0; i < n; ++i) {
// 		int num;
// 		cin >> num;
// 		nums.insert(num);
// 	}

// 	cout << nums.size();
	
// 	return 0;
// }

// sort
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int result = 1;
	int n = 0;
	
	cin >> n;

	vector<int> nums(n);
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end());
	for (int i = 1; i < nums.size(); ++i) {
		result += nums[i] != nums[i - 1];
	}

	cout << result;
	
	return 0;
}