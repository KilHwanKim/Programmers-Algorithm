#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
	int net = 0;
	int check[201] = {0,};

	for (int i = 0; i < computers.size(); i++) {
		int no = 0;
		set<int> s;
		for(int j = 0; j < n; j++) {
			if (computers[i][j] == 1 && check[j] != 0) { 			// �̹� ����� ���� ������
				no = check[j];
				s.insert(check[j]);
			}
		}
		if (no == 0) {		// ������ �� �ִ� ��Ʈ��ũ�� ������
			net++;
			for (int k = 0; k < n; k++) {  
				if (computers[i][k] == 1)
					check[k] = net;
			}
		}
		else {				// ������ �� �ִ� ��Ʈ��ũ�� ������
			if (s.size() == 1) {				// ��Ʈ��ũ�� �ϳ� �϶�
				for (int k = 0; k < n; k++)
					if (computers[i][k] == 1)
						check[k] = no;
			}
			else {								// ��Ʈ��ũ�� ������ �϶�
				net++;
				set<int>::iterator iter;
				for (iter = s.begin(); iter != s.end(); iter++) {
					int temp = *iter;
					for (int k = 0; k < n; k++) {
						if (check[k] == temp)
							check[k] = net;
					}
				}
				for (int k = 0; k < n; k++)
					if (computers[i][k] == 1)
						check[k] = net;
			}
		}
	}
	set<int> s;
	for (int i = 0; i < n; i++) {
		if (check[i] != 0)
			s.insert(check[i]);
	}
		
	return s.size();
}

/*
�ٸ���� Ǯ�� dfs  -> �ð��� �� �ڵ尡 �� ª�� �ҿ�

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int net[201][201] = {0};
int check[201] = {0};

void dfs(int x, int n){
	check[x] = 1;

	for(int i=0;i<n;++i){
		if(net[x][i] == 1 && check[i] != 1){
			dfs(i, n);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(computers[i][j] == 1)
			net[i][j] = 1;
		}
	}

	for(int i=0;i<n;i++){
			if(check[i] != 1){
			dfs(i, n);
			answer +=1;
		  }
	}

	return answer;
}

*/
