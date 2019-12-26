// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int n , g;
    while(scanf("%d %d",&n , &g)==2){

        vector<int> v;

        for(int i=0;i<n;i++){

            int in1, in2;
            scanf("%d %d",&in1, &in2);
            v.push_back(in1-in2);
        }

        sort(v.begin() , v.end());
        int ans = 0;

        for(int i=n-1;i>=0;i--){

            if(v[i]>0)ans+=3;
            else if(v[i]<=0){

                int mi = min(abs(v[i])+1 , g);
                g-=mi;
                v[i]+=mi;

                if(v[i]==0)ans+=1;
                else if(v[i]>0)ans+=3;
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}
