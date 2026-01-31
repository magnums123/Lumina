#pragma once
#include <Lumina.h>

extern Lumina::Application* Lumina::CreateApplication();

int main(int argc, char* argv[])
{
    Lumina::Logger::Init();
    LM_CORE_INFO("Hello from core");
    LM_INFO("Hello from client");

    auto app = Lumina::CreateApplication();
    app->Run();
    delete app;
    return 0;
}
