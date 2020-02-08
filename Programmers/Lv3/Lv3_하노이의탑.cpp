#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> answer102;
void hanoi(int n, int from, int by, int to)			// 1.����Լ� �̿�
{
	if (n == 1)
	{
		vector<int> v;			
		v.push_back(from);
		v.push_back(to);
		answer102.push_back(v);
		return;
	}

	hanoi(n - 1, from, to, by); // n-1 ���� ������ 1���� 3�� �̿��Ͽ� 2�� �ű��.
	vector<int> v;
	v.push_back(from);
	v.push_back(to);
	answer102.push_back(v);
	hanoi(n - 1, by, from, to); // n-1���� ������ 2���� 1�� �̿��Ͽ� 3���� �ű��.
}

vector<vector<int>> solution(int n) {
	//hanoi(n, 1, 2, 3);
	stack<int> s;							// 2. ����� 
	int from = 1;
	int by = 2;
	int to = 3;
	while (1){
        while (n > 1){
            s.push(to);    // ���ڸ���Ʈ Ǫ��
            s.push(by);
            s.push(from);
            s.push(n);
            n--;        // ���ڸ���Ʈ ���� 1
            s.push(to);    // to �� by�� ��ȯ�ϱ� ���� �ӽ÷� ����
            to = by;
            by = s.top();
			s.pop();
        }

		vector<int> v;
		v.push_back(from);
		v.push_back(to);
		answer102.push_back(v);

        if (!s.empty()){
            n = s.top();
			s.pop();
            from = s.top();
			s.pop();
            by = s.top();
			s.pop();
            to = s.top();
			s.pop();

			vector<int> v;
			v.push_back(from);
			v.push_back(to);
			answer102.push_back(v);

            n--;        // ���ڸ���Ʈ ���� 2
            s.push(from);
            from = by;
            by = s.top();
			s.pop();
        }
        else{
            break;
        }
    }

	return answer102;
}
