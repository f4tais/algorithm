#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ¼ö Ã£±â
vector<int> a;
int binarySearch(int low, int high, int target);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	int N, M;
	
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		a.reserve(N);
		for (int i = 0; i < N; i++) {
			int x;
			cin >> x;
			a.push_back(x);
		}
		sort(a.begin(), a.end());

		cin >> M;
		for (int i = 0; i < M; i++) {
			int x;
			cin >> x;
			cout << binarySearch(0, N - 1, x) << "\n";
		}

		a.clear();
	}
	return 0;
}

int binarySearch(int low, int high, int target) {
	if (low > high)
		return 0;
	else {
		int mid = (low + high) / 2;

		if (a[mid] == target)
			return 1;
		else if (a[mid] > target)
			return binarySearch(low, mid - 1, target);
		else if (a[mid] < target)
			return binarySearch(mid + 1, high, target);
	}
}