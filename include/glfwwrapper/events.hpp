/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#pragma once


#include <GL/glew.h>
#include <GLFW/glfw3.h>


namespace tbaricault::glfwwrapper::events
{

    /**
     * @brief Polls GLFW events
     * 
     * @param timeout Waiting timeout in seconds, negative for wait indefinitely
     */
    void poll(double timeout = -1) noexcept;

    /**
     * @brief Posts empty event causing to wake up waiting threads
     */
    void wakeUp() noexcept;

}
