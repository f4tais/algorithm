#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<string, string>& a, pair<string, string>& b) {
	return (a.second > b.second);
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<pair<string, string>> v;
	string temp;

	for (int i = 0; i < numbers.size(); i++) {
		temp = to_string(numbers[i]);
		switch (temp.size()) {
		case 1:
			for (int j = 0; j < 3; j++) temp.push_back(temp[0]);
			break;
		case 2:
			temp += temp;
			break;
		case 3:
			temp.push_back(temp[0]);
			break;
		}
		v.push_back(make_pair(to_string(numbers[i]), temp));
	}

	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < v.size(); i++) answer.append(v[i].first);

	if (answer[0] == '0') return "0";
	return answer;
}