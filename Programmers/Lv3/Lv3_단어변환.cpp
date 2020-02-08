#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
using namespace std;

// BFS �̿�
int solution(string begin, string target, vector<string> words) {
	int answer = 51;
	int i;
	vector<vector<int>> check(words.size() + 1, vector<int>(words.size() + 1, 0));		// 0���� �ʱ�ȭ

	
	for (i = 0; i < words.size(); i++) {			// target�� ������ �ٷ� 0�� ����
		if (words[i] == target)
			break;
	}
	if (i == words.size())
		return 0;

	queue<tuple<string, int, int>> q;
	q.push(make_tuple(begin, 0,0));

	while (!q.empty()) {
		tuple<string, int, int> t = q.front();
		string now = get<0>(t);
		int count = get<1>(t);
		int index = get<2>(t);
		q.pop();
			
		if (now == target) {			// �̹� target�� �Ǿ��� ���
			if (answer > count)		
				answer = count;
			continue;
		}

		if (count >= words.size()) 						// ���� �������� ���� ���Ҵٸ� out
			continue;
		
		for (int i = 0; i < words.size(); i++) {
			int diff = 0;
			if (check[index][i] != 1) {
				for (int j = 0; j < words[i].size(); j++) {
					if (now[j] == words[i][j])
						diff++;
				}
				if (diff == words[i].size() - 1) {
					check[index][i] = 1;
					q.push(make_tuple(words[i], count + 1, index));
				}
			}
		}
	}
	
	return answer;
}

/*
�ٸ���� Ǯ�� DFS

#include <string>
#include <vector>

using namespace std;

vector<bool> used;

int mincnt = 987654321;

void DFS(string cur, const string &target, int cnt, vector<string> &words) {
	if(cur == target) {
		mincnt = mincnt > cnt ? cnt : mincnt;
		return;
	}

	for(int i = 0; i < words.size(); i++) {
		int tmp = 0;
		if(used[i]) continue;

		for(int idx = 0; idx < cur.size(); idx++)
			if(cur[idx] != words[i][idx]) tmp++;

		if(tmp != 1) continue;

		used[i] = true;
		DFS(words[i], target, cnt+1, words);
		used[i] = false;
	}
}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;

	used.resize(words.size());

	for(int i = 0; i < words.size(); i++) {
		int cnt = 0;
		for(int idx = 0; idx < begin.size(); idx++)
			if(begin[idx] != words[i][idx]) cnt++;
		if(cnt != 1) continue;

		used[i] = true;
		DFS(words[i], target, 1, words);
		used[i] = false;

	}

	if(mincnt != 987654321) return mincnt;
	else  return 0;
}
*/