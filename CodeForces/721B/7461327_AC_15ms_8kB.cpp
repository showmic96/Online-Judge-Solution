// In the name of Allah the Lord of the worlds .

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int a, ar[1110] , b , c;
    cin >> a >> b;

    string br;

    for(int i=0;i<a;i++){

        cin >> br;

        ar[i] = br.size();
    }

    cin >> br;

    c = br.size();

    sort(ar , ar+a);
    int counter1 = 0 , counter2 = 0;

    for(int i=0;i<a;i++){

        if(ar[i]<c)counter1++;
        if(ar[i]<=c)counter2++;
    }
    counter2--;

    cout << (counter1/b)*5 + counter1+1 << " " << (counter2/b)*5 + counter2 + 1 << endl;

    return 0;
}
