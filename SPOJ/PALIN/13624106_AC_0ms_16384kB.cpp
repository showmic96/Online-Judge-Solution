// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

char ar[1000005];

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        scanf("%s",&ar);

        int si = strlen(ar);

        bool check = true;

        for(int i=0;i<si;i++){

            if(ar[i]!='9')check = false;
        }

        if(check==true){

            printf("1");
            si-=1;

            for(int i=0;i<si;i++)printf("0");

            printf("1\n");
        }

        else{

            check = true;

            for(int i=0;i<=si/2;i++){

                if(ar[i]!=ar[si-i-1])check = false;
            }

            if(check==true){

                int st = si/2;

                if(si%2==0)st--;

                for(int i=st;i>=0;i--){

                    if(ar[i]!='9'){

                        ar[i] = ar[i]+1;
                        ar[si-i-1] = ar[i];
                        break;
                    }

                    else{

                            ar[i] = '0';
                            ar[si-i-1] = ar[i];
                    }
                }

                printf("%s\n", ar);
            }

            else{

                check = false;

                for(int i=0;i<si/2;i++){

                    if(ar[i]!=ar[si-i-1]){

                        if(ar[i]>ar[si-i-1])check = true;
                        else check = false;

                        ar[si-i-1] = ar[i];

                    }
                }

                if(check==false){

                    int st = si/2;

                    if(si%2==0)st--;

                    for(int i=st;i>=0;i--){

                        if(ar[i]!='9'){

                            ar[i] = ar[i]+1;
                            ar[si-i-1] = ar[i];
                            break;
                        }

                        else{

                            ar[i] = '0';
                            ar[si-i-1] = ar[i];
                        }
                    }
                }

                printf("%s\n", ar);
            }
        }
    }
    return 0;
}
