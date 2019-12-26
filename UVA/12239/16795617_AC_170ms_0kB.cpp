// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int n , m;
    while(scanf("%d %d",&n , &m)==2){

        if(n==0&&m==0)break;

        vector<int>v;
        set<int>st;

        for(int i=0;i<m;i++){

            int in;
            scanf("%d",&in);
            v.push_back(in);
        }

        for(int i=0;i<m;i++){

            for(int j=i+1;j<m;j++){

                st.insert(abs(v[i]-v[j]));
            }
        }

        if(st.size()==n)printf("Y\n");
        else printf("N\n");
    }

    return 0;
}
