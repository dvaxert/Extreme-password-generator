/*
 *  https://github.com/Exerros
 *  11.24.2020
*/
#include "epg_generator.hpp"

namespace epg {

constexpr auto BAD_PASSWORD = "qwerty";

    EPG_GeneratorData::EPG_GeneratorData(
            const char* s,
            const int c,
            bitset<BITSET_SIZE> f,
            shared_ptr<Fl_Output> out
    )
        :seed(s)
        ,symbolCount(c)
        ,flags(f)
        ,output(out)
        { }

    unsigned long
    EPG_Generator::get_hash(const char* str, const int alphabetSize) const {
        return hash<string>{}(string(str) + static_cast<char>(alphabetSize));
    }

    void
    EPG_Generator::generate(const EPG_GeneratorData& data) {
        string result;

        if((data.flags.count() == 0) || (data.symbolCount == 0)) {
            result = BAD_PASSWORD;
        } else {
            EPG_Alphabet alphabet(data.flags);

            if(strlen(data.seed) == 0) {
                unsigned long tmp_seed = static_cast<unsigned long>(
                    steady_clock::now().time_since_epoch().count()
                );
                engine.seed(tmp_seed);
            } else {
                engine.seed(get_hash(data.seed, alphabet.size()));
            }

            uniform_int_distribution<int> destribution(0, alphabet.size());
            for(int i = 0; i < data.symbolCount; ++i) {
                result += alphabet[destribution(engine)];
            }
        }
        data.output->value(result.c_str());
    }
}
