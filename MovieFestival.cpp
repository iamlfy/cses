#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	return p1.second < p2.second;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> times;
	for (int i = 0; i < n; ++i) {
		int start;
		int end;
		cin >> start >> end;
		times.push_back(make_pair(start, end));
	}

	sort(times.begin(), times.end(), cmp);

	int last_end = times[0].second;
	int count = 1;

	for (int i = 1; i < times.size(); ++i) {
		if (times[i].first >= last_end) {
			++count;
			last_end = times[i].second;
		}
	}

	cout << count;
	
	return 0;
}