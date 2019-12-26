#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 , MAX = 100010;
typedef long long ll;
typedef unsigned long long LL;



int main(void)
{
    ll n ,t , in  , sum = 0 , hi = 0 , counter = 0;
    cin >> n >> t;

    ll ar[n];

    for(long long i=0;i<n;i++){

        cin >> ar[i];

    }

    long long point1 = 0 , point2 = 0;

    while(point2 < n){

        sum+=ar[point2];

        if(sum>t){

            //counter = point2 - point1;


            if(counter>hi)hi=counter;
            //counter++;

            while(sum>t){

                sum-=ar[point1];
                point1++;
                counter--;
            }
        }
        counter++;

        point2++;
    }

    if(counter>hi)hi=counter;

    cout << hi << endl;

    return 0;
}
