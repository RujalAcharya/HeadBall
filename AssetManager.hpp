#pragma once

#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace HeadBall {
    class AssetManager {
        public:
            AssetManager() {}
            ~AssetManager() {}

            void loadTexture(std::string name, std::string fileName);
            sf::Texture &getTexture(std::string name);
            void loadSprite(sf::Texture texture);

            void loadFont(std::string name, std::string fileName);
            sf::Font &getFont(std::string name);

            void loadSound(std::string name, std::string fileName);
            sf::SoundBuffer &getSound(std::string name);

            // void loadMusic(std::string name, std::string fileName);
            // sf::Music &getMusic(std::string name);

            bool isTexturePresent(std::string textureName);
            bool isFontPresent(std::string fontName);
            bool isSoundPresent(std::string soundName);

            // unloading (experimental)
            void unloadTexture(std::string name);
            void unloadFont(std::string name);
            void unloadSound(std::string name);

        private:
            std::map<std::string, sf::Texture> _textures;
            std::map<std::string, sf::Font> _fonts;
            std::map<std::string, sf::SoundBuffer> _sound_clips;
            // std::map<std::string, sf::Music &> _music_clips;

    };
}