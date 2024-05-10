#pragma once

struct Data {
    int number, id;

    bool operator<(const Data& data) const {
        return (number < data.number) || (number == data.number && id > data.id);
    }
    bool operator>(const Data& data) const {
        return (number > data.number) || (number == data.number && id < data.id);
    }
    bool operator==(const Data& data) const {
        return number == data.number && id == data.id;
    }
};