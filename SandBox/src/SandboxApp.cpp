//Copyright POW Game std

#include"Pow.h"
#include <POW/Core/EntryPoint.h>
#include"ExampleLayer.h"

class Sanbox : public POW::Application
{	
public:
	Sanbox() { PushLayer(new ExampleLayer() ); }
	~Sanbox(){}
};

POW::Application* POW::CreateApplication()
{
	return new Sanbox();
}