// solved
#include<bits/stdc++.h>
using namespace std;

int main()
{

    int i,j,n,k,x;
    while(cin >> n){
        if(n==0)
            return 0;
        string str;
        int s=0,ans=0;
        for(j=0;j<100;j++){
            s=s*10+1;
            ans=ans*10+(s/n);
            s%=n;

            str+="1";

            if(s==0)
                break;
            else{
                k=j+1;
                x=s;

                while(x!=0&&k<100){
                    x=x*10;
                    ans=ans*10+(x/n);
                    x%=n;
                    k++;
                }
                if(k!=100)
                    break;
            }
        }
       // cout<<s<<' '<<x<<endl;
        if(x==0){
            for(i=j+1;i<k;i++)
                str+="0";
//            cout<<s<<' '<<x<<endl;
        }
        cout << str << endl;
    }


    return 0;
}
