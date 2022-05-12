#include <cstdlib>
#include <string> 
#include <vector>

int foobar (const std::vector<std::string> &a, int b){
    int answer = 0;
    for (int i = 0; i < a.size(); i+=b){
        answer++;
    }
    return answer; 
}

int main(){
    foobar; 
}