#include <bits/stdc++.h>
using namespace std;
int a[70][70]; //a[i][j]记录队伍i和队伍j是否比赛过了
int v[70];    //v[i]记录队伍i该天是否比赛过了
int main() {
    int n;
    cin >> n;
    int len = 1;
    for (int i = 1; i <= n; i++) {
        len *= 2; //len=队伍数2^n
    }
    for (int i = 0; i < len - 1; i++) {    //比赛天数2^n-1，也就是要输出的行数
        printf("<%d>", i + 1); //输出天数
        memset(v, 0, sizeof v);    //重置（新的一天每个队伍都是没有比过赛的）
        for (int j = 0; j < len / 2; j++) {    //每天n场，就是每行要输出几次比赛
            for (int k = 1; k <= len; k++) { //遍历所有队伍，找第一个参赛的队伍
                if (v[k] == 1) { //如果该天该队伍已经比赛过来，跳过
                    continue;
                }
                int judge = 0;    //判断k，h这两个队伍有没有比赛过
                for (int h = 1; h <= len; h++) { //遍历所有队伍，找第二个参赛的队伍
                    if (k == h) { //自己不能和自己比较
                        continue;
                    }
                    if (v[h] == 1)    { //如果该天该队伍已经比赛过来，跳过
                        continue;
                    }
                    if (a[k][h] == 0 && a[h][k] == 0) {    //h，k两队伍该天是否有一起比赛
                        printf("%d-%d ", k, h); //队伍k和队伍h比赛了
                        v[h] = 1;    //标记h队伍今天不再比赛比赛
                        v[k] = 1;    //标记k队伍今天不再比赛比赛
                        a[k][h] = 1;    //标记h和k今天已经比赛
                        judge = 1;    //标记第j场结束，跳到下一场
                        break;
                    }
                }
                if (judge == 1)    { //第j场结束，跳到下一场
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}