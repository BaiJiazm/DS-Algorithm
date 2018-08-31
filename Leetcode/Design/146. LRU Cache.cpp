class LRUCache {
	public:
		LRUCache(int capacity) {
			cap = capacity;
		}

		int get(int key) {
			auto it = m_map.find(key);
			if(it == m_map.end()) return -1;

			m_list.splice(m_list.begin(), m_list, it->second);

			return it->second->second;

		}

		void put(int key, int value) {
			auto it = m_map.find(key);
			if(it != m_map.end()) m_list.erase(it->second);

			m_list.push_front(make_pair(key, value));

			m_map[key] = m_list.begin();

			if(m_map.size() > cap) {
				int k = m_list.rbegin()->first;
				m_list.pop_back();
				m_map.erase(k);
			}

		}

	private:
		int cap;
		list<pair<int, int>> m_list;
		unordered_map<int, list<pair<int, int>>::iterator> m_map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */


class LRUCache {
	public:
		struct Node {
			int key;
			int val;
			Node* pre;
			Node* next;
		};
		Node head;
		unordered_map<int, Node*>hash;

		void detach(Node* p) {
			p->pre->next=p->next;
			p->next->pre=p->pre;
		}
		void insertTail(Node* p) {
			p->pre=head.pre;
			p->next=&head;
			head.pre=p;
			p->pre->next=p;
		}

		LRUCache(int capacity) {
			head.pre=head.next=&head;
			for(int i=0; i<capacity; ++i) {
				Node* p=new Node;
				p->next=head.next;
				p->pre=&head;
				head.next->pre=p;
				head.next=p;
			}
		}

		int get(int key) {
			auto it=hash.find(key);
			if(it!=hash.end()) {
				detach(it->second);
				insertTail(it->second);
				return it->second->val;
			}
			return -1;
		}

		void put(int key, int value) {
			auto it=hash.find(key);
			Node* p;
			if(it==hash.end()) {
				detach(p=head.next);
			} else {
				detach(p=it->second);
			}
			hash.erase(p->key);
			p->key=key;
			p->val=value;
			insertTail(p);
			hash[key]=p;
		}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

