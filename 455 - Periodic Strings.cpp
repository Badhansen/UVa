// Solved
#include<bits/stdc++.h>

using namespace std;
#define filein()       freopen("in.txt", "r", stdin)
#define fileout()      freopen("out.txt", "w", stdout)
const int MaxN = 1e6 + 10;
int lps[MaxN];

int KMPprocess(string ptr, int m)
{
    int i = 0, j = -1;
    lps[i] = j;
    while(i < m){
        while(j >= 0 && ptr[i] != ptr[j])
            j = lps[j];
        i++, j++;
        lps[i] = j;
    }
    return lps[m] - 1;
}

int main()
{
    filein();
    fileout();
    int t;
    cin >> t;
    cin.ignore();
    string txt;
    while(t--){
        cin >> txt;
        cin.ignore();
        int sz = txt.size(), n = KMPprocess(txt, sz);
        int ans = sz - n - 1;
        if(sz%ans == 0){
            cout << ans << endl;
        }
        else
            cout << sz << endl;
        if(t != 0) cout << endl;
    }
    return 0;
}


