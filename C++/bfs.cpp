#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class vertex{
    public:
    int id=-1;
    int d=999999;
    vertex *p;
};
int ver = 0;
int ar[100][100];
vector<vertex*> v;
void bfs(int a){
    vertex *c;
    for(int i=0;i<ver;i++){
        c->id = i;
        v.push_back(c);
    }
    v[a]->d=0;
    queue
}