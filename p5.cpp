#include "iostream"
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int partition_lastPivot(vector<int>& arr, int left, int right)
{
    int pivot = arr[right];
    int i=left-1;
    for(int j=left;j<=right-1;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            int t=arr[i];
            arr[i]=arr[j];
            arr[j]=t;
        }
    }
    int t=arr[right];
    arr[right]=arr[i+1];
    arr[i+1]=t;
    return (i+1); 
}
void quickSort(vector<int>& arr, int left, int right)
{
    if(left < right)
    {
        int partitionIndex = partition_lastPivot(arr, left, right);
        quickSort(arr, left, partitionIndex-1);
        quickSort(arr, partitionIndex+1, right);
    }
}
int main()
{
    int length;
    cout<<"Enter length : ";
    cin>>length;
    vector<int>arr;
    vector<int> arr2;
    for(int i = 0; i<length; i++)
    arr.push_back(rand()%1000);
    arr2=arr;
    auto start = high_resolution_clock::now();
    quickSort(arr,0,length-1);
    // for(auto it : arr)cout<<it<<" ";
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds> (end-start);
    cout<<"Duration in random array is : "<<duration.count()<<" ms\n";
    sort(arr.begin(),arr.end());
    start = high_resolution_clock::now();
    quickSort(arr,0,length-1);
    // for(auto it : arr)cout<<it<<" ";
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds> (end-start);
    cout<<"Duration in sorted array is : "<<duration.count()<<" ms\n";
    sort(arr.begin(),arr.end(),greater<int>());
    start = high_resolution_clock::now();
    quickSort(arr,0,length-1);
    // for(auto it : arr)cout<<it<<" ";
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds> (end-start);
    cout<<"Duration in reversly sorted array is : "<<duration.count()<<" ms\n";
    sort(arr2.begin(),arr2.begin()+(length/2));
    start = high_resolution_clock::now();
    quickSort(arr2,0,length-1);
    // for(auto it : arr)cout<<it<<" ";
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds> (end-start);
    cout<<"Duration in 50\% array is : "<<duration.count()<<" ms\n";
    return 0;
}
