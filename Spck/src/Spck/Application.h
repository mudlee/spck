#pragma once

#include "Spck/Messaging/KeyEvent.h"
#include "API.h"
#include "Spck/Log.h"
#include "Spck/Messaging/Event.h"
#include "Spck/Messaging/ApplicationEvent.h"

namespace Spck 
{
	class SPCK_API Application
	{
	public:
		Application();

		virtual ~Application();

		void Run();

    private:
	    void OnEvent(Event& event);
        bool OnWindowClosed(WindowClosedEvent& e);
        bool OnKeyPressed(KeyPressedEvent& e);
        bool Shutdown();

	private:
	    bool m_Running = true;
	};

	Application* CreateApplication();
}

