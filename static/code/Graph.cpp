    #include<bits/stdc++.h>
    using namespace std;
    template<typename T>
    class Graph{
        map<T,list<T>> l;
        public:
        void add_edge(int x,int y)
        {
            l[x].push_back(y);
            // l[y].push_back(x);
        }
        void add_edge(string x,string y)
        {
            l[x].push_back(y);
            // l[y].push_back(x);
        }
        void bfs(T s)
        {
            map<T,bool> visited;
            queue<T> q;
            q.push(s);
            visited[s]=true;
            cout<<"BFS => ";
            while(!q.empty())
            {
                T node=q.front();
                q.pop();
                cout<<node<<" ";
                for(auto nbr: l[node])
                {
                    if(!visited[nbr])
                    {
                    q.push(nbr);
                    visited[nbr]=true;
                    }
                }
            }
        cout<<"\n";    
        }
        void min_dist(T s)
        {
            queue<T> q;
            map<T,int> dist;
            for(auto i:l)
            {
                T node=i.first;
                dist[node]=INT_MAX;
            }
            q.push(s);
            dist[s]=0;
            while(!q.empty())
            {
                T node=q.front();
                q.pop();
                for(auto nbr:l[node])
                {
                    if(dist[nbr]==INT_MAX)
                    {
                    q.push(nbr);
                    dist[nbr]=dist[node]+1;
                    }
                    
                }        
            }
            for(auto i:l)
            {
                T node=i.first;
                cout<<"Node "<<node<<" Dist from Source "<<dist[node]<<"\n";
            }
        }
        void snake_ans(T s,T d)
        {
            queue<T> q;
            map<T,int> dist;
            map<T,T> m;
            for(auto i:l)
            {
                T node=i.first;
                dist[node]=INT_MAX;
            }
            q.push(s);
            dist[s]=0;
            while(!q.empty())
            {
                T node=q.front();
                q.pop();
                for(auto nbr:l[node])
                {
                    if(dist[nbr]==INT_MAX)
                    {
                    q.push(nbr);
                    dist[nbr]=dist[node]+1;
                    m[nbr]=node;
                    }
                    
                }        
            }
            // for(auto i:l)
            // {
            //     T node=i.first;
            //     cout<<"Node "<<node<<" Dist from Source "<<dist[node]<<"\n";
            // }
            // cout<<dist[d]<<"\n";
            T temp=d;
            while(temp!=s)
            {
                cout<<temp<<"<--";
                temp=m[temp];
            }
        }
        void dfs_wrap(T s,map<T,bool> &m)
        {
            cout<<s<<" ";
            m[s]=true;
            for(auto i:l[s])
            {
                if(!m[i])
                dfs_wrap(i,m);
            }
        }
        void dfs_recursive(T s)
        {
            map<T,bool> visited;
            for(auto i:l)
            {
                T node=i.first;
                visited[node]=false;
            }
            dfs_wrap(s,visited);
            cout<<"\n";
        }
        void dfs_iterative(T src)
        {
            stack<T> s;
            map<T,bool> visited;
            s.push(src);
            visited[src]=true;
            while(!s.empty())
            {
                T node=s.top();
                s.pop();
                
                cout<<node<<" ";
                for(auto i:l[node])
                {   
                    if(!visited[i])
                    {
                    
                    s.push(i);
                    visited[i]=true;
                    }
                }

            }
        }
        void number_of_components()
        {
            map<T,bool> visited;
            for(auto i:l)
            {
                T node=i.first;
                visited[node]=false;
            }
            int count=0;
            for(auto p:l)
            {
                T node=p.first;
                if(!visited[node])
                {
                    cout<<"component "<<count<<" --> " ;              
                    dfs_wrap(node,visited);       
                    count++;
                    cout<<"\n";
                }
            }
        }
        void dfs_wrap_for_topological_sort(T node,map<T,bool> &m,list<T> &ordering)
        {
            // cout<<s<<" ";
            m[node]=true;
            for(auto i:l[node])
            {
                if(!m[i])
                dfs_wrap_for_topological_sort(i,m,ordering);
            }
            ordering.push_front(node);
            return;
        }
        void dfs_topological()
        {
            map<T,bool> visited;
            list<T> ordering;
            for(auto i:l)
            {
                T node=i.first;
                visited[node]=false;
            }
            for(auto p: l)
            {
                T node=p.first;
                if(!visited[node]){
                dfs_wrap_for_topological_sort(node,visited,ordering);
                }
            }
            for(auto node:ordering)
            cout<<node<<" ";
            cout<<"\n";
        }
        void bfs_topological()
        {
            T *indegree=new int[l.size()];
            for(auto i:l)
            {
                T node=i.first;
                indegree[node]=0;
            }
            for(auto p:l)
            {
                int x=p.first;
                for(auto y:p.second)
                indegree[y]++;
            }
            queue<T> q;
            for(auto i:l)
            {
                T node=i.first;
                if(indegree[node]==0)
                q.push(node);
            }
            while(!q.empty())
            {
                T node=q.front();
                cout<<node<<" ";
                q.pop();
                for(auto nbr:l[node])
                {
                    indegree[nbr]--;
                    if(indegree[nbr]==0)
                    q.push(nbr);
                }

            }

        }
        // function to check if undirected graph does'nt have any cycles(i.e. if it's a tree)
        // not a tree if a node is visited twice unless it's not a parent of current node
        // do a bfs and check the above condition
        bool is_Tree()
        {
            map<T,bool> visited;
            queue<T>q;
            map<T,T> parent;
            for(auto i:l)
            {
                T node=i.first;
                visited[node]=false;
            }
            T node_bhaiya;
            for(auto i:l)
            {
                node_bhaiya=i.first;
                break;

            }
            T src=node_bhaiya;
            q.push(src);
            visited[src]=true;
            while(!q.empty())
            {
                T node=q.front();
                q.pop();
                // cout<<node<<" ";
                for(auto nbr:l[node])
                {
                    if(visited[nbr]==true&&parent[node]!=nbr)
                    return false;
                    else if(!visited[nbr])
                    {
                        visited[nbr]=true;
                        parent[nbr]=node;
                        q.push(nbr);
                    }
                }
            }
            return true;



        }
        // detect cycle in a directed graph(using dfs)
        // basically if a graph has a backedge then it will have a cycle(backedge is an edge to ancestor from call stack of current node lying in  its path)
        bool cycle_helper(T node,map<T,bool> &visited,map<T,bool>& stack)
        {
            visited[node]=true;
            stack[node]=true;
            for(auto nbr:l[node])
            {
                if(stack[nbr]==true)
                return true;
                if(!visited[nbr])
                {
                    bool has_cycle=cycle_helper(nbr,visited,stack);
                    if(has_cycle)
                    return true;
                }
            }


            stack[node]=false;
            return false;
        }
        bool directed_contains_cycle()
        {
            map<T,bool> visited;
            map<T,bool>stack;
            T node_bhaiya;
            for(auto i:l)
            {
                node_bhaiya=i.first;
                break;

            }
            
            bool k=cycle_helper(node_bhaiya,visited,stack);
            return k;
            
        }
        // function to check if an undirected graph has cycle using dfs
        // logic remains same as bfs(i.e. if a noed is visited twice and it is not the parent of the current node)
        bool cycle_helper_dfs(T node,map<T,bool>& visited,T parent)
        {
            visited[node]=true;
            for(auto nbr:l[node])
            {
                if(!visited[nbr])
                {
                    bool has_cycle=cycle_helper_dfs(nbr,visited,node);
                    if(has_cycle) return true;
                }
                else if(nbr!=parent)
                return true;
            }
            return false;
        }
        bool contains_cycle_dfs()
        {
            map<T,bool> visited;
            for(auto i:visited)
            i.second=false;
            
            T node_bhaiya;
            for(auto i:l)
            {
                node_bhaiya=i.first;
                break;
            }
            bool k=cycle_helper_dfs(node_bhaiya,visited,node_bhaiya);
            return k;
        }
    };
    template<typename T>
    class Weighted_Graph{
        unordered_map<T,list<pair<T,int>>> m;
        
        public:
        void add_edge(T x,T y,int dist)
        {
        m[x].push_back(make_pair(y,dist));
        // if(bidir)
        m[y].push_back(make_pair(x,dist));
        }
        void dijkstra(T src)
        {
            unordered_map<T,int> dist;
            for(auto j:m)
            dist[j.first]=INT_MAX;
            set<pair<int,T>> s;
            dist[src]=0;
            s.insert(make_pair(0,src));
            while(!s.empty())
            {
                auto p=*(s.begin());
                T node=p.second;
                int node_distance=p.first;
                s.erase(s.begin());
                for(auto childpair:m[node])
                {
                    if(node_distance+childpair.second<dist[childpair.first])
                    {
                        T dest=childpair.first;
                        if(s.find(make_pair(dist[dest],dest))!=s.end())
                        s.erase(s.find(make_pair(dist[dest],dest)));
                        dist[dest]=node_distance+childpair.second;
                        s.insert(make_pair(dist[dest],dest));
                    }
                }

            }
            for(auto d:dist)
            {
                cout<<d.first<<" is located at a distance of "<<d.second<<"\n";
            }
        }
    };
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // Graph<int> g;
        // g.add_edge(0,1);    
        // g.add_edge(1,2);    
        // g.add_edge(2,3);    
        // g.add_edge(3,4);
        // g.add_edge(4,5);
        // g.add_edge(3,0);
        // g.dfs_recursive(0);
        // g.dfs_iterative(0);
        // g.bfs(0);    
        // g.min_dist(0);   
        // int board[50]={0};
        // board[2]=13; 
        // board[5]=2; 
        // board[9] =18;
        // board[18]=11; 
        // board[17]=-13; 
        // board[20]=-14; 
        // board[24] =-8;
        // board[25] =10;
        // board[32] =-2;
        // board[34] =-22;
        // Graph<int> snakes_and_ladder;
        // for(int i=0;i<=36;i++)
        // {
        //     for(int dice=1;dice<=6;dice++)
        //     {
        //         int j=i+dice;
        //         j+=board[j];
        //         if(j<=36)
        //         snakes_and_ladder.add_edge(i,j);
        //     }
        // }
        // snakes_and_ladder.add_edge(36,36);
        // snakes_and_ladder.snake_ans(0,36);
        // Graph<int> G;
        // G.add_edge(0,1);
        // G.add_edge(1,2);
        // G.add_edge(2,3);
        // G.add_edge(0,3);
        // G.add_edge(0,4);
        // G.add_edge(5,6);
        // G.add_edge(6,7);
        // G.add_edge(8,8);
        // gives number of connected components
        // G.number_of_components();
        // Graph<string> st;
        // st.add_edge("Python","DataPreprocessing");
        // st.add_edge("Python","PyTorch");
        // st.add_edge("Python","ML");
        // st.add_edge("DataPreprocessing","ML");
        // st.add_edge("PyTorch","DL");
        // st.add_edge("ML","DL");
        // st.add_edge("DL","FaceRecogn");
        // st.add_edge("DataSet","FaceRecogn");
        // st.dfs_topological();
        // Graph<int> G;
        // G.add_edge(0,2);
        // G.add_edge(1,2);
        // G.add_edge(1,4);
        // G.add_edge(2,3);
        // G.add_edge(2,5);
        // G.add_edge(4,5);
        // G.add_edge(3,5);
        // G.bfs_topological();
        // Graph<int> g;
        // g.add_edge(0,1);
        // g.add_edge(3,2);
        // g.add_edge(1,2);
        // g.add_edge(0,3);
        // g.is_Tree()?cout<<"Ye to tree hai":cout<<"Ye tree to nahi hai";
        // Graph<int> g;
        // g.add_edge(0,1);
        // g.add_edge(1,2);
        // g.add_edge(2,3);
        // g.add_edge(3,4);
        // g.add_edge(4,5);
        // g.add_edge(1,5);
        // g.add_edge(5,6);
        // g.add_edge(4,2);
        // g.directed_contains_cycle()?cout<<"YES":cout<<"NO";
        // Graph<int> g;
        // g.add_edge(0,1);
        // g.add_edge(1,2);
        // g.add_edge(2,3);
        // g.add_edge(3,4);
        // // g.add_edge(4,0);
        // if(g.contains_cycle_dfs()) cout<<"YES";else cout<<"NO";
        // Weighted_Graph<int> g;
        // g.add_edge(1,2,1);
        // g.add_edge(1,3,4);
        // g.add_edge(2,3,1);
        // g.add_edge(3,4,2);
        // g.add_edge(1,4,7);
        // g.dijkstra(1);

    return 0;
    }
    // basically topological sort gives us the dependancies between the nodes for example consider a graph containing various courses with prerequisites it basically gives us the list of courses in sorted order of prerequisites(indegrees)