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
    return lps[m];
}

int main()
{
    //filein();fileout();
    string txt;
    while(1){
        cin >> txt;
        if(txt == ".") break;
        int sz = txt.size(), n = KMPprocess(txt, sz);
        if(n % (sz - n)) cout << 1 << endl;
        else cout << sz/(sz-n) << endl;
    }
    return 0;
}


