#pragma once

// Standard
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <list>
#include <string>
#include <fstream>

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
//#include "./components/cli/informationType.h" // Not working... will fix when CLI is incorperated...
#include "./components/function/math.h"
#include "./components/function/conversions.h"
#include "./components/function/data.h"
#include "./components/function/time.h"
#include "./components/cli/informationType.h"
#include "./components/render/window.h"
#include "./components/render/sprites.h"
#include "./components/entity/sprites.h"