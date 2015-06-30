  /* Example of spoj problem for spoj.com/problems/DQUERY
	Use fastio or replace with scanf and printf for getting accepted.
	Referral link for understanding the whole algorithm
	http://blog.anudeep2011.com/mos-algorithm/
*/
#include<bits/stdc++.h>
using namespace std;
#define fl(i , a, b) for(i = a; i<b; i++)
int a[300100] , final[200020] , hash[1000020];
int ans ; 
int divide ; 
struct s
{	
	int l , r , pos; 
}qa[200010];
bool mycmp(struct s a , struct s b)
{
	if(a.l/divide!=b.l/divide){
		return (a.l/divide<b.l/divide);
	}
	else 
		return a.r < b.r;
}
void add(int i )
{
	hash[a[i]]++;
	if(hash[a[i]]==1)
		ans++;
}
void removeelem(int i )
{
	hash[a[i]]--;
	if(hash[a[i]]==0)
		ans--;
}
int main()
{
	int n ,i, q; 
	cin>>n;
	divide = sqrt(n);
	fl(i , 0 , n) cin>>a[i];
	cin>>q;
	fl(i , 0 ,q){
		cin>>qa[i].l>>qa[i].r;
		qa[i].l--; qa[i].r--;
		qa[i].pos = i ;
	}
	sort(qa , qa+q , mycmp);
	ans =0 ;
	int currL =0 , currR=0 , L, R; 
	fl(i , 0 , q)
	{	
		L = qa[i].l ;R =  qa[i].r;
		while(currL<L)
		{
			removeelem(currL);
			currL++;
		}
		while(currL>L)
		{
			add(currL-1);
			currL--;
		}
		while(currR<=R)
		{
			add(currR);
			currR++;
		}
		while(currR>R+1)
		{
			removeelem(currR-1);
			currR--;
		}
		final[qa[i].pos] = ans;
	}
	fl(i , 0 , q)cout<<final[i]<<endl;
	return 0 ;
}
