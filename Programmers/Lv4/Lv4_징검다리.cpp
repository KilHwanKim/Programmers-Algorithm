#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool remove_rock(vector<int> &rocks, int min, int n) {
	int prev = 0;
	int remove = 0;
	for (int r : rocks) {
		if (r - prev > min)
			prev = r;
		else
			remove++;
	}
	if (remove > n)
		return true;
	else
		return false;
}

// �Ķ��Ʈ�� ��ġ �̿�!
int solution(int distance, vector<int> rocks, int n) {
	sort(rocks.begin(), rocks.end());
	int low = 0;
	int mid = 0;
	int high = distance;

	while (low <= high) {
		mid = (low + high) / 2;	
		if (remove_rock(rocks, mid, n))		// ���� n���� ���� ���� �ߴٸ�
			high = mid - 1;					// high�� ���̰�
		else								// ���� n���� ���� ���� �ߴٸ�
			low = mid + 1;					// low�� �ø���
	}
	return low;
}

