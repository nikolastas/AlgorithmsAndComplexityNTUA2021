#include <iostream>
#include <vector>
#include <stdio.h> 
#include <fstream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <contr

using namespace std;

template<typename T, typename A> 
  std::size_t hash_value(std::vector<T, A> const& val);
struct KeyHasher
{
  std::size_t operator()(const Key& k) const
  {
    using std::size_t;
    using std::hash;
    using std::string;

    return ((hash<string>()(k.first)
             ^ (hash<string>()(k.second) << 1)) >> 1)
             ^ (hash<int>()(k.third) << 1);
  }
};

int max(int a, int b){
    if(a>b){
        return b;
    }
    else {
        return a;
    }
}
void printmap(unordered_map<int, vector<int> > states){
    for (auto const &pair: states) {
                std::cout << "{" << pair.first << ": ";
                for(int i=0;i<pair.second.size();i++){
                    cout<<pair.second[i]<<" ";
                }
            
            cout<<"}"<<endl;
            }
}
void printvector(vector<int> pair){
    for(int i=0;i<pair.size();i++){
                    cout<<pair[i]<<" ";
                }
    cout<<endl;
}
void swap(int a, int b, vector<int>& current){
    int temp=current[a-1];
    current[a-1]=current[b-1];
    current[b-1]=temp;

}
void goThroughPortal(vector<int> current_state,vector<int> portals,unordered_map<vector<int>,int>& states){
    //cout<<"portal started"<<endl;
    //printvector(current_state);
    int portal1,portal2,cost;
    portal1=portals[0];
    portal2=portals[1];
    
    cost=portals[2];
    swap(portal1,portal2,current_state);
    //printvector(current_state);
    states.insert(pair< vector<int>,int > ( current_state,cost));
    //cout<<"end portal"<<endl;
}

int main(int argc, char *argv[]){


    int n, m;
    
    
    fstream myfile(argv[1], ios_base::in);
    myfile>>n>>m;
    vector<vector<int> > portals(n+1,vector<int>(0));
    vector<int> initial_state;
    cout <<"N="<< n<<" M=" <<m<<endl;
    int temp1,temp2,temp3;
    
    for (int i=0;i<n;i++){
        myfile>>temp1;
        initial_state.push_back(temp1);
    }
    unordered_map<vector<int>,int,_Hash_impl=ha> states; 
    states.insert(pair< vector<int>,int > (initial_state,int));
    for (int i=0;i<m;i++){
        
        myfile>>temp1>>temp2>>temp3;
        
        portals[i].push_back(temp1);
        portals[i].push_back(temp2);
        portals[i].push_back(temp3);
        
        
        
    }
    printvector(portals[0]);
    printvector(portals[1]);
    //cout<<"initial state is ";
    //printvector(initial_state);
    //cout<<endl;
    vector<int> temp;
    for(int j=0;j<m;j++){
        
        for (auto i = states.begin(); i != states.end(); i++){
            
            goThroughPortal(i->first,portals[j],states);
            
        }
        
    }
    
    vector<int> final_state(n);
    generate( final_state.begin(), final_state.end(), [i=1]{
         static int i=1;
         return i++;
     });
     printvector(final_state);

    // if(states.find(0)!=states.end()){
    //     cout<<"nice"<<endl;
    // }
    cout<<"ended";
    
}