#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ff first
#define ss second
#define eb emplace_back
#define MP make_pair
#define pb push_back
#define pf push_front
#define ins insert
#define endl '\n'
#define all(v) (v).begin(), (v).end()
#define mset(m,v) memset(m,v,sizeof(m))
#define tr(c,it) for(auto it=c.begin();it!=c.end();it++)
#define fr(i,n) for(lli i=0;i<(n);i++)
#define inc(i,a,b) for(lli i=a;i<=b;i++)
#define dec(i,a,b) for(lli i=a;i>=b;i--)
#define fr2(i,n) for(int i=0;i<(n);i++)
#define inc2(i,a,b) for(int i=a;i<=b;i++)
#define dec2(i,a,b) for(int i=a;i>=b;i--)
#define ymin(a,b)  (a=min((a),(b)))
#define ymax(a,b)  (a=max((a),(b)))
#define sz(x) (lli)(x).size()
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr<< *it << " = " << a << endl;
	err(++it, args...);
}

typedef long long int lli;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef vector<int> vi;
//typedef  vector<vector<lli> >ncr(1001,vector<lli>(1001,0))
typedef vector<plli> vplli;
long long MOD=1000000009;
#define addm(x,y) (x+y>=MOD? (x+y-MOD):(x+y))

const int sigma=128;
typedef struct node
{
	node *next[sigma];
	int wend;
	int prefix;
	node()
	{
		wend=0;
		prefix=0;
		for(int i=0;i<sigma;i++)
			next[i]=NULL;
	}
}trie;
trie *head;
void insert(string &s)
{
	trie *cur=head;
	for(int i=0;i<s.length();i++)
	{
		if(cur->next[s[i]-'a']==NULL)
		{
			cur->next[s[i]-'a']=new trie();
			
		}
		cur=cur->next[s[i]-'a'];
		cur->prefix++;
		
	}
	cur->wend++;
	

}
 
int count(string &s)//this counts how many times a particular string occurs in  a sequence of strings
{
	trie *cur=head;
	for(int i=0;i<s.length();i++)
	{
		//cout<<cur->next[s[i]-'a']<<endl;
		if(cur->next[s[i]-'a']==NULL)
		{
			
			
			return 0;
		}
		cur=cur->next[s[i]-'a'];
	}
	
	return cur->wend;
}
int prefix(string &s)
{
	trie *cur=head;
	for(int i=0;i<s.length();i++)
	{
		if(cur->next[s[i]-'a']==NULL)
		{
			cout<<cur->next[s[i]-'a']<<" "<<endl;
			return 0;
		}
		cur=cur->next[s[i]-'a'];
	}
	cout<<s<<" "<<cur->prefix<<endl;
	return cur->prefix;


}
void dfs(trie *cur,vector<string> &autocmp,string temp)
{
	if(cur->wend)
		autocmp.eb(temp);
	for(lli i=0;i<128;i++)
	{
		if(cur->next[i]!=NULL)
			dfs(cur->next[i],autocmp,temp+char(i+'a'));
	}
}
vector<string>  get_all(string s)
{
	vector<string> autocmp;

	trie *cur=head;
	for(lli i=0;i<s.length();i++)
	{
		
		if(cur->next[s[i]-'a']==NULL)
		{
			
			return autocmp;
		}
		cur=cur->next[s[i]-'a'];
		
	}
	dfs(cur,autocmp,s);
	return autocmp;
}

int32_t main()
{
		#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	IOS
	
	head=new trie();//first allocate space for trie dynamically;
	
	//"Enter the number of strings to be entered"
	lli n;
	cin>>n;
	fr(i,n)
	{
		string s;
	//	"Enter the "i+1 "th string"
		cin>>s;

		insert(s);
	}
	//"Enter the prefix to be searched"
	string ser;
	cin>>ser;

	vector<string> ans=get_all(ser);
	cout<<sz(ans)<<endl;
	for(auto i:ans)
		cout<<i<<" ";
	cout<<endl;
}
