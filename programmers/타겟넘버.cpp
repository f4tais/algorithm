#include <string>
#include <vector>

using namespace std;

int answer = 0;
void dfs(vector<int> numbers, int idx, int target, int num);

int solution(vector<int> numbers, int target) {
	dfs(numbers, 0, target, 0);
	return answer;
}

void dfs(vector<int> numbers, int idx, int target, int num) {
	if (idx == numbers.size()) {
		if (target == num) answer++;
		return;
	}

	dfs(numbers, idx + 1, target, num + numbers[idx]);
	dfs(numbers, idx + 1, target, num - numbers[idx]);
}