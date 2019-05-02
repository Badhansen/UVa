#include<cstdio>
#include<iomanip>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<deque>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#include<limits>

using namespace std;


#define FIO()          ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x)         x.begin(), x.end()


#define Max(x, y)      ((x)>(y) ? (x) : (y))
#define Min(x, y)      ((x)<(y) ? (x) : (y))
#define Abs(x)         ((x)<0 ? (-(x)): (x))


#define PI             acos(-1.0)
#define EPS            1e-9


#define MAX            2e18
#define MOD            1000000007


typedef long long i64;
typedef unsigned long long ui64;
typedef pair<int, int> pii;
typedef pair<i64, i64> pll;
typedef vector<int> vi;
typedef vector<i64> vl;


template<class T> T POW (T b, T p){T res=1;while(p>0){if (p&1) res*=b;p >>= (1ll), b*=b;}return res;}
template<class T> T bMOD (T a, T p, T m){ if (p==0) return (T) 1;if (!(p&1)){T temp=bMOD(a, p/2, m);return ((temp%m)*(temp%m))%m;}return ((a%m)*(bMOD(a, p-1, m)%m))%m;}
template<class T> T inMOD (T a, T m){return bMOD (a, m-2, m);}
template<class T> bool isPrime (T n){ for (T i=2; i*i<=n; i++){if (n%i==0) return false;}return true;}
template<class T> string toString (T n){ stringstream ss;string num;ss<<n;ss>>num;return num;}
template<class T> T sq (T n){ return (n*n);}
template<class T> T gcd (T a, T b){ return (b==0) ? a : gcd (b, a%b);}
template<class T> T lcm (T a, T b){ return (a/gcd (a, b))*b;}
bool iseq (double a, double b){ return fabs(a-b)<EPS;}
template<class T> T toDeg (T x){ return (180.0*x)/((T)PI);}
template<class T> T toReg (T x){ return (x*(T)PI)/(180.0);}
template<class T> double _distance (T x1, T y1, T x2, T y2){ return 1.0*sqrt(sq(x1-x2)+sq(y1-y2));}

int kx[]={-2, -2, +2, +2, +1, -1, +1, -1};
int ky[]={+1, -1, +1, -1, -2, -2, +2, +2};

int dx[]={+0, +0, -1, +1, +1, +1, -1, -1};
int dy[]={+1, -1, +0, +0, -1, +1, +1, -1};

int x[]={+0, +0, +1, -1};
int y[]={+1, -1, +0, +0};





/*

    Badhan Sen
    CSE, JUST.

    Uva : 11517 - Exact Change
    Solved

*/
#define MaxValue 10001
#define MaxCoin 110

i64 mini[MaxValue];
i64 coin[MaxCoin];

void coinChange(i64 coin[], i64 n)
{
    for(i64 i=1; i<=MaxValue; i++)
        mini[i]=MAX;

    mini[0]=0;

    for(i64 i=0; i<n; i++){

        for(i64 j=MaxValue-coin[i]-1; j>=0; j--){
            if(mini[j]<MAX){
                mini[j+coin[i]]=Min(mini[j+coin[i]], mini[j]+1);
                //cout << j+coin[i] << "---" <<  mini[j+coin[i]] << endl;
            }
        }
    }
}

int main ()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    i64 test, n, value;
    scanf("%lld", &test);
    while(test--){
        scanf("%lld", &value);
        scanf("%lld", &n);
        for(i64 i=0; i<n; i++){
            scanf("%lld", &coin[i]);
        }

        sort(coin, coin+n);

        coinChange(coin, n);
        i64 i=0;
        //cout << ways[1500];
        for(i=value; mini[i]==MAX; i++);

            printf("%lld %lld\n", i, mini[i]);


    }


    return 0;
}
