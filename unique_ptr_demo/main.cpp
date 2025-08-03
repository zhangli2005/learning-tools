#include "exercise.h"  // 修改为本地路径
#include <cstring>
#include <memory>
#include <string>
#include <vector>

std::vector<std::string> RECORDS;

class Resource {
    std::string _records;
public:
    void record(char record) { _records.push_back(record); }
    ~Resource() { RECORDS.push_back(_records); }
};

using Unique = std::unique_ptr<Resource>;
Unique reset(Unique ptr) {
    if (ptr) ptr->record('r');
    return std::make_unique<Resource>();
}
Unique drop(Unique ptr) {
    if (ptr) ptr->record('d');
    return nullptr;
}
Unique forward(Unique ptr) {
    if (ptr) ptr->record('f');
    return ptr;
}

int main() {
    std::vector<std::string> problems[3];

    drop(forward(reset(nullptr)));
    problems[0] = std::move(RECORDS);

    forward(drop(reset(forward(forward(reset(nullptr))))));
    problems[1] = std::move(RECORDS);

    drop(drop(reset(drop(reset(reset(nullptr))))));
    problems[2] = std::move(RECORDS);

    // 答案检查
    std::vector<const char*> answers[]{
        {"fd"},
        {"ffr", "d"},
        {"r", "r", "d", "d"}
    };

    for (int i = 0; i < 3; ++i) {
        ASSERT(problems[i].size() == answers[i].size(), "wrong size");
        for (int j = 0; j < problems[i].size(); ++j) {
            ASSERT(problems[i][j] == answers[i][j], "wrong record");
        }
    }

    return 0;
}
