#include <iostream>
#include <vector>
#include <stdio.h> 
#include <fstream>
#include <algorithm>
#include <map>
#include <unordered_map>




namespace std {
struct Key {
    vector<int> first;
    
};
struct KeyEqual {
 bool operator()(const Key& lhs, const Key& rhs) const
 {
    return lhs.first == rhs.first ;
 }
};
struct KeyHash{
        std::size_t operator()(const Key& k) const {
        std::size_t seed = k.first.size();
        for(auto& i : k.first) {
            seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        
        return (seed);

    }
};
}
using namespace std;

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

void printmap2(unordered_map<Key,int,KeyHash,KeyEqual > states){
    for (auto s = states.begin(); s != states.end(); s++) {
                printvector(s->first.first);
                
            
            cout<<endl;
            }
}




void swap(int a, int b, vector<int>& current){
    int temp=current[a-1];
    current[a-1]=current[b-1];
    current[b-1]=temp;

}
void goThroughPortal(vector<int> current_state,vector<int> portals,unordered_map<Key,int,KeyHash,KeyEqual>& states){
    //cout<<"portal started"<<endl;
    //printvector(current_state);
    int portal1,portal2,cost;
    portal1=portals[0];
    portal2=portals[1];
    
    cost=portals[2];
    swap(portal1,portal2,current_state);
    //printvector(current_state);
    Key k;
    k.first=current_state;

    states.emplace(k,cost);
    //cout<<"end portal"<<endl;
}

int main(int argc, char *argv[]){


    int n, m;
    bool print=false;
    if(argc>=3){
        print=true;
    }
    
    fstream myfile(argv[1], ios_base::in);
    myfile>>n>>m;
    vector<vector<int> > portals(m+1,vector<int>());
    vector<int> initial_state;
    if(print)
        cout <<"N="<< n<<" M=" <<m<<endl;
    int temp1,temp2,temp3;
    

    for (int i=0;i<n;i++){
        myfile>>temp1;
        initial_state.push_back(temp1);
    }
    if(print)
        {cout<<"initial state is ";
        printvector(initial_state);
        cout<<endl;}
    Key newk;
    newk.first=initial_state;
    unordered_map<Key,int,KeyHash,KeyEqual> states; 
    states.emplace(newk,0);
    int k=0;
    for (int i=0;i<m;i++){
        
        myfile>>temp1>>temp2>>temp3;
        k++;
        portals[i].push_back(temp1);
        portals[i].push_back(temp2);
        portals[i].push_back(temp3);
        
    
        
        
    }
    if(print)
        cout<<"ended inserting the portlas data"<<endl;
    
    vector<int> temp;
    for(int j=0;j<m;j++){
        
        for (auto i = states.begin(); i != states.end(); i++){
            
            goThroughPortal(i->first.first,portals[j],states);
            printmap2(states);
        }
        
    }
    if(print)
        cout<<"ended goThroughPartals"<<endl;
    vector<int> final_state(n);
    generate( final_state.begin(), final_state.end(), [i=1]{
         static int i=1;
         return i++;
     });
     printvector(final_state);

    //if(states.find(final_state)!=states.end()){
    //     cout<<states[final_state];
    // }
    
    
}