// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct data{

    int a , b;

    data(int _a , int _b){

        a = _a;
        b = _b;
    }
};

bool operator <(data A , data B)
{
    if(A.a==B.a){

        return A.b<B.b;
    }

    return A.a>B.a;
}

vector<data>v;
bool vis[10005];

int main(void)
{
    int n;

    scanf("%d",&n);

    for(int i=0;i<n;i++){

        int in1 , in2;
        scanf("%d %d",&in1 , &in2);
        v.push_back(data(in1 , in2));
    }

    sort(v.begin() , v.end());
    memset(vis , false , sizeof(vis));

    int ans = 0;

    for(int i=0;i<n;i++){

        for(int j=v[i].b;j>=1;j--){

            if(vis[j]==false){

                vis[j] = true;
                ans+=v[i].a;
                break;
            }
        }
    }

    printf("%d\n",ans);

    return 0;
}
