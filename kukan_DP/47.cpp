#include <iostream>
#include <algorithm>
using namespace std;
 
long long N, A[2009], dp[2009][2009][2], ans;
 
long long solve(long long L, long long R, long long turn) {
	if (R - L == N - 1 || L - R == 1) return 0;
	if (dp[L][R][turn] != -(1LL << 60)) return dp[L][R][turn];
 
	long long A1 = solve((L + N - 1) % N, R, turn ^ 1);
	long long A2 = solve(L, (R + 1) % N, turn ^ 1);
 
	long long rem = 0;
	if (turn == 0) {
		A1 += A[(L + N - 1) % N];
		A2 += A[(R + 1) % N];
		rem = max(A1, A2);
	}
	if (turn == 1) {
		if (A[(L + N - 1) % N] > A[(R + 1) % N]) rem = A1;
		else rem = A2;
	}
	dp[L][R][turn] = rem;
	return rem;
}
 
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) { for (int j = 0; j < N; j++) { dp[i][j][0] = -(1LL << 60); dp[i][j][1] = -(1LL << 60); } }
	for (int i = 0; i < N; i++) {
		long long rem = solve(i, i, 1);
		ans = max(ans, rem + A[i]);
	}
	cout << ans << endl;
	
	return 0;
}