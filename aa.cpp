#include<iostream>
#include<cstdio>
#include<list>
#include<queue>

using namespace std;

class tree{
        private:
            int v,line;
            list<int> *Adj;

        public:

            tree(int a,int b){v = a; line = b; Adj = new list<int>[v+1];};

            void construct_tree(){
                while(line--){
                    int v1,child;
                    scanf("%d%d",&v1,&child);
                    Adj[v1].push_back(child);
                }
            }
            //for (list<int>::iterator it=Adj[1].begin(); it != Adj[1].end(); ++it){cout<<"  "<<*it;}
            int BFS(int a,int b){
                bool color[v+1];
                int length[v+1];
                length[a] = 0;
                length[0] = 0;
                for(int i = 0;i <= v; i++)color[i] = 0;
                queue<int> q;
                q.push(a);
                color[a] = 1;
                while(!q.empty()){
                    int i = q.front();
                    q.pop();
                    for(list<int>::iterator it = Adj[i].begin(); it != Adj[i].end(); ++it){
                            if(!color[*it]){
                                q.push(*it);
                                color[*it] = 1;
                                length[*it] = 1 + length[i];
                            }
                    }

                }
                return length[b];
        }
};

int main(){
    while(1){
        int v,line;
        cout<<"Enter no. of Vertices       Number of Edges : ";
        scanf("%d%d",&v,&line);
        tree t(v,line);
        t.construct_tree();
        int ans = t.BFS(1,4);
        cout<<ans<<endl;
    }
}
