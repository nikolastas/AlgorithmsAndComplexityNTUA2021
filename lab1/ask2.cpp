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


using namespace std;

void printvector(vector<int> pair){
    for(int i=0;i<pair.size();i++){
                    printf("%d ",pair[i]);
                }
    cout<<endl;
}
int make2dto1d(int a, int b){
    return (a+b)*(a+b+1)/2+b;
}
// auto next_arr(vector<int> arr,int i){
//     auto it = arr.begin()+i+1;
//     while(it==-2){
//         it++;
//     } 
//     return it;
// }
// auto prev_arr(vector<int> arr,int i){
//     auto it = arr.begin()+i-1;
//     while(it==-2){
//         it--;
//     } 
//     return it;
// }
// int find_v(vector<int> arr, int i, int l){
    
//     int result=999999;
//     for(int )
//     if(result!=999999){
//     return result;
//     }
//     return 999999;
// }
int main(int argc, char *argv[]){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    auto start = std::chrono::high_resolution_clock::now();
    int n, k;
    int sum=0;
    int p=0;
    int temp_k;
    int temp_sum=0;
    int result=999999;
    //tuple<int,int> mytuple;
    int temp_result=0;

    
    
    //scanf("%d %d",&n,&k);
    fstream myfile(argv[1], ios_base::in);
    
    myfile>>n>>k;
    //cin>>n>>k;
    vector<int> arr(n+1);
    
    for(int i=0;i<n;i++){
        //scanf("%d",&arr[i]);
        myfile>>arr[i];
        //cin>>arr[i];
    }
    
    auto after_reading = std::chrono::high_resolution_clock::now();
    vector<vector<int>> sub_sums(n+1,vector<int>());
    map<int,int> mymap;  
    int maps_so_far=0;
    int t=0;
    for(int i=0;i<n;i++){
        sum=0;
        //temp_result=999999;
        for(int j=i;j<n;j++){
            if(sum+arr[j]<=k){
            sum+=arr[j];
            sub_sums[i].push_back(sum);
            t=0;
            if(i!=0){

                while(t<=maps_so_far){
                    auto it=mymap.find(make2dto1d(i,sum));
                    if((it!=mymap.end() && it->second>j-i+1 )|| it==mymap.end()){
                        
                    
                        auto const res=mymap.insert(pair<int,int>(make2dto1d(t,sum),j-i+1));
                        printf("map[%d,%d]=%d \n",t,sum,j);
                            if (!(res.second) && mymap[make2dto1d(i,sum)]>j-i+1) { 
                                res.first->second = j; 
                                
                            }
                        
                    }
                    t++;
                }
            }        
            
            // if(j+1<=n-1){
            //     temp_k=k-sum;
            //     if(temp_k==0){
            //         cout<<" 0 remaing"<<j-i+1<<endl;
            //         result=min(result,j-i+1);
            //         break;
            //     }
            //     temp_sum=0;
            //     temp_result=j-i;
            //     for(int l=j+1;l<n;l++){
            //         printf("[%d,%d,%d] i am missing %d so reamining=%d \n",i,j,l,temp_k,temp_sum);
            //         temp_sum+=arr[l];
            //         if(temp_sum==temp_k) {                     
            //             temp_result+=l-j+1;
            //             cout<<"temp="<<temp_result<<endl;
            //             result=std::min(result,temp_result);
                        
            //             break;
            //         }
            //         else if (temp_sum>k){
            //             break;
            //         }
            //     }
            // }

            }
            else  {
                
                break;
                
            }

        }
       maps_so_far++;
    }
    
    bool check1=false;

    for(int i=0;i<sub_sums.size();i++){
        
        for(int j=0;j<sub_sums[i].size();j++){
             printf("[%d,%d]=%d searching minimum elem for sum=%d\n",i,j,make2dto1d(i,k-sub_sums[i][j]),k-sub_sums[i][j]);
             auto itr=mymap.find(make2dto1d(i,k-sub_sums[i][j]));
             if(itr!=mymap.end()){
                 printf("founf it with size %d\n",itr->second);
                 result=min(result,itr->second);
             }
            // for(int s=i+1;s<sub_sums.size();s++){
            //     for(int l=0;l<sub_sums[s].size();l++){
            //         if(k==sub_sums[i][j]){
            //             result=min(result,j+1);
            //             check1=true;
            //             break;
            //         }
            //         else if((k-sub_sums[i][j])==sub_sums[s][l]){
            //             //printf("sum= %d , tempsum= %d, i=%d,j=%d,k=%d,l=%d\n",sum,temp_sum,i,j,s,l);
            //             result=min(result,j+1+l+1);
            //             check1=true;
            //             break;
                        
            //         }
            //     }
            //     if(check1){
            //         break;
            //     }
            // }
        }
    }
    
    if(result==999999){
        result=-1;
    }
    cout<<result<<endl;
    // for(int i=0;i<sub_sums.size();i++){
    //     printvector(sub_sums[i]);
    // }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration=std::chrono::duration_cast<std::chrono::milliseconds>(after_reading - start);
    auto duration_end=std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    cout<<"after reading "<<duration.count() << endl;   
    cout<<"duration "<<duration_end.count() << endl;
    // printf("n= %d , k=%d \n",n,k);
    //printf("[FINAL] (p1=%d, %d) and (p2=%d,%d) \n",p1,arr[p1],p2,arr[p2]);
    //printvector(arr);
}