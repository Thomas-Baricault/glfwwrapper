/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#pragma once


#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <tbaricault/images.hpp>


namespace tbaricault::glfwwrapper
{

    /**
     * @brief Initializes the GLFW wrapper
     * 
     * This function must be called before any other function in the GLFW wrapper module.
     */
    void init();

    /**
     * @brief Cleans up the GLFW wrapper
     * 
     * After calling this function, no other GLFW wrapper function should be used.
     */
    void cleanup() noexcept;

    /**
     * @brief Polls GLFW events
     * 
     * @param timeout Waiting timeout in seconds, negative for wait indefinitely
     */
    void pollEvents(double timeout = -1) noexcept;

    /**
     * @brief Posts empty event causing to wake up waiting threads
     */
    void wakeUp() noexcept;

    /**
     * @brief Constructs the GLFW image object from an image
     * 
     * @param image Image
     * 
     * @return GLFW image 
     */
    GLFWimage extractImage(const tbaricault::images::Image& image) noexcept;

}
