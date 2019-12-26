// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t , tc = 0;

    scanf("%d",&t);
    while(t--){

        int a , b , c;
        scanf("%d %d %d",&a , &b , &c);

        vector<int>v1 , v2 , v3 , v;

        for(int i=0;i<a;i++){

            int in;
            scanf("%d",&in);
            v1.push_back(in);
            v.push_back(in);
        }

        for(int i=0;i<b;i++){

            int in;
            scanf("%d",&in);
            v2.push_back(in);
            v.push_back(in);
        }

        for(int i=0;i<c;i++){

            int in;
            scanf("%d",&in);
            v3.push_back(in);
            v.push_back(in);
        }

        sort(v.begin() , v.end());
        sort(v1.begin() , v1.end());
        sort(v2.begin() , v2.end());
        sort(v3.begin() , v3.end());

        v.erase(unique(v.begin() , v.end()) , v.end());
        v1.erase(unique(v1.begin() , v1.end()) , v1.end());
        v2.erase(unique(v2.begin() , v2.end()) , v2.end());
        v3.erase(unique(v3.begin() , v3.end()) , v3.end());

        printf("Case #%d:\n",++tc);
        int c1 = 0 , c2 = 0;

        for(int i=0;i<v1.size();i++){

            if(binary_search(v2.begin() , v2.end() , v1[i])==false&&binary_search(v3.begin() , v3.end() , v1[i])==false)c1++;
        }

        for(int i=0;i<v.size();i++){

            if(binary_search(v1.begin() , v1.end() , v[i])==false){

                if(binary_search(v2.begin() , v2.end(), v[i])==true&&binary_search(v3.begin() , v3.end() , v[i])==true)c2++;
            }
        }

        printf("%d %d\n",c1 , c2);
        c1 = 0 , c2 = 0;

        for(int i=0;i<v2.size();i++){

            if(binary_search(v1.begin() , v1.end() , v2[i])==false&&binary_search(v3.begin() , v3.end() , v2[i])==false)c1++;
        }

        for(int i=0;i<v.size();i++){

            if(binary_search(v2.begin() , v2.end() , v[i])==false){

                if(binary_search(v1.begin() , v1.end(), v[i])==true&&binary_search(v3.begin() , v3.end() , v[i])==true)c2++;
            }
        }

        printf("%d %d\n",c1 , c2);
        c1 = 0 , c2 = 0;

        for(int i=0;i<v3.size();i++){

            if(binary_search(v2.begin() , v2.end() , v3[i])==false&&binary_search(v1.begin() , v1.end() , v3[i])==false)c1++;
        }

        for(int i=0;i<v.size();i++){

            if(binary_search(v3.begin() , v3.end() , v[i])==false){

                if(binary_search(v2.begin() , v2.end(), v[i])==true&&binary_search(v1.begin() , v1.end() , v[i])==true)c2++;
            }
        }

        printf("%d %d\n",c1 , c2);
    }

    return 0;
}
