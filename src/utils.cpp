/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#include "glfwwrapper/Monitor.hpp"
#include "glfwwrapper/utils.hpp"


namespace tbaricault::glfwwrapper
{

    void init()
    {
        glfwInit();
        Monitor::init();
        return;
    }

    void cleanup() noexcept
    {
        Monitor::cleanup();
        glfwTerminate();
        return;
    }

    void pollEvents(double timeout) noexcept
    {
        if (timeout < 0)
            glfwWaitEvents();
        else if (timeout == 0)
            glfwPollEvents();
        else
            glfwWaitEventsTimeout(timeout);
        return;
    }

    void wakeUp() noexcept
    {
        glfwPostEmptyEvent();
        return;
    }

    GLFWimage extractImage(const tbaricault::images::Image& image) noexcept
    {
        return {
            image.getSize().x,
            image.getSize().y,
            reinterpret_cast<unsigned char*>(image.getPixels()),
        };
    }

}
