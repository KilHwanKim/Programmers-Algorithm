#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int selectNext(vector<int> cost, vector<bool> check) {
	int end = 0; 
	int min = 500001;
	for (int i = 1; i < cost.size(); i++) {
		if (check[i] == false && cost[i] < min) {		// ����� ���� ���� ������ Ž�� 
			min = cost[i];
			end = i;
		}
	}
	return end;
}

// ���ͽ�Ʈ�� �˰��� 
int solution(int N, vector<vector<int> > road, int K) {
	int answer = 0;
	vector<map<int, int>> graph(N + 1);	// ��� ����
	vector<int> cost(N + 1, 500001);		// ����� �ִ�ġ�� �ʱ�ȭ
	vector<bool> check(N + 1, false);
	cost[1] = 0;	// 1���� 0���� �ʱ�ȭ

	for (int i = 0; i < road.size(); i++) {		// 1-2, 2-1 �� ���� ���� 
		if (graph[road[i][0]].find(road[i][1]) != graph[road[i][0]].end()) {		// ������ �̹� �ִٸ�
			if (graph[road[i][0]][road[i][1]] > road[i][2]) {						// �� ���� ����� ä��
				graph[road[i][0]][road[i][1]] = road[i][2];
				graph[road[i][1]][road[i][0]] = road[i][2];
			}
		}
		else {		// ������ ���ٸ� �ű� ����
			graph[road[i][0]].insert(make_pair(road[i][1], road[i][2]));
			graph[road[i][1]].insert(make_pair(road[i][0], road[i][2]));
		}
	}

	for (int i = 0; i < N - 1; i++) {		// N-1��ŭ ���� (1���� 0���� �ʱ�ȭ �ص���)
		int end = selectNext(cost, check);			// �Ź� ����� ���� ���� ������ �ٽ� Ž��
		for (auto j : graph[end]) {			// ����� ���� ���� ������ ����� ������ ��ȸ
			if (check[j.first] == false)	// ���� ������ ���� ���̶��
				cost[j.first] = min(cost[j.first], cost[end] + j.second);		// ���� ���� ���Ͽ� ����
		}
		check[end] = true;
	}

	for (int i = 1; i < cost.size(); i++) {
		if (cost[i] <= K)
			answer++;
	}

	return answer;
}