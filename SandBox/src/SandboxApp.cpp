//(C) POW Game std 2025

#include"Pow.h"

class Sanbox : public POW::Application
{
	
public:
	Sanbox(){}
	~Sanbox(){}
};

POW::Application* POW::CreateApplication()
{
	return new Sanbox();
}