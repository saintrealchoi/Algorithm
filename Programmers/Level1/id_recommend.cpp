#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    int length = new_id.length();
    string answer = "";
    int count =0;
    int dot_count=0;
    vector<int> erase_list;
    
    for(int i=0; i < length ; i++){
        char temp = new_id[i];
        
        if(temp > 64 && temp <91){
            new_id[i] += 32;
            temp = new_id[i];
        }
        if( (temp<97 || temp >122) && (temp != 45) && (temp != 95) && temp !=46 && (temp <48 || temp >57)){
            erase_list.emplace_back(i);
        }
        
    }
    for(int i=0; i <erase_list.size();i++){
        new_id.erase(erase_list[i]-count,1);
        count++;
    }
    erase_list.clear();
    count =0;
    for(int i =0 ; i<new_id.length();i++){
        if(new_id[i] == 46) dot_count++;
        else dot_count =0;
        
        if(dot_count > 1){
            erase_list.emplace_back(i);
        }
    }
    for(int i=0; i <erase_list.size();i++){
        new_id.erase(erase_list[i]-count,1);
        count++;
    }
    new_id.erase(remove(new_id.begin(),new_id.end(), ' '), new_id.end());
    
    if(new_id[0]==46)
        new_id.erase(0,1);
    if(new_id.back() == 46)
        new_id.erase(new_id.length()-1,1);
    
    if(new_id.empty()) new_id.push_back('a');
    
    if(new_id.length() > 15) {
        new_id.erase(15);
        if(new_id[new_id.length()-1]==46)
            new_id.erase(new_id.length()-1,1);
    }
    while(new_id.length() < 3){
        new_id.push_back(new_id.back());
    }
    
    
    return new_id;
}