// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1234567;

bool isPrime[MAX+9];
vector<int>primes;

void seive()
{
    for(int i=0;i<=MAX;i++)isPrime[i] = true;

    for(long long i=2;i<=MAX;i++){

        for(long long j=2;i*j<=MAX;j++){

            if(isPrime[i]==true)isPrime[i*j] = false;
        }

        if(isPrime[i]==true)primes.push_back(i);
    }

}

int main(void)
{
    seive();

    long long a , b;
    cin >> a >> b;

    long long f = __gcd(a , b);
    long long f_temp = f;
    //cout << "GCD " << f << endl;
    vector<long long>v;

    long long lim = sqrt(f);

    //cout << si << " " << primes[si-1] << endl;
    v.push_back(1);

    for(int i=1;i<=lim;i++){

        if(f%i==0){

            if(i>1){

                v.push_back(i);

                if(i!=f/i&&f/i>1)v.push_back(f/i);
            }

        }
    }

    v.push_back(f_temp);

    sort(v.begin() ,v.end());

    int q;
    cin >> q;

    //for(int i=0;i<v.size();i++)cout << v[i] << " ";
    //cout << endl;
//return 0;
    while(q--){

        long long in1 , in2;
        cin >> in1 >> in2;
        vector<long long > ::iterator it = lower_bound(v.begin() , v.end() , in2);
        //cout << "LOWER BOUND " << it - v.begin() << endl;
        //it--;
        if(in1==1&&in2==1)cout << 1 << endl;
        else if(binary_search(v.begin() , v.end() , *it)==true&&*it>=in1&&*it<=in2)cout << *it << endl;
        else{
            it--;
            if(*it>=in1)cout << *it << endl;
            else cout << -1 << endl;
        }

    }

    return 0;
}
