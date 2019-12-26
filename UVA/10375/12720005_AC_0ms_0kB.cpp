// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int p , q , r , s;
    while(scanf("%d %d %d %d",&p , &q , &r , &s)==4){

        int a[3] , b[3];

        a[0] = p;
        a[1] = s;
        a[2] = r-s;

        b[0] = p-q;
        b[1] = q;
        b[2] = r;

        sort(a , a+3);
        sort(b , b+3);

        double ans = 1;
        vector<pair<int , int> > v1 , v2;

        for(int i=0;i<3;i++){

            if(a[i]>b[i]){
                v1.push_back(make_pair(b[i]+1 , a[i]));
            }

            else{
                v2.push_back(make_pair(a[i]+1 , b[i]));
            }
        }

        int si = max(v1.size() , v2.size());
        for(int i=0;i<si;i++){

            if(i<v1.size()&&i<v2.size()){

                for(int j=v1[i].first , k=v2[i].first;j<=v1[i].second||k<=v2[i].second;j++ , k++){

                    double t1 = 1;
                    double t2 = 1;
                    if(j<=v1[i].second)t1 = j;
                    if(k<=v2[i].second)t2 = k;

                    ans*=t1;
                    ans/=t2;
                }
            }

            else if(i<v1.size()){

                for(int j=v1[i].first;j<=v1[i].second;j++){

                    double temp = j;
                    ans*=temp;
                }
            }

            else{

                for(int j=v2[i].first;j<=v2[i].second;j++){

                    double temp = j;
                    ans/=temp;
                }
            }
        }

        printf("%.5f\n",ans+0.000000001);
    }
    return 0;
}
