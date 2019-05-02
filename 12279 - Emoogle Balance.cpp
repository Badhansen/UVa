/*
                                Badhan Sen
                            Student of C.S.E
                jessore University of Science & Technology
                        Mail: galaxybd9@gmail.com

*/
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n, a, c=1;
    while (1){
        cin >> n;
        if (n==0){
            break;
        }
        int ck=0, pk=0;
        while (n--){
            cin >> a;
            if (a>0)
                ck++;
            else
                pk++;
        }
        cout << "Case " << c << ": " << ck-pk << endl;
        c++;
    }
    return 0;
}
