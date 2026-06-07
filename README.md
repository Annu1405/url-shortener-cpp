# url-shortener-cpp


## What it does
To shorten url , and generate unique code by using HashMaps for fetching the results in O(1) time 


## Concepts used
Data structure used , Hashmap ;
Concepts used - strings to get input , 
maps to generate key- value pairs of the code and url in case of already seen url or code (saves from re-generation of code and faster result)


## Real world connection
This is a mini version of bit.ly which uses exact logic and structure to generate short and unique code for url using maps (key - value pairs application)

## How to run
g++ main.cpp -o shortener
./shortener

## What I learned
- HashMap gives O(1) lookup vs O(n) for arrays
- Two maps can mirror each other to allow reverse lookup
- Same URL always returns same code (no duplicates)