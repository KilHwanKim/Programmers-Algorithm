#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct cmp {				// top�� ���� ���� ���� ������ �������� ����
	bool operator()(vector<int> t, vector<int> u) {
		return t[0] > u[0];
	}
};

int solution(vector<vector<int>> routes) {
	int answer = 1;
	vector<vector<int>> camera;
	priority_queue <vector<int>, vector<vector<int>>, cmp> pq;
	
	for (int i = 0; i < routes.size(); i++) 
		pq.push(routes[i]);
	
	vector<int> prev = pq.top();
	pq.pop();
	camera.push_back(prev);

	while (!pq.empty()) {
		vector<int> now = pq.top();
		pq.pop();
		if (prev[1] >= now[0]) {		// prev.end >= now.start
			if (camera[answer - 1][1] >= now[0]) {		// ���� ī�޶�� ���� �� ���� ��
				camera[answer - 1][0] = now[0];
				camera[answer - 1][1] = min(camera[answer - 1][1], now[1]);
			}
			else {									// ���� ī�޶�� ���� �� ���� ��
				camera.push_back(now);
				answer++;
			}
		}	
		else {							// prev.end < now.start
			camera.push_back(now);
			answer++;
		}
		prev = now;
	}
	return answer;
}

