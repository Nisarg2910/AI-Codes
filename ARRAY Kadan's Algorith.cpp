#include<iostream>
using namespace std;
/*  CORRECT SOLUTION FOR GFG.
int currentSum = 0;
        int maxi = 0;
        int negativeMax = INT_MIN;

        for(int i=0; i<n; ++i){

            currentSum += arr[i];

            if(currentSum<0){
                currentSum = 0;
            }

            maxi = max(maxi, currentSum);

            if(arr[i]<0){
                negativeMax = max(arr[i], negativeMax);
            }
        }

        if(maxi == 0){
            return negativeMax;
        }
        else
            return maxi;
*/
int main(){
    int n;
    cin>>n;

    int arr[n];

    int currentSum = 0;
    int maxi = INT_MIN;

    for(int i=0; i<n; ++i){
        cin>>arr[i];
    }
    for(int i=0; i<n; ++i){


        currentSum += arr[i];

        if(currentSum < 0){
            if(i == n-1){
                maxi = -1;
            }else{
                currentSum = 0;
            }
        }

        maxi = max(maxi, currentSum);
    }

    cout<<"Max: "<<maxi;
}


