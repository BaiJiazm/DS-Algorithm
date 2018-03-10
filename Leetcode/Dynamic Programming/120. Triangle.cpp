
/*
	For the kth level:
	minpath[i] = min( minpath[i], minpath[i+1]) + triangle[k][i];
*/
int minimumTotal(vector<vector<int> > &triangle) {
	int n = triangle.size();
	vector<int> minlen(triangle.back());
	for (int layer = n-2; layer >= 0; layer--) { // For each layer
		for (int i = 0; i <= layer; i++) { // Check its every 'node'
			// Find the lesser of its two children, and sum the current value in the triangle with it.
			minlen[i] = min(minlen[i], minlen[i+1]) + triangle[layer][i];
		}
	}
	return minlen[0];
}
