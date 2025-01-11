#include <bits/stdc++.h>

using namespace std;

// v1
/*
int main(void) {
	int n = 0;
	int num = -1;
	int sumn = 0;
	int sum_input = 0;

	unordered_set<int> exsits;

	// freopen("./tests/12.in", "r", stdin);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		sumn += i;
	}
	// cout << "n is " << n << endl;

	for (int i = 0; i < n - 1; ++i) {
		cin >> num;
		exsits.insert(num);
	}

	for (int i = 1; i <= n; ++i) {
		if (exsits.find(i) == exsits.end()) {
			cout << i;
			return 0;
		}
	}

	return 0;	
}
*/

// v2
/*
int main(void) {
	int n = 0;
	int num = -1;
	int sumn = 0;
	int sum_input = 0;

	unordered_set<int> exsits;

	// freopen("./tests/12.in", "r", stdin);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		sumn += i;
	}
	// cout << "n is " << n << endl;

	for (int i = 0; i < n - 1; ++i) {
		cin >> num;
		sum_input += num;
	}
	cout << sumn - sum_input;

	return 0;	
}
*/

typedef long long ll;
// v3
int main(void) {
	int n = 0;
	ll sumn = 0;

	// freopen("./tests/12.in", "r", stdin);

	cin >> n;

	sumn = (ll)n * (ll)(n + 1) / 2;

	int a = 0;
	n--;
	while (n--) {
		scanf("%d", &a);
		sumn -= a;
	}
	cout << sumn;

	return 0;
}