#include <bits/stdc++.h>
using namespace std;

// 定义函数，返回一个元组，包含最小尝试次数、摔碎的总鸡蛋数和最后摔的鸡蛋是否摔碎
tuple<int, int, bool> solveWithInfo(int h, int m) {
    // 边界情况处理：当楼层数和鸡蛋数都小于1时，返回初始值
    if (h < 1 && m < 1) {
        return make_tuple(0, 0, false);  // 返回0次尝试、0个摔破的鸡蛋、最后摔的鸡蛋未摔破
    }

    // 初始化二维数组，用于动态规划的中间结果
    vector<vector<int>> f(m + 1, vector<int>(h + 1, 0));
    // 初始化二维数组，记录每次摔鸡蛋是否摔碎
    vector<vector<bool>> eggBroken(m + 1, vector<bool>(h + 1, false));

    // 使用动态规划解决蛋掉落问题
    for (int m_i = 2; m_i <= m; ++m_i) {
        for (int h_j = 1; h_j <= h; ++h_j) {
            for (int k = 1; k < h_j; ++k) {
                // 计算尝试次数，取最小值
                int attempts = 1 + max(f[m_i - 1][k - 1], f[m_i][h_j - k]);
                if (attempts < f[m_i][h_j]) {
                    f[m_i][h_j] = attempts;
                    eggBroken[m_i][h_j] = (k == h_j - 1);  // 记录摔鸡蛋是否摔碎
                }
            }
        }
    }

    // 获取结果
    int minAttempts = f[m][h];
    // 统计摔碎的鸡蛋数
    int totalBroken = count_if(eggBroken[m].begin(), eggBroken[m].end(), [](bool broken) { return broken; });
    // 获取最后一次摔的鸡蛋是否摔碎的信息
    bool lastEggBroken = eggBroken[m][h];

    // 返回结果的元组
    return make_tuple(minAttempts, totalBroken, lastEggBroken);
}

int main() {
    int h = 200;  // 楼层数
    int m = 2;   // 鸡蛋数

    // 调用函数获取结果
    auto result = solveWithInfo(h, m);

    // 输出结果
    cout << "最小尝试次数: " << get<0>(result) << endl;
    cout << "摔碎的总鸡蛋数: " << get<1>(result) << endl;
    cout << "最后摔的鸡蛋是否摔碎: " << boolalpha << get<2>(result) << endl;

    return 0;
}