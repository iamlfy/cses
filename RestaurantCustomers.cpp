#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	vector<pair<int, bool>> times;
	for (int i = 0; i < n; ++i) {
		int arrive;
		int leave;
		cin >> arrive >> leave;
		times.push_back(make_pair(arrive, true));
		times.push_back(make_pair(leave, false));
	}

	sort(times.begin(), times.end());

	int cur = 0;
	int maximum = 0;
	for (size_t i = 0; i < times.size(); ++i) {
		if (times[i].second) {
			++cur;
		} else {
			--cur;
		}

		maximum = max(maximum, cur);
	}

	cout << maximum;
	
	return 0;
}