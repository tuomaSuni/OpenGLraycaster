#include <stdexcept>
#include <GLFW/glfw3.h>

class App {
public:

    App();

    void Execute();
    void Initialize();
    void Loop();
    void Terminate();
private:
    GLFWwindow* window;
};