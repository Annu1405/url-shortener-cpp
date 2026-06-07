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

//func 3 : (expand code)
string expand(string code) {
    if(shortToLong.find(code) == shortToLong.end()) {
            return "Code not found!";
        }
        else{
            return shortToLong[code];
            //shortToLong["akj38h"] - www.yt.com (key - value)
        }

}

// last func main( ) here program actually starts running
// everything else is just func waiting to be called
int main() {
    srand(time(0));
int option;
string url;
string code;
//func 4 main loop executes till user says exit
    while(true) {
        cout<< "Menu :" <<endl;
        cout<< "1. Shorten" <<endl;
        cout<< "2. Expand"  <<endl;
        cout<< "3. Exit"  <<endl;
        cout << "Enter your choice :";
        cin >> option;
        if( option == 1) {
        cout << "Enter url to shorten:";
        cin >> url;
        cout << "Shortened code :" << shorten(url) << endl;
        }
        if( option == 2) {
            cout << "Enter code to redirect to it's url :" ;
            cin >> code;
            cout << "Redirects to:" << expand(code) << endl;
        }
        if( option == 3) {
        break;
        }

    }
    return 0;
}

