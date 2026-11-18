#pragma once

#include <string>
#include <raylib.h>

#include <core/types.hpp>

namespace Duq {

    class Window {
    public:

        Duq::Resolution resolution;
        Duq::String title;

        Window(Duq::Resolution RESOLUTION, Duq::String TITLE);

        void initWindow() {

            InitWindow(resolution.width, resolution.height, title.c_str());

        }

        void update() {

            while (!WindowShouldClose()) {

                //

            }

        }

        void closeWindow() {

            CloseWindow();

        }

    };

}