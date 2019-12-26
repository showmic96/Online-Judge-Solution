// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n , ans = -1;
    scanf("%d",&n);
    vector<pair<int ,int>> v(n);
    for(int i=0;i<n;i++){
        int in1 ,in2;
        scanf("%d %d",&in1 , &in2);
        v[i] = {in1 ,in2};
    }
    for(int i=n;i>=0;i--){

        int counter = 0;
        for(auto it:v){
            if(it.first<=i&&i<=it.second)counter++;
        }
        if(counter==i){
            ans = i;
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}
