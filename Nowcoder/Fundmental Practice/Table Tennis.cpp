//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//#include<map>
//#include<set>
//#include<cstring>
//#include<queue>
//#include<algorithm>
//#include<functional>
//using namespace std;
//
//#define NMAX 10000
//#define KMAX 100
//
//class player {
//public:
//	int arrive;
//	int playing;
//	int vip;
//public:
//	friend bool operator <(const player &p1, const player &p2) {
//		return p1.arrive < p2.arrive;
//	}
//};
//
//class playing {
//public:
//	int arrive;
//	int serve;
//	int leave;
//	int table;
//public:
//	friend bool operator <(const playing &p1, const playing &p2) {
//		return p1.leave > p2.leave;
//	}
//};
//
//int timeToInt(const int &h, const int &m, const int &s)
//{
//	return h * 3600 + m * 60 + s;
//}
//
//vector<class player> players(NMAX);
//
//priority_queue<int, vector<int>, greater<int>>openn;
//priority_queue<int, vector<int>, greater<int>>openv;
//
//priority_queue<playing, vector<playing>>close;
//
//int tableServeSum[KMAX + 1];
//bool isVipTable[KMAX + 1];
//int N, K, M;
//
//const int beginTime = 8 * 3600;
//const int endTime = 21 * 3600;
//
//void outPut(const playing &p)
//{
//	printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", p.arrive / 3600, p.arrive / 60 % 60, p.arrive % 60, p.serve / 3600, p.serve / 60 % 60, p.serve % 60, (p.serve - p.arrive + 59) / 60);
//}
//
//void pushClose(const playing &plt)
//{
//	if (plt.serve < endTime) {
//		tableServeSum[plt.table]++;
//		close.push(plt);
//		outPut(plt);
//	}
//}
//void pushOpen(int table)
//{
//	if (isVipTable[table])
//		openv.push(table);
//	else
//		openn.push(table);
//}
//void popClose()
//{
//	pushOpen(close.top().table);
//	close.pop();
//}
//
//
//int popOpen()
//{
//	int state = openn.empty() ? 1 : openv.empty() ? 0 : openn.top() > openv.top() ? 1 : 0;
//	int value;
//	if (state) {
//		value = openv.top();
//		openv.pop();
//	}
//	else {
//		value = openn.top();
//		openn.pop();
//	}
//	return value;
//}
//
//void simulate()
//{
//	int curTime;
//	int pp = 0, pv;
//	int vipWait = 0;
//	playing plt;
//
//	while (pp < N) {
//		while (players[pp].vip == 2)
//			++pp;
//		if (close.empty()) {
//			curTime = players[pp].arrive;
//			plt = { curTime,curTime,curTime + players[pp].playing, popOpen() };
//			pushClose(plt);
//			++pp;
//			continue;
//		}
//
//		if ((int)close.size() < K) {
//			if (players[pp].arrive < close.top().leave) {
//				curTime = max(curTime, players[pp].arrive);
//				plt = { players[pp].arrive,curTime,curTime + players[pp].playing,popOpen() };
//				pushClose(plt);
//				++pp;
//			}
//			else
//				popClose();
//		}
//		else {
//			curTime = close.top().leave;
//			while (!close.empty() && close.top().leave == curTime)
//				popClose();
//			queue<int>vip;
//			for (pv = pp; pv < N&&players[pv].arrive <= curTime; ++pv)
//				if (players[pv].vip == 1)
//					vip.push(pv);
//
//			while (!vip.empty() && !openv.empty()) {
//				pv = vip.front();
//				plt = { players[pv].arrive,curTime,curTime + players[pv].playing,openv.top() };
//				pushClose(plt);
//				players[pv].vip++;
//				vip.pop();
//				openv.pop();
//			}
//
//		}
//	}
//}
//
//int main()
//{
//	while (scanf("%d", &N) != EOF) {
//		memset(isVipTable, false, sizeof(isVipTable));
//		memset(tableServeSum, 0, sizeof(tableServeSum));
//
//		int h, m, s, playMin;
//		int i, no;
//		for (i = 0; i < N; ++i) {
//			scanf("%d:%d:%d %d %d", &h, &m, &s, &playMin, &players[i].vip);
//			players[i].playing = playMin * 60;
//			players[i].arrive = timeToInt(h, m, s);
//		}
//
//		sort(players.begin(), players.begin() + N);
//
//		scanf("%d %d", &K, &M);
//		for (i = 0; i < M; ++i) {
//			scanf("%d", &no);
//			isVipTable[no] = true;
//		}
//		for (i = 1; i <= K; ++i)
//			if (isVipTable[i])
//				openv.push(i);
//			else
//				openn.push(i);
//
//		simulate();
//
//		for (i = 1; i <= K; ++i)
//			i == 1 ? printf("%d", tableServeSum[i]) : printf(" %d", tableServeSum[i]);
//	}
//	return 0;
//}



#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<cstring>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;

#define NMAX 10000
#define KMAX 100

class player {
public:
	int arrive;
	int play;
	int vip;
public:
	friend bool operator <(const player &p1, const player &p2) {
		return p1.arrive < p2.arrive;
	}
};

class playing {
public:
//	int arrive;
//	int serve;
	int leave;
	int table;
public:
	friend bool operator <(const playing &p1, const playing &p2) {
		return p1.leave > p2.leave;
	}
};

vector<class player> p;

priority_queue<int, vector<int>, greater<int>>openn;
priority_queue<int, vector<int>, greater<int>>openv;

priority_queue<playing, vector<playing>>inUsing;

int tableServeSum[KMAX + 1];
bool isVipTable[KMAX + 1];
int N, K, M;

const int beginTime = 8 * 3600;
const int endTime = 21 * 3600;

int popOpen()
{
	int state = openn.empty() ? 1 : openv.empty() ? 0 : openn.top() > openv.top() ? 1 : 0;
	int value;
	if (state) {
		value = openv.top();
		openv.pop();
	}
	else {
		value = openn.top();
		openn.pop();
	}
	return value;
}

void popUsing()
{
	int table = inUsing.top().table;
	if (isVipTable[table])
		openv.push(table);
	else
		openn.push(table);
	inUsing.pop();
}

void pushVipUsing(const int & pv, const int serveTime)
{
	player pler = p[pv];
	playing pling = { pler.play + serveTime,openv.top() };
	inUsing.push(pling);
	openv.pop();
	p[pv].vip = 2;
	tableServeSum[pling.table]++;
	printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", pler.arrive / 3600, pler.arrive / 60 % 60, pler.arrive % 60, serveTime / 3600, serveTime / 60 % 60, serveTime % 60, (serveTime - pler.arrive + 59) / 60);
}

void pushOrdUsing(const int &pn, const int serveTime)
{
	int table = popOpen();
	player pler = p[pn];
	playing pling = { pler.play + serveTime,table };
	inUsing.push(pling);
	p[pn].vip = 2;
	tableServeSum[table]++;
	printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", pler.arrive / 3600, pler.arrive / 60 % 60, pler.arrive % 60, serveTime / 3600, serveTime / 60 % 60, serveTime % 60, (serveTime - pler.arrive + 59) / 60);
}

void simulate()
{
	int serveTime = beginTime;
	int pp = 0;
	int pn, pv;
	int i;
	while (pp < p.size() && serveTime <= endTime) {
		if (p[pp].vip == 2) {
			++pp;
			continue;
		}
		//serveTime = inUsing.empty() ? p[pp].arrive : min(inUsing.top().leave, p[pp].arrive);
		if (!inUsing.empty() && (inUsing.top().leave <= p[pp].arrive || inUsing.size() == K)) {
			serveTime = inUsing.top().leave;
			while (!inUsing.empty() && inUsing.top().leave == serveTime)
				popUsing();
		}
		else {
			serveTime = max(serveTime, p[pp].arrive);
			pn = -1, pv = -1;
			for (pn = pp; pn < p.size() && p[pn].arrive <= serveTime&&!p[pn].vip; ++pn)
				;
			for (pv = pp; pv < p.size() && p[pv].arrive <= serveTime&&p[pv].vip == 1; ++pv)
				;
			if ((pv < p.size() && p[pv].arrive <= serveTime) && !openv.empty())
				pushVipUsing(pv, serveTime);
			else
				pushOrdUsing(pp, serveTime);
		}
	}
}

int main()
{
	while (scanf("%d", &N) != EOF) {
		memset(isVipTable, false, sizeof(isVipTable));
		memset(tableServeSum, 0, sizeof(tableServeSum));
		p.reserve(N);

		int h, m, s, play, vip;
		int arrive;

		int i, no;
		for (i = 0; i < N; ++i) {
			scanf("%d:%d:%d %d %d", &h, &m, &s, &play, &vip);
			arrive = h * 3600 + m * 60 + s;
			play = min(play, 120) * 60;
			if (arrive >= beginTime&&arrive <= endTime)
				p.push_back({ arrive,play,vip });
		}

		sort(p.begin(), p.begin());

		scanf("%d %d", &K, &M);
		for (i = 0; i < M; ++i) {
			scanf("%d", &no);
			isVipTable[no] = true;
		}
		for (i = 1; i <= K; ++i)
			if (isVipTable[i])
				openv.push(i);
			else
				openn.push(i);

		simulate();

		for (i = 1; i <= K; ++i)
			i == 1 ? printf("%d", tableServeSum[i]) : printf(" %d", tableServeSum[i]);
	}
	return 0;
}
