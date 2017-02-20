#ifndef ELEMENT_H
#define ELEMENT_H

#include <vector>
#include <string>
#include <memory>

#include <SDL.h>

#include "Animation.h"
#include "Misc.h"

namespace bkengine
{
    class Element
    {
            friend class Entity;
        public:
            explicit Element(const std::string &description = "", const Location &loc = {0, 0},
                             bool isCollidable = false);
            virtual ~Element();

            void setAnimation(unsigned int index);

            bool hasAnimation(const std::string &name) const;
            bool hasAnimation(unsigned int index) const;

            void removeAnimation(const std::string &name);
            void removeAnimation(unsigned int index);

            Animation &addAnimation(const std::string &descr = "",
                                    unsigned int frameDelta = 1);
            Animation &getAnimation(const std::string &name);
            Animation &getAnimation(unsigned int index);
            Animation &getCurrentAnimation();

            template <typename T> T &addAnimation(const T &);
            template <typename T> T &addAnimation(const std::shared_ptr<T> &);
            template <typename T, typename... Params> T &addAnimation(Params...);
            template <typename T> T &getAnimation(const std::string &name);
            template <typename T> T &getAnimation(unsigned int index);
            template <typename T> T &getCurrentAnimation();

            virtual void onRender();
            virtual void onLoop();
            virtual int onEvent(SDL_Event *e);

            Location getLocation() const;
            std::string getDescription() const;

        protected:
            std::string description;
            Rect collisionRect;
            Location location;
            bool flipped;
            int frame;
            bool isCollidable = false;
            int currentAnimation;
            std::vector<std::shared_ptr<Animation>> animations;
    };

#include "templates/Element_templates.h"
}

#endif // ELEMENT_H