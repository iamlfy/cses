#include <bits/stdc++.h>

using namespace std;

// notice: overflow

int main(void) {
	long long n = -1;
	cin >> n;

	while (1) {
		printf("%lld ", n);
		if (n == 1) {
			break;
		}
		
		if (n % 2 == 0) {
			n /= 2;
		} else {
			n = n * 3 + 1;
		}
	}

	return 0;
}