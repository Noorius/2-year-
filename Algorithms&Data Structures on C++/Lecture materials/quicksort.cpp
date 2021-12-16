#include <iostream>

using namespace std;

int partition(int arr[], int l, int r){
    int pivot = arr[r];
    int i = l -1;

    for(int j = l; j<=r-1; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
            
        }
    }

}

void printArray(int arr[], int n){
    for(int i=0;i <n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[]={12,11,13,51,6,7};
    int n =sizeof(arr)/sizeof(int);

    printArray(arr,n);


    return 0;
}