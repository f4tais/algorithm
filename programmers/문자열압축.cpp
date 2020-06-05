#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = s.size();

	if (answer == 1) return 1;

	for (int i = 1; i <= s.size() / 2; i++) {
		int cnt = 1;
		string fs = s.substr(0, i);
		string cmp, cp;

		for (int j = i; j < s.size(); j += i) {
			cmp = s.substr(j, i);

			if (!(fs.compare(cmp))) cnt++;
			else {
				if (cnt == 1) {
					cp += fs;
					fs = cmp;
				}
				else {
					cp = cp + to_string(cnt) + fs;
					fs = cmp;
					cnt = 1;
				}
			}
			if (j + i >= s.size()) {
				if (cnt != 1) {
					cp = cp + to_string(cnt) + fs;
					break;
				}
				else {
					cp = cp + s.substr(j);
					break;
				}
			}
		}
		answer = (answer > cp.size()) ? cp.size() : answer;
	}

	return answer;
}