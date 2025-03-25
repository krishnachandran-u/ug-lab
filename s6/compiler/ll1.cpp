#include <bits/stdc++.h>

/*
 * S -> aABb 
 * A -> c | 3
 * B -> d | 3
*/

std::map<char, std::set<char>> FIRST = {
    {'S', {'a'}},
    {'A', {'c', '3'}},
    {'B', {'d', '3'}}
};

std::map<char, std::set<char>> FOLLOW = {
    {'S', {'$'}},
    {'A', {'d', 'b'}},
    {'B', {'b'}}
};

