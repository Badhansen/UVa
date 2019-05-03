//solved
#include<bits/stdc++.h>

using namespace std;

#define ll long long

class Euclid{
public:
    ll x, y, d;
    Euclid(){}
    Euclid(ll _x , ll _y, ll _d){
        x = _x; y = _y; d = _d;
    }
};

Euclid edcd(ll a , ll b){
    if(!b)return Euclid(1, 0 , a);
    Euclid r = edcd(b , a%b);
    return Euclid(r.y , r.x - a/b * r.y , r.d );
}

int main()
{
    int test;
    //scanf("%d",&test);
    Euclid ans;
    int cs = 0;
    while(1){
        ll a , b;

        scanf("%lld%lld",&a , &b);
        if(a == 0 && b == 0)return 0;
        if(cs)printf("\n");
        cs = 1;
        ans = edcd(a , b);
        printf("minimum volume: %lld liter(s)\n",ans.d);
        if(ans.x < 0){
            printf("%lld liter(s) withdrawn %lld times\n" , a , -ans.x);
        }
        else if(ans.x == 0){
            printf("%lld liter(s) not needed\n",a);
        }
        else printf("%lld liter(s) poured %lld times\n",a,ans.x);

        if(ans.y < 0){
            printf("%lld liter(s) withdrawn %lld times\n" , b , -ans.y);
        }
        else if(ans.y == 0){
            printf("%lld liter(s) not needed\n",b);
        }
        else printf("%lld liter(s) poured %lld times\n",b,ans.y);


    }
    return 0;
}

