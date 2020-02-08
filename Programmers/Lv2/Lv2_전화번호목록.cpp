#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	bool out = false;

	for (int i = 0; i < phone_book.size() - 1; i++) {
		for (int j = i + 1; j < phone_book.size(); j++) {
			if (phone_book[i].length() <= phone_book[j].length()) {		// s1�� ���̰� s2�� ���̺��� �۰ų� ���� ���� �˻�
				int index = phone_book[j].find(phone_book[i]);
				if (index == 0) {
					answer = false;
					out = true;
					break;
				}
			}
			else {
				int index = phone_book[i].find(phone_book[j]);
				if (index == 0) {
					answer = false;
					out = true;
					break;
				}
			}
		}
		if (out)
			break;
	}

	return answer;
}