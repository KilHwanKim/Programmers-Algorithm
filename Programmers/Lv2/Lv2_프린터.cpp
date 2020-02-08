#include <string>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	bool check[100] = { false, };         // �˻��� �۾����� üũ
	vector<int> temp = priorities;      // �켱���� ������ ����
	int p = priorities[location];       // ����
	int count = priorities.size();
	int i = 0, j = 0;
	int cp = 0;     // ���� �켱����

	sort(temp.begin(), temp.end(), greater<int>());
	cp = temp[i];

	while (count != 0) {
		if ((check[j] == false) && (cp == priorities[j])) {
			check[j] = true;
			count--;
			i++;
			answer++;
			if ((cp == p) && (j == location))
				break;
			cp = temp[i];
		}
		j++;
		if (j == priorities.size())
			j = 0;

	}

	return answer;
}

/*

���� �߰��� Ǯ��

int solution32(vector<int> priorities, int location) {
	int answer = 0;
	bool check = true;
	priority_queue <int, vector<int>, less<int>> pq;
	list<pair<int,int>> l;

	for (int i = 0; i < priorities.size(); i++) {
		pq.push(priorities[i]);
		l.push_back(make_pair(priorities[i],i));
	}

	do {
		int now = l.front().second;
		int prior = l.front().first;

		int p = pq.top();
		if (prior == p) {		// ����
			l.pop_front();
			pq.pop();
			answer++;
			if (now == location)
				check = false;
		}
		else {					// �Ұ���
			l.pop_front();
			l.push_back(make_pair(prior, now));
		}
	} while (check);

	return answer;
}

*/

