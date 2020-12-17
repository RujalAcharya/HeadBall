#pragma once

#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace HeadBall {
    /*!
     * @brief Class for managing assets
     * 
     * Assets managed by this class include Textures, Fonts and Sound.
     */
    class AssetManager {
        public:
            /*!
             * @brief Construct a new Asset Manager object
             * 
             */

            AssetManager() {}

            /*!
             * @brief Destroy the Asset Manager object
             * 
             */
            ~AssetManager() {}

            /*!
             * @brief Load Texture from given file into `map`
             * 
             * @param name Name of Texture object
             * @param fileName Path to Texture
             */
            void loadTexture(std::string name, std::string fileName);

            /*!
             * @brief Get the Texture object
             * 
             * @param name Name of Texture object
             * @return sf::Texture& Reference to Texture object
             */
            sf::Texture &getTexture(std::string name);

            /*!
             * @brief Load Font from given file into `map`
             * 
             * @param name Name of the Font object
             * @param fileName Path to Font
             */
            void loadFont(std::string name, std::string fileName);

            /*!
             * @brief Get the Font object
             * 
             * @param name Name of Font object
             * @return sf::Font& Reference to Font object
             */
            sf::Font &getFont(std::string name);

            /*!
             * @brief Load Sound from given file into `map`
             * 
             * @param name Name of Sound object
             * @param fileName Path to Sound
             */
            void loadSound(std::string name, std::string fileName);

            /*!
             * @brief Get the Sound object
             * 
             * @param name Name of Sound object
             * @return sf::SoundBuffer& Reference to Sound object
             */
            sf::SoundBuffer &getSound(std::string name);

            /*!
             * @brief Check whether the Texture is present in `map`
             * 
             * @param textureName Name of Texture object
             * @return true if Texture is present
             * @return false if Texture is not present
             */
            bool isTexturePresent(std::string textureName);

            /*!
             * @brief Check whether the Font is present in `map`
             * 
             * @param fontName Name of Font object
             * @return true if Font is present
             * @return false if Font is not present
             */
            bool isFontPresent(std::string fontName);

            /*!
             * @brief Check whether the Sound is present in `map`
             * 
             * @param soundName Name of Sound object
             * @return true if Sound is present
             * @return false if Sound is not present
             */
            bool isSoundPresent(std::string soundName);
            
        private:
            std::map<std::string, sf::Texture> _textures;           //!< `map` for storing Textures
            std::map<std::string, sf::Font> _fonts;                 //!< `map` for storing Fonts
            std::map<std::string, sf::SoundBuffer> _sound_clips;    //!< `map` for storing Sound clips/Sound effects
    };
}
