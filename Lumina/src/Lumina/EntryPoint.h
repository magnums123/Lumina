#pragma once
#include <Lumina/Application.h>

extern Lumina::Application* Lumina::CreateApplication();

int main(int argc, char* argv[])
{
    auto app = Lumina::CreateApplication();
    app->Run();
    delete app;
    return 0;
}
