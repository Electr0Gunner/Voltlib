#include <iostream>
#include <App.hpp>

int main(int, char**){
    std::unique_ptr<Volt::App> app = std::make_unique<Volt::App>();
    app->Init();
    app->Start();
}
