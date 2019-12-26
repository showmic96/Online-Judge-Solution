// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int n , k , a , m;
vector<int>v;
bool taken[200005];

bool f(int x)
{
    memset(taken , false , sizeof(taken));
    for(int i=0;i<x;i++){

        taken[v[i]] = true;
    }

    int counter = 0 , c = 0;

    for(int i=1;i<=n;i++){

        if(taken[i]==false){
            c++;
        }

        else{
            c = 0;
        }

        if(c==a){

            i++;
            counter++;
            c = 0;
        }
    }

    if(counter<k)return true;
    return false;
}

int main(void)
{
    scanf("%d %d %d %d",&n , &k , &a , &m);

    for(int i=0;i<m;i++){

        int in;
        scanf("%d",&in);
        v.push_back(in);
    }

    int hi = m , low = 1 , ans = -1 , t = 70 , mid;

    while(t--){

        mid = (hi+low)/2;

        if(f(mid)){

            ans = mid;
            hi = mid-1;
        }
        else{

            low = mid+1;
        }
    }

    printf("%d\n",ans);

    return 0;
}
