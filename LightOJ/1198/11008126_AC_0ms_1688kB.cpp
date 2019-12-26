// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);
        vector<int>v1 , v2;

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            v1.push_back(in);
        }

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            v2.push_back(in);
        }

        sort(v1.begin() , v1.end());
        sort(v2.begin() , v2.end());

        bool taken1[55] , taken2[55];

        memset(taken1 , false , sizeof(taken1));
        memset(taken2 , false , sizeof(taken2));

        int counter = 0;

        for(int i=0;i<n;i++){

            for(int j=n-1;j>=0;j--){

                if(v1[i]>v2[j]){

                    if(taken1[i]==false&&taken2[j]==false){
                        counter+=2;
                        taken1[i] = true;
                        taken2[j] = true;
                        break;
                    }
                }
            }
        }

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                if(v1[i]==v2[j]){

                    if(taken1[i]==false&&taken2[j]==false){

                        counter++;
                        taken1[i] = true;
                        taken2[j] = true;
                    }
                }
            }
        }

        printf("Case %d: %d\n",++c , counter);
    }
    return 0;
}
