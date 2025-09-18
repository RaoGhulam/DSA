#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class HASH{
    int bucket;
    vector<vector<int>> table;
    public:
    HASH(int b){
        bucket = b;
        table.resize(bucket);
    }
    int hash_function(int x){
        return (x%bucket);
    }
    void insert_item(int key){
        int index = hash_function(key);
        table[index].push_back(key);
    }
    void delete_item(int key){
        int index = hash_function(key);

        auto it = find(table[index].begin(), table[index].end(), key);
        if(it != table[index].end()){
            table[index].erase(it);
        }
    }
};