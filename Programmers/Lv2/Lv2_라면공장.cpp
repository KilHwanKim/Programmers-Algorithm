#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	priority_queue<int> pq;

	int start = 0;
	while (stock < k) {
		for (int i = start; i < dates.size(); i++) {
			if (dates[i] <= stock) {		// �ȹ޾Ƶ� �׸�
				pq.push(supplies[i]);
			}
			else {				// �޾ƾ��ϸ�
				start = i;		// �׳�¥�� ����
				break;
			}
		}
		answer++;		//�ް�
		stock += pq.top();
		pq.pop();
	}

	return answer;
}