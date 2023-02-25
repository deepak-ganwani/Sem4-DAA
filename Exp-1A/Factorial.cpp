#include<bits/stdc++.h>
using namespace std;

bool ready[21];
long long value[21];

long long factorial(int n) {
    if(ready[n]) return value[n];
    value[n]=n*factorial(n-1);
    ready[n]=true;
    return value[n];
}

int main(){
    ready[0]=true;
    value[0]=1;
    for (int i = 0; i < 21; i++)
    {
        cout<<i<<" : "<<factorial(i)<<endl;
    }
    
    return 0;
}