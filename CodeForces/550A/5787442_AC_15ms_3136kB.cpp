#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    char a[1000005];
    gets(a);
    long long b ,  c ,c1,c2, d , e , f=0;
    b=strlen(a);
    d=0;f=0;c1=b;c2=b;
    for(c=0;c<b-1;c++)
            if(a[c]=='A'&&a[c+1]=='B'){d+=1;c1=c+2;break;}
    for(c=c1;c<b-1;c++)
            if(a[c]=='B'&&a[c+1]=='A'){d+=1;break;}
    for(c=0;c<b-1;c++)
            if(a[c]=='B'&&a[c+1]=='A'){f+=1;c2=c+2;break;}
    for(c=c2;c<b-1;c++)
            if(a[c]=='A'&&a[c+1]=='B'){f+=1;break;}



    if((d==2)||(f==2)) cout << "YES" << endl;
    else cout << "NO" << endl;
    memset(a, '\0', sizeof(a));

    return 0;
}
