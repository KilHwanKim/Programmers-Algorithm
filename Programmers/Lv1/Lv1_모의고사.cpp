#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int a = 0, b = 0, c = 0;
	int size = answers.size();

	for (int i = 0; i < size; i++) {
		int temp = (i % 5) + 1;
		if (temp == answers[i])			// 1,2,3,4,5 ������ ���
			a++;

		temp = ((i % 8) + 1) / 2;
		if (i % 2 == 0) {				// �ϴ� ¦����ȣ�� �� 2�� ����
			if (answers[i] == 2)
				b++;
		}
		else if (temp % 5 == 1) {		// 1
			if (temp == answers[i])		// �״��
				b++;
		}
		else {		//  3,5,7�� 
			if ((temp + 1) == answers[i])	// temp+1
				b++;
		}

		temp = (i % 10) / 2;
		if (temp > 2) {		// 3,4�϶� (6,7,8,9��)
			if (temp + 1 == answers[i])		// temp+1
				c++;
		}
		else if (temp == 0) {		// 0�϶� (0,1��)
			if (answers[i] == 3)		// 3
				c++;
		}
		else if (temp <= 2) {		// 1,2�϶� (2,3,4,5��)
			if (temp == answers[i])		// �״��
				c++;
		}
	}
	int maxV = max(a, b);
	maxV = max(maxV, c);
	if (a == maxV)
		answer.push_back(1);
	if (b == maxV)
		answer.push_back(2);
	if (c == maxV)
		answer.push_back(3);

	return answer;
}