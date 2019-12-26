// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    scanf("%d",&n);

    map<int , int> mp1 , mp2;

    vector<int>v;

    for(int i=0;i<n;i++){

        int in1 , in2;
        scanf("%d %d",&in1 , &in2);

        v.push_back(in1);
        v.push_back(in2);

        mp1[in1]++;
        if(in1!=in2){

            mp2[in2]++;
        }
    }

    int mi = 1e9 , si = v.size() , need = n/2;

    if(n%2==1)need++;

    for(int i=0;i<si;i++){

        if(mp1[v[i]]>=need){

            mi = 0;
            break;
        }

        if(mp1[v[i]]+mp2[v[i]]>=need){

            mi = min((need-mp1[v[i]]) , mi);
        }
    }

    if(mi==1e9)mi = -1;

    printf("%d\n",mi);

    return 0;
}
