/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#pragma once


#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Device.hpp"


namespace tbaricault::glfwwrapper
{

    /**
     * @brief Mouse wrapper
     */
    class Mouse final
        : public Device
    {

        public:

            /**
             * @brief Mouse cursor mode
             */
            enum class Mode
            {
                /**
                 * @brief Default cursor mode
                 */
                Normal = GLFW_CURSOR_NORMAL,

                /**
                 * @brief Same as default but the cursor isn't displayed
                 */
                Hidden = GLFW_CURSOR_HIDDEN,

                /**
                 * @brief Cursor is hidden and locked to the window
                 */
                Disabled = GLFW_CURSOR_DISABLED,

                /**
                 * @brief Cursor is confined in the window
                 */
                Captured = GLFW_CURSOR_CAPTURED,

            };

            /**
             * @brief Mouse button
             */
            enum class Button : unsigned char
            {
                /**
                 * @brief Mouse button 1, similar to LEFT_BUTTON
                 */
                Button1 = GLFW_MOUSE_BUTTON_1,

                /**
                 * @brief Mouse button 2, similar to RIGHT_BUTTON
                 */
                Button2 = GLFW_MOUSE_BUTTON_2,

                /**
                 * @brief Mouse button 3, similar to MIDDLE_BUTTON
                 */
                Button3 = GLFW_MOUSE_BUTTON_3,

                /**
                 * @brief Mouse button 4
                 */
                Button4 = GLFW_MOUSE_BUTTON_4,

                /**
                 * @brief Mouse button 5
                 */
                Button5 = GLFW_MOUSE_BUTTON_5,

                /**
                 * @brief Mouse button 6
                 */
                Button6 = GLFW_MOUSE_BUTTON_6,

                /**
                 * @brief Mouse button 7
                 */
                Button7 = GLFW_MOUSE_BUTTON_7,

                /**
                 * @brief Mouse button 8
                 */
                Button8 = GLFW_MOUSE_BUTTON_8,

                /**
                 * @brief Left mouse button
                 */
                LeftButton = GLFW_MOUSE_BUTTON_LEFT,

                /**
                 * @brief Middle mouse button
                 */
                MiddleButton = GLFW_MOUSE_BUTTON_MIDDLE,

                /**
                 * @brief Right mouse button
                 */
                RightButton = GLFW_MOUSE_BUTTON_RIGHT,

            };


            /**
             * @brief Default constructor is disabled
             */
            Mouse() = delete;

    };

}
