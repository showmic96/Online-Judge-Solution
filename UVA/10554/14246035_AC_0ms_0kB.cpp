// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

long double get(string ar)
{
    long double now = 0;
    for(int i=0;i<ar.size()-1;i++){

        now*=10;
        now+=ar[i]-'0';
    }
    return now;
}

char s[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    string br , ar;
    while(gets(s)){

        br = "";
        for(int i=0;i<strlen(s);i++)br+=s[i];
        if(br=="-")break;

        long double counter = 0 , cg = 0 , tg = 0;

        while(true){

            if(br=="-")break;
            counter++;
            stringstream ss(br);
            ss >> ar;

            long double t = get(ar) , now, p = 0 , p1 = 0 , p2 = 0 , p3 = 0 , p4 = 0 , p5 = 0 , c = 0;

            if(ar[ar.size()-1]=='%'){p+=t;p1 = t;}
            else if(ar[ar.size()-1]=='C')tg+=t , cg+=t , c+=t;
            else tg+=t*9 , cg+=t*9 , c+=t*9;

            ss >> ar;
            t = get(ar);

            if(ar[ar.size()-1]=='%'){p+=t;p2 = t;}
            else if(ar[ar.size()-1]=='C')tg+=t , c+=t;
            else tg+=t*4 , c+=t*4;

            ss >> ar;
            t = get(ar);

            if(ar[ar.size()-1]=='%'){p+=t;p3 = t;}
            else if(ar[ar.size()-1]=='C')tg+=t,c+=t;
            else tg+=t*4,c+=t*4;

            ss >> ar;
            t = get(ar);

            if(ar[ar.size()-1]=='%'){p+=t;p4 = t;}
            else if(ar[ar.size()-1]=='C')tg+=t,c+=t;
            else tg+=t*4,c+=t*4;

            ss >> ar;
            t = get(ar);

            if(ar[ar.size()-1]=='%'){p+=t;p5 = t;}
            else if(ar[ar.size()-1]=='C')tg+=t,c+=t;
            else tg+=t*7,c+=t*7;

            gets(s);
            br = "";
            for(int i=0;i<strlen(s);i++)br+=s[i];

            if(p1>0)cg+=(c*p1/(100-p)) , tg+=(c*p1/(100-p));
            if(p2>0)tg+=(c*p2/(100-p));
            if(p3>0)tg+=(c*p3/(100-p));
            if(p4>0)tg+=(c*p4/(100-p));
            if(p5>0)tg+=(c*p5/(100-p));

            if(br=="-")break;
        }

        double ans = cg/tg*100;
        printf("%.0lf%c\n",ans,'%');
    }

    return 0;
}
