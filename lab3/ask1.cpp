#include <stdio.h>
#include <vector>
#include <set>

#define dk_max 10001
#define sj_max 1000000001

using namespace std;



void Dijkstra(vector<unsigned long> &dist, int &dk,  vector<unsigned long> &query, set<pair<unsigned long,int>> &waiting_room) {
    while(!waiting_room.empty()) {

        pair<unsigned long,int> head = *waiting_room.begin();
        unsigned long cur = head.second;
        int d_sum = head.first;
        waiting_room.erase(head);

        for(auto di : dist) {
            int new_node = (cur+di) % dk;
            int new_dist = d_sum + di;

            if(new_dist < query[new_node] || query[new_node] == -1) {
                waiting_room.erase( make_pair( query[new_node], new_node ) );
                query[new_node] = new_dist;
                waiting_room.insert( make_pair( query[new_node], new_node ) );
            }
        }
    }
}

int main() {
    int N, dk = dk_max;
    unsigned long Q;
    vector<unsigned long> dist, query(dk_max, -1);
    set<pair<unsigned long,int>> waiting_room;
    scanf("%d %lu", &N, &Q);
    for(int i = 1; i <= N; i++) {
        unsigned long di;
        scanf("%lu", &di);
        dist.push_back(di);
        if(di < dk)
            dk = di;
    }

    query[0] = 0;
    waiting_room.insert( make_pair(query[0],0) );
    Dijkstra(dist, dk, query, waiting_room);
    
    for(int i = 0; i < Q; i++) {
        unsigned long q;
        scanf("%lu", &q);
        (query[q % dk] > q) ? printf("NO\n") : printf("YES\n");
    }
}