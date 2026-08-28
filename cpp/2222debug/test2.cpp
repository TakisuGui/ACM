#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll

struct Submission {
    string team_name;
    char prob_id;
    int time;
    string result;

    // 按时间升序排序
    bool operator<(const Submission& other) const {
        return time < other.time;
    }
};

struct problem {
    bool solve_before = false;
    int ac_time = 0;
    int rej_before = 0;

    bool has_unknow = false;
    int unknow_time = 0;
    int rej_unk_time = 0;
};

class team {
public:
    string name;
    problem probs[26];
    int solved = 0;
    int time_ = 0;

    bool operator>=(const team& a) const {
        if(this->solved != a.solved) return this->solved > a.solved;
        return this->time_ <= a.time_;
    }
};

void solve() {
    int s; 
    if(!(cin >> s)) return;

    vector<Submission> subs(s);
    map<string, int> team_map;
    vector<team> teams;

    for(int i = 0; i < s; i++) {
        cin >> subs[i].team_name >> subs[i].prob_id >> subs[i].time >> subs[i].result;
        
        if(team_map.find(subs[i].team_name) == team_map.end()) {
            team_map[subs[i].team_name] = teams.size();
            team new_team;
            new_team.name = subs[i].team_name;
            teams.push_back(new_team);
        }
    }

    // 关键点：将所有提交按时间升序排序！
    sort(subs.begin(), subs.end());

    // 按时间严格升序模拟
    for(int i = 0; i < s; i++) {
        int t_id = team_map[subs[i].team_name];
        int p_id = subs[i].prob_id - 'A';
        auto& p = teams[t_id].probs[p_id];
        int t_time = subs[i].time;
        string res = subs[i].result;

        if(res == "Accepted") {
            if(!p.solve_before) {
                p.solve_before = true;
                p.ac_time = t_time;
            }
        }
        else if(res == "Rejected") {
            if(!p.solve_before) {
                p.rej_before++;
            }
        }
        else if(res == "Unknown") {
            if(!p.solve_before && !p.has_unknow) {
                p.has_unknow = true;
                p.unknow_time = t_time;
                p.rej_unk_time = p.rej_before; // 因为已经按时间排序，这里的 rej_before 绝对准确
            }
        }
    }

    int n = teams.size();

    // 计算最差情况（所有 Unknown 当作 Rejected）
    vector<team> worst_teams = teams;
    for(int i = 0; i < n; i++) {
        worst_teams[i].solved = 0;
        worst_teams[i].time_ = 0;
        for(int p = 0; p < 26; p++) {
            if(worst_teams[i].probs[p].solve_before) {
                worst_teams[i].solved++;
                worst_teams[i].time_ += worst_teams[i].probs[p].ac_time + worst_teams[i].probs[p].rej_before * 20;
            }
        }
    }

    vector<string> possible_champions;

    // 计算最佳情况（Unknown 当作第一个 AC）
    for(int i = 0; i < n; i++) {
        team best_x = teams[i];
        best_x.solved = 0;
        best_x.time_ = 0;

        for(int p = 0; p < 26; p++) {
            if(best_x.probs[p].solve_before) {
                best_x.solved++;
                best_x.time_ += best_x.probs[p].ac_time + best_x.probs[p].rej_before * 20;
            }
            else if(best_x.probs[p].has_unknow) {
                best_x.solved++;
                best_x.time_ += best_x.probs[p].unknow_time + best_x.probs[p].rej_unk_time * 20;
            }
        }

        bool can = true;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(!(best_x >= worst_teams[j])) {
                can = false;
                break;
            }
        }
        if(can) {
            possible_champions.push_back(teams[i].name);
        }
    }

    sort(possible_champions.begin(), possible_champions.end());
    
    // 规范输出，防止末尾多余空格
    for(size_t i = 0; i < possible_champions.size(); ++i) {
        cout << possible_champions[i] << (i + 1 == possible_champions.size() ? "" : " ");
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; 
    if(cin >> t) {
        while(t--) {
            solve();
        }
    }

    return 0;
}