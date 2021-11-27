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
int main(/*int argc, char *argv[]*/){  
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  
    auto start = std::chrono::high_resolution_clock::now();  
    int n, k;  
    int sum=0;  
    int p=0;  
    int temp_k;  
    int temp_sum=0;  
    int result=999999;  
    tuple<int,int> mytuple;  
    int temp_result=0;  
  
      
      
    //scanf("%d %d",&n,&k);  
    //fstream myfile(argv[1], ios_base::in);  
      
    //myfile>>n>>k;  
    cin>>n>>k;  
    vector<int> arr(n+1);  
      
    for(int i=0;i<n;i++){  
        //scanf("%d",&arr[i]);  
        //myfile>>arr[i];  
        cin>>arr[i];  
    }  
    int index_of_mymap=0;
    auto after_reading = std::chrono::high_resolution_clock::now();  
    vector<vector<int>> sub_sums(n+1,vector<int>());  
    map<pair<int,int>,vector<int>> mymap;
    for(int i=0;i<n;i++){  
        sum=0;  
        //temp_result=999999;  
        for(int j=i;j<n;j++){  
            if(sum+arr[j]<=k){  
            sum+=arr[j];  
            sub_sums[i].push_back(sum);  
            if(i!=0){
                index_of_mymap++;
                int t=0;
                while(t<=index_of_mymap){
                    t++;
                mymap[make_pair(t,sum)]={i,j};
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
         
    }  
      
    bool check1=false;  
  
    for(int i=0;i<sub_sums.size();i++){  
          
        for(int j=0;j<sub_sums[i].size();j++){  
              
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