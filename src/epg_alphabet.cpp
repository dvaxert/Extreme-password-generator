/*
 *  https://github.com/Exerros
 *  11.24.2020
*/
#include "epg_alphabet.hpp"

namespace epg {

constexpr array<pair<char, char>, BITSET_SIZE> SYMBOLS = {
        make_pair('a', 'z'),
        make_pair('A', 'Z'),
        make_pair('0', '9'),
        make_pair('!', '/')
                                                };

    EPG_Alphabet::EPG_Alphabet(const bitset<BITSET_SIZE> flags)
        :alphabet()
    {
        for(size_t i = 0; i < BITSET_SIZE; ++i) {
            if(flags[i] == true) {
                for(char ch = SYMBOLS[i].first; ch <= SYMBOLS[i].second; ++ch) {
                    alphabet += ch;
                }
            }
        }
    }

    int
    EPG_Alphabet::size() const {
        return static_cast<int>(alphabet.size() - 1);
    }

    char
    EPG_Alphabet::operator[](const int id) const {
        return alphabet.at(static_cast<size_t>(id));
    }

}
