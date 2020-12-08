#pragma once

#include <map>
#include<vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace HeadBall {
    class AssetManager {
        public:
            AssetManager() {}
            ~AssetManager() {}

            void loadTexture(std::string name, std::string fileName);
            sf::Texture &getTexture(std::string name);

            void loadFont(std::string name, std::string fileName);
            sf::Font &getFont(std::string name);

            void loadSound(std::string name, std::string fileName);
            sf::SoundBuffer &getSound(std::string name);

            bool isTexturePresent(std::string textureName);
            bool isFontPresent(std::string fontName);
            bool isSoundPresent(std::string soundName);
            
        private:
            std::map<std::string, sf::Texture> _textures;
            std::map<std::string, sf::Font> _fonts;
            std::map<std::string, sf::SoundBuffer> _sound_clips;
    };
}