// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int n;
    scanf("%d",&n);

    vector<int>v;

    for(int i=0;i<n;i++){

        int in;
        scanf("%d",&in);
        v.push_back(in);
    }

    ll sum1 = 0 , sum2 = 0;

    int i = 0 , j = n-1 , counter = 1;

    while(i<=j){

        if(v[i]>v[j]){

            if(counter%2==1)sum1+=v[i];
            else sum2+=v[i];
            i++;
        }

        else{

            if(counter%2==1)sum1+=v[j];
            else sum2+=v[j];
            j--;
        }

        counter++;
    }

    printf("%lld %lld\n",sum1 , sum2);

    return 0;
}
