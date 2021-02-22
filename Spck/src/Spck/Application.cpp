#include "Application.h"
#include "Window/Window.h"
#include "Messaging/Event.h"
#include "Messaging/ApplicationEvent.h"
#include "Messaging/KeyEvent.h"

namespace Spck
{
	Application::Application() = default;

	Application::~Application() = default;

	void Application::Run()
	{
        Window window{};
        window.SetEventCallback([this](auto && PH1) { OnEvent(std::forward<decltype(PH1)>(PH1)); });

		while (m_Running)
        {
            window.FrameEnd();
        }
	}

	void Application::OnEvent(Event& event)
    {
        SPCK_LOG_DEBUG("Event arrived: {0}", event.GetName());
        // For now, we can either close it with ESC or the window's close button.
        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<WindowClosedEvent>(BIND_EVENT_FN(Application::OnWindowClosed));
        dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FN(Application::OnKeyPressed));
    }

    bool Application::OnWindowClosed(WindowClosedEvent &e)
    {
        return Shutdown();
    }

    bool Application::OnKeyPressed(KeyPressedEvent &e)
    {
	    if(e.GetKeyCode() == GLFW_KEY_ESCAPE)
        {
            return Shutdown();
        }
        return false;
    }

    bool Application::Shutdown()
    {
        SPCK_LOG_INFO("Shutting down the engine...");
        m_Running = false;
        return true;
    }


}