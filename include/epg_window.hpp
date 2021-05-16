/*
 *  https://github.com/Exerros
 *  11.24.2020
*/
#pragma once

#include <memory>
#include <bitset>
#include <array>

#include "FL/Fl.H"
#include <FL/Fl_Box.H>
#include "FL/Fl_Window.H"
#include "FL/Fl_Button.H"
#include "FL/Fl_Output.H"
#include "FL/Fl_Check_Button.H"
#include "FL/Fl_Input.H"
#include "FL/Fl_Value_Input.H"
#include "FL/x.H"

#include "epg_window_constants.hpp"
#include "epg_generator.hpp"
#include "epg_config.hpp"
#include "resource.hpp"

using std::unique_ptr;
using std::shared_ptr;
using std::bitset;
using std::array;

namespace epg {

//This class controls the main window of the program, processes values placed
//in different widgets and transfers all this information with the help of
//EPG_GeneratorData class to EPG_Generator class
    class EPG_Window {
    private:
        unique_ptr<Fl_Window> window;
        unique_ptr<Fl_Input> seed;
        unique_ptr<Fl_Value_Input> counter;
        unique_ptr<Fl_Button> button;
        unique_ptr<Fl_Button> splitter;
        //shared_ptr is used to pass a pointer to an object to the EPG_Generator
        //class so that it can set a new password in the Fl_Output field.
        shared_ptr<Fl_Output> output;
        //Check buttons {lower, upper, numbers, extra}
        array<unique_ptr<Fl_Check_Button>, BITSET_SIZE> checkers;
    public:
        EPG_Window();

        //This function places data from Fl_Widget structures into
        //EPG_GeneratorData structure which is later processed in EPG_Generator class.
        EPG_GeneratorData get_data();

        //This function is created as an interface to call other functions from the
        //FLTK library.
        static void generate(Fl_Widget*, void*);
    };

}
