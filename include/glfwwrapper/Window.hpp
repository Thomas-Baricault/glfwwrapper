/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#pragma once


#include <span>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <tbaricault/images.hpp>
#include <tbaricault/math.hpp>

#include "Cursor.hpp"
#include "Keyboard.hpp"
#include "Monitor.hpp"
#include "Mouse.hpp"


namespace tbaricault::glfwwrapper
{

    /**
     * @brief Window wrapper
     */
    class Window
    {

        public:

            /**
             * @brief Resets the window creation parameters to default
             */
            static void resetDefaultParameters() noexcept;

            /**
             * @brief Sets if windows are resizable by default
             * 
             * @param value `true` if resizable, `false` otherwise
             */
            static void setResizableByDefault(bool value = true) noexcept;

            /**
             * @brief Sets if windows are visible by default
             * 
             * @param value `true` if visible, `false` otherwise
             */
            static void setVisibleByDefault(bool value = true) noexcept;

            /**
             * @brief Sets if windows are decorated by default
             * 
             * @param value `true` if decorated, `false` otherwise
             */
            static void setDecoratedByDefault(bool value = true) noexcept;

            /**
             * @brief Sets if windows are focused by default
             * 
             * @param value `true` if focused, `false` otherwise
             */
            static void setFocusedByDefault(bool value = true) noexcept;

            /**
             * @brief Sets if full screen windows are automatically iconified by default when losing focus
             * 
             * @param value `true` if auto iconified, `false` otherwise
             */
            static void setAutoIconifyByDefault(bool value = true) noexcept;

            /**
             * @brief Sets if windows are floating hover all other windows by default
             * 
             * @param value `true` if floating hover all, `false` otherwise
             */
            static void setHoverAllByDefault(bool value = false) noexcept;

            /**
             * @brief Sets if windows are maximized by default
             * 
             * @param value `true` if maximized, `false` otherwise
             */
            static void setMaximizedByDefault(bool value = false) noexcept;

            /**
             * @brief Sets if cursor are centered by default over newly created full screen windows
             * 
             * @param value `true` if the cursor is centered, `false` otherwise
             */
            static void setCenterCursorByDefault(bool value = true) noexcept;

            /**
             * @brief Sets if windows framebuffers are transparent by default
             * 
             * @param value `true` if transparent, `false` otherwise
             */
            static void setTransparentByDefault(bool value = false) noexcept;

            /**
             * @brief Sets if windows are focused by default on show
             * 
             * @param value `true` if focused on show, `false` otherwise
             */
            static void setFocusOnShowByDefault(bool value = true) noexcept;

            /**
             * @brief Sets if windows content are resized based on the monitor
             * 
             * @param value `true` if scaled to monitor, `false` otherwise
             */
            static void setScaleToMonitorByDefault(bool value = false) noexcept;

            /**
             * @brief Sets if windows framebuffer are resized based on the window content scale
             * 
             * @param value `true` if frame buffer is resized, `false` otherwise
             */
            static void setScaleFramebufferByDefault(bool value = true) noexcept;

            /**
             * @brief Sets if mouse events pass through windows by default
             * 
             * @param value `true` if mouse pass through, `false` otherwise
             */
            static void setMousePassThroughByDefault(bool value = false) noexcept;

            /**
             * @brief Sets the default windows position
             * 
             * @param pos The position
             */
            static void setPositionByDefault(const tbaricault::math::Vector2<int>& pos = {INT_MIN}) noexcept;

            /**
             * @brief Constructs an invalid window
             */
            Window() noexcept = default;

            /**
             * @brief Copy constructor is disabled
             */
            Window(const Window&) = delete;

            /**
             * @brief Move constructor
             * 
             * @param other Window to move
             */
            Window(Window&& other) noexcept;

            /**
             * @brief Constructs a window
             * 
             * @param title Window title
             * @param size Window size
             * @param monitor Monitor on which to create the window
             * @param share Window to share context with
             */
            Window(const std::string& title, const tbaricault::math::Vector2<int>& size = {800, 600}, const Monitor& monitor = Monitor::Invalid, const Window& share = {});

            /**
             * @brief Destroys the window
             */
            virtual ~Window() noexcept;

            /**
             * @brief Copy assignment is disabled
             */
            Window& operator=(const Window&) = delete;

            /**
             * @brief Move assignment operator
             * 
             * @param other Window to move
             * 
             * @return Reference to this window
             */
            Window& operator=(Window&& other) noexcept;

            /**
             * @brief Returns whether the window is in a valid state
             */
            explicit operator bool() const noexcept;

            /**
             * @brief Checks whether the window is windowed
             * 
             * @return `true` if windowed, `false` otherwise
             */
            bool isWindowed() const noexcept;

            /**
             * @brief Checks whether the window is focused
             * 
             * @return `true` if focused, `false` otherwise
             */
            bool isFocused() const noexcept;

            /**
             * @brief Checks whether the window is iconified
             * 
             * @return `true` if iconified, `false` otherwise
             */
            bool isIconified() const noexcept;

            /**
             * @brief Checks whether the window is maximized
             * 
             * @return `true` if maximized, `false` otherwise
             */
            bool isMaximized() const noexcept;

            /**
             * @brief Checks whether the window is hovered
             * 
             * @return `true` if hovered, `false` otherwise
             */
            bool isHovered() const noexcept;

            /**
             * @brief Checks whether the window is visible
             * 
             * @return `true` if visible, `false` otherwise
             */
            bool isVisible() const noexcept;

            /**
             * @brief Checks whether the window is resizable
             * 
             * @return `true` if resizable, `false` otherwise
             */
            bool isResizable() const noexcept;

            /**
             * @brief Checks whether the window is decorated
             * 
             * @return `true` if decorated, `false` otherwise
             */
            bool isDecorated() const noexcept;

            /**
             * @brief Checks whether the window is automatically iconified and loses focus when it is in full screen
             * 
             * @return `true` if automatically iconified, `false` otherwise
             */
            bool isAutoIconify() const noexcept;

            /**
             * @brief Checks whether the window is hover all other windows
             * 
             * @return `true` if hover all, `false` otherwise
             */
            bool isHoverAll() const noexcept;

            /**
             * @brief Checks whether the window is transparent
             * 
             * @return `true` if transparent, `false` otherwise
             */
            bool isTransparent() const noexcept;

            /**
             * @brief Checks whether the window is focused on show
             * 
             * @return `true` if focused on show, `false` otherwise
             */
            bool isFocusedOnShow() const noexcept;

            /**
             * @brief Checks whether mouse events pass through the window
             * 
             * @return `true` if mouse events pass through, `false` otherwise
             */
            bool isMousePassThrought() const noexcept;

            /**
             * @brief Checks whether a keyboard key is pressed on the window
             * 
             * @param key Keyboard key
             * 
             * @return `true` if the keyboard key is pressed, `false` otherwise
             */
            bool isKeyPressed(Keyboard::Key key) const noexcept;

            /**
             * @brief Checks whether a mouse button is pressed on the window
             * 
             * @param button Mouse button
             * 
             * @return `true` if the mouse button is pressed, `false` otherwise
             */
            bool isMouseButtonPressed(Mouse::Button button) const noexcept;

            /**
             * @brief Returns the monitor the window is on
             * 
             * @return Window monitor
             */
            Monitor& getMonitor() const noexcept;

            /**
             * @brief Returns the window title
             * 
             * @return Window title
             */
            std::string getTitle() const;

            /**
             * @brief Returns the window opacity
             * 
             * @return Window opacity
             */
            float getOpacity() const noexcept;

            /**
             * @brief Returns the window rect
             * 
             * @return Window rect
             */
            tbaricault::math::Rect<int> getRect() const noexcept;

            /**
             * @brief Returns the window borders size
             * 
             * @return Window borders size
             */
            tbaricault::math::Rect<int> getBorderSize() const noexcept;

            /**
             * @brief Returns the window content size
             * 
             * @return Content size
             */
            tbaricault::math::Vector2<int> getContentSize() const noexcept;

            /**
             * @brief Returns the window content scale
             * 
             * @return Content scale
             */
            tbaricault::math::Vector2<float> getContentScale() const noexcept;

            /**
             * @brief Returns the active modifiers for the window
             * 
             * @return Active modifiers
             */
            unsigned char getActiveModifiers() const noexcept;

            /**
             * @brief Returns the active mouse buttons for the window
             * 
             * @return Active mouse buttons
             */
            unsigned char getActiveMouseButtons() const noexcept;

            /**
             * @brief Returns the cursor position in the window
             * 
             * @return Cursor position
             */
            tbaricault::math::Vector2<double> getCursorPos() const noexcept;

            /**
             * @brief Sets the window title
             * 
             * @param title Title
             */
            void setTitle(const std::string& title) noexcept;

            /**
             * @brief Sets the window icon
             * 
             * @param icon Icon
             */
            void setIcon(const tbaricault::images::Image& icon = {}) noexcept;

            /**
             * @brief Sets the window icon specifing multiple candidate images of different size
             * 
             * @param icons Candidate images
             */
            void setIcon(std::span<const tbaricault::images::Image> icons);

            /**
             * @brief Sets the window cursor
             * 
             * @param cursor Cursor
             */
            void setCursor(const Cursor& cursor) noexcept;

            /**
             * @brief Sets the window cursor mode
             * 
             * @param mode Cursor mode
             */
            void setCursorMode(Mouse::Mode mode) noexcept;

            /**
             * @brief Sets the window size limits
             * 
             * @param min Minimum size
             * @param max Maximum size
             */
            void setSizeLimits(const tbaricault::math::Vector2<int>& min, const tbaricault::math::Vector2<int>& max) noexcept;

            /**
             * @brief Sets the window aspect ratio
             * 
             * @param ratio Aspect ratio
             */
            void setAspectRatio(const tbaricault::math::Vector2<int>& ratio) noexcept;

            /**
             * @brief Sets the window opacity
             * 
             * @param value Opacity
             */
            void setOpacity(float value) noexcept;

            /**
             * @brief Sets if the window is decorated
             * 
             * @param value Whether the window is decorated
             */
            void setDecorated(bool value) noexcept;

            /**
             * @brief Sets if the window is resizable
             * 
             * @param value Whether the window is resizable
             */
            void setResizable(bool value) noexcept;

            /**
             * @brief Sets if the window is hover all other windows
             * 
             * @param value Whether the window is hover all
             */
            void setHoverAll(bool value) noexcept;

            /**
             * @brief Sets if the window is automatically iconified when in full screen and losing focus
             * 
             * @param value Whether the window is automatically iconified
             */
            void setAutoIconify(bool value) noexcept;

            /**
             * @brief Sets if the window is focused on show
             * 
             * @param value Whether the window is focused on show
             */
            void setFocusOnShow(bool value) noexcept;

            /**
             * @brief Sets if the mouse events pass through the window
             * 
             * @param value Whether mouse events pass through the window
             */
            void setMousePassThrough(bool value) noexcept;

            /**
             * @brief Set the cursor position in the window
             * 
             * @param pos The position
             */
            void setCursorPos(const tbaricault::math::Vector2<double>& pos) noexcept;

            /**
             * @brief Closes the window
             */
            virtual void close();

            /**
             * @brief Hides the window
             */
            void hide() noexcept;

            /**
             * @brief Shows the window
             */
            void show() noexcept;

            /**
             * @brief Gives the focus to the window
             */
            void focus() noexcept;

            /**
             * @brief Iconifies the window
             */
            void iconify() noexcept;

            /**
             * @brief Maximizes the window
             */
            void maximize() noexcept;

            /**
             * @brief Restores the window
             */
            void restore() noexcept;

            /**
             * @brief Makes the window full screen on a monitor
             * 
             * @param monitor Monitor to full screen on
             */
            void fullscreen(const Monitor& monitor) noexcept;

            /**
             * @brief Makes the window windowed
             * 
             * @param rect Window rect
             */
            void windowed(const tbaricault::math::Rect<int>& rect = {0, 0, 800, 600}) noexcept;

            /**
             * @brief Requests user attention to the window
             */
            void notify() noexcept;

            /**
             * @brief Moves the window
             * 
             * @param pos New window position
             */
            void move(const tbaricault::math::Vector2<int>& pos) noexcept;

            /**
             * @brief Resizes the window
             * 
             * @param size New window size
             */
            void resize(const tbaricault::math::Vector2<int>& size) noexcept;

            /**
             * @brief Enables the vsync for the window
             */
            void enableVSync() noexcept;

            /**
             * @brief Disables the vsync for the window
             */
            void disableVSync() noexcept;

            /**
             * @brief Cancels window close request
             */
            void cancelClose() noexcept;

            /**
             * @brief Updates window state
             */
            void update();


        protected:

            /**
             * @brief Render window content
             * 
             * @return `true` if content changes, `false` otherwise
             */
            virtual bool _render();

            /**
             * @brief Handles window move events
             * 
             * @param pos New window pos
             */
            virtual void _handleMove(const tbaricault::math::Vector2<int>& pos);

            /**
             * @brief Handles window resize events
             * 
             * @param pos New window size
             */
            virtual void _handleResize(const tbaricault::math::Vector2<int>& size);

            /**
             * @brief Handles window iconify events
             * 
             * @param iconified Whether the window was iconified, `false` means restored
             */
            virtual void _handleIconify(bool iconified);

            /**
             * @brief Handles window maximize events
             * 
             * @param maximized Whether the window was maximized, `false` means restored
             */
            virtual void _handleMaximize(bool maximized);

            /**
             * @brief Handles window framebuffer resize events
             * 
             * @param pos New framebuffer size
             */
            virtual void _handleFramebufferResize(const tbaricault::math::Vector2<int>& size);

            /**
             * @brief Handles window content scale change events
             * 
             * @param pos New content scale
             */
            virtual void _handleContentScale(const tbaricault::math::Vector2<float>& scale);

            /**
             * @brief Handles window focus events
             * 
             * @param focused Whether the window is focused
             */
            virtual void _handleFocus(bool focused);

            /**
             * @brief Handles window keyboard events
             * 
             * @param key Key called
             * @param scancode Key scancode
             * @param action Event action
             * @param modifiers Active key modifiers
             */
            virtual void _handleKey(Keyboard::Key key, int scancode, Keyboard::Action action, unsigned char modifiers);

            /**
             * @brief Handles window keychar events
             * 
             * @param codePoint Char unicode cope point
             */
            virtual void _handleChar(unsigned int codePoint);

            /**
             * @brief Handles window mouse button events
             * 
             * @param button Mouse button called
             * @param action Event action
             * @param modifiers Active key modifiers
             */
            virtual void _handleMouseButton(Mouse::Button button, Mouse::Action action, unsigned char modifiers);

            /**
             * @brief Handles window scroll events
             * 
             * @param offset Scroll offset
             */
            virtual void _handleScroll(tbaricault::math::Vector2<double> offset);

            /**
             * @brief Handles window cursor move events
             * 
             * @param pos New cursor position
             */
            virtual void _handleCursorMove(tbaricault::math::Vector2<double> pos);

            /**
             * @brief Handles window cursor hover events
             * 
             * @param hovered Whether the cursor hovers over the window
             */
            virtual void _handleCursorHover(bool hovered);

            /**
             * @brief Handles window drop events
             * 
             * @param paths File paths dropped
             */
            virtual void _handleDrop(std::vector<std::string_view>& paths);

            /**
             * @brief Handles window refresh events
             */
            virtual void _handleRefresh();

            /**
             * @brief Handles window close events
             */
            virtual void _handleClose();


        private:

            GLFWwindow* _glfwElement = nullptr;


            /**
             * @brief Static GLFW callback for window move events
             * 
             * @param glfwWindow GLFW window pointer
             * @param x New horizontal window coordinate
             * @param y New vertical window coordinate
             */
            static void _moveCallback(GLFWwindow* glfwWindow, int x, int y);

            /**
             * @brief Static GLFW callback for window resize events
             * 
             * @param glfwWindow GLFW window pointer
             * @param width New window width
             * @param height New window height
             */
            static void _resizeCallback(GLFWwindow* glfwWindow, int width, int height);

            /**
             * @brief Static GLFW callback for window iconify events
             * 
             * @param glfwWindow GLFW window pointer
             * @param iconified Whether the window was iconified, `false` means restored
             */
            static void _iconifyCallback(GLFWwindow* glfwWindow, int iconified);

            /**
             * @brief Static GLFW callback for window maximize events
             * 
             * @param glfwWindow GLFW window pointer
             * @param maximized Whether the window was maximized, `false` means restored
             */
            static void _maximizeCallback(GLFWwindow* glfwWindow, int maximized);

            /**
             * @brief Static GLFW callback for window framebuffer resize events
             * 
             * @param glfwWindow GLFW window pointer
             * @param width New framebuffer width
             * @param height New framebuffer height
             */
            static void _framebufferResizeCallback(GLFWwindow* glfwWindow, int width, int height);

            /**
             * @brief Static GLFW callback for window content scale change events
             * 
             * @param glfwWindow GLFW window pointer
             * @param x New horizontal content scale
             * @param y New vertical content scale
             */
            static void _contentScaleCallback(GLFWwindow* glfwWindow, float x, float y);

            /**
             * @brief Static GLFW callback for window focus events
             * 
             * @param glfwWindow GLFW window pointer
             * @param focused Whether the window is focused
             */
            static void _focusCallback(GLFWwindow* glfwWindow, int focused);

            /**
             * @brief Static GLFW callback for window keyboard events
             * 
             * @param glfwWindow GLFW window pointer
             * @param key Key called
             * @param scancode Key scancode
             * @param action Event action
             * @param modifiers Active key modifiers
             */
            static void _keyCallback(GLFWwindow* glfwWindow, int key, int scancode, int action, int modifiers);

            /**
             * @brief Static GLFW callback for window keychar events
             * 
             * @param glfwWindow GLFW window pointer
             * @param codePoint Char unicode cope point
             */
            static void _charCallback(GLFWwindow* glfwWindow, unsigned int codePoint);

            /**
             * @brief Static GLFW callback for window mouse button events
             * 
             * @param glfwWindow GLFW window pointer
             * @param button Mouse button called
             * @param action Event action
             * @param modifiers Active key modifiers
             */
            static void _mouseButtonCallback(GLFWwindow* glfwWindow, int button, int action, int modifiers);

            /**
             * @brief Static GLFW callback for window scroll events
             * 
             * @param glfwWindow GLFW window pointer
             * @param x Horizontal scroll offset
             * @param y Vertical scroll offset
             */
            static void _scrollCallback(GLFWwindow* glfwWindow, double x, double y);

            /**
             * @brief Static GLFW callback for window cursor move events
             * 
             * @param glfwWindow GLFW window pointer
             * @param pos New cursor position
             */
            static void _cursorMoveCallback(GLFWwindow* glfwWindow, double x, double y);

            /**
             * @brief Static GLFW callback for window cursor hover events
             * 
             * @param glfwWindow GLFW window pointer
             * @param hovered Whether the cursor hovers over the window
             */
            static void _cursorHoverCallback(GLFWwindow* glfwWindow, int hovered);

            /**
             * @brief Static GLFW callback for window drop events
             * 
             * @param glfwWindow GLFW window pointer
             * @param count File paths count
             * @param paths File paths dropped
             */
            static void _dropCallback(GLFWwindow* glfwWindow, int count, const char** paths);

            /**
             * @brief Static GLFW callback for window refresh events
             * 
             * @param glfwWindow GLFW window pointer
             */
            static void _refreshCallback(GLFWwindow* glfwWindow);

            /**
             * @brief Static GLFW callback for window close events
             * 
             * @param glfwWindow GLFW window pointer
             */
            static void _closeCallback(GLFWwindow* glfwWindow);

    };

}
