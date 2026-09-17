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


    void Monitor::init()
    {
        Monitor::cleanup();
        glfwSetMonitorCallback(Monitor::_callback);
        int count;
        GLFWmonitor** monitors = glfwGetMonitors(&count);
        if (!monitors)
            return;
        for (int i = 0; i < count; i++)
            Monitor::_registered[monitors[i]] = std::make_unique<Monitor>(monitors[i]);
        Monitor::_updateReferences();
        return;
    }

    void Monitor::cleanup() noexcept
    {
        glfwSetMonitorCallback(nullptr);
        Monitor::_registered.clear();
        Monitor::_references.clear();
        return;
    }

    std::size_t Monitor::getCount() noexcept
    {
        return (Monitor::_registered.size());
    }

    Monitor& Monitor::getPrimary() noexcept
    {
        return (Monitor::getByGLFWElement(glfwGetPrimaryMonitor()));
    }

    std::span<const std::reference_wrapper<Monitor>> Monitor::getAll() noexcept
    {
        return (Monitor::_references);
    }

    Monitor& Monitor::getByGLFWElement(GLFWmonitor* glfwMonitor) noexcept
    {
        if (glfwMonitor == nullptr || !Monitor::_registered.contains(glfwMonitor))
            return (Monitor::Invalid);
        return (*Monitor::_registered.at(glfwMonitor));
    }

    Monitor::Monitor(Monitor&& other) noexcept
        : _glfwElement(other._glfwElement)
    {
        other._glfwElement = nullptr;
        return;
    }

    Monitor::Monitor(GLFWmonitor* glfwMonitor) noexcept
        : _glfwElement(glfwMonitor)
    {
        return;
    }

    Monitor& Monitor::operator=(Monitor&& other) noexcept
    {
        if (&other == this)
            return (*this);
        this->_glfwElement = other._glfwElement;
        other._glfwElement = nullptr;
        return (*this);
    }

    Monitor::operator bool() const noexcept
    {
        return (this->_glfwElement != nullptr);
    }

    bool Monitor::isPrimary() const noexcept
    {
        return (this->_glfwElement && glfwGetPrimaryMonitor() == this->_glfwElement);
    }

    GLFWmonitor* Monitor::getGLFWElement() const noexcept
    {
        return (this->_glfwElement);
    }

    std::string Monitor::getName() const
    {
        if (!this->_glfwElement)
            return ("");
        const char* str = glfwGetMonitorName(this->_glfwElement);
        return (str ? str : "");
    }

    tbaricault::math::Vector2<int> Monitor::getPhysicalSize() const noexcept
    {
        if (!this->_glfwElement)
            return {};
        tbaricault::math::Vector2<int> size;
        glfwGetMonitorPhysicalSize(
            this->_glfwElement,
            &size.x,
            &size.y
        );
        return (size);
    }

    tbaricault::math::Vector2<float> Monitor::getScale() const noexcept
    {
        if (!this->_glfwElement)
            return {};
        tbaricault::math::Vector2<float> scale;
        glfwGetMonitorContentScale(
            this->_glfwElement,
            &scale.x,
            &scale.y
        );
        return (scale);
    }

    tbaricault::math::Rect<int> Monitor::getRect() const noexcept
    {
        if (!this->_glfwElement)
            return {};
        tbaricault::math::Rect<int> rect;
        glfwGetMonitorPos(
            this->_glfwElement,
            &rect.x,
            &rect.y
        );
        const GLFWvidmode* mode = glfwGetVideoMode(this->_glfwElement);
        if (!mode)
            return {};
        rect.w = mode->width;
        rect.h = mode->height;
        return (rect);
    }

    tbaricault::math::Rect<int> Monitor::getWorkRect() const noexcept
    {
        if (!this->_glfwElement)
            return {};
        tbaricault::math::Rect<int> rect;
        glfwGetMonitorWorkarea(
            this->_glfwElement,
            &rect.x,
            &rect.y,
            &rect.w,
            &rect.h
        );
        return (rect);
    }

    Monitor::VideoMode Monitor::getVideoMode() const noexcept
    {
        if (!this->_glfwElement)
            return {};
        const GLFWvidmode* mode = glfwGetVideoMode(this->_glfwElement);
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
        if (!this->_glfwElement)
            return {};
        int count;
        const GLFWvidmode* modes = glfwGetVideoModes(this->_glfwElement, &count);
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
        if (!this->_glfwElement)
            return (result);
        const GLFWgammaramp* ramp = glfwGetGammaRamp(this->_glfwElement);
        if (!ramp)
            return (result);
        result.red.assign(ramp->red, ramp->red + ramp->size);
        result.green.assign(ramp->green, ramp->green + ramp->size);
        result.blue.assign(ramp->blue, ramp->blue + ramp->size);
        return (result);
    }

    void Monitor::setGamma(float gamma) noexcept
    {
        if (this->_glfwElement)
            glfwSetGamma(this->_glfwElement, gamma);
        return;
    }

    void Monitor::setGammaRamp(const GammaRamp& ramp)
    {
        if (ramp.red.size() != ramp.green.size() || ramp.red.size() != ramp.blue.size())
            throw std::invalid_argument("gamma ramp components must have the same size");
        if (!this->_glfwElement)
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
        glfwSetGammaRamp(this->_glfwElement, &glfwRamp);
        return;
    }

    void Monitor::_callback(GLFWmonitor* glfwMonitor, int event)
    {
        switch (event)
        {
            case (GLFW_CONNECTED):
            {
                Monitor::_registered[glfwMonitor] = std::make_unique<Monitor>(glfwMonitor);
                Monitor::_updateReferences();
                break;
            }
            case (GLFW_DISCONNECTED):
            {
                if (Monitor::_registered.contains(glfwMonitor))
                {
                    Monitor::_registered.erase(glfwMonitor);
                    Monitor::_updateReferences();
                }
                break;
            }
        }
        Monitor::_updateReferences();
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
