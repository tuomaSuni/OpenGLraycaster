#include <stdexcept>
#include <GLFW/glfw3.h>
#include "Player.h"

class App {
public:

    App();

    void Execute();
    void Initialize();
    void Loop();
    void Terminate();

private:

    GLFWwindow* window = NULL;
    const GLFWvidmode* videoMode = NULL;

    const int windowWidth = 960;
    const int windowHeight = 540;

    Player player;
};