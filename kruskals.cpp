void kruskals_mst() 
    { 
        // Sort all edges 
        sort(edgelist.begin(), edgelist.end()); 
  
        // Initialize the DSU 
        DSU s(V); 
        int ans = 0; 
        cout << "Following are the edges in the "
                "constructed MST"
             << endl; 
        for (auto edge : edgelist) { 
            int w = edge[0]; 
            int x = edge[1]; 
            int y = edge[2]; 
  
            // Take this edge in MST if it does 
            // not forms a cycle 
            if (s.find(x) != s.find(y)) { 
                s.unite(x, y); 
                ans += w; 
                cout << x << " -- " << y << " == " << w 
                     << endl; 
            } 
        } 
        cout << "Minimum Cost Spanning Tree: " << ans; 
    } 
}; 
  