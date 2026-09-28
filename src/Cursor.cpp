/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#include "glfwwrapper/Cursor.hpp"


namespace tbaricault::glfwwrapper
{

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
        this->_destroy();
        return;
    }

    void Cursor::_destroy() noexcept
    {
        if (this->_handle)
        {
            glfwDestroyCursor(this->_handle);
            this->_handle = nullptr;
        }
        return;
    }

}
