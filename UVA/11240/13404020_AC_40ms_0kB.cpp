// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        vector<int>v;
        int n;
        scanf("%d",&n);

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            v.push_back(in);
        }

        int counter = 1;

        for(int i=1;i<n;i++){

            if(counter%2==0&&v[i]>v[i-1])counter++;
            if(counter%2==1&&v[i]<v[i-1])counter++;
        }

        printf("%d\n",counter);
    }
    return 0;
}
