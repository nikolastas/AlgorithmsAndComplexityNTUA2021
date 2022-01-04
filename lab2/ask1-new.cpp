#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;



int CeilIndex(std::vector<int>& v, int l, int r, int key)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (v[m] >= key)
            r = m -1 ;
        else
            l = m +1;
    }
 
    return l;
}
int CeilIndex2(std::vector<int>& v, int l, int r, int key)
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
void printvector(vector<int> pair){  
    for(int i=0;i<pair.size();i++){  
                    cout<<pair[i]<<" ";  
                }  
    cout<<endl;  
    } 
void LongestIncreasingMinusK(std::vector<int>& v, int i, vector<int> & tail , int element, int& length, int place){
    tail[ CeilIndex2(tail, -1, length - 1, element)] =element;
    
    printf("[minusk] for i=%d a[i]=%d length=%d place=%d\n", i, element, length, place);
    printvector(tail);
}
void LongestIncreasingMinusK2(std::vector<int>& v, int i, vector<int> & tail , int element, int& length, int place){
    if(length>1){
        if (tail[length-1] < element){
            tail[length]=element;
            length++;
        }
        else if (tail[length-1] > element && tail[length-2] < element) {
            tail[length-1]=element;
        }
    }
    else if (length == 1){
        if (tail[length-1] < element){
            tail[length]=element;
            length++;
        }
    }
    else if(length==0){
        tail[0]=element;
        length++;
    }
    
    
    printf("[minusk2] for i=%d a[i]=%d length=%d place=%d\n", i, element, length, place);
    printvector(tail);
}
void LongestIncreasingSubsequenceLength(std::vector<int>& v, int i, vector<int> & tail , int element, int& length, int& place)
{
    if (v.size() == 0)
        return ;
    bool print =false;
    int k;
    // vector<int> index (v.size(), 0);
    

        if(print){
            printf("new i=%d num=%d \n", i, v[i]);
        }
        
        // new smallest value
        if (element < tail[0]){
            tail[0] = element;
            place=0;
        }
            
        // v[i] extends largest subsequenc
        else if (element > tail[length - 1]){
            tail[length] = element;
            place=length;
            length++;
        }
            
        // v[i] will become end candidate of an existing
        // subsequence or Throw away larger elements in all
        // LIS, to make room for upcoming greater elements
        // than v[i] (and also, v[i] would have already
        // appeared in one of LIS, identify the location
        // and replace it)
        else{
            k = CeilIndex2(tail, -1, length - 1, element);
            place=k;
            tail[k] = element;
            
            
        }
        
    printf("for i=%d a[i]=%d length=%d\n", i, element, length);
    printvector(tail);
    
    
    // return length;
}
 


int start(vector<int>& V, vector<int>& K){
    int n1=1, n2=0;
    
    // vector<int> tail{ 1, 3, 6, 7, 8, 0, 0, 0, 0, 0};
    // vector<int> tail2{-14, -12, -9, -8, -7, 8, 0, 0, 0, 0 };
    // n1 = 5;
    // n2=6;
    vector<int> tail(V.size(), 0);  
    vector<int> tail2(K.size(), 0);
    tail[0]=V[0];
    tail2[0]=V[0];
    int place=0;
    for(int i=0; i<V.size(); i++){
        if(i!=0){
            // printf("tail= \n");
            LongestIncreasingSubsequenceLength(V, i, tail, V[i], n1, place);
            
        }
        // printf("tail2= \n");
        LongestIncreasingMinusK2(K, i, tail2, V[i], n2, place);
        LongestIncreasingMinusK(K, i, tail2, K[i], n2, place);
    }
    // printf("tail= \n");
    // printvector(tail);
    // printf("tail2= \n");
    // printvector(tail2);
    return max(n1,n2);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    bool print = true;
    int N, K;
    cin >> N >> K;
    vector<int> initial_state ;
    vector<int> initial_state_minusK ;



    int m;
    for(int i=0;i<N;i++){
        cin >> m;
        initial_state.push_back(m);
        initial_state_minusK.push_back(m-K);        
    }
    // printvector(initial_state);
    // printf("here\n");
    cout<< start(initial_state, initial_state_minusK)<<endl;


}