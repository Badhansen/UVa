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

    @author Badhan Sen
    CSE, JUST.
    mail: galaxybd9@gmail.com

    Uva 166 - Making Change

*/
#define MaxValue 510
#define Maxcoin 6

int mini[Maxcoin][MaxValue];
int coin[]={5, 10, 20, 50, 100, 200};
int available[Maxcoin];


int coinChange(int index, int value)
{
    if(value==0){
        return 1;
    }
    if(value<0){
        return 0;
    }
    if(index==6){
        return 0;
    }
    if(mini[index][value]!=-1){
        return mini[index][value];
    }
    int res=1e8;
    for(int i=1; i<available[index]; i++){
        res=Min(res, coinChange(index, value-(i*coin[index])));
    }
    mini[index][value]=res;
    return mini[index][value];
}

bool solve()
{
    int c=0;
    for(int i=0; i<6; i++){
        scanf("%d", &available[i]);
        if(available[i]==0) c++;
    }
    return c==6?1:0;
}
int main ()
{


    int x, y, n;
    while(1){
        if(solve()){
           break;
        }
        memset(mini, -1, MaxValue);
        scanf("%d.%d", &x, &y);
        n=x+y*100;
        int ans=coinChange(0, n);
        cout << mini[5][n] << endl;
    }


    return 0;
}
