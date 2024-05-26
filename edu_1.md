# Data Structures

## Linear Data Structures

```cpp
#include <vector>
using namespace std;

struct Data { int value, idx; };
vector<Data> vec;
```

### 1. STL vector

- 데이터 삭제: `vec.clear()`
- 데이터 추가: `vec.push_back({ value, idx })`
- 데이터 접근: `vec.front()`, `vec.back()`
- 데이터 정보: `vec.empty()`, `vec.size()`
- 이터레이터: `vec.begin()`, `vec.end()`
- 데이터 순회:

```cpp
for (const auto& data: vec)
    printf("(%d, %d)\n", data.value, data.idx)
```

```cpp
for (auto iter = vec.begin(); iter != vec.end(); iter++) {
    auto data = *iter;
    printf("(%d, %d)\n", data.value, data.idx)
}
```

```cpp
auto iter = vec.begin();
while (iter != vec.end()) {
    auto data = *iter;
    printf("(%d, %d)\n", data.value, data.idx)
    iter++;
}
```

### 2. Singly Linked List

```cpp

```