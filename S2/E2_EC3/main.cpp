#include <iostream>
#include <cassert>
#include <map>
using namespace std;

class Solution {
public:
    string decodeMessage(string key, string message){
        map<char, char> afake;
        char al='a';

        for (char letra:key){
            if (letra == ' ' || afake[letra]) {
                continue;
            }
            afake[letra] = al++;
        }

        afake[' ']=' ';

        string palabra;
        for (char letrita:message){
            palabra+= afake[letrita];
        }

        return palabra;
    }
};

void test(){
    assert(Solution().decodeMessage("the quick brown fox jumps over the lazy dog", "vkbs bs t suepuv") == "this is a secret");
    assert(Solution().decodeMessage("eljuxhpwnyrdgtqkviszcfmabo", "zwx hnfx lqantp mnoeius ycgk vcnjrdb") == "the five boxing wizards jump quickly");
    assert(Solution().decodeMessage("algorimos abc defghi jkl mno pqrstu vwxyz datos", "holamundoutec") == "ndbaguqkdutlj");
    assert(Solution().decodeMessage("abcdefghijklmnopqrstuvwxyz", "i love lourdes") == "i love lourdes");
}

int main(){
    test();
    return 0;
}
