#include <iostream>
#include <vector>

using namespace std;

void printvector(vector<int> pair){
    for(int i=0;i<pair.size();i++){
                    printf("%d ",pair[i]);
                }
    cout<<endl;
}

int main(){

    int n, k;
    scanf("%d %d",&n,&k);
    vector<int> arr(n,int());
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int sum=0;
    int p1=0,p2;
    while(sum!=k)    {
        printf("p1=%d , p2=%d \n",p1,p2);
        for (int i=p1;i<n;i++){
            printf("[i=%d] p1=%d, p2=%d sum=%d \n",i,p1,p2,sum);
            sum+=arr[i];
            if(sum>k){
                printf("got in a\n");
                sum-=arr[i];
                p2=i;
                sum-=arr[p1];
                p1+=1;
                break;
                
            }
            else if (sum==k){
                
                break;
            }
            
        }
    }
    std::min(1,2);
    printf("n= %d , k=%d \n",n,k);
    printf("[FINAL] (p1=%d, %d) and (p2=%d,%d) \n",p1,arr[p1],p2,arr[p2]);
    printvector(arr);
}