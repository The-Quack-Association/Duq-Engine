#pragma once

// Standard
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>

// SFML
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

// OpenGL
#include <GL/glew.h>

// JSON
#include <nlohmann/json.hpp>

// Custom
// #include "./components/cli/informationType.h" // Not working... will fix when CLI system is incorperated...
#include "./components/function/math.h"
#include "./components/function/converters.h"
#include "./components/cli/informationType.h"
#include "./components/render/window.h"
#include "./components/render/sprites.h"
#include "./components/entity/sprites.h"