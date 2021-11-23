#include <iostream>
#include <vector>
#include <stdio.h> 
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

int max(int a, int b){
    if(a>b){
        return b;
    }
    else {
        return a;
    }
}

int main(int argc, char *argv[]){


    int n, m;
    
    cout<<n<<m<<endl;
    fstream myfile(argv[1], ios_base::in);
    myfile>>n>>m;
    vector<vector<int>,int > portals(n+1,(vector<vector<int>>(n+2),0));
    cout << n <<m;
    for (int i=0;i<m;i++){
        myfile>>temp>>portals[i][1];
        myfile>>portals[i+1];
        cout<<portals[i][1];
    }
}