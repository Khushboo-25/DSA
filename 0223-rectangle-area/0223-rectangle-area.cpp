class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int a1=abs(ax1-ax2)*abs(ay1-ay2);
        int a2=abs(bx1-bx2)*abs(by1-by2);
        int mxx=min(ax2,bx2),mnx=max(ax1,bx1);
        int mxy=min(ay2,by2),mny=max(ay1,by1);
        // cout<<mxx<<" "<<mnx<<endl;
        // cout<<mxy<<" "<<mny<<endl;
        int cn=max(0,mxx-mnx)*max(0,mxy-mny);
        return a1+a2-cn;
    }
};