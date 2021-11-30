#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <unordered_map>
#include <tuple>
#include <bits/stdc++.h>
#include <list>
using namespace std::chrono;
using namespace std;

// void printvector(vector<int> pair){
//     for(int i=0;i<pair.size();i++){
//                     printf("%d ",pair[i]);
//                 }
//     cout<<endl;
// }
// int make2dto1d(int a, int b){
//     return (a+b)*(a+b+1)/2+b;
// }

int main(int argc, char *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // auto start = std::chrono::high_resolution_clock::now();
    int n;
    long int k;
    long int sum=0;
    
    // int temp_k;
    // int temp_sum=0;
    long int result=999999999;
    //tuple<int,int> mytuple;
    // int temp_result=0;

    
    
    //scanf("%d %d",&n,&k);
    // fstream myfile(argv[1], ios_base::in);
    
    // myfile>>n>>k;
    cin>>n>>k;
    vector< long int> arr(n+1);
    
    for(int i=0;i<n;i++){
        //scanf("%d",&arr[i]);
        // myfile>>arr[i];
        
        cin>>arr[i];
        
    }
    
    // auto after_reading = std::chrono::high_resolution_clock::now();
    vector<vector<long int>> sub_sums(2*n+1,vector<long int>());
    // unordered_map<int,int> mymap;
    
    long int *val ;
    int *thesi;
    
    size_t size=sizeof(long long int)*(k+1);
    size_t size_thesi=sizeof(long int )*(k+1);
    
    val = (long int *) malloc(size);
    thesi=(int*)malloc(size_thesi);
    
    //memset(val,0,(k+1)*sizeof(int));
    for(int i=0;i<=k;i++){
        val[i]=1000000;
        thesi[i]=1000000;
    }
    
    // mymap.reserve(k); // RESERVING SPACE BEFOREHAND
    // mymap.max_load_factor(0.25);
    
    bool check=false;
    for(int i=0;i<n;i++){
        sum=0;
        for(int j=i;j<n;j++){
            if(sum+arr[j]<=k){
                sum+=arr[j];
                // cout<<"["<<sum<<" "<<i<<" "<<j<<" ";
                long int v = val[sum];
                long int len=j-i+1;
                long int th=thesi[sum];
                if((v>=len || v==1000000  )){
                    val[sum]=j-i+1;
                    thesi[sum]=i;
                    // cout<< "]";
                }
                if(sum==k){
                    if(i==j){
                        result=1;
                        check=true;
                        break;
                        
                    }
                    if(result>j-i+1){
                        result=j-i+1;
                        val[sum]=result;
                    }
                    
                }
            }
            else{
                break;
            }
        }
        if(check){
            break;
        }
        
        // cout<<endl;
        
    }
if(!check){
    for(int i=0;i<n;i++){
        sum=0;
        for(int j=i;j<n;j++){
            if(sum+arr[j]<=k){
                sum+=arr[j];
                // printf("[%d %d]sum=%ld, search for k-sum=%ld\n",i,j,sum,k-sum);
                if(val[k-sum]!=1000000 && thesi[k-sum]>j){
                    result=min(result,val[k-sum]+j-i+1);
                    // printf("found it, new result=%ld\n",result);
                }
            }
            else{
                break;
            }
        }
        
        
    }
}
    

    if(result==999999999){
        result=-1;
    }

    cout<<result<<endl;
}