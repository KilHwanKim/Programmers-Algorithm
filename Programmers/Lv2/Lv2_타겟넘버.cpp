#include <string>
#include <vector>
#include <iostream>
using namespace std;

int answer = 0;

int oper(int i, int num, int sum) {
	if (i == 0) {				// ���ϱ�
		sum += num;
	}
	else if (i == 1) {			// ����
		sum -= num;
	}
	return sum;
}

void go(vector<int> numbers, int target, int index,int result) {
	if (result == target && index == numbers.size()) {			// �Ϸ�����
		answer++;
		return;
	}
	if (index > numbers.size() - 1)								// ��������
		return;
	for (int i = 0; i < 2; i++) 
		go(numbers, target, index + 1, oper(i, numbers[index], result));
}

int solution(vector<int> numbers, int target) {
	go(numbers,target,0,0);
	
	return answer;
}
