#include <bits/stdc++.h>

using namespace std;

// v1
// int main(void) {
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	int m;
// 	int n;

// 	cin >> n >> m;

// 	vector<int> ticket_price(n);
// 	vector<int> customer_price(m);

// 	for (int i = 0; i < n; ++i) {
// 		cin >> ticket_price[i];
// 	}

// 	for (int i = 0; i < m; ++i) {
// 		cin >> customer_price[i];
// 	}

// 	sort(ticket_price.begin(), ticket_price.end());

// 	for (auto &c: customer_price) {
// 		if (ticket_price.empty()) {
// 			cout << "-1 ";
// 			continue;
// 		}

// 		int pos = -1;
// 		for (int i = 0; i < ticket_price.size();) {
// 			if (ticket_price[i] <= c) {
// 				pos = i++;
// 			} else {
// 				break;
// 			}
// 		}

// 		if (pos != -1) {
// 			cout << ticket_price[pos] << " ";
// 			ticket_price.erase(ticket_price.begin() + pos);
// 		} else {
// 			cout << "-1 ";
// 		}
		
// 	}
	
// 	return 0;
// }

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m;
	int n;

	cin >> n >> m;

	vector<int> ticket_price(n);
	vector<int> customer_price(m);

	for (int i = 0; i < n; ++i) {
		cin >> ticket_price[i];
	}

	for (int i = 0; i < m; ++i) {
		cin >> customer_price[i];
	}

	multiset<int> tickets(ticket_price.begin(), ticket_price.end());
	for (auto c : customer_price) {
		auto it = tickets.upper_bound(c);
		if (it == tickets.begin()) {
			cout << -1 << " ";
		} else {
			it = --it;
			cout << *it << " ";
			tickets.erase(it);
		}
	}
	
	return 0;
}