/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#pragma once


#include <string>


namespace tbaricault::glfwwrapper
{

    /**
     * @brief System clipboard handle
     */
    class Clipboard final
    {

        public:

            /**
             * @brief Returns clipboard content
             * 
             * @return Content
             */
            static std::string paste();

            /**
             * @brief Copies a string to the clipboard
             * 
             * @param str String to copy
             */
            static void copy(const std::string& str) noexcept;

            /**
             * @brief Default constructor is disabled
             */
            Clipboard() = delete;

    };

}
