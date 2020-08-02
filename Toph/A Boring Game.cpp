// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int in[100005];
vector<int>edges[100005];

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);
        for(int i=0;i<=n;i++){

            in[i] = 0;
            edges[i].clear();
        }

        for(int i=0;i<n-1;i++){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);

            edges[in1].push_back(in2);
            edges[in2].push_back(in1);

            in[in1]++;
            in[in2]++;
        }

        vector<int>temp;

        for(int i=1;i<=n;i++){

            if(in[i]==1)temp.push_back(i);
        }

        int counter = 0;

        for(int i=1;i<=n;i++){

            int t = 0;

            for(int j=0;j<edges[i].size();j++){

                if(binary_search(temp.begin() , temp.end() , edges[i][j])==true)t++;
            }

            if(binary_search(temp.begin() , temp.end() , i)==true)t++;

            if(t<temp.size()){counter++;}
        }

        printf("Case %d: %d\n",++c , counter);
    }
    return 0;
}
