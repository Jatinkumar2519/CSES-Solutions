#include <bits/stdc++.h>
using namespace std;
struct Node{
    int sum;
    int presum;
    int sufsum;
    int maxsum;
    Node(int num1,int num2,int num3,int num4){
        sum = num1;
        presum = num2;
        sufsum = num3;
        maxsum = num4;
    }
};
struct SegmentTree{
    int n;
    vector<Node> Tree;
    SegmentTree(vector<int>& arr,int n){
        this->n = n;
        Tree.resize(4 * n);
        BuildTree(arr,0,0,n - 1);
    }
    void BuildTree(vector<int>& arr,int node,int l,int r){
        if(l == r){
            Tree[node] = Node(arr[l],arr[l],arr[l],arr[l]);
            return;
        }
        int mid = (l + r) >> 1;
        BuildTree(arr,(node << 1) + 1,l,mid);
        BuildTree(arr,(node << 1) + 2,mid + 1,r);
        int total = Tree[(node << 1) + 1].sum + Tree[(node << 1) + 2].sum;
        int prefix = max(Tree[(node << 1) + 1].presum , Tree[(node << 1) + 1].sum + Tree[(node << 1) + 2].presum);
        int sufix = max(Tree[(node << 1) + 2].sum , Tree[(node << 1) + 1].sufsum + Tree[(node << 1) + 2].sum);
        int maxsum = max({Tree[(node << 1) + 1].sum,Tree[(node << 1) + 2].sum,Tree[(node << 1) + 1].sufsum + Tree[(node << 1) + 2].presum});
        Tree[node] = Node(total,prefix,sufix,maxsum);
    }
    int query(int node,int l,int r,int L,int R){
        if(R < l || r < L) return INT_MIN;
        if(l <= L && R <= r) return Tree[node].maxsum;
        int mid = (L + R) >> 1;
        return max(Tree[(node << 1) + 1].maxsum,Tree[(node << 1) + 2].maxsum);
    }
};
int main() {
    int n,m;
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    SegmentTree code = SegmentTree(arr,n);
    for(int i = 0;i < m;i++){
    }
    return 0;
}