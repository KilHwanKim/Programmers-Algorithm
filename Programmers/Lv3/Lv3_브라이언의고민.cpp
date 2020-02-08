#include <string>
#include <iostream>
#include <set>
#include <queue>
#include <list>
#include <vector>
using namespace std;

string solution(string sentence) {
	string answer = "";
	list<char> ans;
	int two = 0;
	set<char> s;
	set<char> duplicate;
	queue<pair<int, char>> q;
	list<pair<int, int>> l;

	l.push_back(make_pair(-1, -1));		// (start,end) ���� ����

	for (int i = 0; i < sentence.length(); i++) {
		char c = sentence[i];
		if (c == ' ')					// ������ ������ ��Ģ����!
			return "invalid";
		if (c >= 'a' && c <= 'z') {					// ��� �ҹ����� ������ġ�� ť�� ����
			if (s.find(c) == s.end()) {
				q.push(make_pair(i, c));
				s.insert(c);
			}
		}
	}

	while (!q.empty()) {
		char c = q.front().second;
		int start = q.front().first;
		q.pop();
		int end = start;
		int count = 0;

		if (duplicate.find(c) == duplicate.end())	// ������� ���� ��ȣ
			duplicate.insert(c);
		else										// ����� ��ȣ
			return "invalid";

		vector<int> pos;
		for (int i = start; i < sentence.length(); i++) {			// ��Ģ�� ���۰� ���� ���	
			if (sentence[i] == c) {
				if (pos.size() > 0) {
					if (i-pos.back() == 1)					// ���� ��ġ�� �پ��ִٸ�
						return "invalid";
				}
				pos.push_back(i);
				end = i;
			}
		}

		if (l.size() > 1) {											// ���� ��ȣ�� �پ������� ��Ģ����!  
			if (abs(start - l.back().first) == 1 || abs(l.back().second - end) == 1)		//���ۿ� ��ȣ�� �ΰ��پ��ְų�, ���� ��ȣ�� �ΰ� �پ��ְų�
				return "invalid";
		}

		if (pos.size() == 2 && two < 1) {		// ��Ģ2
			l.push_back(make_pair(start, end));		// ��Ģ2 (start,end) ���� : ��ȣ����
			for (int j = start + 1; j < end; j++) {
				if (sentence[j] >= 'a' && sentence[j]<='z') {			// ���ο� �ҹ��� ���� -> ��Ģ1 �߰�
					two = 2;
					break;
				}
				ans.push_back(sentence[j]);
				count++;
			}
			if (two < 1)			// ��Ģ2�� �ִٸ�
				ans.push_back(' ');
			else {					// ��Ģ1�� ���� �ִٸ�
				for (int j = 0; j < count; j++)
					ans.pop_back();
			}
		}
		else {						// ��Ģ1
			if (two > 0) {
				if (sentence[pos.back() + 2] != sentence[l.back().second])		// dAeA"A"d  -> A�� d������
					return "invalid";
				if (sentence[pos.front() - 2] != sentence[l.back().first])		// d"A"AeAd  -> A�� d������
					return "invalid";
			}

			if (start - 1 <= l.back().second && two<1)		// �������� ���� ������ ��ġ�� ��Ģ����!
				return "invalid";
			else {
				if (pos.size() == 1) {						// aAA,  AAa
					if (pos.front() == 0 || pos.front()==sentence.length()-1)
						return "invalid";

				}else {
					for (int j = 0; j < pos.size() - 1; j++) {		// 2���̾� �ȳ��� ��Ģ ����!
						if (pos[j + 1] - pos[j] != 2)
							return "invalid";
					}
					if (pos.front() == 0 || pos.back() == sentence.length() - 1)
						return "invalid";
				}

				start = start - 1;
				end = end + 1;

				if (two < 1)
					l.push_back(make_pair(start, end));		// ��Ģ1 (start,end) ���� : ��������
				for (int j = start; j <= end; j += 2) {
					if(sentence[j] >= 'a' && sentence[j] <= 'z')						// �빮�ڰ� �ƴϸ�
						return "invalid";
					else {
						ans.push_back(sentence[j]);
						count++;
					}
				}
				ans.push_back(' ');
			}
		}
		list<pair<int, int>>::iterator iter1 = l.end();
		list<char>::iterator iter2 = ans.end();
		iter1--;		// ������ ���
		iter1--;		// ������ �ٷ� �� ���
		int prevEnd = (*iter1).second + 1;
		
		if (prevEnd < start && two!=1) {		// ������ ��Ģ���� �ܾ�� �߰�, 
			if (two < 1) {			// ��ǰ ��Ģ�� ans�ȿ� ���ڰ� �־ ������ ������
				for (int i = 0; i <= count; i++)
					iter2--;
			}
			for (int i = prevEnd; i < start; i++)
				ans.insert(iter2, (sentence[i]));
			ans.insert(iter2, ' ');
		}

		if (two > 0) 			// ��Ģ 1,2�� ���� ������
			two--;
	}

	int prevEnd = l.back().second + 1;
	if (prevEnd < sentence.length()) {
		for (int i = prevEnd; i < sentence.length(); i++)
			ans.push_back(sentence[i]);
	}else
		ans.pop_back();

	for (char c : ans)
		answer += c;
	return answer;
}

//int main() {
//	cout << solution94("AsCsWsQsQsEEEEEEEEeEeEe") << '\n';				// invalid
//	cout << solution94("ABCaDaEFGbH") << '\n';				// ABC D EF GH
//	cout << solution94("aAaBBBcAeAeAc") << '\n';			// A BBB AAA
//	cout << solution94("ABCbDaEaFbHI") << '\n';				// ABC DEF HI
//	cout << solution94("AacacaA") << '\n';					// invalid
//	cout << solution94("AaBcBcBcBcB") << '\n';				// invalid
//	cout << solution94("aAAA") << '\n';						// invalid
//	cout << solution94("aA") << '\n';							// invalid
//	cout << solution94("AAAa") << '\n';						// invalid
//	cout << solution94("Aa") << '\n';							// invalid
//	cout << solution94("aAbBBbAa") << '\n';					// invalid
//	cout << solution94("aAbBBbAa") << '\n';					// invalid
//	cout << solution94("aAAbBbAAa") << '\n';					// invalid
//	cout << solution94("aAcAbAbAcAcAcAa") << '\n';			// invalid
//	cout << solution94("acAcAcAa") << '\n';					// invalid
//	cout << solution94("aAcAcAca") << '\n';					// invalid
//	cout << solution94("AdAeAeAdA") << '\n';					// A AAA A
//	cout << solution94("dAAeAd") << '\n';						// invalid
//	cout << solution94("dAeAAd") << '\n';						// invalid
//	cout << solution94("cAbBbAc") << '\n';					// ABA
//	cout << solution94("AbbA") << '\n';						// invalid
//	cout << solution94("aAaaBa") << '\n';						// invalid
//	cout << solution94("aAacBc") << '\n';						// A B  2 + 2
//	cout << solution94("AB") << '\n';							// AB  0 + 0  
//	cout << solution94("AcBc") << '\n';						// A B  0 + 2
//	cout << solution94("aAaB") << '\n';						// A B  2 + 0
//	cout << solution94("aAbAbAbAacBdBdBdBc") << '\n';			// AAAA BBBB  1,2 + 1,2
//	cout << solution94("AbAbAbABdBdBdB") << '\n';				// AAAA BBBB  1   + 1
//	cout << solution94("AbAbAbAcBBBBc") << '\n';				// AAAA BBBB  1   + 2
//	cout << solution94("aAbAbAbAaBdBdBdB") << '\n';			// AAAA BBBB  1,2 + 1
//	cout << solution94("aAbAbAbAacBBBBc") << '\n';			// AAAA BBBB  1,2 + 2	
//	cout << solution94("aAAAAaBdBdBdB") << '\n';				// AAAA BBBB    2 + 1
//	cout << solution94("aAAAAacBBBBc") << '\n';				// AAAA BBBB    2 + 2
//	cout << solution94("aAAAAacBdBdBdBc") << '\n';			// AAAA BBBB    2 + 1,2	
//	cout << solution94("AbAbAbAcBdBdBdBc") << '\n';			// AAAA BBBB    1 + 1,2
//	cout << solution94("IaMMbMb") << '\n';					// IM M M
//	cout << solution94("HaEaLaLObWORLDb") << '\n';			// HELL O WORLD
//	cout << solution94("AaAaAabBBb") << '\n';					// invalid
//	cout << solution94("AaAaAcA") << '\n';					// A A AA
//	cout << solution94("aAabBb") << '\n';						// A B
//	cout << solution94("bBbcHdEdEc") << '\n';					// B HEE
//	cout << solution94("HaEaLaLaObWORLDb") << '\n';			// HELLO WORLD
//	cout << solution94("AaAA") << '\n';						// AA A
//	cout << solution94("JaOOOaA") << '\n';					// J OOO A
//	cout << solution94("aJaOOOcAc") << '\n';					// J OOO A
//	cout << solution94("IaAMa") << '\n';						// I AM		
//	cout << solution94("aIaAM") << '\n';						// I AM
//	cout << solution94("SpIpGpOpNpGJqOOOqA") << '\n';			// SIGONG J OOO A
//	cout << solution94("AxAxAxAoBoBoB") << '\n';				// invalid
//	cout << solution94("AxAxAxABoBoB") << '\n';				// AAAA B B B
//	cout << solution94("aBa") << '\n';						// B
//	cout << solution94("baHELLOabWORLD") << '\n';				// invalid
//	cout << solution94("aAbAba") << '\n';						// invalid
//	cout << solution94("aHbEbLbLbOacWdOdRdLdDc") << '\n';		// HELLO WORLD
//	cout << solution94("bAaOb") << '\n';						// AO
//	cout << solution94("AAAaBaBBBbB") << '\n';				// AAA B BB BB
//	return 0;
//}
