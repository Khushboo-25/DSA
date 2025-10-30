#include <bits/stdc++.h>
using namespace std;

class TextEditor {
public:
    string left, right;

    TextEditor() {}

    void addText(string text) {
        left += text;
    }

    int deleteText(int k) {
        int del = min(k, (int)left.size());
        left.erase(left.size() - del, del);
        return del;
    }

    string cursorLeft(int k) {
        int move = min(k, (int)left.size());
        right = left.substr(left.size() - move, move) + right;
        left.erase(left.size() - move, move);
        return last10();
    }

    string cursorRight(int k) {
        int move = min(k, (int)right.size());
        left += right.substr(0, move);
        right.erase(0, move);
        return last10();
    }

private:
    string last10() {
        int len = min(10, (int)left.size());
        return left.substr(left.size() - len, len);
    }
};
