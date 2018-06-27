priority_queue<int,vector<int>,greater<int> > pq;
pripority_queue<int,vector<int>,less<int> > pq;
struct node{
	int x,y;
	bool operator < (const node &a) const
	{
		return x<a.x;//递减排列 
	}
};
priority_queue<node> pq; 