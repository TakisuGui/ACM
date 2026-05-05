#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(),wordList.end());
        if(dict.find(endWord)==dict.end()) return 0;

        unordered_set<string> small_level;
        unordered_set<string> big_level;
        unordered_set<string> next_level;

        small_level.insert(beginWord);
        big_level.insert(endWord);

        for(int len=2;!small_level.empty();len++)
        {
            for(string w:small_level) // 遍历较小的一侧进行扩散
            {
                for(int j=0;j<w.length();j++) // 尝试修改单词的每一位
                {
                    char old=w[j];
                    for(char change='a';change<='z';change++)
                    {
                        if(change!=old)
                        {
                            w[j]=change;

                            // 如果在另一侧找到了，说明两头接通了，返回当前长度
                            if(big_level.find(w)!=big_level.end()) return len;

                            // 如果在字典中，则加入下一层，并从字典删除（防止重复访问）
                            if(dict.find(w)!=dict.end())
                            {
                                dict.erase(w);
                                next_level.insert(w);
                            }
                        }
                    }
                    w[j]=old; // 还原单词
                }
            }

            if(next_level.size()<=big_level.size())
            {
                small_level=next_level;
            }
            else
            {
                small_level=big_level;
                big_level=next_level;
            }
            next_level.clear();
        }

        return 0;
    }
};