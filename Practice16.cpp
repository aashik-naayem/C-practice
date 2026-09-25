class Solution {
public:
    string s;
    int pos;

    set<string> combine(set<string> a, set<string> b) {
        set<string> result;

        for (string x : a) {
            for (string y : b) {
                result.insert(x + y);
            }
        }

        return result;
    }

    set<string> parseExpression() {
        set<string> result;
        result.insert("");

        while (pos < s.size() && s[pos] != '}' && s[pos] != ',') {
            set<string> part;

            if (s[pos] == '{') {
                pos++;
                part = parseGroup();
                pos++;
            }
            else {
                string word = "";
                word += s[pos];
                pos++;
                part.insert(word);
            }

            result = combine(result, part);
        }

        return result;
    }

    set<string> parseGroup() {
        set<string> result;

        while (true) {
            set<string> part = parseExpression();

            result.insert(part.begin(), part.end());

            if (pos < s.size() && s[pos] == ',') {
                pos++;
            }
            else {
                break;
            }
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        pos = 0;

        set<string> result = parseExpression();

        return vector<string>(result.begin(), result.end());
    }
};