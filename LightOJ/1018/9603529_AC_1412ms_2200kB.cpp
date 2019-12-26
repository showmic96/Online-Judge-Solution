// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int dp[(1<<17) + 10];
int n , lim;
vector<pair<double , double> > v;

int Set(int n , int pos)
{
    return (n|(1<<pos));
}

bool Check(int n , int pos)
{
    return (n&(1<<pos));
}

double slope(pair<double , double> p1 , pair<double , double> p2)
{
    //cout << "yes" << endl;
    if(p1.first - p2.first==0)return 0;
    if(p1.second - p2.second==0)return 1e19;
//cout << "yes" << endl;
    return ((p2.second-p1.second)/(p2.first-p1.first));
}

int f(int state)
{
    //cout << state << " " << lim << endl;
    if(state==lim)return 0;

    if(dp[state]!=-1)return dp[state];

    int temp = state;
    int s = state;
    int value = 123456789;

    for(int i=0;i<n;i++){

        if(Check(state , i)==false){
            bool check = false;
            state = Set(state , i);

            for(int j=i+1;j<n;j++){

                if(Check(state , j)==false){

                    check = true;

                    temp = state;

                    //temp = Set(temp , i);
//cout << "yes";
                    double s = slope(v[i] , v[j]);
//cout << "yes";
                    for(int k=0;k<n;k++){

                        if(slope(v[k] , v[i])==s)temp = Set(temp , k);
                    }

                    value = min(value , f(temp) + 1);
                }
            }

            if(check==false)value = min(value , f(state) + 1);
            break;
        }
    }

    return dp[s] = value;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        memset(dp , -1 , sizeof(dp));

        v.clear();

        scanf("%d",&n);

        lim = 1<<n;
        lim--;

        for(int i=0;i<n;i++){

            double in1 , in2;
            scanf("%lf %lf",&in1 , &in2);
            v.push_back(make_pair(in1 , in2));
        }

        printf("Case %d: %d\n",++c , f(0));
    }
    return 0;
}
