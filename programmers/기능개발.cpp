#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> finish;
	for (int i = 0; i < progresses.size(); i++) {
		int day;
		day = (99 - progresses[i]) / speeds[i] + 1;
		finish.push(day);
	}

	while (!finish.empty()) {
		int fn = 1;
		int fd = finish.front();
		finish.pop();
		while (fd >= finish.front() && finish.front() != 0) {
			finish.pop();
			fn++;
		}
		answer.push_back(fn);
	}

	return answer;
}