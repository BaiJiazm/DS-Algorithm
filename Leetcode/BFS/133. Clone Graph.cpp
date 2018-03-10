/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
	public:
		UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		}
		
		UndirectedGraphNode *cloneGraphSub(UndirectedGraphNode *node,UndirectedGraphNode *parent,UndirectedGraphNode *cloneParent) {
			UndirectedGraphNode*pnode=new UndirectedNode;
			pnode->lable=node->label;
			for (int i=0;i<node->neighbors.size();++i){
				if (node->neighbors[i]==parent)
					pnode->neighbors.push_back(cloneParent);
				else if (node->neighbors[i]!=node){
					pnode->neighbors.push_back(cloneGraph(node->neighbors[i]));
				}
				else
					pnode->neighbors.push_back()
			}
		}
};
