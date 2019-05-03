// Solved
#include<bits/stdc++.h>
using namespace std;
typedef long long lng;

struct mat{
    double a[3][3];
};
mat multiply(mat obj, mat tobj)
{
    struct mat ob;
    ob.a[0][0] = ((obj.a[0][0] * tobj.a[0][0]) + (obj.a[0][1] * tobj.a[1][0]));
    ob.a[0][1] = ((obj.a[0][0] * tobj.a[0][1]) + (obj.a[0][1] * tobj.a[1][1]));
    ob.a[1][0] = ((obj.a[1][0] * tobj.a[0][0]) + (obj.a[1][1] * tobj.a[1][0]));
    ob.a[1][1] = ((obj.a[1][0] * tobj.a[0][1]) + (obj.a[1][1] * tobj.a[1][1]));
    return ob;
}
int main()
{
    int t;
    cin >> t;
    while(t--){
        double  a, b,print;
        long long n,f0,f1;

        scanf("%lld %lld %lf %lf %lld",&f0,&f1,&a,&b,&n);

        mat pq,ans;

        pq.a[0][0]=a;
        pq.a[0][1]=b;
        pq.a[1][0]=1;
        pq.a[1][1]=0;

        ans.a[0][0]=a;
        ans.a[0][1]=b;
        ans.a[1][0]=1;
        ans.a[1][1]=0;
        n-=2;
        while(n){
            if(n%2)
                ans=multiply(ans,pq);
            pq=multiply(pq,pq);
            n/=2;
        }
        print=ans.a[0][0]*f1+ans.a[0][1]*f0;
        printf("%.0lf\n",print);
    }
    return 0;
}


