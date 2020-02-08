#include <vector>
#include <algorithm>
using namespace std;

int MOD = 20170805;

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
int solution(int m, int n, vector<vector<int>> city_map) {
	vector<vector<int>> road(m+1,vector<int>(n+1,0));
	vector<vector<int>> check(m + 1, vector<int>(n + 1, 0));
	
	road[1][0] = 1;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			check[i][j] = city_map[i - 1][j - 1];
			if (check[i][j] == 1) 		// ����
				road[i][j] = 0;
			else if (check[i][j] == 2) {		// ������ �켱
				road[i][j] = max(road[i][j-1], road[i-1][j]);	// ���ʰ� ���� �� ū���� ä��
			}
			else {										// �׳� ��
				if (check[i][j-1] == 2 && check[i - 1][j] == 2) {				// ���ʰ� ���� �Ѵ� 2
					int ti1 = i;					// ���� ã��
					int tj1 = j-1;
					while (check[ti1][tj1] == 2)
						tj1--;
					int ti2 = i-1;					// ���� ã��
					int tj2 = j;
					while (check[ti2][tj2] == 2)
						ti2--;
					road[i][j] = (road[ti1][tj1]+road[ti2][tj2]) % MOD;
				}
				else if (check[i][j - 1] == 2) {			// ���ʸ� 2
					int ti = i;
					int tj = j-1;
					while (check[ti][tj] == 2)
						tj--;
					road[i][j] = (road[i - 1][j] + road[ti][tj]) % MOD;
				}
				else if (check[i - 1][j] == 2) {			// ���ʸ� 2
					int ti = i-1;
					int tj = j;
					while (check[ti][tj] == 2)
						ti--;
					road[i][j] = (road[i][j-1] + road[ti][tj]) % MOD;
				}
				else {										 // �� �� 2�� �ƴ�
					road[i][j] = (road[i][j - 1] + road[i - 1][j])%MOD;
				}
			}
		}
	}

	return road[m][n];
}