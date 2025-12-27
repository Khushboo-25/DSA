class Solution {
public:
    string categorizeBox(int l,int w,int h,int m) 
    {
        bool hv=0,bl=0;
        long long vol=1;
        if(l>=1e4|| w>=1e4|| h>=1e4)
        bl=1;
        vol= 1ll*l*w*h;
        if(vol>=1e9)
        bl=1;
        if(m>=100)
        hv=1;
        if(bl && hv)
        return "Both";
        if(bl)
        return "Bulky";
        if(hv)
        return "Heavy";
        return "Neither";
        
    }
};