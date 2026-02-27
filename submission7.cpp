#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

string goal = "ABCDEFGHIJKLMNO#";

vector<string> neighbors(string s) {
    vector<string> v;
    int pos;
    for (int i = 0; i < 16; i++) if (s[i] == '#') pos = i;
    int r = pos / 4, c = pos % 4;
    if (r > 0) { string t=s; swap(t[pos],t[pos-4]); v.push_back(t); }
    if (r < 3) { string t=s; swap(t[pos],t[pos+4]); v.push_back(t); }
    if (c > 0) { string t=s; swap(t[pos],t[pos-1]); v.push_back(t); }
    if (c < 3) { string t=s; swap(t[pos],t[pos+1]); v.push_back(t); }
    return v;
}

int h1(string s) {
    int c=0;
    for(int i=0;i<16;i++) if(s[i]!='#' && s[i]!=goal[i]) c++;
    return c;
}

int h2(string s) {
    int d=0;
    for(int i=0;i<16;i++){
        if(s[i]=='#') continue;
        int g=goal.find(s[i]);
        d+=abs(i/4-g/4)+abs(i%4-g%4);
    }
    return d;
}

pair<int,int> bfs(string start) {
    queue<pair<string,int>> q;
    unordered_set<string> vis;
    q.push({start,0});
    vis.insert(start);
    int added=1;

    while(!q.empty()){
        auto cur=q.front(); q.pop();
        if(cur.first==goal) return {cur.second,added};
        if(added>1000000) return {cur.second,1000000};
        for(string n:neighbors(cur.first)){
            if(!vis.count(n)){
                vis.insert(n);
                q.push({n,cur.second+1});
                added++;
            }
        }
    }
    return {-1,added};
}

pair<int,int> astar(string start,int type) {
    priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> pq;
    unordered_map<string,int> dist;
    int added=1;

    int h = (type==1? h1(start):h2(start));
    pq.push({h,start});
    dist[start]=0;

    while(!pq.empty()){
        auto top=pq.top(); pq.pop();
        string cur=top.second;
        int g=dist[cur];
        if(cur==goal) return {g,added};

        for(string n:neighbors(cur)){
            int ng=g+1;
            if(!dist.count(n) || ng<dist[n]){
                dist[n]=ng;
                int hn=(type==1? h1(n):h2(n));
                pq.push({ng+hn,n});
                added++;
            }
        }
    }
    return {-1,added};
}

int main() {
    ifstream fin("puzzles.txt");
    ofstream fout("results.txt");

    string puzzle;

    while(fin>>puzzle){
        auto b=bfs(puzzle);
        auto a1=astar(puzzle,1);
        auto a2=astar(puzzle,2);

        fout<<puzzle<<" "
            <<b.first<<" "<<b.second<<" "
            <<a1.second<<" "
            <<a2.second<<endl;
    }

    return 0;
}