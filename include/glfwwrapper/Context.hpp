/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#pragma once


/**
 * @brief Creates and test the GLFW context
 */
#define TBARICAULT_GLFWWRAPPER_INIT if (auto _ = tbaricault::glfwwrapper::Context(); _)


namespace tbaricault::glfwwrapper
{

    /**
     * @brief GLFW context handle
     */
    class Context
    {

        public:

            /**
             * @brief Constructs the context
             */
            Context();

            /**
             * @brief Copy constructor is disabled
             */
            Context(const Context&) = delete;

            /**
             * @brief Move constructor is disabled
             */
            Context(Context&&) = delete;

            /**
             * @brief Destroys the context
             */
            ~Context() noexcept;

            /**
             * @brief Copy assignment is disabled
             */
            Context& operator=(const Context&) = delete;

            /**
             * @brief Move assignment is disabled
             */
            Context& operator=(Context&&) = delete;

            /**
             * @brief Returns whether the context was successfully created
             */
            explicit operator bool() const noexcept;


        private:

            /**
             * @brief Returns whether the context is valid
             */
            bool _valid = false;

    };

}
