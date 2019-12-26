// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int x[1005] , y[1005];

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        vector<pair<int , int> > v;

        int n;
        scanf("%d",&n);

        for(int i=0;i<n;i++){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);
            x[i] = in1;
            y[i] = in2;
        }

        for(int i=0;i<n;i++){

            for(int j=i+1;j<n;j++){

                int xx = x[i]+x[j];
                int yy = y[i]+y[j];

                v.push_back(make_pair(xx , yy));
            }
        }

        sort(v.begin() , v.end());

        int si = v.size();
        long long ans = 0 , counter = 1;

        for(int i=1;i<si;i++){

            if(v[i]==v[i-1]){

                counter++;
            }

            else{

                ans+=(double)counter*(counter-1)/2.00;
                counter = 1;
            }
        }

        ans+=(double)counter*(counter-1)/2.00;

        printf("Case %d: %lld\n",++c , ans);
    }

    return 0;
}
