/**
                                Badhan Sen
                            Student of C.S.E
                jessore University of Science & Technology
                        Mail: galaxybd9@gmail.com

*/
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long t, l, w, h, i=1;
    cin >> t;
    while (i<=t){
        cin >> l >> w >> h;
        if (l<=20){
            if (w<=20){
                if (h<=20){
                    cout << "Case " << i << ": " << "good" <<endl;
                    i++;
                }
                else {
                    cout << "Case " << i << ": " << "bad" <<endl;
                    i++;
                }
            }
            else{
                cout << "Case " << i << ": " << "bad" <<endl;
                i++;
            }

        }
        else{
            cout << "Case " << i << ": " << "bad" <<endl;
            i++;
        }

    }
    return 0;
}

