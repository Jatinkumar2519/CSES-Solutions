#include <bits/stdc++.h>
using namespace std;
vector<int> dirx = {-1,1,0,0};
vector<int> diry = {0,0,-1,1};
vector<char> dir = {'U','D','L','R'};
class Node{
    public:
    int i,j;
    int dist;
    Node(){}
    Node(int i,int j,int dist){
        this->i = i;
        this->j = j;
        this->dist = dist;
    }
};
struct Compare {
    bool operator()(const Node& a, const Node& b) const {
        return a.dist > b.dist; 
    }
};
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    int si = 0,sj = 0;
    cin >> n >> m;
    vector<vector<char>> grid(n,vector<char>(m));
    vector<vector<int>> distance(n,vector<int>(m,INT_MAX));
    vector<vector<char>> path(n,vector<char>(m));
    vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m,{-1,-1}));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A'){
                si = i;
                sj = j;
            }
        }
    }
    priority_queue<Node,vector<Node>,Compare> pq;
    pq.push(Node(si,sj,0));
    distance[si][sj] = 0;
    while(!pq.empty()){
        auto temp = pq.top();pq.pop();
        int x = temp.i;
        int y = temp.j;
        int dist = temp.dist;
        if(distance[x][y] < dist){
            continue;
        }
        for(int d = 0;d < 4;d++){
            int nx = x + dirx[d];
            int ny = y + diry[d];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] != '#'){
                if(distance[nx][ny] > dist + 1){
                    distance[nx][ny] = dist + 1;
                    path[nx][ny] = dir[d];
                    parent[nx][ny] = {x,y};
                    pq.push(Node(nx,ny,dist + 1));
                }
            }
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(grid[i][j] == 'B' && distance[i][j] != INT_MAX){
                cout<< "YES" << endl;
                cout<< distance[i][j] << endl;
                string str;
                int x = i,y = j;
                while(make_pair(x,y) != make_pair(si,sj)){
                    str.push_back(path[x][y]);
                    tie(x,y) = parent[x][y];
                }
                reverse(str.begin(),str.end());
                cout<< str;
                return 0;
            }
        }
    }
    cout<< "NO";
    return 0;
}