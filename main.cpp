#include <iostream>
#include <unordered_map> // for url shortener map 
#include <string>
using namespace std;

unordered_map< string, string > shortToLong;
unordered_map< string , string > longToShort;
// this acts key valuue where each map is taking either of the roles 
// key map 1 - value - map 2 or other way around depends on what user types as input 

//func 1 : (generation of code)
string generateCode () {
    string characters = "abcdefghijklmnopqrstuvwxyz0123456789";
    string code;
    for( int i = 0; i < 6; i++) {
        code += characters[ rand() % characters.size()] ;
        //to get a random value within some number here say size of character = 26+10
    }
    return code;
}

//func 2 : (shorten url)

string shorten(string url) {
        if(longToShort.find(url) == longToShort.end()) {
            string code =generateCode();
            longToShort[url] = code;
            shortToLong[code] = url;
            return code;
        }
        else{
            return longToShort[url];
        }
            //.count() returns 1 if the key exists else 0
    
}

