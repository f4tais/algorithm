#include <iostream>
using namespace std;

// 피보나치 함수
int dp[41];
int fib(int n);

int main() {
	int T, N;

	cin >> T;
	while (T--) {
		cin >> N;
		if (N == 0)
			cout << '1' << ' ' << '0' << endl;
		else {
			fib(N);
			cout << dp[N - 1] << ' ' << dp[N] << endl;
		}
	}

	return 0;
}

int fib(int n) {
	if (n == 0) {
		dp[0] = 0;
		return 0;
	}
	else if (n == 1) {
		dp[1] = 1;
		return 1;
	}
	else if (dp[n] != 0) {
		return dp[n];
	}
	else {
		return dp[n] = fib(n - 1) + fib(n - 2);
	}
}