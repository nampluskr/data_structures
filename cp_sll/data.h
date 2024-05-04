#pragma once

#include <sstream>
#include <string>
// using namespace std;

struct Data {
    int number, id;

    bool operator<(const Data& data) {
        return (number < data.number) || (number == data.number && id > data.id);
    }
    bool operator==(const Data& data) {
        return number == data.number && id == data.id;
    }
    std::string str() const {
        std::ostringstream oss;
        oss << "(" << number << ", " << id << ")";
        return oss.str();
    }
};

template<>
struct std::hash<Data> {
    int operator()(const Data& data) const noexcept {
        return (10000 * data.number + data.id) % 107;
    }
};