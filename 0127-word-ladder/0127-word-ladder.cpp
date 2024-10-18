class Solution {
public:

    int ladderLength(string startWord, string targetWord,
                         vector<string> &wordList) 
    {
        
        queue<pair<string, int>> q;
        q.push({startWord, 1});
        unordered_map<string,int>st;
        for(auto it: wordList)
        {
            st[it]=INT_MAX;
        }
        st[startWord]=1;
        while (!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if (word == targetWord)
                return steps;

            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st[word]>steps+1)
                    {
                        st[word]=steps+1;
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};