# include<bits/stdc++.h>
using namespace std;
int main(){
  int l,m,n;
  cin >> l >> m >> n;
  string str;
  cin >> str;
  string newstr = str.substr(m,l - m);
  cout<< newstr.substr(0,newstr.length() - n);
}