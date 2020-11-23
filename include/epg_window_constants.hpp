/*
 *  https://github.com/Exerros
 *  11.24.2020
*/
#pragma once

#include <array>

#include "FL/Enumerations.H"
#include "epg_alphabet.hpp" //need only for constant BITSET_SIZE

using std::array;

namespace epg {

const Fl_Labeltype LABEL_TYPE = FL_EMBOSSED_LABEL;

constexpr int OFFSET = 5,
              WINDOW_W = 300,
              WINDOW_H = 210,
              SEED_X = OFFSET,
              SEED_Y = 5,
              SEED_W = 250,
              SEED_H = 25,
              COUNTER_X = OFFSET,
              COUNTER_Y = SEED_Y + SEED_H + OFFSET,
              COUNTER_W = 190,
              COUNTER_H = 25,
              CHECKERS_X = OFFSET,
              CHECKERS_Y = COUNTER_Y + COUNTER_H + OFFSET,
              CHECKERS_W = 180,
              CHECKERS_H = 85,
              ONE_CHECKER_H = 20,
              BUTTON_X = CHECKERS_X + CHECKERS_W + OFFSET,
              BUTTON_Y = CHECKERS_Y,
              BUTTON_W = 105,
              BUTTON_H = 85,
              SPLITTER_X = OFFSET,
              SPLITTER_Y = CHECKERS_Y + CHECKERS_H + OFFSET,
              SPLITTER_W = 290,
              SPLITTER_H = 5,
              OUTPUT_X = OFFSET,
              OUTPUT_Y = SPLITTER_Y + SPLITTER_H + OFFSET * 4,
              OUTPUT_W = 290,
              OUTPUT_H = 25;

constexpr auto SEED_NAME = "Seed",
               COUNTER_NAME = "Symbol count",
               BUTTON_NAME = "Generate!",
               OUTPUT_NAME = "Your new password";

constexpr array<decltype(SEED_NAME), BITSET_SIZE> CHECKERS_NAME = {
    "Lower bound symbols",
    "Upper bound symbols",
    "Numbers",
    "Extra symbols"
};

}
