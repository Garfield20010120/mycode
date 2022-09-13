#include <iostream>
 
using namespace std;
 
const int N = 100000;
 
struct node
{
   int l,r,maxn,sum;
}line[3*N];
 
int num[N];
int first,second;    //存储p=2和p=3时的解
 
//创建线段树 
void create(int k,int x,int y)   //k是当前结点的编号，x是左边界，y是右边界  初始时传的参数是1 1 n 
{
   line[k].l = x;line[k].r = y;    //编号为k的结点左孩子初始化为x，右孩子为y 
   if(x == y)         //如果左右孩子相等，说明到叶节点了，那么叶节点存储的就是数组对应位置的真实数据 
   {
      line[k].sum = num[x];   //在本题中，叶子结点的sum存储一个格子的值，其他结点的sum存储其代表区间内所有叶子结点sum值的和 
	  line[k].maxn = num[x];  //叶子结点的maxn就是自己的代表的格子值，其他节点的maxn存储其代表区间内所有叶子maxn的最大值 
	  return;
   }
   
   int mid = (x+y)/2;
   //如果不是叶子结点，继续向下创建树
   //对一棵树从上到下从左到右编号，则编号为k的结点，其左孩子编号为k*2，右孩子编号为K*2+1
   create(k*2,x,mid);  //左孩子的左边界是父亲的左边界，右边界是是父亲左右边界的中点 
   create(k*2+1,mid+1,y);  //右孩子的左边界是父亲左右边界的中点，右边界是父亲的右边界
   //递归返回之后，左右孩子的maxn和sum值才能确定，所以本节点maxn和sum的更新在递归返回之后才进行
   line[k].maxn = max(line[k*2].maxn,line[k*2+1].maxn);     
   line[k].sum = line[k*2].sum+line[k*2+1].sum;
}
 
//单点修改  
void update(int k,int a,int b)  //k是当前处理的树节点编号，a是要定位的格子编号，b是要修改的值 
{
	if(line[k].l == line[k].r)  //如果左右边界相等，说明找到我们要修改的结点了 
	{
		line[k].maxn = b;
		line[k].sum = b;
		return ;      //修改完毕，无需做后续操作，直接返回 
	}
	//如果不是我们要定位的结点 
	int mid = (line[k].l+line[k].r)/2;
	//判断我们要定位的结点在当前处理的左孩子里还是右孩子里 
	if(a <= mid)
		update(k*2,a,b);   //左孩子里 
	else
		update(k*2+1,a,b);  //在右孩子里
	//对叶子结点进行修改后，其查询路径上的结点值都要更新，因此在递归返回后要重新计算一遍maxn和sum 
	line[k].sum = line[k*2].sum+line[k*2+1].sum;
	line[k].maxn = max(line[k*2].maxn,line[k*2+1].maxn);
}
 
//区间查询，p=2和p=3用的都是这个函数，因为他们都是区间查询，只不过查询的数据不同 
void query(int k,int x,int y)    //k是当前处理的树节点编号，x是要查询的区间左端点，y是要查询的区间右端点 
{
   if(line[k].l == x && line[k].r == y)  //如果查询到我们要定位的区间 
   {
      second += line[k].sum;      //这里之所以不用赋值号，是因为如果我们要查询的区间分别属于不同的结点，那么就要把查询区间分成两段分别查询;求和的结果必然是两段之和，求最大值的结果必然是两段中的最大值 
	  first = max(first,line[k].maxn);
	  return;
   }
   
   int mid = (line[k].l+line[k].r)/2;
   
   //只要能进入当前处理的结点，说明要查询的区间肯定是位于当前结点区间里面的，只不过其左右端点与当前区间中点的位置关系不明确，但与当前区间端点的关系肯定是明确的 
   if(y <= mid)    //要查询的区间完全处于当前结点区间中点的左侧 ，注意这里的等号是必须的，如果y=mid时不进这里，下面mid+1就会超过y 
	   query(k*2,x,y);   
   else if(x>mid)   //要查询的区间完全处于当前结点区间中点的右侧
       query(k*2+1,x,y);
   else             //要查询的区间部分位于当前区间中点的内部，部分位于外部 
   {
   	  //将待查区间分成两段 
      query(k*2,x,mid);   
	  query(k*2+1,mid+1,y); 
   }
}
 
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	scanf("%d",&num[i]);
	create(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		if(a==1)
		{
			update(1,b,c);
		}
		else if(a==2)
		{
			first=-10000;
			second=0;
			query(1,b,c);
			cout << second << endl;
		}
		else
		{
			first=-10000;
			second=0;
			query(1,b,c);
			cout << first << endl;
		}
		
	}
	return 0;
}

