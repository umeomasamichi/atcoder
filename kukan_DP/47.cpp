#include <iostream>
#include <algorithm>
using namespace std;
 
long long N, A[2009], dp[2009][2009][2], ans;
 
long long solve(long long L, long long R, long long turn) {
	printf("%d, %d, %d\n", L, R, turn);
	if (R - L == N - 1 || L - R == 1){
		printf("return 0\n");
		return 0;
	}
	if (dp[L][R][turn] != -(1LL)){
		printf("return dp\n");
		return dp[L][R][turn];
	}
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



	cout << rem << endl;
	int x = 5;
	for(int i=0; i<x; i++){
		for(int j=0; j<x; j++){
			int tmp0;
			if(dp[i][j][0]==-1) tmp0 = 0;
			else tmp0 = dp[i][j][0];

			cout << tmp0 << ", ";
		}

		cout << "     ";

		for(int j=0; j<x; j++){
			int tmp1;
			if(dp[i][j][1]==-1) tmp1 = 0;
			else tmp1 = dp[i][j][1];

			cout << tmp1 << ", ";
		}

		cout << endl;
	}
	cout << endl;




	return rem;
}
 
int main() {
	//メモ化再帰ってことね！
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) { for (int j = 0; j < N; j++) { dp[i][j][0] = -(1LL); dp[i][j][1] = -(1LL); } }
	for (int i = 0; i < N; i++) {
		long long rem = solve(i, i, 1);
		ans = max(ans, rem + A[i]);
	}
	cout << ans << endl;

	return 0;
}