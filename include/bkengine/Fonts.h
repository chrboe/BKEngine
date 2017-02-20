#ifndef FONTS_H
#define FONTS_H

#include <string>
#include <map>

#include <SDL_ttf.h>

#include "Core.h"
#include "Logger.h"
#include "SDLWrapper.h"

namespace bkengine
{
    class Fonts
    {
        public:
            static TTF_Font *registerFont(const std::string &fontFile, int size,
                                          const std::string &fontName = "");
            static TTF_Font *getFont(const std::string &fontName, int size);
            static void releaseFont(const std::string &fontName, int size);

        private:
            static void registerCleanup();
            static void cleanup();

            static bool cleanupRegistered;
            static std::map<std::string, std::map<int, TTF_Font *>> fontCache;
            static std::map<std::string, std::string> fontFileCache;
    };
}

#endif