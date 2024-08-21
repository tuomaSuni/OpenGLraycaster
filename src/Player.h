#include <GLFW/glfw3.h>

class Player {

public:

    Player();

    void Move(int key, int action);
    void Render() const;
        
    float GetPosX() const { return posX; }
    float GetPosY() const { return posY; }
private:
    float posX;
    float posY;
};