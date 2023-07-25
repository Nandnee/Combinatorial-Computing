#include<iostream>
using namespace std;
int main() {
    int n, m;
    cin>>n;
    cin>>m;
    int arr[n][n];
    for(int i=0; i<n; i++) {
        for (int j=0;j<n-1;j++) {
            cin>>arr[i][j];
        }
        arr[i][n]=0;
    }
    int flag=1;
    for(int i=1; i<n; i++) {
        if(arr[0][i]>arr[i][0])
        flag=0;
    }
    if (flag==1) {
        cout<<2;
        return 0;
    }
    int flag2=1;
    int count=0;
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(arr[i][j]<arr[j][i-1])
            flag2=0;
        }
        if (flag2==1) {
            count++;
        }
        if (count>1) {
            cout<<2;
            return 0;
        }
    }
    cout<<1;
    return 0;
}