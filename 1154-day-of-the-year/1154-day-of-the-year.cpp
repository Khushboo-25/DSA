class Solution {
public:
// 1	January	31
// 2	February	28 (29 in leap years)
// 3	March	31
// 4	April	30
// 5	May	31
// 6	June	30
// 7	July	31
// 8	August	31
// 9	September	30
// 10	October	31
// 11	November	30
// 12	December	31
/*
If the year is divisible by four, it's a leap year. 
But if the year can be divided by 100 as well as four,
 it's not a leap year. However, 
if the year is divisible by 400, it is a leap year.
*/
bool leap(int y)
{
    if(y%4==0)
    {
        if(y%400==0)
        return 1;
        else if(y%100==0)
        return 0;
        else return 1;
    }
    return 0;
}
    int dayOfYear(string date) {
        vector<int>days={0,
            31,28,31,30,
            31,30,31,31,
            30,31,30,31
            };
        for(int i=1;i<13;i++)
        {
            days[i]+=days[i-1];
            // cout<<days[i]<<" ";
        }

        int year=0;
        for(int i=0;i<4;i++)
        {
            year=year*10+(date[i]-'0');
        }
        int mn=0;
        for(int i=5;i<7;i++)
        {
            mn=mn*10+(date[i]-'0');
        }
        int day=0;
        for(int i=8;i<10;i++)
        {
            day=day*10+(date[i]-'0');
        }
        // cout<<year<<" "<<mn<<" "<<day;
        int ans=days[mn-1]+day;
        if(leap(year) && mn>2)
        {
            ans++;
        }
        return ans;
        
    }
};