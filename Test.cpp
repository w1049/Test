#define dataFile "data.txt"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#define _pause cin.get(), cin.get()
using namespace std;
vector<string> lines;
inline void readFile(char* fileName) {
    FILE* f = fopen(fileName, "r");
    char buf[1024];
    while (fgets(buf, 1024, f) != NULL) lines.push_back(string(buf));
}
inline string getSentence(string inSentence) {
    int pos = inSentence.find(' '),
        len1 = pos,
        len2 = inSentence.length() - pos - 2;
    string res;
    if (rand() % 2) {
        res.resize(len2, '_');
        res = inSentence.substr(0, len1) + "，" + res + "。";
    } else {
        res.resize(len1, '_');
        res = res + "，" + inSentence.substr(pos + 1, len2) + "。";
    }
    return res;
}
int n;
int main() {
    std::ios::sync_with_stdio(false);
    srand((unsigned)time(0));
    readFile((char*)dataFile);
    while (1) {
        cout << "请输入生成个数:";
        cin >> n;
        if (cin.good()) {
            if (n > 100) {
                cout << "你确定吗?输入1确定,输入其他取消:";
                int k;
                cin >> k;
                if (k == 1) break;
            } else if (n > 0) break;
        } else cin.clear(), cin.ignore();
    }
    for (int i = 0; i < n; i++)
        cout << i + 1 << "、" << getSentence(lines[rand() % lines.size()]) << endl;
    cout << "生成完毕!\n\n";
    _pause;
    return 0;
}
