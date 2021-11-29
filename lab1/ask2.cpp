
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
    int n, k;
    int sum=0;
    int p=0;
    // int temp_k;
    // int temp_sum=0;
    int result=999999;
    //tuple<int,int> mytuple;
    // int temp_result=0;

    
    
    //scanf("%d %d",&n,&k);
    //fstream myfile(argv[1], ios_base::in);
    
    // myfile>>n>>k;
    cin>>n>>k;
    vector<int> arr(n+1);
    
    for(int i=0;i<n;i++){
        //scanf("%d",&arr[i]);
        // myfile>>arr[i];
        cin>>arr[i];
    }
    
    auto after_reading = std::chrono::high_resolution_clock::now();
    vector<vector<int>> sub_sums(2*n+1,vector<int>());
    unordered_map<int,int> mymap;

    bool check_for_1_element=false;
    
    for(int i=0;i<n;i++){
        sum=0;
        //temp_result=999999;
        for(int j=i;j<n;j++){
            if(sum+arr[j]<=k){
            sum+=arr[j];
            if(sum==k && j==i){
                result=1;
                // check_for_1_element=true;
                cout<<result<<endl;
                return 0;
                // break;
            }
            sub_sums[i].push_back(sum);
            sub_sums[i].push_back(j-i+1);
            // list1.push_front(sum);
            // t++;
            if(mymap[k-sum]){
                result=min(result,mymap[k-sum]+j-i+1);
            }
            

            }
            else  {
                
                break;
                
            }
            // if(check_for_1_element){
            //     break;
            // }

        }
    if(!(check_for_1_element)){
    for(int k=0;k<sub_sums[i].size();k+=2){
        //printf("new map insert for i=%d sum=%d map=%d\n",i,sub_sums[i][k],mymap[sub_sums[i][k]]);
        if(mymap[sub_sums[i][k]]){
            //printf("[%d] new possible map value =%d\n",mymap[sub_sums[i][k]],sub_sums[i][k+1]);
            mymap[sub_sums[i][k]]=min(mymap[sub_sums[i][k]],sub_sums[i][k+1]);
        }
        else{
            mymap[sub_sums[i][k]]=sub_sums[i][k+1];
        }
        
    }
    }
    }
    // auto pref = std::chrono::high_resolution_clock::now();
    
        
        
        
            
        
        
    if(result==999999){
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

