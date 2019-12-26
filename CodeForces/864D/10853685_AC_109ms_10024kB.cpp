// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll n;
    scanf("%lld",&n);

    vector<ll>v , data;
    int ar[1000005];
    bool first[1000005];

    memset(ar , 0 , sizeof(ar));
    memset(first , true , sizeof(first));

    for(int i=0;i<n;i++){

        ll in;
        scanf("%lld",&in);
        ar[in]++;

        data.push_back(in);
    }

    for(int i=1;i<=n;i++){

        if(ar[i]==0){

            v.push_back(i);
        }
    }

    ll counter = 0 , i1 = 0;

    for(int i=0;i<n;i++){

        if(ar[data[i]]==1)continue;

        if(ar[data[i]]>1){

            if(data[i]<v[i1]&&first[data[i]]==true){first[data[i]]=false;continue;}

            ar[data[i]]--;
            data[i] = v[i1];
            i1++;
            counter++;
        }
    }

    printf("%lld\n",counter);

    for(int i=0;i<n;i++){

        if(i!=0)printf(" ");
        printf("%lld",data[i]);
    }

    printf("\n");

    return 0;
}
