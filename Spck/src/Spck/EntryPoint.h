#pragma once

extern Spck::Application* Spck::CreateApplication();

int main(int argc, char** argv)
{
	Spck::Log::Init();
	SPCK_LOG_INFO("Hello. Starting Spck Engine...");

	auto app = Spck::CreateApplication();
    app->Run();

	delete app;
	return 0;
}

