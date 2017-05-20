#include <bits/stdc++.h>

using namespace std;                 

int main(void) {
                              
	int t;
	cin >> t;

	while(t--) {
		int n;
		cin >> n;

		long long c = (1ll << (2 * n - 1)) + (1ll << (n - 1));
		n = (1 << n);
                                  
		vector<int> cnt(n, 0);
		cin >> cnt[0];
		for(int i = 1; i < n; i++) {
			cin >> cnt[i];
			cnt[i] += cnt[i - 1];
		}

		long long ans = cnt[0];                         
		for(int i = 0; i < n; i++) {
		        // i can match with any '1' up to position j
			if((cnt[i] - ((i-1 >= 0) ? cnt[i - 1] : 0)) == 0)
				continue;

			int j = n - 1 - i;
			if(j > i) ans += 2 * cnt[j] - 2 * cnt[i];
			if(i + i < n && i > 0) ans += 1;
		}
		ans *= 100;
		cout << round(ans * 1.0 / c) << "%" << endl;
       	}

	return 0;
} 
