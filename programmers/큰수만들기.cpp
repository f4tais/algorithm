#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
	string answer = "";
	int n = number.size();
	int s = -1, max = -1, len = n - k, nj;

	for (int i = 0; i < len; i++) {
		// ó���� k���� ���� ������ size��ŭ ��, ���� ū ���� ã�� �� �����Ѹ�ŭ �񱳹����� �ٿ�����.
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