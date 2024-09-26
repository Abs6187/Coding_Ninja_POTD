/* UNLOCKED SOLUTION
    Time Complexity: O(N * log(N))
    Space Complexity: O(N)

    Where N is the size of the pairs array.
*/

#include<queue>
#include<unordered_map>
#include<unordered_set>

int findWays(vector<vector<int>>& pairs, int n) 
{
	// Map to store the given pairs as adjacency list.
	unordered_map<int, unordered_set<int>> adj;
	for (int i = 0; i < n; i++) 
	{
		adj[pairs[i][0]].insert(pairs[i][1]);
		adj[pairs[i][1]].insert(pairs[i][0]);
	}

	// Priority queue to store the nodes in decreasing order of their degree.
	priority_queue<vector<int>> q;
	for (pair<int, unordered_set<int>> p : adj) 
	{
		vector<int> v(2);
		v[0] = p.second.size();
		v[1] = p.first;
		q.push(v);
	}

	int totalNodes = q.size();

	// Unordered_set to store the visited nodes.
	unordered_set<int> visited;
	int ans = 1;

	while (!q.empty()) 
	{
		vector<int> currNode = q.top();
		q.pop();
		int parent = -1;
		int parentSize = 1e9;

		// Finding the parent of the current node.
		for (int x : adj[currNode[1]]) 
		{
			if (visited.find(x) != visited.end() && adj[x].size() < parentSize && adj[x].size() >= currNode[0]) 
			{
				parent = x;
				parentSize = adj[x].size();
			}

		}

		visited.insert(currNode[1]);
        
		// If there is no parent of the current node then it should be the root node.
		if (parent == -1) 
		{
			/*
                If the current node is the root node 
                and if its degree is not equal to 
                totalNodes - 1, hence no reconstruction is possible.
            */
			if (currNode[0] != totalNodes - 1) 
			{
				return 0;
			}

			continue;
		}

		/*
            Checking if all the nodes in current node's adjacency is also 
            present in the parent's adjacency or not. If not then again 
            the reconstruction of the tree is not possible.
        */
		for (int x : adj[currNode[1]]) 
		{
			if (x == parent) 
			{
				continue;
			}

			if (adj[parent].find(x) == adj[parent].end()) 
			{
				return 0;
			}
			
		}

		// If the degree of parent and current node is equal then multiple reconstruction is possible.
		if (currNode[0] == parentSize) 
		{
			ans = 2;
		}

	}

	return ans;
}
