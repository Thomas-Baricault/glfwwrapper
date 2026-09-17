/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#pragma once


#include <GL/glew.h>
#include <GLFW/glfw3.h>


namespace tbaricault::glfwwrapper
{

    /**
     * @brief Base class for devices
     */
    class Device
    {

        public:

            /**
             * @brief Device action
             */
            enum class Action : unsigned char
            {
                /**
                 * @brief The device was pressed
                 */
                Pressed = GLFW_PRESS,

                /**
                 * @brief The device was released
                 */
                Released = GLFW_RELEASE,

                /**
                 * @brief The device action was repeated
                 */
                Repeated = GLFW_REPEAT,

            };

            /**
             * @brief Key modifier
             */
            enum class Modifier : unsigned char
            {
                /**
                 * @brief Shift key
                 */
                Shift = GLFW_MOD_SHIFT,

                /**
                 * @brief Control key
                 */
                Control = GLFW_MOD_CONTROL,

                /**
                 * @brief Alt key
                 */
                Alt = GLFW_MOD_ALT,

                /**
                 * @brief Super key
                 */
                Super = GLFW_MOD_SUPER,

                /**
                 * @brief Caps lock key
                 */
                CapsLock = GLFW_MOD_CAPS_LOCK,

                /**
                 * @brief Num lock key
                 */
                NumLock  = GLFW_MOD_NUM_LOCK,

            };


            /**
             * @brief Default constructor is disabled
             */
            Device() = delete;

    };

}
