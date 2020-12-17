#pragma once

/*!
 * @brief Convert the units from Box2D units to SFML units and vice-versa
 * 
 * This namespace is used for easier conversion of units from the box2d units 
 * to SFML units and vice-versa.
 * SFML uses pixels for position and degree for angle whereas box2d uses SI units 
 * (meters and radian).
 * 
 */
namespace Converter {
    const float PPM = 30.0f;
    const float PI = 3.1415;

    /*!
     * @brief Convert the unit from pixels to meters
     * 
     * @tparam T 
     * @param x 
     * @return constexpr T 
     */
    template <class T>
    constexpr T pixelsToMeters (const T &x) { return x / PPM; }

    /*!
     * @brief Convert the unit from meters to pixels
     * 
     * @tparam T 
     * @param x 
     * @return constexpr T 
     */
    template <class T>
    constexpr T metersToPixels (const T &x) { return x * PPM; }

    /*!
     * @brief Convert the unit from degrees to radians
     * 
     * @tparam T 
     * @param x 
     * @return constexpr T 
     */
    template <class T>
    constexpr T degToRad (const T &x) { return PI * x / 180.0; };

    /*!
     * @brief Convert the unit from radians to degrees
     * 
     * @tparam T 
     * @param x 
     * @return constexpr T 
     */
    template <class T>
    constexpr T radToDeg (const T &x) { return 180.0 * x / PI; }
}