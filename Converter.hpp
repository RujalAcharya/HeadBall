#pragma once

/*
 This namespace is used for easier conversion of units from the box2d units to SFML units and vice-versa.
 SFML uses pixels for position and degree for angle whereas box2d uses SI units (meters and radian).
*/

namespace Converter {
    const float PPM = 30.0f;
    const float PI = 3.1415;

    template <class T>
    constexpr T pixelsToMeters (const T &x) { return x / PPM; }

    template <class T>
    constexpr T metersToPixels (const T &x) { return x * PPM; }

    template <class T>
    constexpr T degToRad (const T &x) { return PI * x / 180.0; };

    template <class T>
    constexpr T radToDeg (const T &x) { return 180.0 * x / PI; }
}