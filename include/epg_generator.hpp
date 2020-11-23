/*
 *  https://github.com/Exerros
 *  11.24.2020
*/
#pragma once

#include <string>
#include <bitset>
#include <memory>
#include <random>
#include <algorithm>
#include <chrono>
#include <cstring>

#include "FL/Fl_Output.H"

#include "epg_alphabet.hpp"

using std::string;
using std::bitset;
using std::shared_ptr;
using std::uniform_int_distribution;
using std::default_random_engine;
using std::min;
using std::chrono::steady_clock;
using std::hash;
using std::to_string;

namespace epg {

//This structure is used to transfer data from EPG_Window class to EPG_Generator class.
    struct EPG_GeneratorData {
        const char* seed;
        int symbolCount;
        bitset<BITSET_SIZE> flags;//in epg_alphabet: constexpr int BITSET_SIZE = 4;
        shared_ptr<Fl_Output> output;

        EPG_GeneratorData(
                      const char* s,
                      const int c,
                      const bitset<BITSET_SIZE> f,
                      shared_ptr<Fl_Output> out
                      );
    };


    //This class processes data obtained from the EPG_Window class and generates
    //a password based on it.
    class EPG_Generator {
    private:
        std::default_random_engine engine;
    public:
        //This function accepts data from EPG_Window, processes them and
        //generates a password based on them.
        void generate(const EPG_GeneratorData& data);

    private:
        //This function calculates the string hash that will be used later
        //to generate the password.
        unsigned long get_hash(const char* str, const int alphabetSize) const;
    };

}
