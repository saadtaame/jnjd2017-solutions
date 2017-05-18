#include <bits/stdc++.h>

using namespace std;

int dp[200][200][2];

int match(string &p, string &s, int i, int j, int pm) {
	if(i == (int)p.size()) return 1;
	if (j > (int)s.size() - (int)p.size() + i) return 0;


	if(dp[i][j][pm] != -1)
		return dp[i][j][pm];

	int opt1 = 0;
	if(((p[i] == s[j]) && pm) || (isupper(s[j]) && p[i] == tolower(s[j])))
		opt1 = match(p, s, i + 1, j + 1, 1);

	int ans = opt1 || match(p, s, i, j + 1, 0);

	return dp[i][j][pm] = ans;
}

int main(void) {
                              
	int t;
	cin >> t;

	int tt = 1;

	while(t--) {

		cout << "Case " << tt++	<<":" << endl;

		int n;
		string p;

		cin >> n >> p;                  
		while(n--) {
			string s;
			cin >> s;

			memset(dp, -1, sizeof(dp));
			if(match(p, s, 0, 0 ,0)) cout << s << endl;
		}
	}
	return 0;
}
