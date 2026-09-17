/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "glfwwrapper/Time.hpp"


namespace tbaricault::glfwwrapper
{

    double Time::get() noexcept
    {
        return (glfwGetTime());
    }

    uint64_t Time::value() noexcept
    {
        return (glfwGetTimerValue());
    }

    uint64_t Time::frequency() noexcept
    {
        return (glfwGetTimerFrequency());
    }

    void Time::set(double time) noexcept
    {
        glfwSetTime(time);
        return;
    }

}
