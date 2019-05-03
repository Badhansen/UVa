// Solved
#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ulng;

ulng dp[101][101];
int t, n, k, test;

void call()
{
    for(int i=0; i<=100; i++){
        for(int j=0; j<=i; j++){
            if(j==0 || i==j){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }
    }
}
int main()
{
    call();
    while(scanf("%d%d", &n, &k) && n && k){
        printf("%d things taken %d at a time is %llu exactly.\n", n, k, dp[n][k]);
    }
    return 0;
}
