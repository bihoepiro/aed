#include <iostream>
#include <cassert>
#include <map>
#include <cmath>
using namespace std;


class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> dic;
        for(char letra:text){
            dic[letra]++;
        }
        int maxb=dic['b'];
        if(maxb> dic['a']){
            maxb=dic['a'];
        }
        if(maxb> dic['n']){
            maxb=dic['n'];
        }
        if(maxb> floor(dic['l']/2)){
            maxb=floor(dic['l']/2);
        }
        if(maxb> floor(dic['o']/2)){
            maxb=floor(dic['o']/2);
        }
        return maxb;
    }
};

void test(){
	assert(Solution().maxNumberOfBalloons("nlaebolko") == 1);
	assert(Solution().maxNumberOfBalloons("loonbalxballpoon") == 2);
	assert(Solution().maxNumberOfBalloons("baalooncokjanshbalokkbalooknlnno") == 2);
	assert(Solution().maxNumberOfBalloons("nobalonccoooouuugklllllonxxxxzzzz") == 1);
	assert(Solution().maxNumberOfBalloons("jkabdikljiurgjhbsadfkjfuabasdfjdfuahdbao") == 0);
}

int main(){
	test();
	return 0;
}
