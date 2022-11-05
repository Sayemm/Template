#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <int> div;

	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			div.push_back(i);
			if (i != n / i) div.push_back(n / i);
		}
	}

	sort(div.begin(), div.end());
	for (auto x : div) {
		cout << x << " ";
	}

	return 0;
}

// Complexity: O(sqrt(n))
