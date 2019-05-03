// Solved
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, a[4];
    cin >> t;
    while(t--){
        for(int i = 0; i < 4; i++){
            cin >> a[i];
        }
        sort(a, a+4);
        if(a[0]==a[3]){
            cout << "square" << endl;
        }
        else if(a[0]==a[1] && a[2]==a[3]){
            cout << "rectangle" << endl;
        }
        else if(a[0]+a[1]+a[2] > a[3]){
            cout << "quadrangle" << endl;
        }
        else{
            cout << "banana" << endl;
        }
    }


    return 0;
}
