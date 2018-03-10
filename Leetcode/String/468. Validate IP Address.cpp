//自己写的，对于对性能没有特别要求的题目，用最简洁易行的方法更好。逻辑清晰，思路简单
class Solution {
	public:
		string validIPAddress(string IP) {
			vector<string>blocks;
			int pos=0;
			int nextPos;
			if ((nextPos=IP.find('.'))!=string::npos) {
				while(nextPos!=string::npos) {
					blocks.push_back(IP.substr(pos,nextPos-pos));
					pos=nextPos+1;
					nextPos=IP.find('.',pos);
				}
				blocks.push_back(IP.substr(pos,IP.length()-pos));
				if (blocks.size()!=4)
					return "Neither";
				for(int i=0; i<4; ++i)
					if (!isIPv4Seg(blocks[i]))
						return "Neither";
				return "IPv4";
			} else if ((nextPos=IP.find(':'))!=string::npos) {
				while(nextPos!=string::npos) {
					blocks.push_back(IP.substr(pos,nextPos-pos));
					pos=nextPos+1;
					nextPos=IP.find(':',pos);
				}
				blocks.push_back(IP.substr(pos,IP.length()-pos));
				if (blocks.size()!=8)
					return "Neither";
				for (int i=0; i<8; ++i)
					if(!isIPv6Seg(blocks[i]))
						return "Neither";
				return "IPv6";
			}
			return "Neither";
		}
		bool isIPv4Seg(string s) {
			if (s.empty()||s.length()>3||s.length()!=1&&s[0]=='0')
				return false;
			int digit=0;
			for (int i=0; i<s.length(); ++i)
				if (s[i]>='0'&&s[i]<='9')
					digit=digit*10+s[i]-'0';
				else
					return false;
			return digit<256;
		}
		bool isIPv6Seg(string s) {
			if (s.empty()||s.length()>4)
				return false;
			for (int i=0; i<s.length(); ++i)
				if (s[i]>='0'&&s[i]<='9'||s[i]>='A'&&s[i]<='F'||s[i]>='a'&&s[i]<='f')
					continue;
				else
					return false;
			return true;
		}
};


class Solution {
	private:
		bool validIPv4(string &IP) {
			int begin = 0, end = 0, cnt = 0;
			while (end < IP.size()) {
				int leadingZeroCount = 0, num = 0;
				while (end < IP.size() && isdigit(IP[end])) {
					num = num * 10 + IP[end] - '0';
					if (IP[end] == '0' && num == 0) leadingZeroCount++;
					if ((leadingZeroCount > 0 && num != 0)
					        || leadingZeroCount > 1
					        || end - begin + 1 > 3
					        || num > 255) return false;
					++end;
				}
				if (end == begin) return false;
				++cnt;
				if (cnt <= 3) {
					if (end >= IP.size() || IP[end] != '.') return false;
					begin = ++end;
				} else {
					if (end != IP.size()) return false;
				}
			}
			return cnt == 4;
		}

		bool validIPv6(string &IP) {
			int cnt = 0, begin = 0, end = 0;
			while (end < IP.size()) {
				while (end < IP.size() && isalnum(IP[end])) {
					if ((IP[end] > 'f' && IP[end] <= 'z')
					        || (IP[end] > 'F' && IP[end] <= 'Z')
					        || end - begin + 1 > 4) return false;
					++end;
				}
				if (begin == end) return false;
				++cnt;
				if (cnt <= 7) {
					if (end >= IP.size() || IP[end] != ':') return false;
					begin = ++end;
				} else {
					if (end != IP.size()) return false;
				}
			}
			return cnt == 8;
		}
	public:
		string validIPAddress(string IP) {
			if (validIPv4(IP)) return "IPv4";
			if (validIPv6(IP)) return "IPv6";
			return "Neither";
		}
};
