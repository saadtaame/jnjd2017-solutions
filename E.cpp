#include <bits/stdc++.h>

using namespace std;

long long count(int N, int M) {
	if(N == 0 || M == 0)
		return 0;

	if(N > M)
		return N / M + count(M, N % M);
	else
		return M / N + count(N, M % N);
}

int main(void) {
	int t;
	cin >> t;

	while(t--) {
		int N, M;
		cin >> N >> M;
		cout << count(N, M) << endl;
	}

	return 0;
}
