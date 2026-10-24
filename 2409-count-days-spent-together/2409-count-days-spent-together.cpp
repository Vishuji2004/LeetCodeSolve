class Solution {
    vector<int> months = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> pre(months.size());
        pre[0] = 0;
        for(int i = 1; i < pre.size(); i++){
            pre[i] = pre[i-1] + months[i];
        }

        auto day = [&](const string& date) -> int{
            int m = stoi(date.substr(0, 2));
            int d = stoi(date.substr(3));

            return pre[m-1] + d;
        };

        return max(0, day(min(leaveAlice, leaveBob)) - day(max(arriveAlice, arriveBob)) + 1);
    }
};