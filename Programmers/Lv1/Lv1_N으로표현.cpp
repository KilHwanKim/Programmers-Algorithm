#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int mincount = -1;
void go(int N, int number, int result, int count) {
	if (count > 8) {			// ��������
		return;
	}
	if (number == result) {		// �Ϸ�����
		if (count < mincount || mincount == -1) {		// ���� answer������ ������ �־���
			mincount = count;
		}
		return;
	}

	int nn = 0;
	for (int i = 0; i < 8; i++) {
		nn = nn * 10 + N;		// N, NN, NNN, NNNN .....
		go(N, number, result + nn, count + 1 + i);		// i�� N�� � �پ��ִ� ��
		go(N, number, result * nn, count + 1 + i);
		go(N, number, result - nn, count + 1 + i);
		go(N, number, result / nn, count + 1 + i);

	}
}
int solution(int N, int number) {
	go(N, number, 0, 0);
	return mincount;
}
