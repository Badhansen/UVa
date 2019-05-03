//Solved
#include<bits/stdc++.h>

using namespace std;

int main()
{

    int a[10], t, ts = 1;
    cin >> t;
    while(t--){
        for(int i = 0; i < 7; i++){
            cin >> a[i];
        }
        int sum = 0;
        sort(a + 4, a + 7, greater<int> ());
        for(int i = 0; i < 4; i++){
            sum += a[i];
        }
        sum += (a[4] + a[5])/2;

        if(sum >= 90){
            cout << "Case " << ts++ << ": " << "A" << endl;
        }
        else if(sum >= 80){
            cout << "Case " << ts++ << ": " << "B" << endl;
        }
        else if(sum >= 70){
            cout << "Case " << ts++ << ": " << "C" << endl;
        }
        else if(sum >= 60){
            cout << "Case " << ts++ << ": " << "D" << endl;
        }
        else{
            cout << "Case " << ts++ << ": " << "F" << endl;
        }
    }
    return 0;
}
