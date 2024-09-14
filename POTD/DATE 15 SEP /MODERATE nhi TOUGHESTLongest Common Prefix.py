#include<bits/stdc++.h>
//Answer Dekhlo samjah mein nhi aayaa ye YT dekho
using namespace std;

class Node{
	vector<Node*> links;
	int count;
	public:
	Node()
	{
		links.resize(26,NULL);
		count = 0;
	}
	Node * getLink(char c)
	{
		return links[c-'a'];
	}
	void insert(char c,Node * node)
	{
		links[c-'a'] = node;
	}
	void incCnt()
	{
		count++;
	}
	int getCnt()
	{
		return count;
	}
};

class Trie
{
	Node * root;
	public:
	Trie()
	{
		root = new Node();
	}
	void insert(string &s)
	{
		Node * node = root;
		for(int i=0;i<s.size();i++)
		{
			if(!node->getLink(s[i]))
			{
				node->insert(s[i],new Node());
			}
			node = node->getLink(s[i]);
			node->incCnt();
		}
	}
	int getCnt(string & s)
	{
		Node * node = root;
		int ans = 0;
		for(int i=0;i<s.size();i++)
		{
			if(!node->getLink(s[i])) break;
			node = node->getLink(s[i]);
			ans+=node->getCnt();
		}
		return ans;
	}
};

void solve(int n,vector<string> & db,int q,vector<string> & queries)
{
	vector<int> ans(q,-1);
	unordered_map<string,vector<int>> umap;
	for(int i=0;i<queries.size();i++)
	{
		umap[queries[i]].push_back(i);
	}
	Trie* trie = new Trie();
	for(int i=0;i<n;i++)
	{
		trie->insert(db[i]);
		if(umap[db[i]].size()>0)
		{
			for(auto idx:umap[db[i]])
			{
				ans[idx] = (i+1) + trie->getCnt(db[i]);
			}
		}
	}
	for(int i=0;i<q;i++)
	{
		if(ans[i]==-1)
		{
			ans[i] =n+  trie->getCnt(queries[i]);
			// cout << "q" << i << " " << ans[i] << endl;
		}
	}
	for(int i=0;i<q;i++) cout << ans[i] << endl;
}





int main() {
	int n;
	cin >> n;
	vector<string> db(n);
	for(int i=0;i<n;i++) cin >> db[i];
	int q;
	cin >> q;
	vector<string> queries(q);
	for(int i=0;i<q;i++) cin >> queries[i];
	solve(n,db,q,queries);
	// Write your code here
}
