#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <functional>
#include "Spck/API.h"
#include "Spck/Messaging/Event.h"

namespace Spck
{
    using EventCallbackFn = std::function<void(Event&)>;

    class SPCK_API Window
    {
    public:
        Window();

        virtual ~Window();

        void SetEventCallback(const EventCallbackFn& callback) { m_Data.EventCallback = callback; }

        void FrameEnd();
    private:
        void Init();

    private:
        struct WindowData
        {
            EventCallbackFn EventCallback;
        };

        GLFWwindow* m_Window;
        WindowData m_Data;
    };
}
