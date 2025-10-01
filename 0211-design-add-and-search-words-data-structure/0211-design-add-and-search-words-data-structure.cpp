class WordDictionary {
public:
    unordered_set<long long> nums;   // numeric encodings (safe)
    unordered_set<string> strs;      // fallback for overflowed words
    static const long long BASE = 27;
    static const long long MAXLL = LLONG_MAX;

    WordDictionary() {}

    void addWord(string wd) {
        long long num = 0;
        for (char ch : wd) {
            int d = (ch - 'a') + 1; // 1..26 (NO zero)
            // overflow check: num*BASE + d <= MAXLL
            if (num > (MAXLL - d) / BASE) {
                // can't encode safely -> store string fallback
                strs.insert(wd);
                return;
            }
            num = num * BASE + d;
        }
        nums.insert(num);
    }

private:
    // generate all numeric encodings for pattern (left-to-right).
    // if overflow would occur we set overflow=true and stop numeric generation.
    void genNumbers(const string &word, int i, long long cur, vector<long long> &out, bool &overflow) {
        if (overflow) return;
        if (i == word.size()) {
            out.push_back(cur);
            return;
        }
        if (word[i] == '.') {
            for (int j = 1; j <= 26; ++j) {
                if (cur > (MAXLL - j) / BASE) { overflow = true; return; }
                genNumbers(word, i + 1, cur * BASE + j, out, overflow);
                if (overflow) return;
            }
        } else {
            int d = (word[i] - 'a') + 1;
            if (cur > (MAXLL - d) / BASE) { overflow = true; return; }
            genNumbers(word, i + 1, cur * BASE + d, out, overflow);
        }
    }

    bool matchesPattern(const string &pattern, const string &s) {
        if (pattern.size() != s.size()) return false;
        for (int i = 0; i < (int)s.size(); ++i)
            if (pattern[i] != '.' && pattern[i] != s[i]) return false;
        return true;
    }

public:
    bool search(string word) {
        vector<long long> candidates;
        bool overflow = false;
        genNumbers(word, 0, 0LL, candidates, overflow);

        // check numeric matches (if any were successfully generated)
        for (long long num : candidates) {
            if (nums.find(num) != nums.end()) return true;
        }

        // if numeric generation overflowed, or a long word was stored as string,
        // fall back to brute-force string matching against stored strings.
        if (overflow || !strs.empty()) {
            for (const auto &s : strs) {
                if (matchesPattern(word, s)) return true;
            }
        }

        return false;
    }
};
