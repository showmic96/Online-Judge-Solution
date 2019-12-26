// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n , m;
vector<int>v;

bool possible(int t)
{
    int t_temp = t , counter = 0;

    for(int i=0;i<m;i++){

        t_temp = t;
        int temp = v[i];
        int j = 2;

        while(t_temp>0){

            if(temp>t_temp)break;
            t_temp-=temp;
            counter++;
            temp=v[i]*j;
            j++;
            //cout << counter << " " << temp << endl;
        }
    }

    if(counter>=n)return true;
    return false;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

      scanf("%d %d",&n , &m);
      v.clear();

      for(int i=0;i<m;i++){

        int in;
        scanf("%d",&in);
        v.push_back(in);
      }

      ll hi = 1e8 , low = 1 , mid , ans = 0 , c = 80;

      while(c--){

        mid = (hi+low)/2;

        if(possible(mid)==true){

            ans = mid;
            hi = mid-1;
        }

        else{
            low = mid+1;
        }

      }

      printf("%lld\n",ans);

    }
    return 0;
}
