#include "gamemaster.h"
#include <string>


GameMaster  master;
bool is_start = true;
int width;
int height;
GLfloat button_width = 0.3;
GLfloat button_height = 0.2;

void changeSize(int w, int h) {

    master.setWidth(w);
    master.setHeight(h);

    width = w;
    height = h;

    // Use the Projection Matrix
    glMatrixMode(GL_PROJECTION);

    // Reset Matrix
    glLoadIdentity();

    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Get Back to the Modelview
    glMatrixMode(GL_MODELVIEW);
}

void drawString(float x, float y, float z, std::string string) {
    glRasterPos3f(x, y, z);

    for (const auto c : string) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);  // Updates the position
    }
}

void renderButton() {
    glBegin(GL_QUADS);
    glColor3f(0.3,0.7,0.6);
    glVertex3f(0.5 - button_width / 2, 0.5 - button_height / 2, 0.1);
    glVertex3f(0.5 - button_width / 2, 0.5 + button_height / 2, 0.1);
    glVertex3f(0.5 + button_width / 2, 0.5 + button_height / 2, 0.1);
    glVertex3f(0.5 + button_width / 2, 0.5 - button_height / 2, 0.1);
    glEnd();

    // Render the text
    glColor3d(1.0,1.0,1.0);
    drawString(0.38, 0.5, 0.2, "START");
}

void renderKills()
{
    glColor3d(1.0,1.0,1.0);
    drawString(0.9, 0.9, 0.2, std::to_string(master.getKills()));
}


void renderScene(void) {

    // Clear Color and Depth Buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity();

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex3f( 0.33f, 0.0f, 0.0f);
    glVertex3f( 0.33f, 1.0f, 0.0f);
    glEnd();
    glPopMatrix();



    if (master.getGameStatus())
    {
        master.step(0.016);
    } else
    {
        renderButton();
    }
    renderKills();


    glutSwapBuffers();
}

void mouseMove(int x, int y)
{

    GLfloat mouseX = 1.0 * x / master.getWidth() ;
    GLfloat mouseY = 1.0 - 1.0 * y / master.getHeight() ;
    master.setMousePos(mouseX, mouseY);
}

void mouseClick(int button, int state, int x, int y)
{
    if (master.getGameStatus())
    {
        if (state == GLUT_DOWN &&
            button == GLUT_LEFT_BUTTON)
        {
            master.playerShoot();
        }
    } else {
        if (state == GLUT_DOWN &&
            button == GLUT_LEFT_BUTTON &&
            x >= static_cast<int>(width * (0.5 - button_width / 2)) && x <= static_cast<int>(width * (0.5 + button_width / 2)) &&
            y >= static_cast<int>(height * (0.5 - button_height / 2)) && y <= static_cast<int>(height * (0.5 + button_height / 2)))
        {
            master.startGame();
        }
    }
}


int main(int argc, char **argv) {

    //GameMaster::init(argc, argv);

    // init GLUT and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(640,480);
    glutCreateWindow("Lighthouse3D- GLUT Tutorial");

    // register callbacks
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);

    //glutMotionFunc(mouseMove);
    glutPassiveMotionFunc(mouseMove);
    glutMouseFunc(mouseClick);

    // enter GLUT event processing cycle
    glutMainLoop();
    return 1;
}
