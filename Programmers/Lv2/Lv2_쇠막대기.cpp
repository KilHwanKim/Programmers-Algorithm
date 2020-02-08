#include <string>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int solution(string arrangement) {
	int answer = 0;
	queue<int> q;

	for (int i = 0; i < arrangement.length() - 1; i++) {
		if (arrangement[i] == '(' && arrangement[i + 1] == '(')		//������� ����
			q.push(i);
	}

	char p, n;
	int index, end;
	answer += q.size();

	while (!q.empty()) {
		index = q.front();
		end = 1;
		q.pop();
		p = arrangement[index];

		for (int i = index + 1; i < arrangement.length(); i++) {
			n = arrangement[i];
			if (n == ')')
				end--;
			else
				end++;

			if (n == ')' && p == ')' && end == 0) {		// ������� ����
				break;
			}
			else if (n == ')' && p == '(') { 		//������
				answer++;
			}
			p = n;
		}

	}

	return answer;
}