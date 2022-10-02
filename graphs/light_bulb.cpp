    private static int solve(int[] bulbs, int[] dist){ 
        int N = bulbs.length;
        UF uf = new UF(N+1);
        List<int[]> edges = new ArrayList<>();
        for (int i = 0; i < N; i++){
            if (bulbs[i] == 1){
                uf.union(i, N);
            }else{
                if (i > 0){
                    edges.add(new int[]{dist[i]-dist[i-1], i, i-1});
                }else if (i < N-1){
                    edges.add(new int[]{dist[i+1]-dist[i], i, i+1});
                }
            }
        }
        if (uf.size() == N+1){
            return -1; // IMPOSSIBLE
        }
        int ans = 0;
        edges.sort(Comparator.comparingInt(o -> o[0]));
        for (int[] e : edges){
            int cost = e[0], v = e[1], u = e[2];
            if (uf.union(v, u)){
                ans += cost;
            }
        }
        return ans;
    }
