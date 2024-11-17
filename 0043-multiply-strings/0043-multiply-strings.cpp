class Solution {
public:
void trim(string &s)
{
    int n = s.size();
    while (n > 0)
    {
        if (s[n - 1] == '0')
            s.pop_back();
        else
            break;
        n--;
    }
    if (s == "")
        s = "0";
}

void update2(string prev, string &s1)
{
    trim(prev);
    trim(s1);
    int n2 = prev.size();
    int n1 = s1.size();
    int i = 0;
    int j = 0;
    int cr = 0;
    while (i < n1 && j < n2)
    {
        int mm = (s1[i] - '0') + (prev[j] - '0');
        int rm = (mm + cr) % 10;
        int c = (mm + cr) / 10;
        s1[i] = '0' + rm;
        cr = c;
        i++;
        j++;
    }
    while (i < n1)
    {
        int mm = (s1[i] - '0');
        int rm = (mm + cr) % 10;
        int c = (mm + cr) / 10;
        s1[i] = '0' + rm;
        cr = c;
        i++;
    }
    while (j < n2)
    {
        int mm = (prev[j] - '0');
        int rm = (mm + cr) % 10;
        int c = (mm + cr) / 10;
        s1 += '0' + rm;
        cr = c;
        j++;
    }
    if (cr > 0)
    {
        s1 += '0' + cr;
    }
}

void update(string &s1, char chr)
{
    int n1 = s1.size();
    int cr = 0;
    for (int i = 0; i < n1; i++)
    {
        int mm = (s1[i] - '0') * (chr - '0');
        int rm = (mm + cr) % 10;
        int c = (mm + cr) / 10;
        s1[i] = '0' + rm;
        cr = c;
    }
    if (cr > 0)
    {
        s1 += '0' + cr;
    }
}

    string multiply(string s1, string s2) {
    int str1 = 0, str2 = 0;
    if (s1[0] == '-')
    {
        str1 = 1;
        s1 = s1.substr(1);
    }
    if (s2[0] == '-')
    {
        str2 = 1;
        s2 = s2.substr(1);
    }

    int n1 = s1.size();
    int n2 = s2.size();
    
    // Edge case: multiplying by 0
    if (s1 == "0" || s2 == "0")
        return "0";

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    string prev = "";
    for (int i = 0; i < n2; i++)
    {
        string temp = s1; // Create a copy of s1 for each iteration
        update(temp, s2[i]);
        for (int j = 0; j < i; j++) // Shift left by appending zeroes
        {
            temp = '0' + temp;
        }
        update2(prev, temp);
        prev = temp;
    }

    reverse(prev.begin(), prev.end()); // Reverse the result back to normal

    if(prev=="" || prev=="0")
    return "0";
    // Handle sign of result
    if ((str1 + str2) % 2 == 1)
        return '-' + prev;
    
    return prev;
}
};