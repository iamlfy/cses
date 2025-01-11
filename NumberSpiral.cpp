#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ull n;
	cin >> n;

	for (ull i = 0; i < n; ++i) {
		ull row;
		ull col;

		cin >> row >> col;

		// num[row][col]
		// find at row or col
		ull target = max(row, col);
		ull target_max = target * target;
		ull target_min = target_max - 2 * (target - 1);

		// if (target % 2 == 1) {
		// 	cout << ((target == row) ? (target_min + col - 1) : (target_max - row + 1)) << "\n";
		// } else {
		// 	cout << ((target == row) ? (target_max - col + 1) : (target_min + row - 1)) << "\n";
		// }

		if (target == row) {
			if (target % 2 == 1) {
				// increasing
				cout << target_min + col - 1 << "\n";
			} else {
				// decreasing
				cout << target_max - col + 1 << "\n";
			}
		} else {
			if (target % 2 == 0) {
				// increasing
				cout << target_min + row - 1 << "\n";
			} else {
				// decreasing
				cout << target_max - row + 1 << "\n";
			}
		}
	}
	
	return 0;
}