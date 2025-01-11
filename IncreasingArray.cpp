#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	long long moves = 0;

	cin >> n;

	vi nums(n);
	cin >> nums[0];
	for (int i = 1; i < n; ++i) {
		cin >> nums[i];
		if (nums[i] < nums[i - 1]) {
			moves += nums[i - 1] - nums[i];
			nums[i] = nums[i - 1];
		}
	}

	cout << moves;

	return 0;
}