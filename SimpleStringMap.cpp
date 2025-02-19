#include <string>
#include <iostream>
#include <vector>

class SimpleStringMap{

private:

    //std::string values[100];
    std::vector<std::pair<std::string, std::string>> values[100];

    int hash(const std::string &key){
        int hashValue = 0;
        for(char ch : key){
            hashValue = hashValue + ch;
        }
        hashValue = hashValue % 100;
        return hashValue;
    }

public:
    void put(std::string key, std::string value){
        int hashValue = hash(key);

        for(auto &pair : values[hashValue]){
            if(pair.first == key){
                pair.second = value;
                return;
            }
        }
        values[hashValue].emplace_back(key, value);
    }

    std::string get(std::string key){
        int hashValue = hash(key);
        auto &pairs = values[hashValue];
        
        for(const auto &pair : values[hashValue]){
            if(pair.first == key){
                return pair.second;
            }
        }

        return nullptr;
    }
};

int main(){
    SimpleStringMap ssMap;

    ssMap.put("one","two");
    ssMap.put("Daniel","Raymond");
    ssMap.put("12","2");
    ssMap.put("one","three");
    ssMap.put("1","1");

    std::cout << ssMap.get("one") <<"\n";
    std::cout << ssMap.get("Daniel") <<"\n";
    std::cout << ssMap.get("12") <<"\n";
    std::cout << ssMap.get("1") <<"\n";
}