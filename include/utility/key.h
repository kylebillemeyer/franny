//
// Created by bille on 11/1/2024.
//

#ifndef KEY_STATE_H
#define KEY_STATE_H
#include <unordered_map>
#include <set>

#include "GLFW/glfw3.h"

namespace utility {
    enum KeyState {
        DOWN,
        UP
    };

    class KeyManager {
    public:
        explicit KeyManager(GLFWwindow * window, const std::set<int> &keysToTrack);

        void trackKey(int key);
        void untrackKey(int key);

        bool isKeyDown(int key) const;
        bool isKeyUp(int key) const;
        bool wasKeyPressed(int key) const;
        bool wasKeyReleased(int key) const;

        void process();

    private:
        GLFWwindow *window;
        std::set<int> keys;
        std::unordered_map<int, KeyState> lastState;
        std::unordered_map<int, KeyState> currentState;
    };
}

#endif //KEY_STATE_H
