// Solved
#include<bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        double cnt = 0;
        for(int i=1; i<=n; i++){
            cnt += log10(i);
        }
        long long s = ceil(cnt);
        if(n==1){
            printf("1\n");
        }
        else{
            printf("%lld\n", s);
        }
    }
    return 0;
}


