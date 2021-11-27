#include <iostream>
#include <vector>

#include <fstream>
#include <algorithm>
#include <bits/stdc++.h> 
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <chrono>
int m;
struct Edge {
    int src, dest;
    
};
struct subset {
    int parent;
    int rank;
    
};
struct Graph {
    // V-> Number of vertices, E-> Number of edges
    int V, E;
 
    // graph is represented as an array of edges
    struct Edge* edge;
};
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph
        = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
 
    graph->edge = (struct Edge*)malloc(
        graph->E * sizeof(struct Edge));
 
    return graph;
};

int min(int a, int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}
int find(struct subset subsets[], int i)
{
    // find root and make root as parent of i (path
    // compression)
    
    if (subsets[i].parent != i){
        //std::cout<<"recursize find! for"<<subsets[i].parent<<std::endl;
        subsets[i].parent= find(subsets, subsets[i].parent);
    }
    //std::cout<<"returned :)"<<std::endl;
   
    return subsets[i].parent;
}
// int find_and_fix_cost(struct subset subsets[], int i, int cost)
// {
//     // find root and make root as parent of i (path
//     // compression)
    
//     if (subsets[i].parent != i){
//         //std::cout<<"recursize find!"<<std::endl;
//         subsets[i].parent= find(subsets, subsets[i].parent);
//     }
//     //std::cout<<"returned :)"<<std::endl;
//     subsets[subsets[i].parent].min_cost=min(subsets[subsets[i].parent].min_cost,cost);
//     return subsets[i].parent;
// }


void Union(struct subset subsets[], int xroot, int yroot)
{
 
    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
 
    // If ranks are same, then make one as root and
    // increment its rank by one
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
using namespace std;
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
            swap1(&arr[i][1], &arr[j][1]);
            swap1(&arr[i][0], &arr[j][0]);
		}
	}
	swap1(&arr[i + 1][2], &arr[high][2]);
    swap1(&arr[i + 1][1], &arr[high][1]);
    swap1(&arr[i + 1][0], &arr[high][0]);
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
void printvector(vector<int> pair){
    for(int i=0;i<pair.size();i++){
                    cout<<pair[i]<<" ";
                }
    cout<<endl;
}
int main(/*int argc, char *argv[]*/){
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL); 
    int n;
    //auto start = std::chrono::high_resolution_clock::now();
    //fstream myfile(argv[1], ios_base::in);
    
    
    //myfile>>n>>m;
    cin>>n>>m;
    // scanf("%d",&n);
    // scanf("%d",&m);
    vector<int> initial_state;
    
    int temp1,temp2,temp3;
    

    for (int i=0;i<n;i++){
       cin>>temp1;
       // scanf("%d",&temp1);
        //myfile>>temp1;
        initial_state.push_back(temp1);
    }
    
    vector<vector<int> > portals(m+1,vector<int>());
    vector<int> uniq;
    if((n <=100000) && (m<=100000)){
        for (int i=1;i<=m;i++){  
            cin>>temp1>>temp2>>temp3;
            // scanf("%d",&temp2);
            // scanf("%d",&temp1);
            // scanf("%d",&temp3); 
            portals[m-i].push_back(temp1);  
            portals[m-i].push_back(temp2);  
            portals[m-i].push_back(temp3);  
            
        }  
        quickSort(portals,0,m-1);
        
    } 
    else{
        for (int i=1;i<=m;i++){  
        // scanf("%d",&temp1);
        // scanf("%d",&temp2);
        // scanf("%d",&temp3); 
        cin>>temp1>>temp2>>temp3;  
        //myfile>>temp1>>temp2>>temp3;  
        portals[m-i].push_back(temp1);  
        portals[m-i].push_back(temp2);  
        portals[m-i].push_back(temp3);  
        } 
        //cout<<"i got in"<<endl; 
    }
   
    int low=0, high=m,l;
    int result=999999999;
    
    bool check1=true;
    struct Graph* graph = createGraph(n+1, m+1);
    struct subset* subsets= (struct subset*)malloc(n * sizeof(struct subset)+1);
    std::vector<int> vec1;
    
    int lower_point_of_insert=0;
    while(low<=high){
        
        //cout<<"starting"<<endl;
        int m= (low + high)/2;
        //cout<<"went in for "<<m<<endl;
               
                
        if(lower_point_of_insert==0){ 
            for (int i=0;i<n;i++){
                subsets[initial_state[i]].parent=initial_state[i];
                subsets[initial_state[i]].rank=0;
                
            }
        }
        for (int i=lower_point_of_insert;i<m;i++){
                
            temp1=portals[i][0];
            temp2=portals[i][1];
            temp3=portals[i][2];
            graph->edge[i].src = temp1;
            graph->edge[i].dest=temp2;
            int x = find(subsets, graph->edge[i].src);
            int y = find(subsets, graph->edge[i].dest);
            Union(subsets, x, y);
            result=min(result,temp3);
        }

            for(int i=0;i<=n-2;i++){
                if(initial_state[i]!=i+1){
                    if(find(subsets,subsets[initial_state[i]].parent)!= find(subsets,subsets[i+1].parent) ){
                        lower_point_of_insert=m;
                        low=m+1;
                        check1=false;
                        break;
                    }
                }
                    
            }
            if(check1){
                high=m-1;
                if((low<=high )){
                    for (int i=0;i<n;i++){
                        subsets[initial_state[i]].parent=initial_state[i];
                        subsets[initial_state[i]].rank=0;
                        

                    }
                lower_point_of_insert=0;
                }
                    
            }
        check1=true;
        
        
            
       
    }
    
    // auto stop = std::chrono::high_resolution_clock::now();
    // auto duration=std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    // cout<<duration.count() << endl;
    cout<<portals[low-1][2]<<endl;
    //printf("%d \n",portals[low-1][2]);
    
}