# 139_wordBreak

## my sol 1     20/6/25     60 min

FAIL

应该早点过来记录的...其实代码我写了30 min就写完了，后面30min都在debug，de一个while循环和if混淆的bug...

感觉有些递归逻辑对while和if的感觉要求很高，直觉一定要灵敏...

但是还是超时了，有些样例真是刁钻。

``` C++
class Solution {
private:
    set<string> dict;
public:
    bool findWord(int left, string s) {
        int right = left + 1;
        int len = s.length();
        if (left >= len) return false;
        while (right <= len && dict.find(s.substr(left, right - left)) == dict.end()) {
            right++;
        }
        if (right < len && dict.find(s.substr(left, right - left)) != dict.end()) {
            bool negret;
            while (right != len && (negret = !findWord(right, s))) {
                right++;
                while (right <= len && dict.find(s.substr(left, right - left)) == dict.end()) {
                    right++;
                }
                if (right > len) break;
            }
            if (right == len) return true;
            return !negret;
        } else if (right == len && dict.find(s.substr(left, right - left)) != dict.end()) {
            return true;
        } else if (right > len) {
            return false;
        }
        return false;   // ...为了应付oj的
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        if (wordDict.size() == 0) return false;
        for (string word : wordDict) {
            dict.insert(word);
        }
        return findWord(0, s);
    }
};
```

超时样例：
```
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
```
唉...

## my sol 2     20/6/25     10 min

FAIL

果然是治标不治本吗...

``` C++
class Solution {
private:
    set<string> dict;
public:
    bool findWord(int left, string s) {
        int right = left + 1;
        int len = s.length();
        if (left >= len) return false;
        while (right <= len && dict.find(s.substr(left, right - left)) == dict.end()) {
            right++;
        }
        if (right < len && dict.find(s.substr(left, right - left)) != dict.end()) {
            bool negret;
            while (right != len && (negret = !findWord(right, s))) {
                right++;
                while (right <= len && dict.find(s.substr(left, right - left)) == dict.end()) {
                    right++;
                }
                if (right > len) break;
            }
            if (right == len) return true;
            return !negret;
        } else if (right == len && dict.find(s.substr(left, right - left)) != dict.end()) {
            return true;
        } else if (right > len) {
            return false;
        }
        return false;   // ...为了应付oj的
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        if (wordDict.size() == 0) return false;
        
        //
        set<char> check;

        for (string word : wordDict) {
            // 
            for (char ch : word) {
                check.insert(ch);
            }
            dict.insert(word);
        }

        //
        for (char ch : s) {
            if (check.find(ch) == check.end()) return false;
        }
        return findWord(0, s);
    }
};
```

超时了...

错误样例：
``` 
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
["aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa","ba"]

```

## ref sol 1    20/6/25    

32 ms

13.3 mb

动态规划

状态转移方程：dp[i] = dp[j] && check(s[j..i-1])

对于边界条件，定义dp[0] = true表示空串且合法

``` C++
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto wordDictSet = unordered_set <string> ();
        for (auto word: wordDict) {
            wordDictSet.insert(word);
        }

        auto dp = vector <bool> (s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};
```

## my sol 3     20/6/26     10 min

4 ms    96.78%

7.5 mb  100%

剪枝效果很明显...

通过学习ref1然后加入剪枝写成的sol3

``` C++
#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> check;
        int maxLen = 0;
        for (string word : wordDict) {
            if (maxLen < word.length()) maxLen = word.length();
            check.insert(word);
        }

        vector<bool> dp(s.length()+1, false);
        dp[0] = true;
        for (int i = 1; i <= s.length(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (i - j > maxLen) break;
                if (dp[j] && check.find(s.substr(j, i - j)) != check.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};
```

这个动态规划的算法确实要比我的递归思想更快，因为它把前j个字符的是否合法的信息保存在了一个数组里，这样后面就不用重新调用计算了。而且剪枝也可以节省非常多的时间。

突然发现，我的算法说不定可以加入剪枝试试。


## my sol 4     20/6/26     5 min

FAIL

自己想办法在sol2的基础上加入了剪枝，但是由于原来写的代码可维护性太差了，导致出现了未知的逻辑错误...

已经不想搞这道题了，暂时就这样吧

``` C++
#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

class Solution {
private:
    set<string> dict;
    int maxLen = 0;
public:
    bool findWord(int left, string s) {
        int right = left + 1;
        int len = s.length();
        if (left >= len) return false;
        while (right <= len && dict.find(s.substr(left, right - left)) == dict.end()) {
            right++;
        }
        if (right < len && dict.find(s.substr(left, right - left)) != dict.end()) {
            bool negret;
            while (right != len && (negret = !findWord(right, s))) {
                right++;
                while (right <= len && dict.find(s.substr(left, right - left)) == dict.end()) {
                    right++;
                    if (right - left > maxLen) break;   // 剪枝
                }
                if (right > len) break;
                if (right - left > maxLen) break;   // 剪枝
            }
            if (right == len) return true;
            if (right - left > maxLen) return false;    // 剪枝
            return !negret;
        } else if (right == len && dict.find(s.substr(left, right - left)) != dict.end()) {
            return true;
        } else if (right > len) {
            return false;
        }
        return false;   // ...为了应付oj的
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        if (wordDict.size() == 0) return false;
        
        //
        // set<char> check;

        for (string word : wordDict) {
            // 
            // for (char ch : word) {
            //     check.insert(ch);
            // }
            dict.insert(word);
            if (maxLen < word.length()) maxLen = word.length();
        }

        //
        // for (char ch : s) {
        //     if (check.find(ch) == check.end()) return false;
        // }
        return findWord(0, s);
    }
};

int main() {
    // 0-8, 9-23, 24-30, 31-43
    string s = "fohhemkkaecojceoaejkkoedkofhmohkcjmkggcmnami";
    vector<string> wordDict = {"kfomka","hecagbngambii","anobmnikj","c","nnkmfelneemfgcl","ah","bgomgohl","lcbjbg","ebjfoiddndih","hjknoamjbfhckb","eioldlijmmla","nbekmcnakif","fgahmihodolmhbi","gnjfe","hk","b","jbfgm","ecojceoaejkkoed","cemodhmbcmgl","j","gdcnjj","kolaijoicbc","liibjjcini","lmbenj","eklingemgdjncaa","m","hkh","fblb","fk","nnfkfanaga","eldjml","iejn","gbmjfdooeeko","jafogijka","ngnfggojmhclkjd","bfagnfclg","imkeobcdidiifbm","ogeo","gicjog","cjnibenelm","ogoloc","edciifkaff","kbeeg","nebn","jdd","aeojhclmdn","dilbhl","dkk","bgmck","ohgkefkadonafg","labem","fheoglj","gkcanacfjfhogjc","eglkcddd","lelelihakeh","hhjijfiodfi","enehbibnhfjd","gkm","ggj","ag","hhhjogk","lllicdhihn","goakjjnk","lhbn","fhheedadamlnedh","bin","cl","ggjljjjf","fdcdaobhlhgj","nijlf","i","gaemagobjfc","dg","g","jhlelodgeekj","hcimohlni","fdoiohikhacgb","k","doiaigclm","bdfaoncbhfkdbjd","f","jaikbciac","cjgadmfoodmba","molokllh","gfkngeebnggo","lahd","n","ehfngoc","lejfcee","kofhmoh","cgda","de","kljnicikjeh","edomdbibhif","jehdkgmmofihdi","hifcjkloebel","gcghgbemjege","kobhhefbbb","aaikgaolhllhlm","akg","kmmikgkhnn","dnamfhaf","mjhj","ifadcgmgjaa","acnjehgkflgkd","bjj","maihjn","ojakklhl","ign","jhd","kndkhbebgh","amljjfeahcdlfdg","fnboolobch","gcclgcoaojc","kfokbbkllmcd","fec","dljma","noa","cfjie","fohhemkka","bfaldajf","nbk","kmbnjoalnhki","ccieabbnlhbjmj","nmacelialookal","hdlefnbmgklo","bfbblofk","doohocnadd","klmed","e","hkkcmbljlojkghm","jjiadlgf","ogadjhambjikce","bglghjndlk","gackokkbhj","oofohdogb","leiolllnjj","edekdnibja","gjhglilocif","ccfnfjalchc","gl","ihee","cfgccdmecem","mdmcdgjelhgk","laboglchdhbk","ajmiim","cebhalkngloae","hgohednmkahdi","ddiecjnkmgbbei","ajaengmcdlbk","kgg","ndchkjdn","heklaamafiomea","ehg","imelcifnhkae","hcgadilb","elndjcodnhcc","nkjd","gjnfkogkjeobo","eolega","lm","jddfkfbbbhia","cddmfeckheeo","bfnmaalmjdb","fbcg","ko","mojfj","kk","bbljjnnikdhg","l","calbc","mkekn","ejlhdk","hkebdiebecf","emhelbbda","mlba","ckjmih","odfacclfl","lgfjjbgookmnoe","begnkogf","gakojeblk","bfflcmdko","cfdclljcg","ho","fo","acmi","oemknmffgcio","mlkhk","kfhkndmdojhidg","ckfcibmnikn","dgoecamdliaeeoa","ocealkbbec","kbmmihb","ncikad","hi","nccjbnldneijc","hgiccigeehmdl","dlfmjhmioa","kmff","gfhkd","okiamg","ekdbamm","fc","neg","cfmo","ccgahikbbl","khhoc","elbg","cbghbacjbfm","jkagbmfgemjfg","ijceidhhajmja","imibemhdg","ja","idkfd","ndogdkjjkf","fhic","ooajkki","fdnjhh","ba","jdlnidngkfffbmi","jddjfnnjoidcnm","kghljjikbacd","idllbbn","d","mgkajbnjedeiee","fbllleanknmoomb","lom","kofjmmjm","mcdlbglonin","gcnboanh","fggii","fdkbmic","bbiln","cdjcjhonjgiagkb","kooenbeoongcle","cecnlfbaanckdkj","fejlmog","fanekdneoaammb","maojbcegdamn","bcmanmjdeabdo","amloj","adgoej","jh","fhf","cogdljlgek","o","joeiajlioggj","oncal","lbgg","elainnbffk","hbdi","femcanllndoh","ke","hmib","nagfahhljh","ibifdlfeechcbal","knec","oegfcghlgalcnno","abiefmjldmln","mlfglgni","jkofhjeb","ifjbneblfldjel","nahhcimkjhjgb","cdgkbn","nnklfbeecgedie","gmllmjbodhgllc","hogollongjo","fmoinacebll","fkngbganmh","jgdblmhlmfij","fkkdjknahamcfb","aieakdokibj","hddlcdiailhd","iajhmg","jenocgo","embdib","dghbmljjogka","bahcggjgmlf","fb","jldkcfom","mfi","kdkke","odhbl","jin","kcjmkggcmnami","kofig","bid","ohnohi","fcbojdgoaoa","dj","ifkbmbod","dhdedohlghk","nmkeakohicfdjf","ahbifnnoaldgbj","egldeibiinoac","iehfhjjjmil","bmeimi","ombngooicknel","lfdkngobmik","ifjcjkfnmgjcnmi","fmf","aoeaa","an","ffgddcjblehhggo","hijfdcchdilcl","hacbaamkhblnkk","najefebghcbkjfl","hcnnlogjfmmjcma","njgcogemlnohl","ihejh","ej","ofn","ggcklj","omah","hg","obk","giig","cklna","lihaiollfnem","ionlnlhjckf","cfdlijnmgjoebl","dloehimen","acggkacahfhkdne","iecd","gn","odgbnalk","ahfhcd","dghlag","bchfe","dldblmnbifnmlo","cffhbijal","dbddifnojfibha","mhh","cjjol","fed","bhcnf","ciiibbedklnnk","ikniooicmm","ejf","ammeennkcdgbjco","jmhmd","cek","bjbhcmda","kfjmhbf","chjmmnea","ifccifn","naedmco","iohchafbega","kjejfhbco","anlhhhhg"};
    Solution sol;
    cout << sol.wordBreak(s, wordDict);
    return 0;
}
```