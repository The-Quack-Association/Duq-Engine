#pragma once

// Standard
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <list>
#include <sstream>
#include <string>
#include <fstream>
#define STB_IMAGE_IMPLEMENTATION
#include "components/function/stb/stb_image.h"

// GLFW
#include <GLFW/glfw3.h>

// OpenGL
#include <glad/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// JSON
#include <nlohmann/json.hpp>

// Custom
// #include "/components/cli/informationType.h" // Not working... will fix when CLI is incorperated...
#include "components/function/math.h"
#include "components/function/conversions.h"
#include "components/scene/scene.h"
#include "components/function/data.h"
#include "components/function/time.h"
#include "components/function/input.h"
#include "components/cli/informationType.h"
#include "components/render/window.h"
#include "components/render/graphics.h"
#include "components/render/sprite.h"
#include "components/entity/entity.h"
#include "components/entity/player.h"
#include "components/render/camera.h"
#include "components/function/game.h"