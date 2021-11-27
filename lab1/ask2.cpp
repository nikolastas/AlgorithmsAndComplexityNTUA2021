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
    /* υπαρχουν οι εξεις περιπτωσεις : 
    1) αναζητησε αν υπάρχει αθροισμα αριθμών Κ
        α. αν υπάρχει δες αν έχει άλλο
    2) αν δεν υπάρχει πάρε το μέγιστο δυνατό Κ
    



    */
    int n, k;
    scanf("%d %d",&n,&k);
    vector<int> arr(n,int());
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("n= %d , k=%d \n",n,k);
    printvector(arr);
    int sum=0;
    int p1=0,p2=n-1;
    int result=-1;
    printf("p1=%d , p2=%d \n",p1,p2);
    for (int i=0;i<n;i++){
        
        printf("[i=%d] p1=%d, p2=%d sum=%d \n",i,p1,p2,sum);
        
        if(sum+arr[i]<=k){
        printf("smaller sum \n");
        sum+=arr[i];
        p2=i;
        }
        else{
            printf("checking if i could create a new sum \n");
            if(arr[i]+sum-arr[p1]<=k){
                printf("i am in\n");
                p1++;
                sum-=arr[p1-1];
                sum+=arr[i];
                p2=i;
            }
        }
        
        
        
    }
    printf("[FINAL] (p1=%d, arr[]=%d) and (p2=%d,arr[]=%d) sum=%d \n",p1,arr[p1],p2,arr[p2],sum);
    if(p1!=p2){
        result=p2-p1+1;
    }
    printf("the final:%d \n",result);
}