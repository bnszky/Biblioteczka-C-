//https://eduinf.waw.pl/inf/alg/001_search/0012.php
vector <bool> linear_sieve(int n){
    bool *S;
    S = new bool [ n + 1 ];
    
      for(int i = 2; i <= n; i++) S[i] = true;
      int p,q,x;
      p = 2;
      
      while(p * p <= n)
      {
        q = p;
        while(p * q <= n)
        {
          x = p * q;
          while(x <= n)
          {
            S[x] = false;
            x *= p;
          }
          while(!S[ ++q ]);
        }
        while(!S[ ++p ]);
      }
      
    vector<bool> v; v.resize(n+1);
    for(int i = 2; i <= n; i++) v[i] = S[i];
    delete []S;
    return v;
}