/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "glfwwrapper/Clipboard.hpp"


namespace tbaricault::glfwwrapper
{

    std::string Clipboard::paste()
    {
        const char* str = glfwGetClipboardString(nullptr);
        return (str ? str : "");
    }

    void Clipboard::copy(const std::string& str) noexcept
    {
        glfwSetClipboardString(nullptr, str.c_str());
        return;
    }

}
