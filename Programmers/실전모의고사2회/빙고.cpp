#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<int> nums) {
	int answer = 0;
	vector<int> check1(board.size(), 0);
	vector<int> check2(board.size(), 0);
	vector<int> check3(2, 0);

	while (nums.size() != 0) {							// ����� O(n^3) , nums�� set���� �ٲٸ� O(n^2)
		int k = nums[nums.size() - 1];
		nums.pop_back();
		for (int i = 0; i < board.size(); i++) {
			bool c = false;
			for (int j = 0; j < board[i].size(); j++) {
				if (k == board[i][j]) {
					check1[j]++;						// ���� üũ
					check2[i]++;						// ���� üũ
					if (i == j)
						check3[0]++;					// �밢��1 üũ
					if (i + j == board.size() - 1)
						check3[1]++;					// �밢��2 üũ

					board[i][j] = -1;
					c = true;
					break;
				}
			}
			if (c)
				break;
		}
	}

	for (int i = 0; i < board.size(); i++) {
		if (check1[i] == board.size())
			answer++;
		if (check2[i] == board.size())
			answer++;
	}
	if (check3[0] == board.size())
		answer++;
	if (check3[1] == board.size())
		answer++;

	return answer;
}