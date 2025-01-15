#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(void) {
	map<int, int> nums;
	nums.insert({1, 1});
	nums.insert({1, 2});

	auto it = nums.begin();
	cout << typeid(it).name() << endl;
	cout << it->first << endl;

	return 0;
}
