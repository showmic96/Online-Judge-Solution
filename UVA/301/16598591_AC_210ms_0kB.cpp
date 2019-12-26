// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int t , n , m , counter = 0 , ar[10];
struct s{

    int u , v , c;
    s(int _u , int _v , int _c){

        u = _u;
        v = _v;
        c = _c;
    }
};
vector<s>v;

void f(int i , int val)
{
    if(i==m){

        counter = max(counter , val);
        return ;
    }

    f(i+1 , val);
    bool check = true;

    for(int j=v[i].u;j<v[i].v;j++){

        ar[j]+=v[i].c;
        if(ar[j]>t)check = false;
    }

    if(check==true){

        f(i+1 , val+(v[i].v-v[i].u)*v[i].c);
    }

    for(int j=v[i].u;j<v[i].v;j++){

        ar[j]-=v[i].c;
    }
}

int main(void)
{
    while(scanf("%d %d %d",&t , &n , &m)==3){

        if(t==0&&n==0&&m==0)break;

        v.clear();

        for(int i=0;i<m;i++){

            int in1 , in2 , in3;
            scanf("%d %d %d",&in1 , &in2 , &in3);
            v.push_back(s(in1 , in2 , in3));
        }

        counter = 0;
        memset(ar , 0 , sizeof(ar));
        f(0 , 0);
        printf("%d\n",counter);
    }
    return 0;
}
