#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

vector<long long>v;
vector<long long>ans(3);
long long small = 100000000000 ;
long long l,r;

void work(int n){

    for(long long i=0;i<n;i++){
        l = i+1;
        r = n-1;
        while(l < r){
            if(abs(small) > abs(v[i] + v[l] + v[r])){
                small = v[i] + v[l] + v[r];

                ans[0] = v[i];
                ans[1] = v[l];
                ans[2] = v[r];
            }

            if( v[i] + v[l] + v[r] < 0 ){
                l++;
            }
            else{
                r--;
            }
        }
    }

    sort(ans.begin(),ans.end());
    for(int i=0;i<3;i++){
        cout << ans[i] << " ";
    }
    return;
}



int main()
{
    long long n;
    cin >> n;
    for(long long i=0;i<n;i++){
        int m;
        cin >> m;
        v.push_back(m);
    }
    sort(v.begin(),v.end());

    work(n);

    return 0;
}
