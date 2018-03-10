#include<iostream>
#include<vector>
#include<list>
using namespace std;
struct Edge
{
    int to,len;
};
bool spfa(const int &beg,//������
          const vector<list<Edge> > &adjlist,//�ڽӱ�ͨ�������ñ��⿽��
          vector<int> &dist,//�����㵽��������·������
          vector<int> &path)//·���ϵ���õ��ǰһ����
//û�и�Ȩ��·����0
//�������������û�е����κ�ȫ�ֱ���������ֱ�Ӹ��ƣ�
{
    const int INF=0x7FFFFFFF,NODE=adjlist.size();//���ڽӱ�Ĵ�С���ݶ�����������ٲ�������
    dist.assign(NODE,INF);//��ʼ������Ϊ�����
    path.assign(NODE,-1);//��ʼ��·��Ϊδ֪
    list<int> que(1,beg);//�������
    vector<int> cnt(NODE,0);//��¼������Ӵ����������жϸ�Ȩ��·
    vector<bool> flag(NODE,0);//��־���飬�ж��Ƿ��ڶ�����
    dist[beg]=0;//�����㵽����·������Ϊ0
    cnt[beg]=flag[beg]=1;//��Ӳ���ʼ����
    while(!que.empty())
    {
        const int now=que.front();
        que.pop_front();
        flag[now]=0;//����ǰ����ĵ����
        for(list<Edge>::const_iterator//�ó��������������ڽӱ�
                i=adjlist[now].begin(); i!=adjlist[now].end(); ++i)
            if(dist[i->to]>dist[now]+i->len)//���������ǲ���ʽ
            {
                dist[i->to]=dist[now]+i->len;//����
                path[i->to]=now;//��¼·��
                if(!flag[i->to])//��δ�ڴ��������
                {
                    if(NODE==++cnt[i->to])return 1;//��������ָ�Ȩ��·
                    if(!que.empty()&&dist[i->to]<dist[que.front()])//���зǿ������ڶ��ף�SLF��
                        que.push_front(i->to);//���ڶ���
                    else que.push_back(i->to);//������ڶ�β
                    flag[i->to]=1;//���
                }
            }
    }
    return 0;
}
int main()
{
    int n_num,e_num,beg;//�������
    cout<<"��������������������㣺";
    cin>>n_num>>e_num>>beg;
    vector<list<Edge> > adjlist(n_num,list<Edge>());//Ĭ�ϳ�ʼ���ڽӱ�
    for(int i=0,p; i!=e_num; ++i)
    {
        Edge tmp;
        cout<<"�����"<<i+1<<"���ߵ���㡢�յ㡢���ȣ�";
        cin>>p>>tmp.to>>tmp.len;
        adjlist[p].push_back(tmp);
    }
    vector<int> dist,path;//���ڽ������·�����ȼ�·������
    if(spfa(beg,adjlist,dist,path))cout<<"ͼ�д��ڸ�Ȩ��·\n";
    else for(int i=0; i!=n_num; ++i)
        {
            cout<<beg<<"��"<<i<<"����̾���Ϊ"<<dist[i]<<"�������ӡ·����";
            for(int w=i; path[w]>=0; w=path[w])cout<<w<<"<-";
            cout<<beg<<'\n';
        }
}
//���c++������ĳЩ����»�runtime error
//¥���ǲ���ûע����Ǵ�0��ʼ��
