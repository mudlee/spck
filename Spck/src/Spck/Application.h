#pragma once

#include "Core.h"

namespace Spck 
{
	class SPCK_API Application
	{
	public:
		Application();
		virtual ~Application();
		void run();
	};

	Application* CreateApplication();
}

