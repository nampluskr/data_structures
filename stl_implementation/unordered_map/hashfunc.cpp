#ifndef MAX_TABLE
#define MAX_TABLE   1007
#endif

template<typename T>
int hashfunc(const T& key) { return key % MAX_TABLE; }


// int hashfunc(const char* key) {
//     unsigned long long h = 5381;
//     int c;
//     while (c = *key++) h = (((h << 5) + h) + c) % MAX_TABLE;
//     return h % MAX_TABLE;
// }