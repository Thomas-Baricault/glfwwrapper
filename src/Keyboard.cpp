/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#include "glfwwrapper/Keyboard.hpp"


namespace tbaricault::glfwwrapper
{

    int Keyboard::getScancode(Keyboard::Key key) noexcept
    {
        return (glfwGetKeyScancode(static_cast<int>(key)));
    }

    std::string Keyboard::getKeyName(Keyboard::Key key)
    {
        const char* str = glfwGetKeyName(static_cast<int>(key), 0);
        return (str ? str : "");
    }

    std::string Keyboard::getScancodeName(int scancode)
    {
        const char* str = glfwGetKeyName(GLFW_KEY_UNKNOWN, scancode);
        return (str ? str : "");
    }

}
