#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    priority_queue<int>input;

    int a , in;

    while(cin >> a){

        if(!a)break;
        for(int i=0;i<a;i++){

            cin >> in;
            input.push(-in);
        }
        long long ans = 0;
        int temp3;


        while(!input.empty()){

            int temp1 = -input.top();
            input.pop();
            int temp2 = -input.top();
            input.pop();

            //cout << temp1 << " " << temp2 << endl;
            temp3 = temp1+temp2;
            ans+=temp3;

            if(input.empty()==true)break;

            input.push(-temp3);

        }

        cout << ans << endl;
    }

    return 0;
}
