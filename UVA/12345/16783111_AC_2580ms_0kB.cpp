// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int mp[1000005];
vector<int>v;
char x[3];

int main(void)
{
    int n , q;
    scanf("%d %d",&n , &q);

    for(int i=0;i<n;i++){

        int in;
        scanf("%d",&in);
        v.push_back(in);
    }

    while(q--){

        int in1 , in2;
        scanf("%s %d %d",&x , &in1 , &in2);

        if(x[0]=='M'){

            v[in1] = in2;
        }
        else{

            int ans = 0;

            for(int i=in1;i<in2;i++){

                if(mp[v[i]]==0){

                    ans++;
                    mp[v[i]] = 1;
                }
            }

            for(int i=in1;i<in2;i++){

                mp[v[i]] = 0;
            }

            printf("%d\n",ans);
        }
    }

    return 0;
}
