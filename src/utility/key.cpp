#include "franny/utility/key.h"

#include "GLFW/glfw3.h"

namespace franny::utility {
    KeyManager::KeyManager(GLFWwindow * window, const std::set<int> &keysToTrack): window(window), keys(keysToTrack) {
        for (auto key : keysToTrack) {
            lastState[key] = UP;
            currentState[key] = UP;
        }
    }

    void KeyManager::trackKey(const int key) {
        keys.insert(key);
        lastState[key] = UP;
        currentState[key] = UP;
    }

    void KeyManager::untrackKey(const int key) {
        keys.erase(key);
        lastState.erase(key);
        currentState.erase(key);
    }

    bool KeyManager::isKeyDown(const int key) const {
        return currentState.at(key) == DOWN;
    }

    bool KeyManager::isKeyUp(const int key) const {
        return currentState.at(key) == UP;
    }

    bool KeyManager::wasKeyPressed(const int key) const {
        return lastState.at(key) == UP && currentState.at(key) == DOWN;
    }

    bool KeyManager::wasKeyReleased(const int key) const {
        return lastState.at(key) == DOWN && currentState.at(key) == UP;
    }

    void KeyManager::process() {
        for (auto key : keys) {
            lastState[key] = currentState[key];
            if (glfwGetKey(window, key) == GLFW_PRESS) {
                currentState[key] = DOWN;
            } else {
                currentState[key] = UP;
            }
        }
    }
}
