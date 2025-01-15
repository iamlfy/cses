#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	bool has_solution = false;

	int n;
	int target;
	cin >> n >> target;

	map<int, int> nums;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		
		auto it = nums.find(target - num);
		if (it != nums.end()) {
			cout << (it->second + 1) << " " << (i + 1) << "\n";
			has_solution = true;
			break;
		}

		nums[num] = i;
	}

	if (!has_solution) {
		cout << "IMPOSSIBLE\n";
	}
	
	return 0;
}