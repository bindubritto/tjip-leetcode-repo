class Solution {
public:
    int romanToInt(string str) {
        
        unordered_map<char, int> roman;
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;
        
        int res = 0, i;
        
        for ( i = 0 ; i < str.length() - 1; i++){
            if(roman[str[i]] < roman[str[i+1]]){
                res -= roman[str[i]];
            }
            else{
                res += roman[str[i]];
            }
        }
        res += roman[str[i]];
        
        return res;
    }
};