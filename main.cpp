    #include <bits/stdc++.h>
    #include "strstream"


    using namespace std;

    #define vc vector
    #define vi vector<int>
    #define vll vector<long long>
    #define vpii vector<pair<int, int>>
    #define vpll vector<pair<long long, long long>>
    #define pii pair<int, int>
    #define pll pair<long long, long long>
    #define pci pair<char, int>
    #define pcl pair<char, long long>
    #define psi pair<string, int>
    #define psl pair<string, long long>
    #define el  endl
    #define ull unsigned long long
    #define ll long long

    #define pn cout << "no" << endl
    #define Pn cout << "No" << endl
    #define PN cout << "NO" << endl
    #define py cout << "yes" << endl
    #define Py cout << "Yes" << endl
    #define PY cout << "YES" << endl
    #define fi first
    #define se second

    #define voyager ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    // INT MAX = 2.147483647 x 10^(9)
    // LONG LONG MAX  = 9.223372036854799561 x 10^(18)

    int charToInt(char ch){
        return (ch - '0');
    }
    char intToChar( int digit){
        return (char)(digit + '0');
    }
    char toLower(char upper)
    {
        if(isupper(upper)) { return (char(upper + 32)); }
        return upper;
    }
    ll stringToInt(const string& strNum)
    {
        ll num=0, n=0;
        for (ll i = (ll)strNum.size()-1; i >=0 ; i--,n++){
            num += (strNum[i]-'0') * (ll)pow(10,n);
        }
        return num;
    }
    string intToString(ll num)
    {
        strstream s; s << num;
        string str ; s >> str;
        return str;
    }
    template<typename T>
    void print(T array[], int size, char dilm=' ', char end='\n')
    {
        // if {size} is greater than the real size, this will lead to unexpected behaviour.
        if(size)
        {
            for (int i = 0; i < size-1; ++i) {
                cout << array[i] << dilm;
            }
            cout << array[size-1] << end;
        }
    }
    template<typename T>
    void print(vector<T> vect, char dilm=' ', char end='\n')
    {
        if(!vect.empty()) {
            for (int i = 0; i < vect.size() - 1; ++i) { cout << vect[i] << dilm; }
            cout << vect.back() << end;
        }
    }
    template<typename T>
    void print(list<T> lst, char dilm=' ', char end='\n')
    {
        if(lst.size()) {
            int ctr = 0;
            for (const auto &i: lst) {
                ctr++;
                if (ctr == lst.size()) { break; }
                cout << i << dilm;
            }
            cout << lst.back() << end;
        }
    }
    template<typename T>
    void print(deque<T> deq, char dilm=' ', char end='\n')
    {
        if(deq.size()) {
            int ctr = 0;
            for (const auto &i: deq) {
                ctr++;
                if (ctr == deq.size()) { break; }
                cout << i << dilm;
            }
            cout << deq.back() << end;
        }
    }
    template <typename first,typename second>
    void print(pair<first, second> pair, char dilm=' ', char end='\n')
    {
        cout << pair.first << dilm << pair.second << end;
    }
    // ---------------------------------------------------------------
    template<typename T>
    void read(vector<T>& vect, int s=0, int end=INT_MAX)
    {
        if(end==INT_MAX){end=vect.size()-1;}
        for (int i = 0; i <= end; ++i) { cin >> vect[i];}
    }
    // ---------------------------------------------------------------
    ll fastPower(ll x, ll n)
    {
        if(!x) { return 0; }
        if(x==1 || !n) { return 1; }
        long long powerOne=1;
        while (n>1) // if we used (n>=1) then we should return 'powerOne' only cause at the last step (x * powerOne) will be done and there is no need to re-multiplying it again
        {
            // if n is odd then n-1 will be even.
            if(n&1){powerOne *= x; n--;}
            x *= x;
            n >>=1;
        }
        return  x * powerOne;
    }
    // ---------------------------------------------------------------
    template<typename number>
    void preFixSum(vector<number>& source)
    {
        auto it= source.begin() + 1;
        for( ; it < source.end(); it++)
            (*it)= *(it - 1) + (*it);
    }
    template<typename number>
    void preFixSum( const vector<number>& source, vector<number>& prefix_sum)
    {
        prefix_sum.resize(source.size());
        prefix_sum[0]=source[0];
        auto itSource= source.begin() + 1;
        auto itPrefix_sum= prefix_sum.begin() + 1;
        for( ; itSource < source.end(); itSource++,itPrefix_sum++)
            (*itPrefix_sum)= *(itPrefix_sum - 1) + (*itSource);
    }
    // ---------------------------------------------------------------
    // Bit Manipulation
    template<typename T>
    bool check(int i, T mask){ return ( (mask >> i) & 1 ) ; }
    template<typename T>
    void setDigit(bool val,int i, T& mask)
    {
        if(val){ mask |= (1ll<<i); }
        else{ mask &=(~(1ll<<i)); }
    }
    template<typename T>
    void flip(int i, T& mask){ mask ^= (1ll<<i); }
    template<typename T>
    T countOnes(T mask)
    {
        T ctr=0;
        for(T i=0;(1ll<<i)<=mask;i++){if(check(i)){ctr++;}}
        return ctr;
    }
    // ---------------------------------------------------------------
    bool isPrimeRec(ll num)
    {
        if (num<=1)
            return 0;
        static ll div= 1;
        div++;
        if((div*div)>num) {div = 1;return true;}
        if(num%div==0) {div = 1;  return false;}
        return isPrimeRec(num);
    }
    bool isPrimeItr(ll num)
    {
        if(num==2){return true;}
        if ((num<=1) || !(num&1)) { return 0; }
        for (int i = 2; (i*i) <=num ; ++i) { if(num%i ==0){return false;}}
        return true;
    }
    // ---------------------------------------------------------------
    ll gcd(ll a, ll b){return (b? gcd(b,a%b):a);}
    // ---------------------------------------------------------------
    ll lcm(ll a, ll b){return (a/gcd(a,b) * b);}

    // ---------------------------------------------------------------
    /*ll nCrMod(ll n , ll r, ll m)
    {
        // if this function will be called many times you should make
        // factMod[max com_num] global and fill it one time to avoid time limit
        if(n<r){return 0;}
        ll factMod[n+1];
        factMod[0]=1;
        for (int i = 1; i <=n ; i++) { factMod[i] = ((factMod[i-1]%m )*(i%m)) % m; }
        return ((factMod[n]*modInverseFermat(factMod[r],m))%m * modInverseFermat(factMod[n-r], m))%m; // we did not use % with modInverse case it does it by itself
    }*/
    //-----------------------------------------------------------------------------------
    const int mod = 1e9+7, base = 53, base2=57;
    const ll N = 1e6+10, inf = 1e15;
    vector<vector<pll>> graph(N);
    vector<bool> vis(N,0);

    // ---------- for grid--------------
    vector<vector<int>> cost(1000+10,vector<int>(1000+10));
    pii get_r_c(int x, int colNum)
    {
        // x must be one based and r , c must be zero based
        int i = ceil((double)x / colNum) - 1;
        int j;
        if(x % colNum == 0){ j= colNum - 1;}else{ j = (x % colNum) - 1;}

        return {i,j};
    }
    int get_x(int i, int j, int colNum)
    {
        // x must be one based and r , c must be zero based
        return (i * colNum + j + 1);
    }
    bool isvalid(int i, int j, int rowNum, int colNum)
    {
        // n is the size of the square grid
        return (i>=0 && i<rowNum  && j>=0 && j<colNum);
    }
    ll get_weight(int src, int dis, int colnum)
    {
        pll s = get_r_c(src, colnum);
        pll d = get_r_c(dis, colnum);
        return 0;
    }
    vpll get_adj(ll node, int rowNum, int colNum)
    {
        auto p = get_r_c(node, colNum);
        int i = p.fi, j=p.se;

        vi dx = {-1, 1, 0, 0};
        vi dy = {0 , 0,-1, 1};
        vpll ans;
        for (int ii = 0; ii < dx.size(); ++ii)
        {
            int ni = i+dx[ii], nj = j+dy[ii];
            if(isvalid(ni, nj, rowNum, colNum)) {
                ll dis = get_x(ni, nj, colNum);
                ll cost = ::cost[ni][nj];
                //cout << dis << " ";
                ans.push_back({cost, dis}); }
        }

        return ans;
    }
    vll dijkstra4grid(ll src, int rowNum, int colNum )
    {
        vector<ll> dist(N,-1);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

        pq.push({cost[0][0], src});

        while(!pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            ll parent_node = p.se;
            ll parent_dist = p.fi;

            if(dist[parent_node] != -1){ continue; }
            dist[parent_node] = parent_dist;

            for (auto ch: get_adj(parent_node,rowNum, colNum))
            {
                ll child = ch.se;
                ll child_dist = ch.fi + parent_dist;
                if(dist[child] == -1)
                {
                    pq.push({child_dist, child});
                }
            }
        }


        return dist;
    }
    // --------------------------------
    //vector<int> cost(N,-1);
    //vector<vi> cost_2d(5e2 + 10, vector<int>(5e2 + 10, -1));
    vll dijkstra(int src)
    {
        // make this globl
        vector<vpll> graph(N);

        /// Dijkstra, // first time is the beast time
        vll cost(N, -1);
        priority_queue <pll, vector<pll>, greater<pll> > pq;
        pq.emplace(0, src);
        while(!pq.empty())
        {
            auto p = pq.top();  pq.pop();
            ll node = p.second, nodeCost = p.first;

            if(cost[node] != -1) { continue ;} // first time is the beast time

            cost[node] = nodeCost;
            for(auto edge: graph[node]) {
                ll child = edge.fi;
                ll edgeCost = edge.se ;
                ll newcost = nodeCost + edgeCost;

                if (cost[child] == -1) // if it did not enter the pq before
                {
                    pq.emplace(newcost, child);
                }
            }
        }


        return cost;

    }
    /*

    vi shortestPath(int head, int target)
    {
        vi parent(N, -1);
        queue<int> q;
        q.push(head);
        vis[head]=1;
        while (q.size())
        {
            int parent_node = q.front();    q.pop();
            for (int ch: graph[parent_node]) {
                if(!vis[ch]){
                    vis[ch]=1;
                    parent[ch] = parent_node;
                    q.push(ch);
                }
            }
        }

        vi path;
        for (int i = target; i !=-1 ; i = parent[i]) { path.push_back(i); }
        reverse(path.begin(), path.end());

        return path;
    }
    vi shortestPathCost(int head)
    {
        vi cost(N, -1);
        queue<int> q;
        q.push(head);
        cost[head]=0;
        while (q.size())
        {
            int parent_node = q.front();    q.pop();
            int parent_cost = cost[parent_node];
            for (int ch: graph[parent_node]) {
                if(cost[ch] == -1){
                    cost[ch] = parent_cost+1;
                    q.push(ch);
                }
            }
        }

        return cost;
    }
    vi shortestPathCost(const vi& heads)
    {
        vi cost(N, -1);
        queue<int> q;
        for (auto h:heads) {
            q.push(h);
            cost[h] = 0;
        }
        while (q.size())
        {
            int parent_node = q.front();    q.pop();
            int parent_cost = cost[parent_node];
            for (int ch: graph[parent_node]) {
                if(cost[ch] == -1){
                    cost[ch] = parent_cost+1;
                    q.push(ch);
                }
            }
        }

        return cost;
    }
    vector<pii> getAdj(pii pr, int n, int m)
    {
        vector<pii> adj;
        vi dr ={-1,1, 0,0}; // up , down, left ,right
        vi dc ={0 ,0,-1,1};
        for (int i = 0; i < dr.size(); ++i) {
            int x = pr.fi + dr[i];
            int y = pr.se + dc[i];
            if((x >=1) && (x<=n) && (y >=1) && (y<=m) && grid[x][y]=='.'){ adj.emplace_back(x, y); }
        }
        return adj;
    }

    class dsu
    {
    public:
        const int N ;
        int n, base, com_num;
        vector<int> parent, parent_size;
        //----------------------
        vi sum, num;
        //----------------------
        explicit dsu(int n, int max_size, int base=1) : N(max_size), base(base), n(n), com_num(n)
        {
            parent.resize(N, 0);
            parent_size.resize(N, 0);
            //--------------------
            sum.resize(N);
            num.resize(N);
            //--------------------
            make_set();
        }
        void make_set()
        {
            for (int i = base; i <=n ; ++i) {
                parent[i]=i;
                parent_size[i] = 1;
                //--------------------
                sum[i]= i;
                num[i]= 1;
                //--------------------
            }
        }

        int find(int node)
        {
            if(node == parent[node]){return node;}
            parent[node] = find(parent[node]);
            return parent[node];
        }
        bool same(int a, int b)
        {
            return (find(a) == find(b));
        }
        int get_size(int node)
        {
            int parent_node = find(node);
            return parent_size[parent_node];
        }

        int union_set(int a, int b)
        {
            // if a and in the same set return false
            if(same(a, b)){ return false;}
            if(get_size(b) > get_size(a)){ swap(a, b);}

            int a_parent = find(a);
            int b_parent = find(b);

            parent_size[a_parent] += get_size(b_parent);
            parent[b_parent] = a_parent;

            //--------------------
             sum[a_parent] +=  sum[b_parent];
             num[a_parent] +=  num[b_parent];
            //--------------------

            com_num--;
            return true;
        }
        int union_set(pii a_b){ return union_set(a_b.fi, a_b.second); }

        void move(int a, int b)
        {
            // this moves a to b
            if(same(a, b)){ return;}
            int a_par= find(a);
            int b_par= find(b);

            parent[a] = b_par;

            num[a_par]--;
            sum[a_par]-= a;

            num[b_par]++;
            sum[b_par]+= a;
        }
    };
    class edge
    {
    public:
        int  a, b, cost;
        edge(int a, int b, int cost): cost(cost), a(a), b(b){}
        edge(pii a_b, int cost): cost(cost), a(a_b.fi), b(a_b.se){}
        edge() = delete;
        static bool comp(edge edg1, edge edg2) { return (edg1.cost < edg2.cost); }

    };

    vector<edge> mst(vector<edge>& edges, int n)
    {
        vector<edge> ans;
        dsu ds(n,N,1);

        std::sort(edges.begin(), edges.end(),edge::comp); // [](edge a, edge b)->bool{return (a.cost < b.cost);}

        for (auto edge:edges) {
            if(ds.same(edge.a, edge.b)){ continue;}

            ds.union_set(edge.a, edge.b);
            ans.push_back(edge);
        }

        return ans;
    }

    */

    //---------------------S-t-r-i-n-g----H-a-s-h-i-n-g-----------------------
    int pw[N], inv[N];
    int pw2[N] , inv2[N];
    int add( int a , int b)
    {
        return (0LL + a + mod + b) %mod;
    }
    int mul ( int a , int b)
    {
        return 1LL * a * b %mod;
    }
    int fastpow( int b , int p)
    {
        if(!p)
            return 1;
        int temp = fastpow(b , p >> 1);
        temp = mul(temp,temp);
        if(p&1)
            temp = mul(temp,b);
        return temp;
    }
    // pre() is called once before all test cases
    void pre()
    {
        pw[0] = 1, inv[0] = 1;
        pw2[0] = 1, inv2[0] = 1;
        for ( int i = 1 ; i < N ; i++)
        {
            pw[i] = mul(base,pw[i-1]);
            inv[i] = fastpow(pw[i],mod-2);
            pw2[i] = mul(base2,pw2[i-1]);
            inv2[i] = fastpow(pw2[i],mod-2);
        }
    }
    // pre-calculating hash values for all substrings
    int pref[N], pref2[N];
    void generateHash( string &str)
    {
        for ( int i = 0 ; i < str.size() ; i++)
        {
            int idx = str[i] - 'a' + 1;
            pref[i] = mul(idx , pw[i]);
            if(i)
                pref[i] = add(pref[i],pref[i-1]);
            pref2[i] = mul(idx , pw2[i]);
            if(i)
                pref2[i] = add(pref2[i],pref2[i-1]);
        }
    }
    pair < int , int > getHash( string &str)
    {
        int hashValue = 0, hashValue2=0;
        for ( int i = 0 ; i < str.size() ; i++)
        {
            int idx = str[i] - 'a' + 1;
            hashValue = add(hashValue,mul(idx , pw[i]));
            hashValue2 = add(hashValue2,mul(idx , pw2[i]));
        }
        return {hashValue,hashValue2};
    }
    pair < int , int >  getHash( int l , int r)
    {
        int ret = pref[r];
        if(l)
            ret = add(ret , - pref[l-1]);
        ret = mul(ret, inv[l]);

        int ret2 = pref2[r];
        if(l)
            ret2 = add(ret2 , - pref2[l-1]);
        ret2 = mul(ret2, inv2[l]);
        return {ret,ret2};
    }
    struct hasher
    {
        int pref[N], pref2[N];
        void generateHash( string &str){
        for ( int i = 0 ; i < str.size() ; i++)
        {
            int idx = str[i] - 'A' + 1;
            pref[i] = mul(idx , pw[i]);
            if(i)
                pref[i] = add(pref[i],pref[i-1]);
            pref2[i] = mul(idx , pw2[i]);
            if(i)
                pref2[i] = add(pref2[i],pref2[i-1]);
        }
    }
        pair < int , int >  getHash( int l , int r)
        {
            int ret = pref[r];
            if(l)
                ret = add(ret , - pref[l-1]);
            ret = mul(ret, inv[l]);

            int ret2 = pref2[r];
            if(l)
                ret2 = add(ret2 , - pref2[l-1]);
            ret2 = mul(ret2, inv2[l]);
            return {ret,ret2};
        }
    };




    // --------------------------------------------------------------
    int sp[N][25], lg[N],  a[N];
    int merge(int a , int b)
    {
        return min(a , b);
    }

    void build_sparse_table(int n)
    {
        // O(nlog(n))
        // zero based
        lg[0] = lg[1] = 0;
        for ( int i = 2 ; i <= n ; i++)
            lg[i] = lg[i>>1] + 1 ;

        for ( int i = 0 ; i < n ; i++)
            sp[i][0] = a[i];

        for ( int j = 1 ; j < 21 ; j++)
            for ( int i = 0 ; i + (1<<j) <= n ; i++)
                sp[i][j] = merge(sp[i][j-1] , sp[i + (1<<(j-1))][j-1]);
    }

    int query( int l , int r)
    {
        // O(1)
        // zero based
        int k = lg[r-l+1];
        return merge(sp[l][k], sp[r-(1<<k)+1][k]);
    }



    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0, r =numbers.size()-1;
        vector<int> ans(2);
        while (l<r){
            //cout << l <<  ' ' << r << endl;
            if(numbers[l]+numbers[r] == target){
               // cout << l <<  ' ' << r << endl;
                return vector<int>({ l+1, r+1})  ;
            }else if(numbers[l]+numbers[r] < target){
                l++;
            }else{
                r--;
            }

        }
        return ans;

    }




    void solve(int testCase){

        vi input({2,7,11,15});

        print(twoSum(input, 9));

    }


    int main()
    {

        /////////
        voyager
        /////////




        // pre();
        int tc=1;
//        cin >> tc;
        for (int i = 1; i <= tc; ++i) {
            solve(i);
        }



        ////////// end main
        return 0;


    }




