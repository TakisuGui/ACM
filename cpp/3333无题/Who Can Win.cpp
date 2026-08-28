#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e18;
const int MOD=998244353;

class submission
{
public:
    string team_name;
    char prob_id;
    int time_;
    string result;

    bool operator<(submission& other)
    {
        return this->time_<other.time_;
    }
};

struct problem
{
    bool solve_before=false;
    int ac_time=0;
    int rej_before=0;

    bool has_unknow=false;
    int unknow_time=0;
    int rej_unk_time=0; // 第一次 Unknown 之前的 Rejected 总数（包含封榜前的）
};

class team
{
public:
    string name;
    problem probs[26];
    int solved=0;
    int time_=0;

    bool operator>=(team& a)
    {
        if(this->solved!=a.solved) return this->solved>a.solved;
        return this->time_<=a.time_;
    }
};

void solve()
{
    int s; cin>>s;
    vector<submission> subs(s);
    map<string,int> team_map; 
    vector<team> teams;

    for(int i=0;i<s;i++)
    {
        cin>>subs[i].team_name>>subs[i].prob_id>>subs[i].time_>>subs[i].result;

        if(team_map.find(subs[i].team_name)==team_map.end())
        {
            team_map[subs[i].team_name]=teams.size();
            team new_team;
            new_team.name=subs[i].team_name;
            teams.push_back(new_team);
        }
    }

    sort(subs.begin(),subs.end());

    for(int i=0;i<s;i++)
    {
        int t_id=team_map[subs[i].team_name];
        int p_id=subs[i].prob_id-'A';
        int t_time=subs[i].time_;
        auto& p=teams[t_id].probs[p_id];

        if(subs[i].result=="Accepted")
        {
            if(!p.solve_before)
            {
                p.solve_before=true;
                p.ac_time=t_time;
            }
        }
        else if(subs[i].result=="Rejected")
        {
            if(!p.solve_before) p.rej_before++;
        }
        else if(subs[i].result=="Unknown")
        {
            if(!p.solve_before&&!p.has_unknow)
            {
                p.has_unknow=true;
                p.unknow_time=t_time;
                p.rej_unk_time=p.rej_before;
            }
        }
    }
    int n=teams.size();

    vector<team> worst_teams=teams;
    for(int i=0;i<n;i++)
    {
        worst_teams[i].solved=0;
        worst_teams[i].time_=0;
        for(int p=0;p<26;p++)
        {
            if(worst_teams[i].probs[p].solve_before)
            {
                worst_teams[i].solved++;
                worst_teams[i].time_+=worst_teams[i].probs[p].ac_time+worst_teams[i].probs[p].rej_before*20;
            }
        }
    }

    vector<string> possible_champions;

    for(int i=0;i<n;i++)
    {
        team best_x=teams[i];
        best_x.solved=0;
        best_x.time_=0;

        for(int p=0;p<26;p++)
        {
            if(best_x.probs[p].solve_before)
            {
                best_x.solved++;
                best_x.time_+=best_x.probs[p].ac_time+best_x.probs[p].rej_before*20;
            }
            else if(best_x.probs[p].has_unknow)
            {
                best_x.solved++;
                best_x.time_+=best_x.probs[p].unknow_time+best_x.probs[p].rej_unk_time*20;
            }
        }

        bool can=true;
        for(int j=0;j<n;j++)
        {
            if(i==j) continue;
            if(!(best_x>=worst_teams[j]))
            {
                can=false;
                break;
            }
        }
        if(can)
        {
            possible_champions.push_back(teams[i].name);
        }
    }

    sort(possible_champions.begin(),possible_champions.end());
    for(auto& x : possible_champions) cout<<x<<" ";
    cout<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}