
class fileSysNode {
	public:
		unordered_map<string,pair<string,fileSysNode*>>cont;
};

typedef unordered_map<string,pair<string,fileSysNode*>>::iterator It;
typedef pair<string,fileSysNode*> Pr;

class FileSystem {
		fileSysNode *root;
	public:
		FileSystem() {
			root= new fileSysNode();
		}

		vector<string> ls(string path) {
			fileSysNode *pf=root;
			vector<string>lsContent;
			string name;
			int index=1,nextIndex;
			while(1) {
				nextIndex=path.find_first_of(index,'/');
				name=path.substr(index,nextIndex-index);
				Pr pr=pf->cont.find(name)->second;
				if(nextIndex==string::npos) {
					if(!pr.first.empty())
						return {pr.first};
					if(pr.second)
						for(auto &a:pr.second->cont)
							lsContent.push_back(a.first);
					return lsContent;
				}
				index=nextIndex;
				pf=pr.second;
			}
			return {};
		}

		void mkdir(string path) {
			fileSysNode *pf=root;
			string name;
			int index=1,nextIndex;
			while(index<path.length()) {
				nextIndex=path.find_first_of(index,'/');
				name=path.substr(index,nextIndex-index);
				if(nextIndex==string::npos)
					pf->cont[name]= {"",NULL};
				else {
					It it=pf->cont.find(name);
					if(it==pf->cont.end())
						pf->cont[name]= {"",new fileSysNode};
					else
						pf=pf->cont[name].second;
				}
				index=nextIndex;
			}
		}

		void addContentToFile(string filePath, string content) {

		}

		string readContentFromFile(string filePath) {
			return "";
		}
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * vector<string> param_1 = obj.ls(path);
 * obj.mkdir(path);
 * obj.addContentToFile(filePath,content);
 * string param_4 = obj.readContentFromFile(filePath);
 */
