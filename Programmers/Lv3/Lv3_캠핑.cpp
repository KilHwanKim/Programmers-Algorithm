#include <vector>
#include <set>
using namespace std;

struct tent_cmp{				// top�� ���� ���� ���� ������ �������� ����
	bool operator()(pair<int, int> t, pair<int, int> u) {
		if (t.first == u.first)
			return t.second < u.second;
		else
			return t.first < u.first;
	}
};

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
int solution(int n, vector<vector<int>> data) {
	int answer = 0;
	set<pair<int, int>, tent_cmp> s;

	for (int i = 0; i < data.size(); i++)
		s.insert(make_pair(data[i][0], data[i][1]));

	set<pair<int, int>>::iterator iter;
	for (iter = s.begin(); iter != s.end(); iter++) {
		int start_x = iter->first;		// �������� x
		int start_y = iter->second;		// �������� y

		int end_up = start_y;
		int end_up_x = start_x;
		int end_down = start_y;
		set<pair<int, int>>::iterator temp;
		for (temp = iter; temp != s.end(); temp++) {		// �Ѱ輱 ����
			if (end_up == start_y && temp->first != start_x && end_up < temp->second) {
				end_up = temp->second;
				end_up_x = temp->first;
			}

			if (end_down == start_y && temp->first != start_x && end_down > temp->second) {
				end_down = temp->second;
			}

			if (end_up != start_y && end_down != start_y)
				break;
		}

		int prev_end_up = INT_MAX;
		set<pair<int, int>>::iterator iter2;
		for (iter2 = iter; iter2 != s.end(); iter2++) {
			int end_x = iter2->first;
			int end_y = iter2->second;

			if (end_x == start_x)
				continue;

			if (end_y > start_y) {
				if (end_up >= end_y) {
					if (end_up != end_y) {
						prev_end_up = end_up;
						end_up_x = end_x;
					}
					end_up = end_y;		// ���ο� ���� �Ѱ輱 ����
					answer++;
				}
				else {
					if (end_x == end_up_x && end_y <= prev_end_up)
						answer++;
				}
			}
			else if (end_y < start_y) {
				if (end_down <= end_y) {
					end_down = end_y;		// ���ο� �Ʒ��� �Ѱ輱 ����
					answer++;
				}
			}
			else
				continue;
		}
	}
	return answer;
}
