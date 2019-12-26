// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 3e3+9;
int ar[MAX+9];
vector<int>ans;

void pre()
{
    memset(ar , 0 , sizeof(ar));
    for(int i=2;i<=MAX;i++){

        if(ar[i]==0){

            for(int j=2*i;j<=MAX;j+=i)ar[j]++;
        }
    }
    ans.push_back(0);
    for(int i=0;i<=MAX;i++)if(ar[i]>=3)ans.push_back(i);
}

int main(void)
{
    pre();

    int t;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }
    return 0;
}
