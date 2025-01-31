//Copyright POW Game std

#pragma once
#include"Pow/Core/Layer.h"
#include"Pow/Core/Log.h"
class ExampleLayer : public POW::Layer
{
public:
	ExampleLayer():Layer("Example Layer 1"){}

	virtual void OnUpdate() override { PE_TRACE("E.g.Layer::OnUpdate call"); }

	void OnEvent(POW::Event& event) override { PE_TRACE("E.g ::  On Event{0}", event.ToString()); }
};

