/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#pragma once


namespace tbaricault::glfwwrapper
{

    /**
     * @brief Time wrapper
     */
    class Time final
    {

        public:

            /**
             * @brief Returns the number of seconds elapsed since GLFW initialized
             * 
             * @return Seconds
             */
            static double get() noexcept;

            /**
             * @brief Returns the raw value of the timer in 1 / frequency seconds
             * 
             * @return Timer raw value
             */
            static uint64_t value() noexcept;

            /**
             * @brief Returns the frequency in Hz of the raw timer
             * 
             * @return Frequency
             */
            static uint64_t frequency() noexcept;

            /**
             * @brief Sets the timer value in seconds
             * 
             * @param time Time in seconds
             */
            static void set(double time) noexcept;

            /**
             * @brief Default constructor is disabled
             */
            Time() = delete;

    };

}
