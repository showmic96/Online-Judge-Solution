// In the name of Allah the Lord of the Worlds. 

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int cal[3005][40005];

ll dis(pair<double , double>p1 , pair<double , double>p2)
{
    double d = (p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second);
    
    ll ans = ceil(sqrt(d));
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int n , q;
    while(cin >> n >> q){
        
        if(n==0&&q==0)break;
        memset(cal , 0 , sizeof(cal));
        vector<pair<double , double> > v;
        for(int i=0;i<n;i++){
            
            double in1 , in2;
            cin >> in1 >> in2;
            v.push_back(make_pair(in1, in2));
        }
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<n;j++){
                
                if(i==j)continue;
                
                cal[i][dis(v[i] , v[j])] += 1;
            }
            
            for(int j=1;j<40005;j++)cal[i][j]+=cal[i][j-1];
        }
        
        while(q--){
            
            ll in;
            cin >> in;
            
            ll counter = 0;
            
            for(int i=0;i<n;i++){
                
                counter+=cal[i][in];
            }
            counter+=n;
            
            double ans = (double)counter/(double)n;
            
            cout << setprecision(2) << fixed << ans << endl;
        }
        
        cout << endl;
    }
    return 0;
}