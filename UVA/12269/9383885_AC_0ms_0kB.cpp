// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

struct myStrcut{

    double s , e;

    myStrcut(double st , double et){

        s = st;
        e = et;
    }

};

bool cmp(myStrcut A , myStrcut B)
{
    return A.s < B.s;
}

int main(void)
{
    int n , m;
    double d;
    while(scanf("%d %d %lf",&n , &m , &d)==3){

        if(!n&&!m)break;

        d/=2;

        vector<myStrcut>v1 , v2;

        for(int i=0;i<n;i++){

            double in;
            scanf("%lf",&in);

            v1.push_back(myStrcut(in-d , in+d));
        }

        for(int i=0;i<m;i++){

            double in;
            scanf("%lf",&in);
            v2.push_back(myStrcut(in-d , in+d));
        }

        sort(v1.begin() , v1.end() , cmp);
        sort(v2.begin() , v2.end() , cmp);

        double current = 0;
        bool check = true;

        for(int i=0;i<n;i++){

            if(v1[i].s>current)break;

            current = v1[i].e;
        }

        if(current<75)check = false;
        current = 0;


        for(int i=0;i<m;i++){

            if(v2[i].s>current)break;

            current = v2[i].e;
        }

        if(current<100)check = false;

        if(check==false)printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
