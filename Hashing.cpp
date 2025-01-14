#include <bits/stdc++.h>
using namespace std;

struct Hash {
    const int MOD = 1e9+9;
    const int BASE1 = 5689;
    const int BASE2 = 8861;

    vector<pair<int,int>> hashes , Pow;

    Hash(string s){
        hashes.assign(s.size() + 1 , {1,1});
        Pow.assign(s.size()+1,{1,1});

        for(int i=0;i<s.size();i++){
            hashes[i+1] = {
                (hashes[i].first * BASE1 + (s[i] -'a' + 1))%MOD , 
                 (hashes[i].second * BASE2 + (s[i] -'a' + 1))%MOD
            };
            Pow[i+1] = {
                (Pow[i].first * BASE1) % MOD,
                (Pow[i].second * BASE2) % MOD
            };
        }
    }
    pair<int,int> get(int l , int r){
        l++;
        r++;

        int hash1 = (hashes[r].first - (hashes[l-1].first * Pow[r-l+1].first) % MOD + MOD ) % MOD;
        int hash2 = (hashes[r].second - (hashes[l-1].second * Pow[r-l+1].second) % MOD + MOD ) % MOD;
        return {hash1 , hash2};
    }
};

void harshit()
{
   
}

