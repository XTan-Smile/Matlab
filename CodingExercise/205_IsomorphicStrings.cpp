class Solution {
public:
    bool isIsomorphic(string s, string t) {
        /*** hash table ***/
        int lenStr = s.length();
        if (lenStr != t.length()) return false;
        std::unordered_map<char, int> hashS;
        std::unordered_map<char, int> hashT;
        std::unordered_map<char, int>::const_iterator itS, itT;
        for (int i = 0; i < lenStr; i++) {
            itS = hashS.find(s[i]);
            itT = hashT.find(t[i]);
            if (itS == hashS.end() && itT == hashT.end()) {
                hashS[s[i]] = i;
                hashT[t[i]] = i;
            }
            else if (itS == hashS.end()) return false;
            else if (itT == hashT.end()) return false;
            else {
                if (hashS[s[i]] - hashT[t[i]] != 0)
                    return false;
            }
        }
        return true;
        /*** hash table end ***/
        /*** using char arrays ***/
        int lenStr = s.length();
        if (lenStr != t.length()) return false;
        char strS[256] = {0};
        char strT[256] = {0};
        for (int i = 0; i < lenStr; i++) {
            if (strS[s[i]] == 0 && strT[t[i]] == 0) {
                strS[s[i]] = t[i];
                strT[t[i]] = s[i];
            }
            else if (strS[s[i]] == 0) return false;
            else if (strT[t[i]] == 0) return false;
            else {
                if (strS[s[i]] != t[i])
                    return false;
            }
        }
        return true;
        /*** using char arrays end ***/
    }
};