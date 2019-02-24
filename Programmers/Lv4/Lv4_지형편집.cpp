#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

long long min_ll(long long a, long long b) { return a < b ? a : b; }

inline long long cal_cost(vector<vector<int> >& land, int P, int Q, long long check, int n) {		// &연산자를 넣지 않으면 무조건 시간초과..

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans += (land[i][j] - check) * (land[i][j] - check > 0 ? Q : -P);
		}
	}
	return ans;
}

// 파라메트릭 서치 이용! 
long long solution(vector<vector<int> > land, int P, int Q)
{
	long long answer = LONG_MAX;
	int n = land.size();
	int low = 0;
	int high = 1000000000;
	int mid = 0;

	// 비용 그래프는 아래로 볼록
	// 아래로 볼록한 그래프는 기울기가 0일때 최소값. 따라서 기울기 0인 지점 탐색
	while (low <= high) {
		mid = (low + high) / 2;
		unsigned long long pos1 = cal_cost(land, P, Q, mid, n);
		unsigned long long pos2 = cal_cost(land, P, Q, mid + 1, n);
		if (pos1 == pos2)
			break;
		if (pos1 < pos2)
			high = mid - 1;
		else
			low = mid + 1;
	}
	// 근사값이기 때문에 앞뒤값을 한번더 검사
	for (int i = mid - 1; i <= mid + 1; i++)
		answer = min(answer, cal_cost(land, P, Q, i, n));

	return answer;
}

/*

//삼분탐색 이용! 
long long solution(vector<vector<int> > land, int P, int Q)
{
	long long answer = LONG_MAX;
	int n = land.size();
	double low = 0;
	double high = 0;

	for (int i = 0; i < land.size(); i++) {
		for (int j = 0; j < land[i].size(); j++) {
			high = max(high, (double)land[i][j]);
		}
	}

	// 비용 그래프는 아래로 볼록
	// 아래로 볼록한 그래프는 기울기가 0일때 최소값. 따라서 기울기 0인 지점 탐색
	double aab, abb;
	long long pos1, pos2;
	for (int i = 0; i < 50; i++) {
		aab = (2 * low + high) / 3.0;
		abb = (low + 2 * high) / 3.0;
		pos1 = cal_cost(land, P, Q, aab, n);
		pos2 = cal_cost(land, P, Q, abb, n);
		if (pos1 > pos2)
			low = aab;
		else
			high = abb;
	}
	double mid = (low + high) / 2;
	// 근사값이기 때문에 앞뒤값을 한번더 검사
	for (int i = mid - 3; i <= mid + 3; i++)
		answer = min_ll(answer, cal_cost(land, P, Q, i,n));

	return answer;
}

*/


