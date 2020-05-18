#include <iostream>
#include <cmath>
using namespace std;

// 소수 구하기
int main() {
	int N, M;
	int j;

	cin >> N >> M;
	bool* arr = new bool[M + 1];

	for (int i = 0; i < M + 1; i++) {
		arr[i] = true;
	}

	for (int i = 2; i < M + 1; i++) {
		if (arr[i]) {
			if ((unsigned int)pow(i, 2) > 1000001) {
				break;
			}
			else {
				for (j = (int)pow(i, 2); j < M + 1;) {
					arr[j] = false;
					j = j + i;
				}
			}
		}
	}

	if (N == 1) N++;

	for (int i = N; i < M + 1; i++) {
		if (arr[i] && i >= N)
			cout << i << "\n";
	}

	delete[] arr;

	return 0;
}