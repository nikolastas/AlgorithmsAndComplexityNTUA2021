#include <iostream>
#include <vector>
#include <stdio.h> 
#include <fstream>
#include <algorithm>
#include <map>
#include <unordered_map>






//------------------------------------------------------------------------------------------------------------------
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
//-----------------------------------------------------------------------------------
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

void makefinal(vectr<int> initial, vector<int> final, vector<int>& differences){
    int n=initial.size();
    for(  int i=0; i<n;i++){
        if(initial[i]!=final[i]){
            differences.push_back(initia[i]);

        }
    }
}
//--------------------------------------------------------------------------------------------
void swap1(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition (vector<vector<int>> &arr, int low, int high)
{   
    
	int pivot = arr[high][2]; // pivot
	int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
    
	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot
		if (arr[j][2] > pivot)
		{
			i++; // increment index of smaller element
			swap1(&arr[i][2], &arr[j][2]);
		}
	}
	swap1(&arr[i + 1][2], &arr[high][2]);
	return (i + 1);
}


/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(vector<vector<int>>& arr, int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
        
		int pi = partition(arr, low, high);
        
		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
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

    vector<int> final_state(n);
    generate( final_state.begin(), final_state.end(), [i=1]{
         static int i=1;
         return i++;
     });
    vector<int> diff;
    makefinal(initial_state,final_state,diff);
    printvector(diff);



    // Key newk;

    // newk.first=initial_state;
    
    // unordered_map<Key,int,KeyHash,KeyEqual> states; 
    // states.emplace(newk,0);
    
    // for (int i=0;i<m;i++){
        
    //     myfile>>temp1>>temp2>>temp3;
        
    //     portals[i].push_back(temp1);
    //     portals[i].push_back(temp2);
    //     portals[i].push_back(temp3);
        
    
        
        
    // }
    // if(print)
    //     cout<<"ended inserting the portlas data"<<endl;
    
    
    
    // if(print)
    //     cout<<"start quicksort"<<endl;
    // quickSort(portals,0,m-1);
    

    // if(print)
    //     cout<<"ended sorting portals"<<endl;
    // vector<int> temp;

    
    // Key finalk;
    // finalk.first=final_state;
    // if(print)
    //     printvector(final_state);
    // for(int j=m-1;j<=0;j--){
    //     cout<<"j="<<j<<endl;
    //     for (auto i = states.begin(); i != states.end(); i++){
            
    //         goThroughPortal(i->first.first,portals[j],states);
    //         cout<<"for step in portal: "<<portals[j][0]<<portals[j][1]<<portals[j][2];
    //         cout<<"there are that states";
    //         printmap2(states);
    //         cout<<endl;
    //         cout<<"next step"<<endl;           
    //         if(states.find(finalk)!=states.end()){
    //             cout<<"found it at step"<<portals[j][0]<<portals[j][1]<<portals[j][2];
                
    //             break;
    //         }
    //     }
        
    // }
    // if(print)
    //     cout<<"ended goThroughPartals"<<endl;
    
    

    
    
    
}