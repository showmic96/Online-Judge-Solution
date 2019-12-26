#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

bool cmp(pair<int , int>A , pair<int , int> B)
{
    return A.second < B.second;
}

int main(void)
{
    vector<pair<int , int> > input;

    int a , b, in1 ,in2;
    while(cin >> a){

        if(!a)break;

        input.clear();

        for(int i=0;i<a;i++){

            cin >> in1 >> in2;
            input.push_back(make_pair(in1 , in2));
        }

        sort(input.begin() , input.end() ,cmp);

        int d = 0;

        while(input[d].second<0)d++;
        
        double hi = 1e9 , temp;
        
        for(int i=d;i<a;i++){
            
            temp = 4.5/input[i].first*3600+input[i].second;
            
            if(temp<hi)hi = temp;
        }
        

        cout << ceil(hi) << endl;
    }
    return 0;
}
