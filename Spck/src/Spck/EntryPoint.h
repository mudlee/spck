#pragma once
#include <stdio.h>

#ifdef SPCK_PLATFORM_WINDOWS

extern Spck::Application* Spck::CreateApplication();

int main(int argc, char** argv)
{
	Spck::Log::Init();
	SPCK_LOG_INFO("Starting Spck Engine...");

	auto app = Spck::CreateApplication();
	app->run();

	delete app;
	return 0;
}
#else
	#error Currently only Windows is supported.
#endif

