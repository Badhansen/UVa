/*
                                Badhan Sen
                            Student of C.S.E
                jessore University of Science & Technology
                        Mail: galaxybd9@gmail.com

*/
#include <stdio.h>
#include <string.h>
int main ()
{
    int t;
    scanf ("%d", &t);
    int i;
    char s[10];
    for (i=0;i<t;i++){
        scanf ("%s", s);
        int len;
        len=strlen(s);
        if (len==3){
            int j,a;
            for (j=0;j<3;j++){
                if (s[j]=='t'||s[j+1]=='w'){
                    printf ("2\n");
                    break;
                }
                else {
                    printf ("1\n");
                    break;
                }
            }
        }
        else
            printf ("3\n");
    }
    return 0;
}
