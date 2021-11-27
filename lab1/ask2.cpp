#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <unordered_map>
#include <tuple>
using namespace std;

void printvector(vector<int> pair){
    for(int i=0;i<pair.size();i++){
                    printf("%d ",pair[i]);
                }
    cout<<endl;
}

namespace N {
 
typedef std::tuple<int,int> key_t;
 
struct key_hash : public std::unary_function<key_t, std::size_t>
{
   std::size_t operator()(const key_t& k) const
   {
      return std::get<0>(k) ^ std::get<1>(k);
   }
};
 
struct key_equal : public std::binary_function<key_t, key_t, bool>
{
   bool operator()(const key_t& v0, const key_t& v1) const
   {
      return (
               std::get<0>(v0) == std::get<0>(v1) &&
               std::get<1>(v0) == std::get<1>(v1) 
             );
   }
};
 

 
typedef std::unordered_map<const key_t,int,key_hash,key_equal> map_t;
 
}


template<class TupType, size_t... I>
void print(const TupType& _tup, std::index_sequence<I...>)
{
    
    (..., (std::cout << (I == 0? "" : ", ") << std::get<I>(_tup)));
    
}

template<class... T>
void print (const std::tuple<T...>& _tup)
{
    print(_tup, std::make_index_sequence<sizeof...(T)>());
}

int main(int argc, char *argv[]){
    auto start = std::chrono::high_resolution_clock::now();
    int n, k;
    int sum=0;
    int p=0;
    int temp;
    tuple<int,int> mytuple;
    

    
    N::map_t mymap;
    //scanf("%d %d",&n,&k);
    fstream myfile(argv[1], ios_base::in);
    
    myfile>>n>>k;
    vector<int> arr(n+1);
    
    for(int i=0;i<n;i++){
        //scanf("%d",&arr[i]);
        myfile>>arr[i];
    }
    
    auto after_reading = std::chrono::high_resolution_clock::now();
    
    for(int i=0;i<n;i++){
        sum=0;
        for(int j=i;j<n;j++){
            if(sum+arr[j]<=k){
            sum+=arr[j];
            //mymap[std::make_tuple(i,j)]=sum;

            }
            else if(sum>k) {
                
                break;
                
            }
        }
       
    }
    printf("mymap has size %d\n",mymap.size());
    // for(auto itr = mymap.begin(); itr != mymap.end(); ++itr){
    //     cout<<"[";
    //     print(itr->first);
    //     printf("] = %d\n",itr->second);
    // }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration=std::chrono::duration_cast<std::chrono::milliseconds>(after_reading - start);
    auto duration_end=std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    cout<<"after reading "<<duration.count() << endl;   
    cout<<"duration "<<duration_end.count() << endl;
    printf("n= %d , k=%d \n",n,k);
    //printf("[FINAL] (p1=%d, %d) and (p2=%d,%d) \n",p1,arr[p1],p2,arr[p2]);
    //printvector(arr);
}