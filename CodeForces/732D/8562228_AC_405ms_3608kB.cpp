// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5+9;
int day[MAX+9];
int n , m;

struct myStruct{

    bool taken;
    int i , value;

}data[MAX+9];

bool is_possible(int lim)
{

    int counter = 0 , c = 0;

    for(int i = lim ; i>0 ;i--){

        if(day[i]==0){

            if(counter>=0)continue;
            counter++;
        }

        else if(data[day[i]].taken==true){

            if(counter>=0)continue;
            counter++;
        }

        else{

            c++;
            counter-=data[day[i]].value;
            data[day[i]].taken = true;
        }
    }

    for(int i=1;i<=lim;i++){
        data[i].taken = false;
    }

    if(counter>=0&&c>=m)return true;
    return false;
}

int main(void)
{

    cin >> n >> m;

    for(int i=1;i<=n;i++)cin >> day[i];

    for(int i=1;i<=m;i++){

        cin >> data[i].value;
        data[i].taken = false;

    }

    int hi = n , low = 1 , mid , t = 200 , ans = -1 ;

    while(t--){

        mid = (hi+low)/2;
        if(is_possible(mid)==true){

            ans = mid;
            hi = mid-1;
        }

        else low = mid+1;
    }

    cout << ans << endl;

    return 0;
}
