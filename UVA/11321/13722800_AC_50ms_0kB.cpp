// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n , m;
vector<int>v;

bool cmp(int a , int b)
{
    if(a%m==b%m){

        if(abs(a)%2!=abs(b)%2){

            if(abs(a)%2==1)return true;
            return false;
        }
        if(abs(a)%2==1&&abs(a)%2==abs(b)%2){

            return a>b;
        }
        else if(abs(a)%2==abs(b)%2){

            return a<b;
        }

        return false;
    }

    return a%m<b%m;
}

int main(void)
{

    while(scanf("%d %d",&n , &m)==2){

        printf("%d %d\n",n , m);

        if(n==0&&m==0)break;
        v.clear();

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            v.push_back(in);
        }

        sort(v.begin() , v.end() , cmp);

        for(int i=0;i<n;i++)printf("%d\n",v[i]);
    }
    return 0;
}
