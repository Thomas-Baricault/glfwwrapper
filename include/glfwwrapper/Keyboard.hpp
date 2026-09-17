/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#pragma once


#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Device.hpp"


namespace tbaricault::glfwwrapper
{

    /**
     * @brief Keyboard wrapper
     */
    class Keyboard final
        : public Device
    {

        public:

            /**
             * @brief Keyboard key
             */
            enum class Key
            {

                A = GLFW_KEY_A,

                Apostrophe = GLFW_KEY_APOSTROPHE,

                B = GLFW_KEY_B,

                BackSlash = GLFW_KEY_BACKSLASH,

                BackSpace = GLFW_KEY_BACKSPACE,

                C = GLFW_KEY_C,

                CapsLock = GLFW_KEY_CAPS_LOCK,

                Comma = GLFW_KEY_COMMA,

                D = GLFW_KEY_D,

                Delete = GLFW_KEY_DELETE,

                Down = GLFW_KEY_DOWN,

                E = GLFW_KEY_E,

                End = GLFW_KEY_END,

                Enter = GLFW_KEY_ENTER,

                Equal = GLFW_KEY_EQUAL,

                Escape = GLFW_KEY_ESCAPE,

                F = GLFW_KEY_F,

                F1 = GLFW_KEY_F1,

                F2 = GLFW_KEY_F2,

                F3 = GLFW_KEY_F3,

                F4 = GLFW_KEY_F4,

                F5 = GLFW_KEY_F5,

                F6 = GLFW_KEY_F6,

                F7 = GLFW_KEY_F7,

                F8 = GLFW_KEY_F8,

                F9 = GLFW_KEY_F9,

                F10 = GLFW_KEY_F10,

                F11 = GLFW_KEY_F11,

                F12 = GLFW_KEY_F12,

                F13 = GLFW_KEY_F13,

                F14 = GLFW_KEY_F14,

                F15 = GLFW_KEY_F15,

                F16 = GLFW_KEY_F16,

                F17 = GLFW_KEY_F17,

                F18 = GLFW_KEY_F18,

                F19 = GLFW_KEY_F19,

                F20 = GLFW_KEY_F20,

                F21 = GLFW_KEY_F21,

                F22 = GLFW_KEY_F22,

                F23 = GLFW_KEY_F23,

                F24 = GLFW_KEY_F24,

                F25 = GLFW_KEY_F25,

                G = GLFW_KEY_G,

                GRAVE_ACCENT = GLFW_KEY_GRAVE_ACCENT,

                H = GLFW_KEY_H,

                Home = GLFW_KEY_HOME,

                I = GLFW_KEY_I,

                Insert = GLFW_KEY_INSERT,

                J = GLFW_KEY_J,

                K = GLFW_KEY_K,

                KeyPad0 = GLFW_KEY_KP_0,

                KeyPad1 = GLFW_KEY_KP_1,

                KeyPad2 = GLFW_KEY_KP_2,

                KeyPad3 = GLFW_KEY_KP_3,

                KeyPad4 = GLFW_KEY_KP_4,

                KeyPad5 = GLFW_KEY_KP_5,

                KeyPad6 = GLFW_KEY_KP_6,

                KeyPad7 = GLFW_KEY_KP_7,

                KeyPad8 = GLFW_KEY_KP_8,

                KeyPad9 = GLFW_KEY_KP_9,

                KeyPadDecimal = GLFW_KEY_KP_DECIMAL,

                KeyPadDivide = GLFW_KEY_KP_DIVIDE,

                KeyPadEnter = GLFW_KEY_KP_ENTER,

                KeyPadEqual = GLFW_KEY_KP_EQUAL,

                KeyPadMultiply = GLFW_KEY_KP_MULTIPLY,

                KeyPadSubtract = GLFW_KEY_KP_SUBTRACT,

                L = GLFW_KEY_L,

                Left = GLFW_KEY_LEFT,

                /**
                 * @brief Left alt key
                 */
                LeftAlt = GLFW_KEY_LEFT_ALT,

                LeftBracket = GLFW_KEY_LEFT_BRACKET,

                /**
                 * @brief Left control key
                 */
                LeftControl = GLFW_KEY_LEFT_CONTROL,

                /**
                 * @brief Left shift key
                 */
                LeftShift = GLFW_KEY_LEFT_SHIFT,

                /**
                 * @brief Left super key
                 */
                LeftSuper = GLFW_KEY_LEFT_SUPER,

                M = GLFW_KEY_M,

                Main0 = GLFW_KEY_0,

                Main1 = GLFW_KEY_1,

                Main2 = GLFW_KEY_2,

                Main3 = GLFW_KEY_3,

                Main4 = GLFW_KEY_4,

                Main5 = GLFW_KEY_5,

                Main6 = GLFW_KEY_6,

                Main7 = GLFW_KEY_7,

                Main8 = GLFW_KEY_8,

                Main9 = GLFW_KEY_9,

                Menu = GLFW_KEY_MENU,

                Minus = GLFW_KEY_MINUS,

                N = GLFW_KEY_N,

                NumLock = GLFW_KEY_NUM_LOCK,

                O = GLFW_KEY_O,

                P = GLFW_KEY_P,

                PageDown = GLFW_KEY_PAGE_DOWN,

                PageUp = GLFW_KEY_PAGE_UP,

                Pause = GLFW_KEY_PAUSE,

                Period = GLFW_KEY_PERIOD,

                PrintScreen = GLFW_KEY_PRINT_SCREEN,

                Q = GLFW_KEY_Q,

                R = GLFW_KEY_R,

                Right = GLFW_KEY_RIGHT,

                /**
                 * @brief Right alt key
                 */
                RightAlt = GLFW_KEY_RIGHT_ALT,

                RightBracket = GLFW_KEY_RIGHT_BRACKET,

                /**
                 * @brief Right control key
                 */
                RightControl = GLFW_KEY_RIGHT_CONTROL,

                /**
                 * @brief Right shift key
                 */
                RightShift = GLFW_KEY_RIGHT_SHIFT,

                /**
                 * @brief Right super key
                 */
                RightSuper = GLFW_KEY_RIGHT_SUPER,

                S = GLFW_KEY_S,

                ScrollLock = GLFW_KEY_SCROLL_LOCK,

                SemiColon = GLFW_KEY_SEMICOLON,

                Slash = GLFW_KEY_SLASH,

                Space = GLFW_KEY_SPACE,

                T = GLFW_KEY_T,

                Tab = GLFW_KEY_TAB,

                U = GLFW_KEY_U,

                Unknown = GLFW_KEY_UNKNOWN,

                Up = GLFW_KEY_UP,

                V = GLFW_KEY_V,

                W = GLFW_KEY_W,

                World1 = GLFW_KEY_WORLD_1,

                World2 = GLFW_KEY_WORLD_2,

                X = GLFW_KEY_X,

                Y = GLFW_KEY_Y,

                Z = GLFW_KEY_Z,

            };


            /**
             * @brief Returns the scancode of a specific key
             * 
             * @param key Key identifier
             * 
             * @return Key scancode or -1 on error
             */
            static int getScancode(Key key) noexcept;

            /**
             * @brief Returns the printable name of a key
             * 
             * @param key Key identifier
             * 
             * @return Key printable name or an empty string if the key is unknow
             */
            static std::string getKeyName(Key key);

            /**
             * @brief Returns the printable name of a key by its scancode
             * 
             * @param scancode Key scancode
             * 
             * @return Key printable name or an empty string if the scancode is unknow
             */
            static std::string getScancodeName(int scancode);

            /**
             * @brief Default constructor is disabled
             */
            Keyboard() = delete;

    };

}
