#include<iostream>
#include<cstdio>
#include<list>
#include<queue>

using namespace std;

int main(){

        while(1)
        {
            int v,line;
            cout<<"Enter no. of Vertices & Number of inputs : ";
            scanf("%d%d",&v,&line);
            list<int> Adj[v+1];
            while(line--)
            {
                int v1,child;
                scanf("%d%d",&v1,&child);
                Adj[v1].push_back(child);
            }
            //for (list<int>::iterator it=Adj[1].begin(); it != Adj[1].end(); ++it){cout<<"  "<<*it;}
            bool color[v+1];
            int length[v+1];
            length[1] = 0;
            length[0] = 0;
            for(int i = 0;i <= v; i++)color[i] = 0;
            queue<int> q;
            q.push(1);
            color[1] = 1;
            while(!q.empty()){
                int i = q.front();
                //cout << i << endl;
                q.pop();
                for(list<int>::iterator it = Adj[i].begin(); it != Adj[i].end(); ++it){
                        if(!color[*it]){
                            q.push(*it);
                            color[*it] = 1;
                            length[*it] = 1 + length[i];
                        }
                }

            }
            cout << length[v] << endl;

        }
}
