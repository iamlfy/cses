#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	// vector<ll> maximum(n);
	vector<ll> nums(n);
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}

	// maximum[0] = nums[0];
	// for (int i = 1; i < n; ++i) {
	// 	maximum[i] = max(maximum[i - 1] + nums[i], nums[i]);
	// 	// cout << "maximum[" << i << "] is " << maximum[i] << endl;
	// }

	// 判断字数组的最大值时，只和maximum[i-1]的值，以及当前num有关
	// 所以可以用一个变量保存maximum[i-1]的值，节省空间
	ll ret = nums[0];
	ll sum = 0;

	for (int i = 0; i < n; ++i) {
		sum += nums[i];
		if (sum > ret) {
			ret = sum;
		}

		if (sum < 0) {
			sum = 0;
		}
	}

	// sort(maximum.begin(), maximum.end());
	// cout << *(--maximum.end()) << endl;
	cout << ret << "\n";
	
	return 0;
}