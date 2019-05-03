// solved
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long arr[33005],i,j,n;
    arr[0]=0;
    arr[1]=2;
    j=1;
    for(i=2;i<33000;i++){
        if(i==j){
            arr[i]=i*2;
            j=1;
        }
        else if(j==1){
            arr[i]=i+1;
            j+=2;
        }
        else{
            arr[i]=arr[j]+(i-j);
            j+=2;
        }
    }
    while(scanf("%lld",&n)!=EOF){
        printf("%lld\n",arr[n]);
    }
    return 0;
}

