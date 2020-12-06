#include "AssetManager.hpp"

namespace HeadBall {

    ////////////////////////////////////////////////////
    // Textures
    void AssetManager::loadTexture(std::string name, std::string fileName) {
        sf::Texture texture;

        //loadFromFile() method below loads texture and returns true if successfully loaded, false otherwise
        if(texture.loadFromFile(fileName)) {
            this->_textures[name] = texture;
        }
    }

    sf::Texture &AssetManager::getTexture(std::string name) {
        return this->_textures.at(name);
    }

    // void AssetManager::loadSprite(sf::Texture texture){

    // }

    ////////////////////////////////////////////////////
    // Fonts
    void AssetManager::loadFont(std::string name, std::string fileName) {
        sf::Font font;
        
        if(font.loadFromFile(fileName)) {
            this->_fonts[name] = font;
        }
    }

    sf::Font &AssetManager::getFont(std::string name) {
        return this->_fonts.at(name);
    }


    ////////////////////////////////////////////////////
    // Sound clips
    void AssetManager::loadSound(std::string name, std::string fileName) {
        sf::SoundBuffer soundBuf;

        if(soundBuf.loadFromFile(fileName)) {
            this->_sound_clips[name] = soundBuf;
        }
    }

    sf::SoundBuffer &AssetManager::getSound(std::string name) {
        return this->_sound_clips.at(name);
    }


    /*
    ////////////////////////////////////////////////////
    // Music clips
    void AssetManager::loadMusic(std::string name, std::string fileName) {
        sf::Music *music = new sf::Music;

        if(music->openFromFile(fileName)) {
            this->_music_clips[name] = &music;  // fix an error in this part
        }
    }

    sf::Music &AssetManager::getMusic(std::string name) {
        return this->_music_clips.at(name);
        // return music;
    }
    */


   bool AssetManager::isTexturePresent(std::string textureName){
       if (!_textures.count(textureName)){  //i.e. if count value == 0(false), return false
           return false;
       }
       return true;
   }

    bool AssetManager::isFontPresent(std::string fontName){
       if (!_fonts.count(fontName)){  //i.e. if count value == 0(false), return false
           return false;
       }
       return true;
   }

    bool AssetManager::isSoundPresent(std::string soundName){
       if (!_sound_clips.count(soundName)){  //i.e. if count value == 0(false), return false
           return false;
       }
       return true;
   }


    ////////////////////////////////////////////////////
    // experimental
    // remove(unload) particular object from map to free up space when not needed:
    void AssetManager::unloadTexture(std::string name) {
        this->_textures.erase(name);
    }

    void AssetManager::unloadFont(std::string name) {
        this->_fonts.erase(name);
    }

    void AssetManager::unloadSound(std::string name) {
        this->_sound_clips.erase(name);
    }
}