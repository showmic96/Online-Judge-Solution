// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

bool visited[123456];

int Find(int v , int x)
{
    int temp = v/x;
    int dis = temp*x;
    temp=v-dis;

    return temp;
}

int main(void)
{
    int n , x;
    cin >> n >> x;

    for(int i=0;i<123456;i++)visited[i] = false;

    while(n--){

        int in1 , in2;
        cin >> in1 >> in2;

        for(int i=in1;i<=in2;i++)visited[i] = true;
    }

    int counter = 0 , ans = 0;

    for(int i=1;i<=123456;i++){

        if(visited[i]==false)counter++;
        else{

            if(counter==0)ans++;
            else{

                ans++;
                int temp = Find(counter , x);
                //cout << counter << " " << temp << endl;
                ans+=temp;
                counter = 0;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
