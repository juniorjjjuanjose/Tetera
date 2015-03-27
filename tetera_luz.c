#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

void ponerMaterial();//Declaracion de la funcion que asignara los materiales

void init(void)
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0); //Activamos las luces en 0
    glDepthFunc(GL_LESS); //comparación de profundidad
    glEnable(GL_DEPTH_TEST); //activa GL_DEPTH_TEST
}

//Definicion de constantes para Ambient
GLfloat AX = 0.329412f;
GLfloat AY = 0.223529f;
GLfloat AZ = 0.027451f;

//Definicion de constantes para Diffuse
GLfloat DX = 0.780392f;
GLfloat DY = 0.568627f;
GLfloat DZ = 0.113725f;

//Definicion de constantes para Spectacular
GLfloat SX = 0.992157f;
GLfloat SY = 0.941176f;
GLfloat SZ = 0.807843f;

//Definicion de Shine
GLfloat SH = 27.8974f;

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
// Activamos la matriz de proyeccion.
    glMatrixMode(GL_PROJECTION);
// "limpiamos" esta con la matriz identidad.
    glLoadIdentity();
// Usamos proyeccion ortogonal
    glOrtho(-300, 300, -300, 300, -300, 300);
// Activamos la matriz de modelado/visionado.
    glMatrixMode(GL_MODELVIEW);
// "Limpiamos" la matriz
    glLoadIdentity();
}
void display(void)
{
    GLfloat mat_ambient[] = {AX, AY, AZ};
    GLfloat mat_diffuse[] = {DX, DY, DZ};
    GLfloat mat_specular[] = {SX, SY, SZ};
    GLfloat shine[] = {SH};
// "Limpiamos" el frame buffer con el color de "Clear", en este
// caso negro.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode( GL_MODELVIEW_MATRIX );
    glLoadIdentity();

// Rotacion de 25 grados en torno al eje x
    glRotated(25.0, 1.0, 0.0, 0.0);
// Rotacion de -30 grados en torno al eje y
    glRotated(-30.0, 0.0, 1.0, 0.0);
// Dibujamos una "Tetera" y le aplico el material
    glPushMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);

    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);

    glMaterialfv(GL_FRONT, GL_SHININESS, shine);
//setMaterial
    glutSolidTeapot(110.0);
    glFlush();
}

int tecla;

void keyboard(unsigned char key, int x, int y)
{
    switch (key)

    {
    case 49:
        tecla = 1;
        ponerMaterial();
        break;

    case 50:
        tecla = 2 ;
        ponerMaterial();
        break;

    case 51:
        tecla = 3;
        ponerMaterial();
        break;

    case 52:
        tecla = 4;
        ponerMaterial();
        break;

    case 53:
        tecla = 5;
        ponerMaterial();
        break;
    }

    glutPostRedisplay();// actualización de visualización
}

void ponerMaterial()
{
    if (tecla == 1)
    {
        AX=0.135;
        AY=0.2225;
        AZ=0.1575;
        DX=0.54;
        DY=0.89;
        DZ=0.63;
        SX=0.316228;
        SY=0.316228;
        SZ=0.316228;
        SH=0.1;
    }
    if (tecla == 2)
    {
        AX=0.05375;
        AY=0.05;
        AZ=0.06625;
        DX=0.18275;
        DY=0.17;
        DZ=0.22525;
        SX=0.332741;
        SY=0.328634;
        SZ=0.346435;
        SH=0.3;
    }
    if (tecla == 3)
    {
        AX=0.25;
        AY=0.20725;
        AZ=0.20725;
        DX=1.0;
        DY=0.829;
        DZ=0.829;
        SX=0.296648;
        SY=0.296648;
        SZ=0.296648;
        SH=0.088;
    }
    if (tecla == 4)
    {
        AX=0.1745;
        AY=0.01175;
        AZ=0.01175;
        DX=0.61424;
        DY=0.04136;
        DZ=0.04136;
        SX=0.727811;
        SY=0.626959;
        SZ=0.625969;
        SH=0.6;
    }
    if (tecla == 5)
    {
        AX=0.1;
        AY=0.18725;
        AZ=0.01745;
        DX=0.396;
        DY=0.74151;
        DZ=0.69102;
        SX=0.297254;
        SY=0.30829;
        SZ=0.306678;
        SH=0.1;
    }

}

int main(int argc, char **argv)
{
// Inicializo OpenGL
    glutInit(&argc, argv);
// Activamos buffer simple y colores del tipo RGB
    glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH);
// Definimos una ventana de medidas 800 x 600 como ventana
// de visualizacion en pixels
    glutInitWindowSize (700, 500);
// Posicionamos la ventana en la esquina superior izquierda de
// la pantalla.
    glutInitWindowPosition (0, 0);
// Creamos literalmente la ventana y le adjudicamos el nombre que se
// observara en su barra de titulo.
    glutCreateWindow ("Tetera_Cambia_Color");
// Inicializamos el sistema
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard); //Llamado de la funcion que detecta la tecla precionada
    glutMainLoop();
    return 0;
}
