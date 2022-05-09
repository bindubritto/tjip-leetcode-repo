
// Way - 01
class Solution {
public:
    bool isIsomorphic(string s, string t, int iteration_count = 0) {
        unordered_map<char, char> from;
        
        for(int i = 0; i < s.size(); i++){
            if (from.count(s[i]) && from[s[i]] != t[i] ) {
                return false;
            }
            from[s[i]] = t[i];
        }
        if (iteration_count == 0) return isIsomorphic(t, s, 1);
        return true;
    }
};

// Way - 02

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> from, to;
        
        for(int i = 0; i < s.size(); i++){
            if ((from.count(s[i]) && from[s[i]] != t[i] ) || (to.count(t[i]) && to[t[i]] != s[i] )) {
                return false;
            }
            from[s[i]] = t[i];
            to[t[i]] = s[i];
        }
        return true;
    }
};

