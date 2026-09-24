/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#include "glfwwrapper/events.hpp"
#include "glfwwrapper/Window.hpp"


namespace tbaricault::glfwwrapper
{

    void Window::resetDefaultParameters() noexcept
    {
        glfwDefaultWindowHints();
        return;
    }

    void Window::setResizableByDefault(bool value) noexcept
    {
        glfwWindowHint(GLFW_RESIZABLE, value);
        return;
    }

    void Window::setVisibleByDefault(bool value) noexcept
    {
        glfwWindowHint(GLFW_VISIBLE, value);
        return;
    }

    void Window::setDecoratedByDefault(bool value) noexcept
    {
        glfwWindowHint(GLFW_DECORATED, value);
        return;
    }

    void Window::setFocusedByDefault(bool value) noexcept
    {
        glfwWindowHint(GLFW_FOCUSED, value);
        return;
    }

    void Window::setAutoIconifyByDefault(bool value) noexcept
    {
        glfwWindowHint(GLFW_AUTO_ICONIFY, value);
        return;
    }

    void Window::setHoverAllByDefault(bool value) noexcept
    {
        glfwWindowHint(GLFW_FLOATING, value);
        return;
    }

    void Window::setMaximizedByDefault(bool value) noexcept
    {
        glfwWindowHint(GLFW_MAXIMIZED, value);
        return;
    }

    void Window::setCenterCursorByDefault(bool value) noexcept
    {
        glfwWindowHint(GLFW_CENTER_CURSOR, value);
        return;
    }

    void Window::setTransparentByDefault(bool value) noexcept
    {
        glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, value);
        return;
    }

    void Window::setFocusOnShowByDefault(bool value) noexcept
    {
        glfwWindowHint(GLFW_FOCUS_ON_SHOW, value);
        return;
    }

    void Window::setScaleToMonitorByDefault(bool value) noexcept
    {
        glfwWindowHint(GLFW_SCALE_TO_MONITOR, value);
        return;
    }

    void Window::setScaleFramebufferByDefault(bool value) noexcept
    {
        glfwWindowHint(GLFW_SCALE_FRAMEBUFFER, value);
        return;
    }

    void Window::setMousePassThroughByDefault(bool value) noexcept
    {
        glfwWindowHint(GLFW_MOUSE_PASSTHROUGH, value);
        return;
    }

    void Window::setPositionByDefault(const tbaricault::math::Vector2<int>& pos) noexcept
    {
        glfwWindowHint(GLFW_POSITION_X, pos.x);
        glfwWindowHint(GLFW_POSITION_Y, pos.y);
        return;
    }

    Window::Window(Window&& other) noexcept
        : _handle(other._handle)
    {
        other._handle = nullptr;
        return;
    }

    Window::Window(const std::string& title, const tbaricault::math::Vector2<int>& size, const Monitor& monitor, const Window& share)
    {
        this->_handle = glfwCreateWindow(
            size.x,
            size.y,
            title.c_str(),
            monitor
                ? monitor.getHandle()
                : nullptr,
            share
                ? share._handle
                : nullptr
        );
        if (this->_handle)
        {
            glfwMakeContextCurrent(this->_handle);
            glewInit();
            glfwSetWindowUserPointer(this->_handle, this);
            glfwSetInputMode(this->_handle, GLFW_LOCK_KEY_MODS, GLFW_TRUE);
            glfwSetWindowPosCallback(this->_handle, Window::_moveCallback);
            glfwSetWindowSizeCallback(this->_handle, Window::_resizeCallback);
            glfwSetWindowIconifyCallback(this->_handle, Window::_iconifyCallback);
            glfwSetWindowMaximizeCallback(this->_handle, Window::_maximizeCallback);
            glfwSetFramebufferSizeCallback(this->_handle, Window::_framebufferResizeCallback);
            glfwSetWindowContentScaleCallback(this->_handle, Window::_contentScaleCallback);
            glfwSetWindowFocusCallback(this->_handle, Window::_focusCallback);
            glfwSetKeyCallback(this->_handle, Window::_keyCallback);
            glfwSetCharCallback(this->_handle, Window::_charCallback);
            glfwSetMouseButtonCallback(this->_handle, Window::_mouseButtonCallback);
            glfwSetScrollCallback(this->_handle, Window::_scrollCallback);
            glfwSetCursorPosCallback(this->_handle, Window::_cursorMoveCallback);
            glfwSetCursorEnterCallback(this->_handle, Window::_cursorHoverCallback);
            glfwSetDropCallback(this->_handle, Window::_dropCallback);
            glfwSetWindowRefreshCallback(this->_handle, Window::_refreshCallback);
            glfwSetWindowCloseCallback(this->_handle, Window::_closeCallback);
        }
        return;
    }

    Window::~Window() noexcept
    {
        if (this->_handle)
            glfwDestroyWindow(this->_handle);
        return;
    }

    Window& Window::operator=(Window&& other) noexcept
    {
        if (&other == this)
            return (*this);
        this->_handle = other._handle;
        other._handle = nullptr;
        return (*this);
    }

    Window::operator bool() const noexcept
    {
        return (this->_handle != nullptr);
    }

    bool Window::isWindowed() const noexcept
    {
        return (glfwGetWindowMonitor(this->_handle) == nullptr);
    }

    bool Window::isFocused() const noexcept
    {
        return (glfwGetWindowAttrib(this->_handle, GLFW_FOCUSED));
    }

    bool Window::isIconified() const noexcept
    {
        return (glfwGetWindowAttrib(this->_handle, GLFW_ICONIFIED));
    }

    bool Window::isMaximized() const noexcept
    {
        return (glfwGetWindowAttrib(this->_handle, GLFW_MAXIMIZED));
    }

    bool Window::isHovered() const noexcept
    {
        return (glfwGetWindowAttrib(this->_handle, GLFW_HOVERED));
    }

    bool Window::isVisible() const noexcept
    {
        return (glfwGetWindowAttrib(this->_handle, GLFW_VISIBLE));
    }

    bool Window::isResizable() const noexcept
    {
        return (glfwGetWindowAttrib(this->_handle, GLFW_RESIZABLE));
    }

    bool Window::isDecorated() const noexcept
    {
        return (glfwGetWindowAttrib(this->_handle, GLFW_DECORATED));
    }

    bool Window::isAutoIconify() const noexcept
    {
        return (glfwGetWindowAttrib(this->_handle, GLFW_AUTO_ICONIFY));
    }

    bool Window::isHoverAll() const noexcept
    {
        return (glfwGetWindowAttrib(this->_handle, GLFW_FLOATING));
    }

    bool Window::isTransparent() const noexcept
    {
        return (glfwGetWindowAttrib(this->_handle, GLFW_TRANSPARENT_FRAMEBUFFER));
    }

    bool Window::isFocusedOnShow() const noexcept
    {
        return (glfwGetWindowAttrib(this->_handle, GLFW_FOCUS_ON_SHOW));
    }

    bool Window::isMousePassThrought() const noexcept
    {
        return (glfwGetWindowAttrib(this->_handle, GLFW_MOUSE_PASSTHROUGH));
    }

    bool Window::isKeyPressed(Keyboard::Key key) const noexcept
    {
        return (glfwGetKey(this->_handle, static_cast<int>(key)) == static_cast<int>(Keyboard::Action::Pressed));
    }

    bool Window::isMouseButtonPressed(Mouse::Button button) const noexcept
    {
        return (glfwGetMouseButton(this->_handle, static_cast<int>(button)) == static_cast<int>(Mouse::Action::Pressed));
    }

    Monitor& Window::getMonitor() const noexcept
    {
        return (Monitor::getByGLFWElement(glfwGetWindowMonitor(this->_handle)));
    }

    std::string Window::getTitle() const
    {
        const char* title = glfwGetWindowTitle(this->_handle);
        return (title ? title : "");
    }

    float Window::getOpacity() const noexcept
    {
        return (glfwGetWindowOpacity(this->_handle));
    }

    tbaricault::math::Rect<int> Window::getRect() const noexcept
    {
        tbaricault::math::Rect<int> rect;
        glfwGetWindowPos(
            this->_handle,
            &rect.x,
            &rect.y
        );
        glfwGetWindowSize(
            this->_handle,
            &rect.w,
            &rect.h
        );
        return (rect);
    }

    tbaricault::math::Rect<int> Window::getBorderSize() const noexcept
    {
        tbaricault::math::Rect<int> rect;
        glfwGetWindowFrameSize(
            this->_handle,
            &rect.x,
            &rect.y,
            &rect.w,
            &rect.h
        );
        return (rect);
    }

    tbaricault::math::Vector2<int> Window::getContentSize() const noexcept
    {
        tbaricault::math::Vector2<int> size;
        glfwGetFramebufferSize(
            this->_handle,
            &size.x,
            &size.y
        );
        return (size);
    }

    tbaricault::math::Vector2<float> Window::getContentScale() const noexcept
    {
        tbaricault::math::Vector2<float> size;
        glfwGetWindowContentScale(
            this->_handle,
            &size.x,
            &size.y
        );
        return (size);
    }

    unsigned char Window::getActiveModifiers() const noexcept
    {
        unsigned char modifiers = 0;
        if (this->isKeyPressed(Keyboard::Key::LeftShift) || this->isKeyPressed(Keyboard::Key::RightShift))
            modifiers |= static_cast<unsigned char>(Device::Modifier::Shift);
        if (this->isKeyPressed(Keyboard::Key::LeftControl) || this->isKeyPressed(Keyboard::Key::RightControl))
            modifiers |= static_cast<unsigned char>(Device::Modifier::Control);
        if (this->isKeyPressed(Keyboard::Key::LeftAlt) || this->isKeyPressed(Keyboard::Key::RightAlt))
            modifiers |= static_cast<unsigned char>(Device::Modifier::Alt);
        if (this->isKeyPressed(Keyboard::Key::LeftSuper) || this->isKeyPressed(Keyboard::Key::RightSuper))
            modifiers |= static_cast<unsigned char>(Device::Modifier::Super);
        return (modifiers);
    }

    unsigned char Window::getActiveMouseButtons() const noexcept
    {
        unsigned char buttons = 0;
        for (unsigned char i = 0; i < 8; i++)
            if (this->isMouseButtonPressed(static_cast<Mouse::Button>(i)))
                buttons |= 1 << i;
        return (buttons);
    }

    tbaricault::math::Vector2<double> Window::getCursorPos() const noexcept
    {
        tbaricault::math::Vector2<double> pos;
        glfwGetCursorPos(
            this->_handle,
            &pos.x,
            &pos.y
        );
        return (pos);
    }

    void Window::setTitle(const std::string& title) noexcept
    {
        glfwSetWindowTitle(this->_handle, title.c_str());
        return;
    }

    void Window::setIcon(const tbaricault::images::Image& icon) noexcept
    {
        if (icon)
        {
            GLFWimage image = {
                icon.getSize().x,
                icon.getSize().y,
                reinterpret_cast<unsigned char*>(icon.getPixels()),
            };
            glfwSetWindowIcon(this->_handle, 1, &image);
        }
        else
        {
            glfwSetWindowIcon(this->_handle, 0, nullptr);
        }
        return;
    }

    void Window::setIcon(std::span<const tbaricault::images::Image> icons)
    {
        GLFWimage* images = new GLFWimage[icons.size()];
        for (std::size_t i = 0; i < icons.size(); i++)
        {
            images[i] = {
                icons[i].getSize().x,
                icons[i].getSize().y,
                reinterpret_cast<unsigned char*>(icons[i].getPixels()),
            };
        }
        glfwSetWindowIcon(this->_handle, icons.size(), images);
        delete[] images;
        return;
    }

    void Window::setCursor(const Cursor& cursor) noexcept
    {
        glfwSetCursor(
            this->_handle,
            cursor
                ? cursor.getHandle()
                : nullptr
        );
        return;
    }

    void Window::setCursorMode(Mouse::Mode mode) noexcept
    {
        glfwSetInputMode(
            this->_handle,
            GLFW_CURSOR,
            static_cast<int>(mode)
        );
        if (glfwRawMouseMotionSupported())
        {
            glfwSetInputMode(
                this->_handle,
                GLFW_RAW_MOUSE_MOTION,
                mode == Mouse::Mode::Disabled
            );
        }
        return;
    }

    void Window::setSizeLimits(const tbaricault::math::Vector2<int>& min, const tbaricault::math::Vector2<int>& max) noexcept
    {
        glfwSetWindowSizeLimits(
            this->_handle,
            min.x < 0 ? GLFW_DONT_CARE : min.x,
            min.y < 0 ? GLFW_DONT_CARE : min.y,
            max.x < 0 ? GLFW_DONT_CARE : max.x,
            max.y < 0 ? GLFW_DONT_CARE : max.y
        );
        return;
    }

    void Window::setAspectRatio(const tbaricault::math::Vector2<int>& ratio) noexcept
    {
        glfwSetWindowAspectRatio(
            this->_handle,
            ratio.x < 0 ? GLFW_DONT_CARE : ratio.x,
            ratio.y < 0 ? GLFW_DONT_CARE : ratio.y
        );
        return;
    }

    void Window::setOpacity(float value) noexcept
    {
        glfwSetWindowOpacity(this->_handle, value);
        return;
    }

    void Window::setDecorated(bool value) noexcept
    {
        glfwSetWindowAttrib(this->_handle, GLFW_DECORATED, value);
        return;
    }

    void Window::setResizable(bool value) noexcept
    {
        glfwSetWindowAttrib(this->_handle, GLFW_RESIZABLE, value);
        return;
    }

    void Window::setHoverAll(bool value) noexcept
    {
        glfwSetWindowAttrib(this->_handle, GLFW_FLOATING, value);
        return;
    }

    void Window::setAutoIconify(bool value) noexcept
    {
        glfwSetWindowAttrib(this->_handle, GLFW_AUTO_ICONIFY, value);
        return;
    }

    void Window::setFocusOnShow(bool value) noexcept
    {
        glfwSetWindowAttrib(this->_handle, GLFW_FOCUS_ON_SHOW, value);
        return;
    }

    void Window::setMousePassThrough(bool value) noexcept
    {
        glfwSetWindowAttrib(this->_handle, GLFW_MOUSE_PASSTHROUGH, value);
        return;
    }

    void Window::setCursorPos(const tbaricault::math::Vector2<double>& pos) noexcept
    {
        glfwSetCursorPos(this->_handle, pos.x, pos.y);
        return;
    }

    void Window::close()
    {
        glfwSetWindowShouldClose(this->_handle, GLFW_TRUE);
        return;
    }

    void Window::hide() noexcept
    {
        glfwHideWindow(this->_handle);
        return;
    }

    void Window::show() noexcept
    {
        glfwShowWindow(this->_handle);
        return;
    }

    void Window::focus() noexcept
    {
        glfwFocusWindow(this->_handle);
        return;
    }

    void Window::iconify() noexcept
    {
        glfwIconifyWindow(this->_handle);
        return;
    }

    void Window::maximize() noexcept
    {
        glfwMaximizeWindow(this->_handle);
        return;
    }

    void Window::restore() noexcept
    {
        glfwRestoreWindow(this->_handle);
        return;
    }

    void Window::fullscreen(const Monitor& monitor) noexcept
    {
        if (!monitor)
            return;
        Monitor::VideoMode mode = monitor.getVideoMode();
        glfwSetWindowMonitor(
            this->_handle,
            monitor.getHandle(),
            0,
            0,
            mode.size.x,
            mode.size.y,
            mode.refreshRate
        );
        return;
    }

    void Window::windowed(const tbaricault::math::Rect<int>& rect) noexcept
    {
        glfwSetWindowMonitor(
            this->_handle,
            nullptr,
            rect.x,
            rect.y,
            rect.w,
            rect.h,
            GLFW_DONT_CARE
        );
        return;
    }

    void Window::notify() noexcept
    {
        glfwRequestWindowAttention(this->_handle);
        return;
    }

    void Window::move(const tbaricault::math::Vector2<int>& pos) noexcept
    {
        glfwSetWindowPos(
            this->_handle,
            pos.x,
            pos.y
        );
        return;
    }

    void Window::resize(const tbaricault::math::Vector2<int>& size) noexcept
    {
        glfwSetWindowSize(
            this->_handle,
            size.x,
            size.y
        );
        return;
    }

    void Window::enableVSync() noexcept
    {
        glfwMakeContextCurrent(this->_handle);
        glfwSwapInterval(1);
        return;
    }

    void Window::disableVSync() noexcept
    {
        glfwMakeContextCurrent(this->_handle);
        glfwSwapInterval(0);
        return;
    }

    void Window::cancelClose() noexcept
    {
        glfwSetWindowShouldClose(this->_handle, GLFW_FALSE);
        return;
    }

    void Window::update()
    {
        if (glfwWindowShouldClose(this->_handle))
        {
            glfwDestroyWindow(this->_handle);
            this->_handle = nullptr;
        }
        else
        {
            this->_handleRefresh();
        }
        return;
    }

    bool Window::_render()
    {
        glfwMakeContextCurrent(this->_handle);
        return (false);
    }

    void Window::_handleMove(const tbaricault::math::Vector2<int>&)
    {
        return;
    }

    void Window::_handleResize(const tbaricault::math::Vector2<int>&)
    {
        return;
    }

    void Window::_handleIconify(bool)
    {
        return;
    }

    void Window::_handleMaximize(bool)
    {
        return;
    }

    void Window::_handleFramebufferResize(const tbaricault::math::Vector2<int>&)
    {
        return;
    }

    void Window::_handleContentScale(const tbaricault::math::Vector2<float>&)
    {
        return;
    }

    void Window::_handleFocus(bool)
    {
        return;
    }

    void Window::_handleKey(Keyboard::Key, int, Keyboard::Action, unsigned char)
    {
        return;
    }

    void Window::_handleChar(unsigned int)
    {
        return;
    }

    void Window::_handleMouseButton(Mouse::Button, Mouse::Action, unsigned char)
    {
        return;
    }

    void Window::_handleScroll(tbaricault::math::Vector2<double>)
    {
        return;
    }

    void Window::_handleCursorMove(tbaricault::math::Vector2<double>)
    {
        return;
    }

    void Window::_handleCursorHover(bool)
    {
        return;
    }

    void Window::_handleDrop(std::vector<std::string_view>&)
    {
        return;
    }

    void Window::_handleRefresh()
    {
        if (this->_render())
            glfwSwapBuffers(this->_handle);
        return;
    }

    void Window::_handleClose()
    {
        if (glfwWindowShouldClose(this->_handle))
            events::wakeUp();
        return;
    }

    void Window::_moveCallback(GLFWwindow* glfwWindow, int x, int y)
    {
        static_cast<Window*>(glfwGetWindowUserPointer(glfwWindow))->_handleMove({x, y});
        return;
    }

    void Window::_resizeCallback(GLFWwindow* glfwWindow, int width, int height)
    {
        static_cast<Window*>(glfwGetWindowUserPointer(glfwWindow))->_handleResize({width, height});
        return;
    }

    void Window::_iconifyCallback(GLFWwindow* glfwWindow, int iconified)
    {
        static_cast<Window*>(glfwGetWindowUserPointer(glfwWindow))->_handleIconify(iconified);
        return;
    }

    void Window::_maximizeCallback(GLFWwindow* glfwWindow, int maximized)
    {
        static_cast<Window*>(glfwGetWindowUserPointer(glfwWindow))->_handleMaximize(maximized);
        return;
    }

    void Window::_framebufferResizeCallback(GLFWwindow* glfwWindow, int width, int height)
    {
        glfwMakeContextCurrent(glfwWindow);
        glViewport(0, 0, width, height);
        static_cast<Window*>(glfwGetWindowUserPointer(glfwWindow))->_handleFramebufferResize({width, height});
        return;
    }

    void Window::_contentScaleCallback(GLFWwindow* glfwWindow, float x, float y)
    {
        static_cast<Window*>(glfwGetWindowUserPointer(glfwWindow))->_handleContentScale({x, y});
        return;
    }

    void Window::_focusCallback(GLFWwindow* glfwWindow, int focused)
    {
        static_cast<Window*>(glfwGetWindowUserPointer(glfwWindow))->_handleFocus(focused);
        return;
    }

    void Window::_keyCallback(GLFWwindow* glfwWindow, int key, int scancode, int action, int modifiers)
    {
        static_cast<Window*>(glfwGetWindowUserPointer(glfwWindow))->_handleKey(
            static_cast<Keyboard::Key>(key),
            scancode,
            static_cast<Keyboard::Action>(action),
            static_cast<unsigned char>(modifiers)
        );
        return;
    }

    void Window::_charCallback(GLFWwindow* glfwWindow, unsigned int codePoint)
    {
        static_cast<Window*>(glfwGetWindowUserPointer(glfwWindow))->_handleChar(codePoint);
        return;
    }

    void Window::_mouseButtonCallback(GLFWwindow* glfwWindow, int button, int action, int modifiers)
    {
        static_cast<Window*>(glfwGetWindowUserPointer(glfwWindow))->_handleMouseButton(
            static_cast<Mouse::Button>(button),
            static_cast<Keyboard::Action>(action),
            static_cast<unsigned char>(modifiers)
        );
        return;
    }

    void Window::_scrollCallback(GLFWwindow* glfwWindow, double x, double y)
    {
        static_cast<Window*>(glfwGetWindowUserPointer(glfwWindow))->_handleScroll({x, y});
        return;
    }

    void Window::_cursorMoveCallback(GLFWwindow* glfwWindow, double x, double y)
    {
        static_cast<Window*>(glfwGetWindowUserPointer(glfwWindow))->_handleCursorMove({x, y});
        return;
    }

    void Window::_cursorHoverCallback(GLFWwindow* glfwWindow, int hovered)
    {
        static_cast<Window*>(glfwGetWindowUserPointer(glfwWindow))->_handleCursorHover(hovered);
        return;
    }

    void Window::_dropCallback(GLFWwindow* glfwWindow, int count, const char** paths)
    {
        std::vector<std::string_view> v;
        while (count--)
            v.push_back(*paths++);
        static_cast<Window*>(glfwGetWindowUserPointer(glfwWindow))->_handleDrop(v);
        return;
    }

    void Window::_refreshCallback(GLFWwindow* glfwWindow)
    {
        static_cast<Window*>(glfwGetWindowUserPointer(glfwWindow))->_handleRefresh();
        return;
    }

    void Window::_closeCallback(GLFWwindow* glfwWindow)
    {
        static_cast<Window*>(glfwGetWindowUserPointer(glfwWindow))->_handleClose();
        return;
    }

}
