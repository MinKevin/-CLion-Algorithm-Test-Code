#include <codecvt>
#include <stdio.h>
#include "gtest/gtest.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <regex>
#include <locale>
#include "../algorithm-frame.h"

using namespace std;

inline std::string &ltrim(std::string &s, const char *t = " \t\n\r\f\v") {
    s.erase(0, s.find_first_not_of(t));
    return s;
}

// trim from right
inline std::string &rtrim(std::string &s, const char *t = " \t\n\r\f\v") {
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

inline std::string &trim(std::string &s, const char *t = " \t\n\r\f\v") {
    return ltrim(rtrim(s, t), t);
}

TEST(ALGORITHM_TEST, INTEGRATED_TEST) {
    setlocale(LC_ALL, "");
    string fileName = "../" + static_cast<string>(PROBLEM_FILE_NAME).append(".txt");
    cout << fileName << '\n';
    fstream file(fileName);

    string process = "input";
    if (file.is_open()) {
        stringstream ss;
        string inputBuffer;
        bool isOssInited = false;
        string line;
        while (getline(file, line)) {
            if (!trim(line).empty()) {
                if (process == "input") {
                    inputBuffer.append(line + "\n");
                } else if (process == "output") {
                    if (!isOssInited) {
                        ostringstream oss;
                        streambuf *streamBuf = cout.rdbuf();
                        cout.rdbuf(oss.rdbuf());

                        output();

                        cout.rdbuf(streamBuf);

                        ss.clear();
                        ss.str(oss.str());

                        isOssInited = true;
                    }
                    string line3;
                    getline(ss, line3);
                    trim(line3);
                    cout << line << ' ' << line3 << '\n';
                    EXPECT_EQ(line, line3);
                }
            } else {
                if (process == "input") {
                    process = "output";
                    istringstream iss(inputBuffer);
                    inputBuffer.clear();
                    cin.rdbuf(iss.rdbuf());
                    input();

                    solution();
                } else if (process == "output") {
                    process = "input";
                    isOssInited = false;
                }
            }
        }
        file.close();
    }
    else {
        cout << "파일이 없습니다.\n";
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
