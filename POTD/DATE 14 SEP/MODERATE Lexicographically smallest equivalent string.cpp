#include <bits/stdc++.h> 
class Disjoint{
	vector<int>par;
	vector<int>rank;
	public:
     Disjoint(int n)
	 {
		 par.resize(n);
		 rank.resize(n,1);
		 for (int i=0;i<n;i++) par[i]=i;
	 }
   int findpar(int node)
   {
	   if (par[node]==node) return node;
	   return par[node]=findpar(par[node]);
   }
   void unions(int u,int v)
   {
	   u=findpar(u);
	   v=findpar(v);
	   if (u==v) return;
	   if (rank[u]>rank[v])
	   {
		   par[v]=u;
	   }
	   else if (rank[v]>rank[u])
	   {
		   par[u]=v;
	   }
	   else{
		   par[u]=v;
		   rank[v]++;
	   }
   }
};
string smallestString(string s, string t, string str)
{
	Disjoint* d=new Disjoint(26);
	for (int i=0;i<s.size();i++)
	{
		d->unions(s[i]-'a',t[i]-'a');
	}
	map<int,vector<int>>mp;
	for (int i=0;i<26;i++)
	{
		int u=d->findpar(i);
		mp[u].push_back(i);
	}
	string ans="";
	for (auto it:mp)
	{
		sort(it.second.begin(),it.second.end());
	}
	for (int i=0;i<str.size();i++)
	{
		int u=d->findpar(str[i]-'a');
		int num=mp[u][0];
		ans.push_back(num+'a');
	} 
	return ans;
}
