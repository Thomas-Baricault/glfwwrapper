/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#pragma once


namespace tbaricault::glfwwrapper
{

    /**
     * @brief Manages the GLFW runtime lifetime
     */
    class Runtime
    {

        public:

            /**
             * @brief Constructs the runtime
             */
            Runtime();

            /**
             * @brief Copy constructor is disabled
             */
            Runtime(const Runtime&) = delete;

            /**
             * @brief Move constructor is disabled
             */
            Runtime(Runtime&&) = delete;

            /**
             * @brief Destructor
             */
            ~Runtime() noexcept;

            /**
             * @brief Copy assignment is disabled
             */
            Runtime& operator=(const Runtime&) = delete;

            /**
             * @brief Move assignment is disabled
             */
            Runtime& operator=(Runtime&&) = delete;

            /**
             * @brief Returns whether the runtime was successfully initialized
             */
            explicit operator bool() const noexcept;


        private:

            /**
             * @brief Whether the runtime handle is valid
             */
            bool _valid = false;

    };

}
