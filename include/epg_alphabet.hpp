/*
 *  https://github.com/Exerros
 *  11.24.2020
*/
#pragma once

#include <string>
#include <bitset>
#include <functional>
#include <array>

using std::string;
using std::bitset;
using std::array;
using std::pair;
using std::make_pair;

namespace epg {
//This constant stores the value of the dictionary parts used in the program,
//which is also equal to the number of check buttons.
    constexpr int BITSET_SIZE = 4;

//This class manages the alphabet used. It allows changing the characters used
//for password generation without changing the generation functions themselves.
    class EPG_Alphabet {
    private:
        string alphabet;
    public:
        EPG_Alphabet(const bitset<BITSET_SIZE> flags);

//This function returns the current alphabet size - 1. This is done to be able
//to use this value as the last index when calling other functions that use
//the alphabet.
        int size() const;

//This function allows you to return characters from the alphabet by their
//index. This function does not check for errors because it happens in the
//EPG_Generator class. Take this into account when using or changing it.
        char operator[](const int id) const;
    };

}
