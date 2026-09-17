/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#pragma once


#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <tbaricault/math.hpp>


namespace tbaricault::glfwwrapper
{

    /**
     * @brief Monitor wrapper
     */
    class Monitor final
    {

        public:

            /**
             * @brief Video mode wrapper
             */
            struct VideoMode
            {

                /**
                 * @brief Size (width, height)
                 */
                tbaricault::math::Vector2<int> size;

                /**
                 * @brief Red channel bit depth
                 */
                int redBits = 0;

                /**
                 * @brief Green channel bit depth
                 */
                int greenBits = 0;

                /**
                 * @brief Blue channel bit depth
                 */
                int blueBits = 0;

                /**
                 * @brief Refresh rate in Hz
                 */
                int refreshRate = 0;

            };

            /**
             * @brief Gamma ramp wrapper
             */
            struct GammaRamp
            {

                /**
                 * @brief Red channel response
                 */
                std::vector<unsigned short> red;

                /**
                 * @brief Green channel response
                 */
                std::vector<unsigned short> green;

                /**
                 * @brief Blue channel response
                 */
                std::vector<unsigned short> blue;

            };


            /**
             * @brief Invalid monitor
             */
            static Monitor Invalid;


            /**
             * @brief Initializes monitors
             */
            static void init();

            /**
             * @brief Cleans up registered monitors
             */
            static void cleanup() noexcept;

            /**
             * @brief Returns monitors count
             * 
             * @return Number of monitors
             */
            static std::size_t getCount() noexcept;

            /**
             * @brief Returns the primary monitor
             * 
             * @return Primary monitor
             */
            static Monitor& getPrimary() noexcept;

            /**
             * @brief Returns all the monitors
             * 
             * @return Monitors vector
             */
            static std::span<const std::reference_wrapper<Monitor>> getAll() noexcept;

            /**
             * @brief Returns the monitor associated with a GLFW pointer
             * 
             * @param glfwMonitor GLFW pointer
             * 
             * @return Monitor
             */
            static Monitor& getByGLFWElement(GLFWmonitor* glfwMonitor) noexcept;

            /**
             * @brief Contrucs an invalid monitor
             */
            Monitor() noexcept = default;

            /**
             * @brief Copy constructor is disabled
             */
            Monitor(const Monitor&) = delete;

            /**
             * @brief Move constructor
             * 
             * @param other Monitor to move
             */
            Monitor(Monitor&& other) noexcept;

            /**
             * @brief Constructs a monitor from GLFW monitor pointer
             * 
             * @param glfwMonitor GLFW monitor pointer
             */
            Monitor(GLFWmonitor* glfwMonitor) noexcept;

            /**
             * @brief Destructor
             */
            ~Monitor() noexcept = default;

            /**
             * @brief Copy assignment is disabled
             */
            Monitor& operator=(const Monitor&) = delete;

            /**
             * @brief Move assignment operator
             * 
             * @param other Monitor to move
             * 
             * @return Reference to this monitor
             */
            Monitor& operator=(Monitor&& other) noexcept;

            /**
             * @brief Returns whether the monitor is in a valid state
             */
            explicit operator bool() const noexcept;

            /**
             * @brief Checks whether the monitor is the primary monitor
             * 
             * @return `true` if is primary, `false` otherwise
             */
            bool isPrimary() const noexcept;

            /**
             * @brief Returns the monitor GLFW pointer
             * 
             * @return GLFW pointer
             */
            GLFWmonitor* getGLFWElement() const noexcept;

            /**
             * @brief Returns the monitor name
             * 
             * @return The monitor name or an empty string on error
             */
            std::string getName() const;

            /**
             * @brief Returns the monitor physical size in millimeters
             * 
             * @return Monitor physical size (width, height)
             */
            tbaricault::math::Vector2<int> getPhysicalSize() const noexcept;

            /**
             * @brief Returns the monitor scale
             * 
             * @return Monitor scale (width, height)
             */
            tbaricault::math::Vector2<float> getScale() const noexcept;

            /**
             * @brief Returns the monitor rectangle on the virtual desktop
             * 
             * @return Monitor rectangle
             */
            tbaricault::math::Rect<int> getRect() const noexcept;

            /**
             * @brief Returns the monitor work rectangle (the area not occupied by global task bars or menu bars)
             * 
             * @return Monitor work rectangle
             */
            tbaricault::math::Rect<int> getWorkRect() const noexcept;

            /**
             * @brief Returns the monitor video mode
             * 
             * @return Monitor video mode
             */
            VideoMode getVideoMode() const noexcept;

            /**
             * @brief Returns the monitor available video modes
             * 
             * @return Video modes
             */
            std::vector<VideoMode> getVideoModes() const;

            /**
             * @brief Returns the monitor gamma ramp
             * 
             * @return Gamma ramp
             */
            GammaRamp getGammaRamp() const;

            /**
             * @brief Sets the monitor gamma value
             * 
             * @param gamma The gamma value
             */
            void setGamma(float gamma) noexcept;

            /**
             * @brief Sets the monitor gamma ramp
             * 
             * @param ramp Gamma ramp
             * 
             * @throws std::invalid_argument If gamma ramp components have different sizes
             */
            void setGammaRamp(const GammaRamp& ramp);


        private:

            /**
             * @brief Registered monitors
             */
            static std::unordered_map<GLFWmonitor*, std::unique_ptr<Monitor>> _registered;

            /**
             * @brief Cached reference vector
             */
            static std::vector<std::reference_wrapper<Monitor>> _references;

            /**
             * @brief GLFW pointer
             */
            GLFWmonitor* _glfwElement = nullptr;


            /**
             * @brief Monitor event callback
             * 
             * @param glfwMonitor GLFW monitor pointer
             * @param event Event
             */
            static void _callback(GLFWmonitor* glfwMonitor, int event);

            /**
             * @brief Updates references vector
             */
            static void _updateReferences();

    };

}
