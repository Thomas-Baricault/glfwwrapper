/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#include "Wrapper.hpp"


namespace tbaricault::glfwwrapper
{

    template<typename T>
    Wrapper<T>::Wrapper(Wrapper&& other) noexcept
        : _handle(other._handle)
    {
        other._handle = nullptr;
        return;
    }

    template<typename T>
    Wrapper<T>& Wrapper<T>::operator=(Wrapper&& other) noexcept
    {
        if (&other == this)
            return (*this);
        this->_destroy();
        this->_handle = other._handle;
        other._handle = nullptr;
        return (*this);
    }

    template<typename T>
    Wrapper<T>::operator bool() const noexcept
    {
        return (this->_handle != nullptr);
    }

    template<typename T>
    T* Wrapper<T>::getHandle() const noexcept
    {
        return (this->_handle);
    }

}
