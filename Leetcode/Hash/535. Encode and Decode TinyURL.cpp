//方法一：直接返回，但是这样复制较长字符串浪费时间
class Solution {
	public:

		// Encodes a URL to a shortened URL.
		string encode(string longUrl) {
			return longUrl;
		}

		// Decodes a shortened URL to its original URL.
		string decode(string shortUrl) {
			return shortUrl;
		}
};

//将长字串转化为数字，但是要求译码返回的字符串不是数字，所以要用尽可能少的字符来表示数字
class Solution {
	public:
		string dict = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		int id = 0;
		unordered_map<string,string> m;  //key is longURL, value is shortURL
		unordered_map<int, string> idm;  //key is id in DB, value is longURL
		// Encodes a URL to a shortened URL.
		string encode(string longUrl) {
			if(m.find(longUrl) != m.end())
				return m[longUrl];
			string res = "";
			id++;
			int count = id;
			while(count > 0) {
				res = dict[count%62] + res;
				count /= 62;
			}
			m[longUrl] = res;
			idm[id] = longUrl;
			return res;
		}

		// Decodes a shortened URL to its original URL.
		string decode(string shortUrl) {
			int id = 0;
			for(int i = 0; i < shortUrl.size(); i++) {
				id = 62*id + (int)(dict.find(shortUrl[i]));
			}
			if(idm.find(id) != idm.end())
				return idm[id];
			return "";
		}
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
