class Solution {
public:
    string trafficSignal(int timer) 
    {
        if(timer<0 || timer>90 ||(timer<30 && timer>0))
        return "Invalid";
        if(timer>30 && timer<=90)
        return "Red";
        if(timer==30)
        return "Orange";
        return "Green";
        
    }
};