/*
 *  https://github.com/Exerros
 *  11.24.2020
*/
#include "epg_window.hpp"

#define prefix_unused(variable) ((void)variable)

namespace epg {

    EPG_Window::EPG_Window()
        :window(new Fl_Window(WINDOW_W, WINDOW_H, PROGRAM_NAME))
        ,seed(new Fl_Input(SEED_X, SEED_Y, SEED_W, SEED_H, SEED_NAME))
        ,counter(new Fl_Value_Input(COUNTER_X, COUNTER_Y,
                                    COUNTER_W, COUNTER_H, COUNTER_NAME))
        ,button(new Fl_Button(BUTTON_X, BUTTON_Y,
                              BUTTON_W, BUTTON_H, BUTTON_NAME))
        ,splitter(new Fl_Button(SPLITTER_X, SPLITTER_Y,
                                SPLITTER_W, SPLITTER_H))
        ,output(new Fl_Output(OUTPUT_X, OUTPUT_Y,
                              OUTPUT_W, OUTPUT_H, OUTPUT_NAME))
    {
        for(size_t i = 0; i < BITSET_SIZE; ++i) {
            checkers[i] = unique_ptr<Fl_Check_Button>(new Fl_Check_Button(
                CHECKERS_X,
                CHECKERS_Y + ONE_CHECKER_H * static_cast<int>(i),
                CHECKERS_W,
                ONE_CHECKER_H,
                CHECKERS_NAME[i]
            ));
            checkers[i]->labeltype(LABEL_TYPE);
        }

        seed->align(FL_ALIGN_RIGHT);
        seed->labeltype(LABEL_TYPE);
        counter->align(FL_ALIGN_RIGHT);
        counter->labeltype(LABEL_TYPE);
        output->align(FL_ALIGN_TOP);
        output->labeltype(LABEL_TYPE);
        button->labeltype(LABEL_TYPE);
        button->callback(generate, static_cast<void*>(this));

        window->end();
        window->show();
        Fl::run();
    }

    EPG_GeneratorData
    EPG_Window::get_data() {
        bitset<BITSET_SIZE> flags;
        for(size_t i = 0; i < BITSET_SIZE; ++i) {
            flags.set(i, checkers[i]->value());
        }

        return EPG_GeneratorData(
            seed->value(),
            static_cast<int>(counter->value()),
            flags,
            output
        );
    }

    void
    EPG_Window::generate(Fl_Widget* w, void* d) {
        prefix_unused(w);
        EPG_Generator generator;
        EPG_GeneratorData data = (static_cast<EPG_Window*>(d))->get_data();
        generator.generate(data);
    }
}
