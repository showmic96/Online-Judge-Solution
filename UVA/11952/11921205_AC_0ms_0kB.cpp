// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

char ar[10] , br[10] , cr[10];

int f(string ar , int b)
{
    int si = ar.size();

    int value = 0;

    for(int i=0;i<si;i++){

        value*=b;
        value+=ar[i]-'0';
    }

    return value;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        scanf("%s + %s = %s",&ar , &br , &cr);

        string a(ar , strlen(ar)) , b(br , strlen(br)) , c(cr , strlen(cr));

        bool check = true;
        int mi = 1;

        for(int i=0;i<a.size();i++){

            if(a[i]!='1')check = false;
            mi = max(mi , a[i]-'0');
        }

        for(int i=0;i<b.size();i++){

            if(b[i]!='1')check = false;
            mi = max(mi , b[i]-'0');
        }

        for(int i=0;i<c.size();i++){

            if(c[i]!='1')check = false;
            mi = max(mi , c[i]-'0');
        }


        if(check==true&&a.size()+b.size()==c.size()){

            printf("1\n");
        }

        else{

            check = false;

            for(int i=mi+1;i<=30;i++){

                if(f(a , i)+f(b,i)==f(c,i)){

                    check = true;
                    printf("%d\n",i);
                    break;
                }
            }

            if(check==false)printf("0\n");
        }
    }
    return 0;
}
