#include "EntryPoint.h"
#include "framework/Application.h"

int main()
{
    SPKT::Application* app = GetApplication();
    app->Run();
    delete app;
}

