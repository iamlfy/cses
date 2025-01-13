#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, x;
	cin >> n >> x;
	int ret = 0;

	vector<int> weights(n);
	for (int i = 0; i < n; ++i) {
		cin >> weights[i];
	}

	sort(weights.begin(), weights.end());

	int left = 0;
	int right = n - 1;

	while (left <= right) {
		++ret;
		if (left == right) {
			break;
		}

		if (weights[left] + weights[right] <= x) {
			++left;
			--right;
		} else {
			--right;
		}
	}

	cout << ret;

	return 0;
}