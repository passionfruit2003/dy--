#include<bits/stdc++.h>
using namespace std;
vector <int> lim[2][20];
int sum[2][20];
int ans[20][20];
int n;
int check(int x,int y){
	int tot=0;
	for(int i=1;i<=y;i++)
		tot+=ans[x][i];
	if(tot+n-y<sum[0][x]) return 0;
	tot=0;
	for(int i=1;i<=x;i++)
		tot+=ans[i][y];
	if(tot+n-x<sum[1][y]) return 0;
	vector<int> cntx,cnty;
	int count=0;
	for(int i=1;i<=y;i++){
		if(ans[x][i]==1) count++;
		else{
			if(count>0) cntx.push_back(count);
			count=0;
		}
	}
	if(count>0) cntx.push_back(count);
	count=0;
	for(int i=1;i<=x;i++){
		if(ans[i][y]==1) count++;
		else{
			if(count>0) cnty.push_back(count);
			count=0;
		}
	}
	if(count>0) cnty.push_back(count);
	if(cntx.size()>lim[0][x].size()||cnty.size()>lim[1][y].size()) return 0;
	if(y==n){
		int len1=lim[0][x].size(),len2=cntx.size();
		if(len1!=len2) return 0;
		for(int i=0;i<len1;i++)
			if(lim[0][x][i]!=cntx[i]) return 0;
	}
	if(x==n){
		int len1=lim[1][y].size(),len2=cnty.size();
		if(len1!=len2) return 0;
		for(int i=0;i<len1;i++)
			if(lim[1][y][i]!=cnty[i]) return 0;
	}
	int lenx=cntx.size(),leny=cnty.size();
	if(lenx!=0){
		if(ans[x][y]==1){
			for(int i=0;i<lenx-1;i++)
				if(lim[0][x][i]!=cntx[i]) return 0;
			if(lim[0][x][lenx-1]<cntx[lenx-1]) return 0;
		}else{
			for(int i=0;i<lenx;i++)
				if(lim[0][x][i]!=cntx[i]) return 0;
		}
	}
	if(leny!=0){
		if(ans[x][y]==1){
			for(int i=0;i<leny-1;i++)
				if(lim[1][y][i]!=cnty[i]) return 0;
			if(lim[1][y][leny-1]<cnty[leny-1]) return 0;
		}else{
			for(int i=0;i<leny;i++)
				if(lim[1][y][i]!=cnty[i]) return 0;
		}
	}
	return 1;
}
void debug(){
	cout<<"!!!!!!"<<endl;
	for(int i=1;i<=n;i++){
		cout<<endl;
		for(int j=1;j<=n;j++)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	cout<<"!!!!!!"<<endl;
}
int dfs(int x,int y){
	if(x==n+1) return 1;
	int nex=x,ney=y;
	if(y!=n) ney++;
	else {nex++;ney=1;}
	ans[x][y]=0;
	int res=check(x,y);
	if(res==1){
		int nex_res=dfs(nex,ney);
		if(nex_res==1) return 1;
		else{
			ans[x][y]=1;
			if(check(x,y)==0) return 0;
			return dfs(nex,ney);
		}
	}else{
		ans[x][y]=1;
			if(check(x,y)==0) return 0;
			return dfs(nex,ney);
	}
}
int main(){
	cin>>n;
	getchar();
	for(int k=0;k<2;k++)
		for(int i=1;i<=n;i++){
			string line;
			getline(cin, line);
			istringstream iss(line);
			int num;
			while(iss >> num){
				lim[k][i].push_back(num);
				sum[k][i]+=num;
			}
		}
	int res=dfs(1,1);
	if(res==0) cout<<"нч╫Б";
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				cout<<ans[i][j]<<" ";
			cout<<endl;
		}
	}
	system("pause");
}
