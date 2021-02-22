#include "Window.h"
#include "Spck/Log.h"
#include "Spck/Messaging/ApplicationEvent.h"
#include "Spck/Messaging/KeyEvent.h"

namespace Spck
{
    Window::Window()
    {
        Init();
    }

    Window::~Window()
    {
        if(m_Window)
        {
            glfwDestroyWindow(m_Window);
            glfwTerminate();
        }
    }

    void Window::Init()
    {
        SPCK_LOG_DEBUG("Creating m_Window...");

        if(!glfwInit())
        {
            SPCK_LOG_ERROR("Failed to initialize GLFW");
        }

        glfwSetErrorCallback([](int error, const char* description)
        {
            SPCK_LOG_ERROR("GLFW ERROR. Code: {}, message: {}", error, description);
            exit(EXIT_FAILURE);
        });

        glfwDefaultWindowHints();
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        // OpenGL specific stuff. Will be moved to its place when we have a clear renderer structure
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
        // OpenGL specific stuff. Will be moved to its place when we have a clear renderer structure

        m_Window = glfwCreateWindow(800, 600, "SPCK", nullptr, nullptr);
        if (m_Window == nullptr)
        {
            SPCK_LOG_ERROR("Failed to Create GLFW m_Window");
            glfwTerminate();
            exit(EXIT_FAILURE);
        }

        glfwMakeContextCurrent(m_Window);
        SPCK_LOG_DEBUG("Window created");

        glfwSetWindowUserPointer(m_Window, &m_Data);

        glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            switch (action)
            {
                case GLFW_PRESS:
                    KeyPressedEvent event(key);
                    data.EventCallback(event);
                    break;
                // TODO: handle release, repeat
            }
        });

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            WindowClosedEvent event;
            data.EventCallback(event);
        });
    }

    void Window::FrameEnd()
    {
        glfwPollEvents();
    }
}
