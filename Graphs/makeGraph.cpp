#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef unordered_set<int> usi;
typedef pair<int, vvi> pivvi;
typedef unordered_map< int, int> umii;
typedef unordered_map<const int, int> umcii;
typedef unordered_map<int, umii> umiumii;
typedef unordered_map<int, usi> umiusi;
typedef unordered_map<int, umii> umiumii;

#define forn(i, n) for (int i = 0; i < n; i++)

vector<int> input_vi()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    return v;
}

void print_vi(vector<int> v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << "\t";
    }
    cout << "\n";
    v[0] = 10;
}

vvb make_adj_matrix(pivvi &graph)
{
int node=graph.first;
vvi edges=graph.second;

vvb adj_matrix(node, vector<bool>(node, false));

for(int i=0;i<edges.size();i++){
adj_matrix[edges[i][0]-1][edges[i][1]-1]=true;
adj_matrix[edges[i][1]-1][edges[i][0]-1]=true;
}
return adj_matrix;
}
vvb make_adj_matrix_directed(pivvi &graph)
{
int node=graph.first;
vvi edges=graph.second;

vvb adj_matrix(node, vector<bool>(node, false));

for(int i=0;i<edges.size();i++){
adj_matrix[edges[i][0]-1][edges[i][1]-1]=true;

}
return adj_matrix;
}
void print_adj_matrix(vector<vector<bool>> &adj_matrix) {
    for (const auto &row : adj_matrix) {
        for (bool val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

void print_adj_list(const umiusi &adj_list) {
    for (const auto &pair : adj_list) {
        int node = pair.first;
        const usi &neighbors = pair.second;
        cout << node << ": ";
        for (int neighbor : neighbors) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

umiusi make_adj_list(pivvi &graph)
{
int node=graph.first;
vvi edges=graph.second;
umiusi adj_list; 
for(int i=0;i<edges.size();i++){
    adj_list[edges[i][0]].insert(edges[i][1]);
    adj_list[edges[i][1]].insert(edges[i][0]);
}
return adj_list;

}
umiusi make_adj_list_directed(pivvi &graph)
{
int node=graph.first;
vvi edges=graph.second;
umiusi adj_list; 
for(int i=0;i<edges.size();i++){
    adj_list[edges[i][0]].insert(edges[i][1]);
    
}
return adj_list;

}
void initial_list(umiumii &adj_list,int node){
    for(int i=0;i<node;i++){
        adj_list[i]=umii();
    }

}
umiumii make_adj_list_weighted(pivvi &graph)
{
int node=graph.first;
vvi edges=graph.second;
umiumii adj_list; 
initial_list(adj_list,node);
for(int i=0;i<edges.size();i++){
    adj_list[edges[i][0]][edges[i][1]]=edges[i][2];
    adj_list[edges[i][1]][edges[i][0]]=edges[i][2];
    
}
return adj_list;

}


void convert_to_adj_list(vvb &adj_matrix)
{
    int n = adj_matrix.size();
    umiusi adj_list;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj_matrix[i][j]) {
                adj_list[i].insert(j);
            }
        }
    }
}
void DFS(vector<bool> &visited,umiusi &adj_list,int node){
    if(visited[node])return;
    visited[node]=true;
    cout<<node<<" ";
    usi neighbors=adj_list[node];
    for(int neighbor:neighbors){
        if(!visited[neighbor]){
        DFS(visited,adj_list,neighbor);}
    }
    for(int i=0;i<visited.size();i++){
        if(!visited[i])DFS(visited,adj_list,i);
    }

}
void BFS_helper(vector<bool> &visited,umiusi &adj_list,int node,queue<int> &q){
    visited[node]=true;
    
    q.push(node);
    while(!q.empty()){
        cout<<q.front()<<" ";
        usi neighbors=adj_list[q.front()];
        for(int neighbor:neighbors){
        if(!visited[neighbor]){
            visited[neighbor]=true;
            q.push(neighbor);
        }

    }
    q.pop();
    }

}
void Print_distance(umii &distance){
    for(const auto p:distance){
        cout<<p.first<<" : "<<p.second<<endl;

    }

}
void initialize_distance(umii &distance,int nodes){
    
    
    for(int i=0;i<nodes;i++){
        distance[i]=INT_MAX;
    }
}
void dijkstras_help(umiumii adj_list,int node,umii &distance,vb &visited){
visited[node]=true;
for(const auto  nebs:adj_list[node]){
        
            int neighbor=nebs.first;
            int weight=nebs.second;
            
                if(distance[neighbor]>distance[node]+weight && !visited[neighbor]){
                    distance[neighbor]=distance[node]+weight;
                }
                
            
            
        
}
int node_min=node,dis_min=INT_MAX;
for(pair<int,int> dis:distance){
    if(dis.second<dis_min && !visited[dis.first]){
        node_min=dis.first;
        dis_min=dis.second;
    }

}
if(!visited[node_min]){
dijkstras_help(adj_list,node_min,distance,visited);
}


}
void dijkstras(umiumii adj_list,int node){
    umii distance;
    vector<bool> visited(adj_list.size(),false);
    initialize_distance(distance,adj_list.size());
    distance[node]=0;
    dijkstras_help(adj_list,node,distance,visited);
    Print_distance(distance);

    

}

void BFS(umiusi &adj_list,int node){
    int n=adj_list.size();
    vector<bool> visited(n,false);
    queue<int> q;
    BFS_helper(visited,adj_list,node,q);
    
    
    for(int i=0;i<visited.size();i++){
        if(!visited[i]){
            BFS_helper(visited,adj_list,i,q);
        }
    }

}

void convert_to_adj_matrix(umiusi &adj_list,int node)
{   vvb adj_matrix(node,vector<bool>(node, false));
    for (const auto &pair : adj_list) {
        int node = pair.first;
        const usi &neighbors = pair.second;
        int start=node;

        for (int neighbor : neighbors) {
            adj_matrix[start][neighbor]=true;
            adj_matrix[neighbor][start]=true;
        }
        cout << endl;
    }
    //
}


void enter_edges_directed(vvi &edges){
for(int i=0;i<edges.size();i++){
    int u,v,w;
    cin>>u;
    cin>>v;
    cin>>w;
    edges[i]={u,v,w};

}
}
pivvi dummy_graph()
{
    int v;
    int edge;
    cin>>v;
    cin>>edge;
    // vvi edges({{1, 2}, {1, 3}, {1, 4}, {2, 5},{2,6},{6,3},{4,5}});
    // vvi edges_directed({{1, 2,3}, {1, 3,2}, {1, 4,4}, {2, 5,1}});
    vvi edges(edge,vector<int>(3));
    enter_edges_directed(edges);
    
    return {v, edges};
}

void solve()
{
    pivvi graph1 = dummy_graph();
    // vvb adj_ma=make_adj_matrix(graph1);
    // print_adj_matrix(adj_ma);
    umiumii adj_lis=make_adj_list_weighted(graph1);
    // print_adj_list(adj_lis);
    // vector<bool> visited(graph1.first,false);
    // cout<<"Enter Starting Node ";
    // int node;
    // cin>>node;
    int start;
    cin>>start;
    dijkstras(adj_lis,start);
}

int main()
{
    solve();
}