#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool num = true;

int check(string s){
    vector<int> v;
    int count[3]={0};
    int tmp;
    for(int i =0 ; i < s.length(); i++){
        if(s[i] == '['){ 
            count[0]++; 
            v.emplace_back(0);
        }
        else if(s[i] == '(') {
            count[1]++;
            v.emplace_back(1);
        }
        else if(s[i] == '{') {
            count[2]++; 
            v.emplace_back(2);
        }
        

        if(s[i] == ']' ) {
            count[0]--;
            if(v.empty()) return 0;
            tmp = v.back();
            v.pop_back();
            if( tmp != 0){
                return 0;
            }
        }
        else if(s[i] == ')'){
            count[1]--;
            if(v.empty()) return 0;
            tmp = v.back();
            v.pop_back();
            if(tmp != 1)
                return 0;
        }
        else if(s[i] == '}'){
            count[2]--;
            if(v.empty()) return 0;
            tmp = v.back();
            v.pop_back();
            if( tmp != 2)
                return 0;
        }
        
        for(int j = 0 ; j<3 ; j++){
            if(count[j] < 0){
                return 0;
            } 
        }
    }
    
    for (int i =0; i <3 ;i++){
        if(count[i]>0) return 0;
    }
    
    return 1;
}

int solution(string s) {
    int answer = 0;
    int length = s.length();
    
    for(int i = 0 ; i < length ; i++){
        string find;
        char tmp = s[s.length()-1];
        s.pop_back();
        
        find.push_back(tmp);
        find.append(s);
        
        
        answer += check(find);
        
        s = find;
    }
    
    return answer;
}
