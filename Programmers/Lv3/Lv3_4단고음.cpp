#include <map>
using namespace std;

map<pair<int, int>, int> dm;

int dfs(int plusCount, int n) {
	if (plusCount > 38)		// *�� 19���� �ִ�! ���� +�� 38���� �ִ�
		return 0;

	if (n == 1) {			// ���Ϸ��� ���� 1�� ��
		if (plusCount == 0)	// ���� plus�� 0��
			return 1;
		else
			return 0;
	}

	if (dm.find({ plusCount,n }) != dm.end())		// �̹� ���� ���� ������ �����´�
		return dm[{ plusCount, n }];

	dm[{ plusCount, n }] = dfs95(plusCount + 1, n - 1);		// +�� �߰�!

	if (plusCount >= 2 && n % 3 == 0)		// plusCount�� 2�� ��Ұ�, ���Ϸ��� ���� 3�� ����� ��
		dm[{ plusCount, n }] += dfs95(plusCount - 2, n / 3);		// ����� ���� �߰�!

	return dm[{ plusCount, n }];
}

int solution(int n) {
	int answer = dfs95(0, n);
	return answer;
}