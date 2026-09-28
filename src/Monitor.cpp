/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#include <algorithm>
#include <stdexcept>

#include "glfwwrapper/Monitor.hpp"


namespace tbaricault::glfwwrapper
{

    Monitor Monitor::Invalid = Monitor(nullptr);

    std::unordered_map<GLFWmonitor*, std::unique_ptr<Monitor>> Monitor::_registered = {};

    std::vector<std::reference_wrapper<Monitor>> Monitor::_references = {};


    std::size_t Monitor::getCount() noexcept
    {
        return (Monitor::_registered.size());
    }

    Monitor& Monitor::getPrimary() noexcept
    {
        return (Monitor::getByHandle(glfwGetPrimaryMonitor()));
    }

    std::span<const std::reference_wrapper<Monitor>> Monitor::getAll() noexcept
    {
        return (Monitor::_references);
    }

    Monitor& Monitor::getByHandle(GLFWmonitor* handle) noexcept
    {
        if (handle == nullptr || !Monitor::_registered.contains(handle))
            return (Monitor::Invalid);
        return (*Monitor::_registered.at(handle));
    }

    Monitor::Monitor(GLFWmonitor* handle) noexcept
        : _handle(handle)
    {
        return;
    }

    bool Monitor::isPrimary() const noexcept
    {
        return (this->_handle && glfwGetPrimaryMonitor() == this->_handle);
    }

    std::string Monitor::getName() const
    {
        if (!this->_handle)
            return ("");
        const char* str = glfwGetMonitorName(this->_handle);
        return (str ? str : "");
    }

    tbaricault::math::Vector2<int> Monitor::getPhysicalSize() const noexcept
    {
        if (!this->_handle)
            return {};
        tbaricault::math::Vector2<int> size;
        glfwGetMonitorPhysicalSize(
            this->_handle,
            &size.x,
            &size.y
        );
        return (size);
    }

    tbaricault::math::Vector2<float> Monitor::getScale() const noexcept
    {
        if (!this->_handle)
            return {};
        tbaricault::math::Vector2<float> scale;
        glfwGetMonitorContentScale(
            this->_handle,
            &scale.x,
            &scale.y
        );
        return (scale);
    }

    tbaricault::math::Rect<int> Monitor::getRect() const noexcept
    {
        if (!this->_handle)
            return {};
        tbaricault::math::Rect<int> rect;
        glfwGetMonitorPos(
            this->_handle,
            &rect.x,
            &rect.y
        );
        const GLFWvidmode* mode = glfwGetVideoMode(this->_handle);
        if (!mode)
            return {};
        rect.w = mode->width;
        rect.h = mode->height;
        return (rect);
    }

    tbaricault::math::Rect<int> Monitor::getWorkRect() const noexcept
    {
        if (!this->_handle)
            return {};
        tbaricault::math::Rect<int> rect;
        glfwGetMonitorWorkarea(
            this->_handle,
            &rect.x,
            &rect.y,
            &rect.w,
            &rect.h
        );
        return (rect);
    }

    Monitor::VideoMode Monitor::getVideoMode() const noexcept
    {
        if (!this->_handle)
            return {};
        const GLFWvidmode* mode = glfwGetVideoMode(this->_handle);
        if (!mode)
            return {};
        return {
            {
                mode->width,
                mode->height
            },
            mode->redBits,
            mode->greenBits,
            mode->blueBits,
            mode->refreshRate
        };
    }

    std::vector<Monitor::VideoMode> Monitor::getVideoModes() const
    {
        if (!this->_handle)
            return {};
        int count;
        const GLFWvidmode* modes = glfwGetVideoModes(this->_handle, &count);
        if (modes == nullptr)
            return {};
        std::vector<Monitor::VideoMode> result;
        result.reserve(count);
        for (int i = 0; i < count; i++)
        {
            result.push_back({
                {
                    modes[i].width,
                    modes[i].height
                },
                modes[i].redBits,
                modes[i].greenBits,
                modes[i].blueBits,
                modes[i].refreshRate
            });
        }
        return (result);
    }

    Monitor::GammaRamp Monitor::getGammaRamp() const
    {
        GammaRamp result;
        if (!this->_handle)
            return (result);
        const GLFWgammaramp* ramp = glfwGetGammaRamp(this->_handle);
        if (!ramp)
            return (result);
        result.red.assign(ramp->red, ramp->red + ramp->size);
        result.green.assign(ramp->green, ramp->green + ramp->size);
        result.blue.assign(ramp->blue, ramp->blue + ramp->size);
        return (result);
    }

    void Monitor::setGamma(float gamma) noexcept
    {
        if (this->_handle)
            glfwSetGamma(this->_handle, gamma);
        return;
    }

    void Monitor::setGammaRamp(const GammaRamp& ramp)
    {
        if (ramp.red.size() != ramp.green.size() || ramp.red.size() != ramp.blue.size())
            throw std::invalid_argument("gamma ramp components must have the same size");
        if (!this->_handle)
            return;
        GLFWgammaramp glfwRamp = {
            const_cast<unsigned short*>(ramp.red.data()),
            const_cast<unsigned short*>(ramp.green.data()),
            const_cast<unsigned short*>(ramp.blue.data()),
            static_cast<unsigned int>(std::min({
                ramp.red.size(),
                ramp.green.size(),
                ramp.blue.size()
            }))
        };
        glfwSetGammaRamp(this->_handle, &glfwRamp);
        return;
    }

    void Monitor::_destroy() noexcept
    {
        this->_handle = nullptr;
        return;
    }

    void Monitor::_callback(GLFWmonitor* handle, int event)
    {
        switch (event)
        {
            case (GLFW_CONNECTED):
            {
                Monitor::_registered[handle] = std::make_unique<Monitor>(handle);
                Monitor::_updateReferences();
                break;
            }
            case (GLFW_DISCONNECTED):
            {
                if (Monitor::_registered.contains(handle))
                {
                    Monitor::_registered.erase(handle);
                    Monitor::_updateReferences();
                }
                break;
            }
        }
        return;
    }

    void Monitor::_updateReferences()
    {
        Monitor::_references.clear();
        Monitor::_references.reserve(Monitor::_registered.size());
        for (const auto& [_, monitor] : Monitor::_registered)
            Monitor::_references.push_back(*monitor);
        return;
    }

}
