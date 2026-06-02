class Solution {
public:
    

int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                       vector<int>& waterStartTime, vector<int>& waterDuration) {
    int minFinishTime = INT_MAX;

    for (int i = 0; i < landStartTime.size(); i++) {
        for (int j = 0; j < waterStartTime.size(); j++) {
            // Option 1: Land → Water
            int startLand = landStartTime[i];
            int finishLand = startLand + landDuration[i];
            int startWater = max(finishLand, waterStartTime[j]);
            int finish1 = startWater + waterDuration[j];

            // Option 2: Water → Land
            int startWater2 = waterStartTime[j];
            int finishWater2 = startWater2 + waterDuration[j];
            int startLand2 = max(finishWater2, landStartTime[i]);
            int finish2 = startLand2 + landDuration[i];

            minFinishTime = min({minFinishTime, finish1, finish2});
        }
    }

    return minFinishTime;
}

};