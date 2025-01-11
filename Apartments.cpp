#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	int m;
	int k;
	int ret = 0;

	cin >> n >> m >> k;

	vector<int> desiredSize(n);
	vector<int> actualSize(m);

	for (int i = 0; i < n; ++i) {
		cin >> desiredSize[i];
	}

	for (int i = 0; i < m; ++i) {
		cin >> actualSize[i];
	}

	sort(desiredSize.begin(), desiredSize.end());
	sort(actualSize.begin(), actualSize.end());

	int applicants = 0;
	int apartments = 0;
	while (applicants < n && apartments < m) {
		if (actualSize[apartments] >= (desiredSize[applicants] - k) && 
			actualSize[apartments] <= (desiredSize[applicants] + k)) {
			++ret;
			++applicants;
			++apartments;
		}
		else if (actualSize[apartments] < (desiredSize[applicants] - k)) {
			++apartments;
		}
		else {
			++applicants;
		}
	}

	cout << ret;
	
	return 0;
}