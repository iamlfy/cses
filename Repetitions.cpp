#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string dna;
	cin >> dna;
	
	int longest = 1;
	int cur_len = 1;
	
	for (int i = 1; i < dna.size(); ++i) {
		if (dna[i] == dna[i - 1]) {
			++cur_len;
		} else {
			cur_len = 1;
		}
		longest = max(longest, cur_len);
	}
	
	cout << longest << '\n';
	
	return 0;
}