#include <iostream>
#include <cassert>
#include <map>
using namespace std;

/*
 * Ian Gonzales
 * Samanta Chang
 * Bihonda Epiquien
 * */

class Solution {
public:
    string decodeMessage(string key, string message) {
        // add your code
        map<char, char> tabla;
        char abece = 'a';

        for (char letra: key) {
            if (letra == ' ' || tabla[letra]) {
                continue;
            }
            tabla[letra] = abece++;
        }

        string valor_retorno = "";
        for (char letra: message) {
            if (letra == ' ') {
                valor_retorno += ' ';
            }
            else {
                valor_retorno += tabla[letra];
            }
        }
        return valor_retorno;
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
