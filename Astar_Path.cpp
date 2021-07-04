//Harshal Khamkar  19QE30004
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define F first
#define S second
#define mp make_pair
#define pb push_back
using ii = pair<int,int>;

vector<string> grid;
vector<vector<int>> dist;
vector<vector<ii>> parent;
int n,m; //Grid Dimensions
int dx[]={0,1,0,-1}; //For 4 possible movements from a given cell
int dy[]={1,0,-1,0};
bool check(int x, int y){
    //Checking for valid cell
    if(x>=0 && x<n && y>=0 && y<m && grid[x][y]!='#')return 1;
    else return 0;
}
void bfs(ii start){
 dist=vector<vector<int>> (n,vector<int>(m,1e9)); //Initilaising all distances to 1e9
 parent=vector<vector<ii>>(n,vector<ii>(m,mp(-1,-1))); 
 dist[start.F][start.S]=0; //distance of starting point is zero

 queue<ii> q;
 q.push(start);
 while(!q.empty()){
   ii curr=q.front(); q.pop();
   int x=curr.F;
   int y=curr.S;
   // checking all 4 possible movements
   for(int k=0;k<4;k++){
    int nx=x+dx[k];
    int ny=y+dy[k];
    if(check(nx,ny) && dist[nx][ny]>dist[x][y]+1){
        dist[nx][ny]=dist[x][y]+1; //if shorter distance than previous is possible
        parent[nx][ny]={x,y};
        q.push(mp(nx,ny));                                      
                                                 }
                       }

                  }
}

void solve(){
 cout<<"Give the size of the grid:"<<endl;
    cin>>n>>m;
    grid.resize(n);
    cout<<"Input grid: "<<endl;
    for(int i=0;i<n;i++){
        cin>>grid[i];
                        }
 cout<<"Give the starting and End co-ordinates: "<<endl;
 ii start,end;
 cin>>start.F>>start.S;
 cin>>end.F>>end.S;
 bfs(start);
 
 ii curr=end;
 while(curr!=mp(-1,-1)){
    grid[curr.F][curr.S]='P'; //marking shortest path by 'P'
    curr=parent[curr.F][curr.S];
                       }
 grid[start.F][start.S]='S'; //marking starting point by 'S'
 grid[end.F][end.S]='E'; //marking End point by 'F'

 //Checking if path is possible:
 if(dist[end.F][end.S]!=1e9){
 cout<<"Distance Travelled is: "<<dist[end.F][end.S]<<endl;
 for(int i=0;i<n;i++)cout<<grid[i]<<endl;
                            }
 else cout<<"No Path Exist"<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}