/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "glfwwrapper/Context.hpp"
#include "glfwwrapper/Monitor.hpp"


namespace tbaricault::glfwwrapper
{

    Context::Context()
    {
        if (!glfwInit())
            return;
        glfwSetMonitorCallback(Monitor::_callback);
        int count;
        GLFWmonitor** monitors = glfwGetMonitors(&count);
        if (!monitors)
            return;
        for (int i = 0; i < count; i++)
            Monitor::_registered[monitors[i]] = std::make_unique<Monitor>(monitors[i]);
        Monitor::_updateReferences();
        this->_valid = true;
        return;
    }

    Context::~Context() noexcept
    {
        glfwSetMonitorCallback(nullptr);
        Monitor::_registered.clear();
        Monitor::_references.clear();
        glfwTerminate();
        return;
    }

    Context::operator bool() const noexcept
    {
        return (this->_valid);
    }

}
