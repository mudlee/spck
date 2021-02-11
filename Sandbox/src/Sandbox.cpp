#include <iostream>
#include <Spck.h>

class Sandbox : public Spck::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Spck::Application* Spck::CreateApplication()
{
	return new Sandbox();
}