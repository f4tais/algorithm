#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
	string answer = "";
	int n = number.size();
	int s = -1, max = -1, len = n - k, nj;

	for (int i = 0; i < len; i++) {
		// 처음엔 k개의 수를 제거한 size만큼 비교, 가장 큰 수를 찾은 뒤 제거한만큼 비교범위를 줄여나감.
		for (int j = s + 1; j < n - (len - i) + 1; j++) {
			if (max < number[j] - '0') {
				max = number[j] - '0';
				nj = j;
			}
		}
		answer.push_back(max + '0');
		s = nj;
		max = -1;
	}
	return answer;
}