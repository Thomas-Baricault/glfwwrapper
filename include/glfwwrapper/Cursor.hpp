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
     * @brief Mouse cursor
     */
    class Cursor final
    {

        public:

            /**
             * @brief Standard cursor
             */
            enum class Standard
            {
                /**
                 * @brief Default arrow cursor
                 */
                Arrow = GLFW_ARROW_CURSOR,

                /**
                 * @brief Text-editing I-beam cursor
                 */
                IBeam = GLFW_IBEAM_CURSOR,

                /**
                 * @brief Crosshair cursor, often used in precision tools
                 */
                Crosshair = GLFW_CROSSHAIR_CURSOR,

                /**
                 * @brief Pointing-hand cursor used for clickable items
                 */
                PointingHand = GLFW_POINTING_HAND_CURSOR,

                /**
                 * @brief Horizontal resize cursor
                 */
                ResizeWE = GLFW_RESIZE_EW_CURSOR,

                /**
                 * @brief Vertical resize cursor
                 */
                ResizeNS = GLFW_RESIZE_NS_CURSOR,

                /**
                 * @brief Diagonal resize cursor (NW-SE)
                 */
                ResizeNWSE = GLFW_RESIZE_NWSE_CURSOR,

                /**
                 * @brief Diagonal resize cursor (NE-SW)
                 */
                ResizeNESW = GLFW_RESIZE_NESW_CURSOR,

                /**
                 * @brief Omni-directional resize cursor
                 */
                ResizeAll = GLFW_RESIZE_ALL_CURSOR,

                /**
                 * @brief Cursor displayed when an action is not permitted
                 */
                NotAllowed = GLFW_NOT_ALLOWED_CURSOR,

            };


            /**
             * @brief Constructs an invalid cursor
             */
            Cursor() noexcept = default;

            /**
             * @brief Copy constructor is disabled
             */
            Cursor(const Cursor&) = delete;

            /**
             * @brief Move constructor
             * 
             * @param other Cursor to move
             */
            Cursor(Cursor&& other) noexcept;

            /**
             * @brief Constructs a standard cursor
             * 
             * @param cursor Standard cursor identifier
             */
            Cursor(Standard cursor) noexcept;

            /**
             * @brief Constructs a cursor from an image
             * 
             * @param image Image to construct from
             * @param hotspot Cursor hotspot
             */
            Cursor(const tbaricault::images::Image& image, const tbaricault::math::Vector2<int>& hotspot);

            /**
             * @brief Destructor
             */
            ~Cursor() noexcept;

            /**
             * @brief Copy assignment operator is disabled
             */
            Cursor& operator=(const Cursor&) = delete;

            /**
             * @brief Move assignment operator
             * 
             * @param other Cursor to move
             * 
             * @return Reference to this cursor
             */
            Cursor& operator=(Cursor&& other) noexcept;

            /**
             * @brief Returns whether the cursor is in a valid state
             */
            explicit operator bool() const noexcept;

            /**
             * @brief Returns the cursor GLFW pointer
             * 
             * @return GLFW pointer
             */
            GLFWcursor* getGLFWElement() const noexcept;


        private:

            /**
             * @brief GLFW pointer
             */
            GLFWcursor* _glfwElement = nullptr;

    };

}
