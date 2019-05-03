// Solved
#include<bits/stdc++.h>
using namespace std;

int main ()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int x, i, j;
    while (scanf("%d", &x)!=EOF){
        int a[1001];
        for (i=0; i<x; i++){
            cin >> a[i];
        }
        int c=0;
        for (i=1; i<x; i++){
            for (j=0; j<i; j++){
                if (a[j]>a[i]){
                    c++;
                }
            }
        }
        cout << "Minimum exchange operations : " << c << endl;
    }
    return 0;
}

