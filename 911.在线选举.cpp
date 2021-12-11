class TopVotedCandidate {
public:
    vector<int> win;
    vector<int> times;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        unordered_map<int, int> cnt;

        int top = 0;
        int ID = 0;
        for (int i = 0; i < persons.size(); i++)
        {
            cnt[persons[i]] ++;
            if (top <= cnt[persons[i]])
            {
                top = cnt[persons[i]];
                ID = persons[i];
            }
            win.push_back(ID);
        }
        this->times = times;
    }

    int q(int t) {
        int l = 0, r = times.size() - 1;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (times[mid] <= t) l = mid;
            else r = mid - 1;
        }

        return win[l];
    }
};