#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

void fastscan(int &number) //https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;
 
    number = 0;
 
    // extract current character from buffer
    c = getchar();
    if (c=='-')
    {
        // number is negative
        negative = true;
 
        // extract the next character from the buffer
        c = getchar();
    }
 
    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
 
    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}

int CeilIndex(std::vector<int>& v, int l, int r, int key)
{
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (v[m] >= key)
            r = m;
        else
            l = m;
    }
 
    return r;
}
int CeilIndex2(std::vector<int>& v, int l, int r, int key)
{
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (v[m] <= key)
            r = m;
        else
            l = m;
    }
 
    return r;
}
void printvector(vector<int> pair){  
    for(int i=0;i<pair.size();i++){  
                    cout<<pair[i]<<" ";  
                }  
    cout<<endl;  
    } 
int LongestIncreasingSubsequenceLength(std::vector<int>& v, size_t s, vector<int> & tail, std::vector<int>& lis)
{
    if (v.size() == 0)
        return 0;
    bool print =false;
    int pos=1;
    // std::vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail
 
    tail[0] = v[0];
    lis[0] = 1;
    if(s >= v.size()){
        s= v.size()-1;
    }
    int k;
    vector<int> index (v.size(), 0);
    for (size_t i = 1; i <= s; i++) {

        if(print){
            printf("new i=%ld num=%d \n", i, v[i]);
        }
        
        // new smallest value
        if (v[i] < tail[0]){
            tail[0] = v[i];
            index[0]=i;
            // k =   CeilIndex(tail, -1, length - 1, v[i]);
            lis[pos] = 1;
        }
            
        // v[i] extends largest subsequence
        else if (v[i] > tail[length - 1]){
            tail[length] = v[i];
            index[length] = i;
            lis[pos] = length+1;
            length++;
        }
            
        // v[i] will become end candidate of an existing
        // subsequence or Throw away larger elements in all
        // LIS, to make room for upcoming greater elements
        // than v[i] (and also, v[i] would have already
        // appeared in one of LIS, identify the location
        // and replace it)
        else{
            k = CeilIndex(tail, -1, length - 1, v[i]);
            tail[k] = v[i];
            index[k]=i;
            lis[pos] = lis[index[k-1]]+1;

        }
        if(print){
            printf("lis= \n");
            printvector(lis);
            printf("tail= \n");
            printvector(tail);
        }
        pos++;
    }
 
    return length;
}
 

int LongestDecreasingSubsequenceLengthFromLastToFirst(std::vector<int>& v, size_t s, std::vector<int>& tail, std::vector<int>& lds, vector<int>& index)
{
    bool print = false;
    if (v.size() == 0)
        return 0;
 
    // printf("HERE tail[0]=%d \n", tail[0]);
    int length = 1; // always points empty slot in tail
    // printf("[j=%ld] number= %d \n", v.size()-1, v[v.size()-1]);
    tail[0] = v[v.size()-1];
    lds[0] = 1;
    
    int k;
    if(s >= v.size()){
        s= v.size()-1;
    }
    if(print){
        cout<<endl;
    }
    
    size_t j;
    int pos=1;
    for (size_t i = 2; i <= s+1; i++) {
        j = v.size()-i;
        
        if(print){
            printf("[j=%ld] number= %d \n", j, v[j]);
        }
        // new smallest value
        if (v[j] > tail[0]){
            tail[0] = v[j];
            index[0]=j;
            lds[pos]=1;
        }
 
        // v[i] extends largest subsequence
        else if (v[j] < tail[length - 1])
        {
            tail[length] = v[j];
            lds[pos] = length+1;
            index[length]= j;
            length++;
        }
            
 
        // v[i] will become end candidate of an existing
        // subsequence or Throw away larger elements in all
        // LIS, to make room for upcoming greater elements
        // than v[i] (and also, v[i] would have already
        // appeared in one of LIS, identify the location
        // and replace it)
        else{
            k = CeilIndex2(tail, -1, length - 1, v[j]);
            tail[k] = v[j];
            index[k]=j;
            lds[pos] = lds[v.size()-1-index[k-1]]+1;
        }
        pos++;
        if(print){
            printf("tail= \n");
            printvector(tail);
            printf("lds= \n");
            printvector(lds);
        }
        
    }
 
    return length;
}

int binarySearchforResult(vector<int> LDS, int l, int r, int key){
while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (LDS[m] >= key)
            r = m;
        else
            l = m;
    }
 
    return r;
} 

int main(){
bool print = true;
int N, K;
fastscan(N);
fastscan(K);
vector<int> initial_state;
vector<int> initial_state_plusK;



int m;
    for(int i=0;i<N;i++){
        fastscan(m);
        initial_state.push_back(m);
        initial_state_plusK.push_back(m+K);        
    }
    int n1,n2;
    vector<int> lds (initial_state.size(),0);
    vector<int> lis (initial_state.size(),0);
    vector<int> ans1 (initial_state.size(), 0);
    vector<int> ans2 (initial_state.size(), 0);
    vector<int> index (initial_state.size(), 0);
    if(print){
    printf("lis = ");
    printvector(lis);
    printf("lds = ");
    printvector(lds);
    cout<<"the size is "<<lis.size()<<endl;
    }
    
    
    if(print){cout << "Length of Longest Decreasing Subsequence is "
              << LongestDecreasingSubsequenceLengthFromLastToFirst(initial_state_plusK,initial_state.size(),lds, ans2, index) << '\n';
    cout<< "done \n";
    if(print){
        printf("lds= \n");
        printvector(lds);
        printf("ans2= \n");
        printvector(ans2);
    }
     n1 = LongestIncreasingSubsequenceLength(initial_state, initial_state.size(), lis, ans1);
     n2 = LongestDecreasingSubsequenceLengthFromLastToFirst(initial_state_plusK,initial_state.size(),lds, ans2, index);
    cout<<"--------------------------------------------"<<endl;
    cout << "Length of Longest Increasing Subsequence is "
            << LongestIncreasingSubsequenceLength(initial_state, initial_state.size(), lis, ans1) << '\n';
    cout<< "done \n";}
    else{
     n1 = LongestIncreasingSubsequenceLength(initial_state, initial_state.size(), lis, ans1);
     n2 = LongestDecreasingSubsequenceLengthFromLastToFirst(initial_state_plusK,initial_state.size(),lds, ans2, index);
    
    }
    if(print)
    {
        printvector(lis);
        printvector(ans1);
    }   
    int result=0; 
    int l=0;
    int h=0;
    for(size_t i=0; i<initial_state.size();i++){
    
        l=CeilIndex2(lds, -1, n2-1, initial_state[i]);
        h=CeilIndex(lis, -1, n1-1, initial_state[i]);
        
        if(index[l] > i){
            if(print){
                printf("[i=%ld]{init=%d} lis= %d l=%d LDS=%d result=%d \n", i,initial_state[i] ,ans1[i], l , lds[l], result );
            }
            result=max(result, ans1[i]+l);
        }
        else{
            l=0;
        }
        
    }
    cout<<result<<endl;

    

}