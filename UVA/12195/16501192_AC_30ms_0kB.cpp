// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char ar[205];

double get(string ar)
{
    double temp = 0;

    for(int i=0;i<ar.size();i++){

        if(ar[i]=='W')temp+=1;
        else if(ar[i]=='H')temp+=1.0/2.0;
        else if(ar[i]=='Q')temp+=1.0/4.0;
        else if(ar[i]=='E')temp+=1.0/8.0;
        else if(ar[i]=='S')temp+=1.0/16.0;
        else if(ar[i]=='T')temp+=1.0/32.0;
        else if(ar[i]=='X')temp+=1.0/64.0;
    }

    return temp;
}

int main(void)
{
    while(scanf("%s",&ar)==1){

        if(ar[0]=='*')break;

        string temp = "";
        int counter = 0;

        for(int i=1;i<strlen(ar);i++){

            if(ar[i]=='/'){

                double now = get(temp);
                if(abs(1.00-now)<0.00000001)counter++;
                temp = "";
            }
            else temp+=ar[i];
        }

        printf("%d\n",counter);
    }

    return 0;
}
