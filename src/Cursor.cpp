/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#include "glfwwrapper/Cursor.hpp"
#include "glfwwrapper/utils.hpp"


namespace tbaricault::glfwwrapper
{

    Cursor::Cursor(Cursor&& other) noexcept
        : _glfwElement(other._glfwElement)
    {
        other._glfwElement = nullptr;
        return;
    }

    Cursor::Cursor(Cursor::Standard cursor) noexcept
    {
        this->_glfwElement = glfwCreateStandardCursor(static_cast<int>(cursor));
        return;
    }

    Cursor::Cursor(const tbaricault::images::Image& image, const tbaricault::math::Vector2<int>& hotspot)
    {
        GLFWimage glfwImage = extractImage(image);
        this->_glfwElement = glfwCreateCursor(
            &glfwImage,
            hotspot.x,
            hotspot.y
        );
        return;
    }

    Cursor::~Cursor() noexcept
    {
        if (this->_glfwElement)
            glfwDestroyCursor(this->_glfwElement);
        return;
    }

    Cursor& Cursor::operator=(Cursor&& other) noexcept
    {
        if (&other == this)
            return (*this);
        if (this->_glfwElement)
            glfwDestroyCursor(this->_glfwElement);
        this->_glfwElement = other._glfwElement;
        other._glfwElement = nullptr;
        return (*this);
    }

    Cursor::operator bool() const noexcept
    {
        return (this->_glfwElement != nullptr);
    }

    GLFWcursor* Cursor::getGLFWElement() const noexcept
    {
        return (this->_glfwElement);
    }

}
