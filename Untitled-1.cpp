priority_queue<int,vector<int>,greater<int> > pq;//数字小的优先级高
pripority_queue<int,vector<int>,less<int> > pq;//数字大的优先级高
struct node{
	int x,y;
	bool operator < (const node &a) const
	{
		return x<a.x;//递减排列 
	}
};
priority_queue<node> pq; 