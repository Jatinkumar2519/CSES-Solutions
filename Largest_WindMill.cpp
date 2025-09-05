#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> degree(n + 1,0);
    vector<vector<int>> graph(n + 1);
    for(int i = 0;i < n - 1;i++){
        int a,b;
        cin >> a >> b;
        degree[a]++;degree[b]++;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int root = 1;
	int maxdeg = 0;
	for(int i = 1;i <= n;i++){
		if(degree[i] > maxdeg){
			root = i;
			maxdeg = degree[i];
		}
	}
	queue<pair<int,int>> q;
	q.push({root,-1});
	int height = 0;
	while(!q.empty()){
		height++;
		int len = q.size();
		for(int _ = 0;_ < len;_++){
			auto temp = q.front();q.pop();
			int node = temp.first;
			int par = temp.second;
			for(auto& nn : graph[node]){
				if(par == nn) continue;
				q.push({nn,node});
			}
		}
	}
	int size = maxdeg + height - 1;
	if(height >= 3){
    	cout<< size << ' ' << root;
	}
	else{
		cout<< -1 << endl;
	}
    return 0;
}