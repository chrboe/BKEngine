#ifndef BKENGINE_GAME_UTILS_H
#define BKENGINE_GAME_UTILS_H

#include <algorithm>
#include <memory>

#include "core/Game.h"
#include "core/Scene.h"
#include "exceptions/NameAlreadyExistsException.h"
#include "exceptions/NameNotFoundException.h"


namespace bkengine
{
    class Game;
    class Scene;

    class GameUtils
    {
    public:
        static void addScene(const std::shared_ptr<Game> &game, const std::shared_ptr<Scene> &sceneToAdd);
        static bool hasScene(const std::shared_ptr<Game> &game, const std::string &name);
        static std::shared_ptr<Scene> removeScene(const std::shared_ptr<Game> &game, const std::string &name);
        static std::vector<std::shared_ptr<Scene>> removeAllScenes(const std::shared_ptr<Game> &game);

        static std::vector<std::string> getSceneNames(const std::shared_ptr<Game> &game);
        static std::shared_ptr<Scene> getScene(const std::shared_ptr<Game> &game, const std::string &name);
        static uint32_t getSceneCount(const std::shared_ptr<Game> &game);

        static void activateScene(const std::shared_ptr<Game> &game, const std::string &name);
        static std::shared_ptr<Scene> getCurrentScene(const std::shared_ptr<Game> &game);

    private:
        GameUtils() = delete;
    };
}

#endif  // BKENGINE_GAME_UTILS_H