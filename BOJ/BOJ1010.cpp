#include <iostream>
#include <stack>
using namespace std;

// 다리 놓기
int dp[31][31];

int nCr(int n, int r) {
	if (n == r || r == 0)
		return 1;
	if (dp[n][r])
		return dp[n][r];
	return dp[n][r] = nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int n, m;
		cin >> n >> m;
		cout << nCr(m, n) << '\n';
	}

	return 0;
}