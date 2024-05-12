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
    int hash(int max_table) const {
        return (number * 10000 + id) % max_table;
    }
};