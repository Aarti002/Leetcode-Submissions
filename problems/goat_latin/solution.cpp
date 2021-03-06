class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'A' ||
                ch == 'e' || ch == 'E' ||
                ch == 'i' || ch == 'I' ||
                ch == 'o' || ch == 'O' ||
                ch == 'u' || ch == 'U');
    }
    string toGoatLatin(string S) {
        string temp = "";
        vector<string> words;
        for(char ch:S) {
            if(ch == ' ') {
                words.push_back(temp);
                temp = "";
            } else {
                temp += ch;
            }
        }
        words.push_back(temp);

        int len = 0;
        string a_string = "a";
        for(int i = 0; i<words.size(); i++) {
            len = words[i].length();
            if(isVowel(words[i][0])) {
                words[i] += "ma";
                words[i] += a_string;
            } else {
                words[i].push_back(words[i][0]);
                words[i].erase(words[i].begin());
                words[i] += "ma";
                words[i] += a_string;
            }
            a_string += "a";
        }
        S = "";
        for(string word:words) {
            S += word + " ";
        }
        S.erase(S.end()-1);
        return S;
    }
};