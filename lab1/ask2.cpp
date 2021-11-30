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

struct modified_hash {
 
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30))
            * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27))
            * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    int operator()(uint64_t x) const
    {
        static const uint64_t random
            = steady_clock::now()
                  .time_since_epoch()
                  .count();
        return splitmix64(x + random);
    }
};




int main(int argc, char *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // auto start = std::chrono::high_resolution_clock::now();
    int n;
    long int k;
    long int sum=0;
    
    // int temp_k;
    // int temp_sum=0;
    int result=999999999;
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
    int *i_thesi;
    size_t size=sizeof(long long int)*(k+1);
    size_t size_thesi=sizeof(long int )*(k+1);
    size_t i_size_thesi=sizeof(long int )*(k+1);
    val = (long int *) malloc(size);
    thesi=(int*)malloc(size_thesi);
    i_thesi=(int*)malloc(i_size_thesi);
    //memset(val,0,(k+1)*sizeof(int));
    for(int i=0;i<=k;i++){
        val[i]=1000000;
        thesi[i]=1000000;
    }
    
    // mymap.reserve(k); // RESERVING SPACE BEFOREHAND
    // mymap.max_load_factor(0.25);
    vector<long int> res;
    bool check_for_1_element=false;
    
    for(int i=0;i<n; i++){
        sum=0;
        //temp_result=999999;
        for(int j=i;j<n;j++){
            
            if(sum+arr[j]<=k){
                sum+=arr[j];
                



                printf("[%d,%d] sum=%ld : ",i,j,sum);
                long int v = val[sum];
                long int len=j-i+1;
                long int th=thesi[sum];
                if(((v>=len )|| v==1000000  )){
                    printf(" sum got in:%ld th=%d |",v,thesi[sum]);
                    val[sum]=j-i+1;
                    thesi[sum]=i;
                }
                // sub_sums[i].push_back(sum);
                // sub_sums[i].push_back(j);
                // sub_sums[i].push_back(i);
                // list1.push_front(sum);
                // t++;
                if(thesi[k-sum]<i){
                    
                
                
                if(sum==k){
                    // printf("sum is same as k\n");
                    if(j==i){
                        result=1;
                        check_for_1_element=true;
                        break;
                    }
                    else{
                        if(j-i+1<result){
                            result=j-i+1;
                        }
                    }
                }
                if(val[k-sum]!=1000000  ){
                     printf("searching for %ld and found %ld %d\n",k-sum,val[k-sum], thesi[k-sum]);
                    
                    long int tmp=(val[k-sum]+j-i+1);
                    if((result>tmp ) ){
                        result=tmp;
                        printf("i DID change %d\n",result);

                    }
                    
                    
                }
                printf("k-sum not found! [%ld] thesi=%d\n",val[k-sum],thesi[k-sum]);
                }

            }
            else  {
                i=j;
                break;
                
            }
            

        }
        if(check_for_1_element){
                break;
            }
        
    
    }
    if(result==999999999){
        result=-1;
    }

    cout<<result<<endl;
    // auto end = std::chrono::high_resolution_clock::now();
    // auto duration_pref=std::chrono::duration_cast<std::chrono::milliseconds>(pref - start);
    // auto duration=std::chrono::duration_cast<std::chrono::milliseconds>(after_reading - start);
    // auto duration_end=std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    // cout<<"after reading "<<duration.count() << endl;
    // cout<<"pref "<<duration_pref.count() << endl;    
    // cout<<"duration "<<duration_end.count() << endl;
}