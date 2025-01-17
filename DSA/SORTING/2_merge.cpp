#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
merge sort--
its based on Divide-and-conquer algorithm --
desi bahsa me - todo or jodo ;
png dala hu wo dekh lo
// jitni algo padhi h ab tk unme sb me fast h ye algorithm


*/

// space complexity -o(n);
// time complexity-o(nlogn);
void sort_krke_merge_kr_do(int arr[],int s,int e){
    int mid=s+(e-s)/2; //hm do array bnaenge unko sort krke copy mar denge main arr me;
    int len1=mid-s+1;
    int len2=e-mid;
    int *first =new int[len1];
    int *second=new int[len2];
    int mainarrayindex=s;
    for(int i=0;i<len1;i++){
        first[i]=arr[mainarrayindex];
        mainarrayindex++;
    }
    mainarrayindex=mid+1;
    for(int i=0;i<len2;i++){
        second[i]=arr[mainarrayindex];
        mainarrayindex++;
    }
    //merge 2 soreted array
    int index1=0;
    int index2=0;
    mainarrayindex=s;
    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[mainarrayindex]=first[index1];
            mainarrayindex++;
            index1++;
        }
        else{
            arr[mainarrayindex]=second[index2];
            mainarrayindex++;
            index2++;
        }
    }
    while(index1<len1){
         arr[mainarrayindex]=first[index1];
            mainarrayindex++;
            index1++;
    }
    while(index2<len2){
            arr[mainarrayindex]=second[index2];
            mainarrayindex++;
            index2++;

    }


}
void merge_sort(int arr[],int s,int e){
    if(s>=e){
        return;
    }
    int mid=s+(e-s) /2;
    merge_sort(arr,s,mid);
    merge_sort(arr,mid+1,e);
    sort_krke_merge_kr_do(arr,s,e);
}



int main(){ 
    int arr[]={64,25,12,22,11};
    merge_sort(arr,0,4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<"  ";
    }cout<<endl;
}