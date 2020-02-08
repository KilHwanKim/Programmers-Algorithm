#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	map<int, set<int>> down;
	map<int, set<int>> up;

	for (int i = 0; i <= n; i++) {
		set<int> s;
		down.insert(make_pair(i, s));
		up.insert(make_pair(i, s));
	}

	for (int i = 0; i < results.size(); i++) {
		down.find(results[i][0])->second.insert(results[i][1]);
		up.find(results[i][1])->second.insert(results[i][0]);
	}

	for (int i = 0; i < 2; i++) {
		for (auto &i : down) {
			for (auto j : i.second) {
				for (auto k : down.find(j)->second)
					i.second.insert(k);
			}
		}

		for (auto &i : up) {
			for (auto j : i.second) {
				for (auto k : up.find(j)->second)
					i.second.insert(k);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (up[i].size() + down[i].size() >= n - 1)
			answer++;
	}

	return answer;
}

/*
�ٸ���� Ǯ��

#include <string>
#include <vector>
#include<iostream>
using namespace std;

int d[101][101];
int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	for(int i=0;i<results.size();i++)
	{
		d[results[i][0]][results[i][1]]=1; // �¸�
		d[results[i][1]][results[i][0]]=-1; // �й�
	}

	for (int i = 1; i <= n; i++)
	{
		for (int from = 1; from <= n; from++)
		{
			if (d[from][i] == 0)
			{
				continue;
			}
			for (int to = 1; to <= n; to++)
			{
				if (d[from][i] == d[i][to])
				{
					d[from][to] = d[from][i];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = 1; j <= n; j++)
		{
			// ��� ���谡 ���� �� sum�� ����
			if(d[i][j]!=0 && (i!=j))
			{
				sum++;
			}
		}
		// ��� ���谡 ��� �ִٸ� ������ �ű�� �ִ� ����
		if(sum==(n-1))
		{
			answer++;
		}
	}
	return answer;
}

*/