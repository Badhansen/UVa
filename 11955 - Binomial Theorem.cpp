// Solved
// 11955 - Binomial Theorem
#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ulng;

ulng dp[52][52];
int n, id, t, test = 1;
string str, a, b, c;

void call()
{
    for(int i=0; i<=51; i++){
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
void solve()
{
    cin >> str;
    for(int i=1; i<str.size(); i++){
        if(str[i]=='+'){
            a = str.substr(1, i-1);
            id = i+1;
        }
        else if(str[i]==')'){
            b = str.substr(id, i-id);
        }
        else if(str[i]=='^'){
            c = str.substr(i+1, str.size()-i+1);
        }
    }
    stringstream ss;
    ss << c;
    ss >> n;
}
void print()
{
    int pa, pb, k = 0;

    for(int i=0; i<=n; i++){
        pa = n - k;
        pb = k;

        if(i != 0){
            if(i != n+1){
                cout << "+";
            }
        }
        if(dp[n][k] != 1){
            cout << dp[n][k] << "*";
        }
        if(pa != 0){
            if(pa == 1){
                cout << a;
            }
            else{
                cout << a << "^" << pa;
            }
            if(pa != n){
                cout << "*";
            }

        }
        if(pb != 0){
            if(pb == 1){
                cout << b;
            }
            else{
                cout << b << "^" << pb;
            }
        }
        k++;
    }
}
int main()
{
    call();
    cin >> t;
    while(t--){
        solve();
        cout << "Case " << test++ << ": ";
        print();
        cout << endl;
    }

    return 0;
}


