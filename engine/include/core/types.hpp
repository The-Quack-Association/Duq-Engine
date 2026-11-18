#pragma once

#include <cstdint>
#include <string>

#include <raylib.h>

namespace Duq {

    // Integer aliases
    using EntityID = std::uint32_t;
    using ComponentID = std::uint32_t;

    // Common engine types
    using String = std::string;

    // 2D types
    using Vector2 = ::Vector2;
    using Vector3 = ::Vector3;
    using Rectangle = ::Rectangle;
    using Color = ::Color;

    // Entity identifier
    constexpr EntityID INVALID_ENTITY_ID = 0;

    // Common dimensions
    struct Resolution {

        int width = 1280;
        int height = 720;

    };

}