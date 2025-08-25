#include<iostream>
#include<vector>
#include<queue>

using namespace std;
class Solution{
public:
    bool bellman_ford(int n,vector<vector<int>> &edges){
        vector<int> dist(n,INT_MAX);
    
        dist[0]=0;
        for(int i=0;i<n;i++){
            for(auto e:edges){
                int u=e[0];
                int v=e[1];
                int w=e[2];
                if(dist[u] != INT_MAX && dist[u]+w < dist[v]){
                    dist[v]=dist[u]+w;
                }
                if(dist[v] != INT_MAX && dist[v] + w < dist[u]){
                    dist[u]=dist[v]+w;
                }
            }
        }
        for(auto e:edges){
            int u=e[0];
                int v=e[1];
                int w=e[2];
                if(dist[u] != INT_MAX && dist[u]+w < dist[v]){
                    return true;
                }
                if(dist[v] != INT_MAX && dist[v] + w < dist[u]){
                    return true;
                }
        }
        return false;
    }
};


int main(){
    int n = 4;  


vector<vector<int>> edges = {
    {0, 1, 1},
    {1, 2, -1},
    {2, 3, -1},
    {3, 0, -1}   
};

    Solution *s=new Solution();
    bool flag=s->bellman_ford(n,edges);
    if(flag){
        cout<<"cycle present"<<endl;
    }
    else{
        cout<<"no cycle u are free bitch"<<endl;
    }
}