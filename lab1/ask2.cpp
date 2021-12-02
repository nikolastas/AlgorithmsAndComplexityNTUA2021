#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;





long int *val ;

int main(int argc, char *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long int k;
    long int sum=0;
    int result=999999999;
    //scanf("%d %d",&n,&k);
    fstream myfile(argv[1], ios_base::in);
    myfile>>n>>k;
    // cin>>n>>k;
    vector< long int> arr(n+1);
    
    for(int i=0;i<n;i++){
        //scanf("%d",&arr[i]);
        myfile>>arr[i];
        // cin>>arr[i];
        
    }
    
    vector<vector<long int>> sub_sums(2*n+1,vector<long int>());
    
    size_t size=sizeof(long long int)*(k+1);
    val = (long int *) malloc(size);
    for(int i=0;i<=k;i++){
        val[i]=1000000;
    }
    
    vector<long int> res;
    bool check_for_1_element=false;
    for(int i=0;i<n; i++){
        sum=0;
        //temp_result=999999;
        // int start=0;
        for(int j=i-1;j>=0;j--){
            
            if(sum+arr[j]<=k){
                sum+=arr[j];
                long int v = val[sum];
                long int len=i-j;
                // printf("[%d, %d]aristera sum=%ld with length=%ld",i,j,sum,len);
                if((v>(i-j) )){
                    val[sum]=i-j;
                    // printf(" sum got in with length=%d\n",val[sum]);
              
                }
                
            }
            else{
                break;
            }
        }
        sum=0;
        for(int j=i;j<n;j++){
            
            if(sum+arr[j]<=k){
                sum+=arr[j];
                // printf("[%d,%d] deksia sum=%ld \n",i,j,sum);
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
                    //  printf("searching for %ld and found %ld %d\n",k-sum,val[k-sum], thesi[k-sum]);
                    
                    long int tmp=(val[k-sum]+j-i+1);
                    if((result>tmp ) ){
                        result=tmp;
                        // printf("i DID change %d\n",result);

                    }
                    
                    
                }
                // printf("k-sum not found! [%ld] thesi=%d\n",val[k-sum],thesi[k-sum]);
                

            }
            else  {
            
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
}