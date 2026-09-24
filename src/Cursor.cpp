/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#include "glfwwrapper/Cursor.hpp"


namespace tbaricault::glfwwrapper
{

    Cursor::Cursor(Cursor&& other) noexcept
        : _handle(other._handle)
    {
        other._handle = nullptr;
        return;
    }

    Cursor::Cursor(Cursor::Standard cursor) noexcept
    {
        this->_handle = glfwCreateStandardCursor(static_cast<int>(cursor));
        return;
    }

    Cursor::Cursor(const tbaricault::images::Image& image, const tbaricault::math::Vector2<int>& hotspot)
    {
        GLFWimage glfwImage = {
            image.getSize().x,
            image.getSize().y,
            reinterpret_cast<unsigned char*>(image.getPixels()),
        };
        this->_handle = glfwCreateCursor(
            &glfwImage,
            hotspot.x,
            hotspot.y
        );
        return;
    }

    Cursor::~Cursor() noexcept
    {
        if (this->_handle)
            glfwDestroyCursor(this->_handle);
        return;
    }

    Cursor& Cursor::operator=(Cursor&& other) noexcept
    {
        if (&other == this)
            return (*this);
        if (this->_handle)
            glfwDestroyCursor(this->_handle);
        this->_handle = other._handle;
        other._handle = nullptr;
        return (*this);
    }

    Cursor::operator bool() const noexcept
    {
        return (this->_handle != nullptr);
    }

    GLFWcursor* Cursor::getHandle() const noexcept
    {
        return (this->_handle);
    }

}
