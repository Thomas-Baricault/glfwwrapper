/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#include "glfwwrapper/events.hpp"


namespace tbaricault::glfwwrapper::events
{

    void poll(double timeout) noexcept
    {
        if (timeout < 0)
            glfwWaitEvents();
        else if (timeout == 0)
            glfwPollEvents();
        else
            glfwWaitEventsTimeout(timeout);
        return;
    }

    void wakeUp() noexcept
    {
        glfwPostEmptyEvent();
        return;
    }

}
