#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
void init(void)
{
    /* selecciona el color de borrado */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
}

//Definicion de constantes
GLfloat X = 0.1f;
GLfloat Y = 0.1f;
GLfloat Z = 0.0f;
GLfloat scale = 1.0f;

void display(void)
{
    /* borra la pantalla */
    glClear (GL_COLOR_BUFFER_BIT);
    /* seleccionamos la matriz modelo/vista */
    glMatrixMode(GL_MODELVIEW);
    /* color */
    glColor3f(1.0, 0.0, 1.0);
    glLoadIdentity();
    /*glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    glRotatef( rotate_z, 0.0, 0.0, 1.0 );
    //glTranslatef(X, Y, Z);*/

    glScalef( scale, scale, scale );

    /* transformación modelo/vista */
    gluLookAt(X,Y,Z, //punto de vista en el eje X,Y,Z
              0.0,0.0,0.0, //Centro del Objeto en el eje X,Y,Z
              0.0,1.0,0.0); //Orientación de la cámara (vector UP el eje X,Y,Z)
    /* Dibujamos una tetera */
    glutWireTeapot(0.5);
    /* Vacia el buffer de dibujo */
    glFlush ();
}
/*void reshape(int w, int h)
{
 /* definemos el marco */
/*glViewport(0, 0, w, h);
/* cambiamos a la matriz de proyección */
//glMatrixMode(GL_PROJECTION);
/* definimos una proyección perspectiva con
un fovy de 60 grados y el near a 1.0 y el
far a 20.0 */
/*glLoadIdentity();
gluPerspective(60.0, GLfloat(w) / GLfloat(h), 1.0, 20.0);
}*/

void keyboard(unsigned char key, int x, int y)//Funcion que sirve para el uso de las teclas +,-,X,Y,Z y
{
    switch (key)
    {
    case 45:
        scale=0.5;
        break;
    case 43:
        scale=1.5;
        break;
    case 'x' :
        X = 0.9f;
        Y = 0.1f;
        Z = 0.1f;
        break;
    case 'y' :
        Y = 0.9f;
        X = 0.1f;
        Z = 0.1f;
        break;
    case 'z' :
        Z = 0.9f;
        Y = 0.1f;
        X = 0.1f;
        break;
    case 'X' :
        X = 0.9f;
        Y = 0.1f;
        Z = 0.1f;
        break;
    case 'Y' :
        Y = 0.9f;
        X = 0.1f;
        Z = 0.1f;
        break;
    case 'Z' :
        Z = 0.9f;
        Y = 0.1f;
        X = 0.1f;
        break;
    case 27:
        exit(0);
    }

    glutPostRedisplay();//Actualización de visualización
}
int main(int argc, char** argv)
{
// Inicializa la librería auxiliar GLUT
    glutInit(&argc, argv);
// Inicializa el modo de visualización
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
// Indica el tamaño de la ventana (ancho,alto)
    glutInitWindowSize(500, 500);
// Indica la posición inicial (xmin,ymin)
    glutInitWindowPosition(100, 100);
// Abre la ventana con el título indicado
    glutCreateWindow("Tetera en 3 Dimenciones");
// Inicializar valores
    init();
// Indica cual es la función de dibujo
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
// Indica cual es la función para el cambio de tamaño de la ventana
//glutReshapeFunc(reshape);
// Comienza el bucle de dibujo y proceso de eventos.
    glutMainLoop();
}
