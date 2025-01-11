#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	if (2 == n || 3 == n) {
		cout << "NO SOLUTION";
		return 0;
	}

	if (n == 1) {
		cout << "1";
		return 0;
	}

	cout << "2 ";
	for (int i = 4; i <= n; i += 2) {
		cout << i << " ";
	}

	for (int i = 1; i <= n; i += 2) {
		cout << i << " ";
	}

	return 0;
}