// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll>v , v1 , v2;

int main(void)
{
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){

        ll in;
        scanf("%lld",&in);
        v.push_back(in);
    }

    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){

            for(int k=0;k<n;k++){

                ll temp = v[i]*v[j]+v[k];
                v1.push_back(temp);
            }
        }
    }

    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){

            for(int k=0;k<n;k++){

                if(v[k]==0)continue;

                ll temp = (v[i]+v[j])*v[k];
                v2.push_back(temp);
            }
        }
    }

    sort(v2.begin() , v2.end());

    ll counter = 0;

    for(int i=0;i<v1.size();i++){

        counter+=upper_bound(v2.begin() , v2.end() , v1[i])-lower_bound(v2.begin() , v2.end() , v1[i]);
    }

    printf("%lld\n",counter);

    return 0;
}
