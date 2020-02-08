#include <string>
#include <vector>

using namespace std;

// �׳� BFS�� �ð��ʰ�
// DP�� �������!
int solution(int n, vector<int> money) {
	int MOD = 1000000007;
	int answer = 0;
	vector<int> d(n + 1, 0);
	d[0] = 1;

	for (int i = 0; i < money.size(); i++) {
		for (int j = money[i]; j <= n ; j++) {
			d[j] = d[j] + d[j - money[i]] % MOD;
		}
	}

	return d[n];
}