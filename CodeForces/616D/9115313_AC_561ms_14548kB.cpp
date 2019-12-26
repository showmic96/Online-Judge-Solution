// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int n , k;
    scanf("%d %d",&n, &k);//cin >> n >> k;

    vector<int>v;
    map<int , int>mp;

    for(int i=0;i<n;i++){

        int in;
        scanf("%d",&in);//cin >> in;
        v.push_back(in);
    }

    int p1 = 0 , p2 = 0 , diff = 1 , l , r , mx = -1;
    mp[v[p1]]++;

    while(p2<n){

        if(diff<=k){

            if(p2-p1>mx){

                mx = p2-p1;
                l = p1;
                r = p2;
            }
        }

        if(diff<=k){

            if(p2+1==n)break;
            p2++;
            mp[v[p2]]++;

            if(mp[v[p2]]==1)diff++;
        }

        else{

            mp[v[p1]]--;

            if(mp[v[p1]]==0)diff--;

            p1++;
        }


    }

    if(diff<=k){

        if(p2-p1>mx){

            mx = p2-p1;
            l = p1;
            r = p2;
        }
    }

    printf("%d %d\n",l+1 , r+1);//cout << l+1 << " " << r+1 << endl;

    return 0;
}
