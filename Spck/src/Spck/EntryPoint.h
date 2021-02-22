#pragma once
#include <stdio.h>

extern Spck::Application* Spck::CreateApplication();

int main(int argc, char** argv)
{
	Spck::Log::Init();
	SPCK_LOG_INFO("Hello. Starting Spck Engine...");

	auto app = Spck::CreateApplication();
	app->run();

	delete app;
	return 0;
}

