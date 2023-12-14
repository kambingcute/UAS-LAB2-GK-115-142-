#include <freeglut.h>
#include <cmath>

GLfloat cameraRadius = 15.0;  // Inisialisasi jarak awal kamera dari pusat
GLfloat cameraAngle = 0.0;    // Inisialisasi sudut awal kamera
GLfloat cloudPositionX = 1.5; // Awal posisi awan
GLfloat cloudDirection = 0.03; // Ukuran langkah pergeseran awan
GLfloat cloudSpeed = 0.01;

void display();
void reshape(int, int);
void init();
void specialKeys(int key, int x, int y);
void idle();

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(350, 50);
    glutInitWindowSize(1020, 900);
    glutCreateWindow("Tugas UAS Agatha & M Fauzy Harahap ");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);
    init();
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}

void drawTree() {
    // Brown cylinder
    glPushMatrix();
    glTranslatef(-5.0, -6.0, 10.0); // Adjust the position near semak-semak
    glRotatef(-90.0, 1.0, 0.0, 0.0); // Rotasi sejajar sumbu Y
    glColor3f(0.5, 0.2, 0.0); // Brown color

    GLUquadric* cylinderQuadric = gluNewQuadric();
    gluQuadricOrientation(cylinderQuadric, GLU_OUTSIDE);
    gluCylinder(cylinderQuadric, 0.2, 0.2, 2, 50, 50); // Draw a brown cylinder
    gluDeleteQuadric(cylinderQuadric);

    glPopMatrix();

    // Green cone on top of the cylinder
    glPushMatrix();
    glTranslatef(-5.0, -3.0, 10.0); // Adjust the position near semak-semak
    glRotatef(90.0, 1.0, 0.0, 0.0); // Rotasi sejajar sumbu Y
    glColor3f(0.0, 1.0, 0.0); // Green color

    GLUquadric* coneQuadric = gluNewQuadric();
    gluQuadricOrientation(coneQuadric, GLU_OUTSIDE);
    gluCylinder(coneQuadric, 0.0, 0.5, 2.0, 50, 50); // Draw a green cone with the tip upwards
    gluDeleteQuadric(coneQuadric);

    glPopMatrix();

    // Brown cylinder for the second tree
    glPushMatrix();
    glTranslatef(-2.0, -6.0, 10.0); // Adjust the position near semak-semak
    glRotatef(-90.0, 1.0, 0.0, 0.0); // Rotasi sejajar sumbu Y
    glColor3f(0.5, 0.2, 0.0); // Brown color

    GLUquadric* cylinderQuadric2 = gluNewQuadric();
    gluQuadricOrientation(cylinderQuadric2, GLU_OUTSIDE);
    gluCylinder(cylinderQuadric2, 0.2, 0.2, 0.5, 50, 50); // Draw a brown cylinder
    gluDeleteQuadric(cylinderQuadric2);

    glPopMatrix();

    // Green cone on top of the second cylinder
    glPushMatrix();
    glTranslatef(-2.0, -4.5, 10.0); // Adjust the position near semak-semak
    glRotatef(90.0, 1.0, 0.0, 0.0); // Rotasi sejajar sumbu Y
    glColor3f(0.0, 1.0, 0.0); // Green color

    GLUquadric* coneQuadric2 = gluNewQuadric();
    gluQuadricOrientation(coneQuadric2, GLU_OUTSIDE);
    gluCylinder(coneQuadric2, 0.0, 0.5, 1.0, 50, 50); // Draw a green cone with the tip upwards
    gluDeleteQuadric(coneQuadric2);

    glPopMatrix();

    // Brown cylinder for the third tree
    glPushMatrix();
    glTranslatef(2.0, -6.0, 10.0); // Adjust the position near semak-semak
    glRotatef(-90.0, 1.0, 0.0, 0.0); // Rotasi sejajar sumbu Y
    glColor3f(0.5, 0.2, 0.0); // Brown color

    GLUquadric* cylinderQuadric3 = gluNewQuadric();
    gluQuadricOrientation(cylinderQuadric3, GLU_OUTSIDE);
    gluCylinder(cylinderQuadric3, 0.2, 0.2, 0.5, 50, 50); // Draw a brown cylinder
    gluDeleteQuadric(cylinderQuadric3);

    glPopMatrix();

    // Green cone on top of the second cylinder
    glPushMatrix();
    glTranslatef(2.0, -4.5, 10.0); // Adjust the position near semak-semak
    glRotatef(90.0, 1.0, 0.0, 0.0); // Rotasi sejajar sumbu Y
    glColor3f(0.0, 1.0, 0.0); // Green color

    GLUquadric* coneQuadric3 = gluNewQuadric();
    gluQuadricOrientation(coneQuadric3, GLU_OUTSIDE);
    gluCylinder(coneQuadric3, 0.0, 0.5, 1.0, 50, 50); // Draw a green cone with the tip upwards
    gluDeleteQuadric(coneQuadric3);

    glPopMatrix();

    // Brown cylinder for the 4th tree
    glPushMatrix();
    glTranslatef(5.0, -6.0, 10.0); // Adjust the position near semak-semak
    glRotatef(-90.0, 1.0, 0.0, 0.0); // Rotasi sejajar sumbu Y
    glColor3f(0.5, 0.2, 0.0); // Brown color

    GLUquadric* cylinderQuadric4 = gluNewQuadric();
    gluQuadricOrientation(cylinderQuadric4, GLU_OUTSIDE);
    gluCylinder(cylinderQuadric4, 0.2, 0.2, 2, 50, 50); // Draw a brown cylinder
    gluDeleteQuadric(cylinderQuadric4);

    glPopMatrix();

    // Green cone on top of the cylinder
    glPushMatrix();
    glTranslatef(5.0, -3.0, 10.0); // Adjust the position near semak-semak
    glRotatef(90.0, 1.0, 0.0, 0.0); // Rotasi sejajar sumbu Y
    glColor3f(0.0, 1.0, 0.0); // Green color

    GLUquadric* coneQuadric4 = gluNewQuadric();
    gluQuadricOrientation(coneQuadric4, GLU_OUTSIDE);
    gluCylinder(coneQuadric4, 0.0, 0.5, 2.0, 50, 50); // Draw a green cone with the tip upwards
    gluDeleteQuadric(coneQuadric4);

    glPopMatrix();

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    GLfloat cameraX = cameraRadius * sin(cameraAngle); // Menghitung posisi kamera X
    GLfloat cameraZ = cameraRadius * cos(cameraAngle); // Menghitung posisi kamera Z

    gluLookAt(cameraX, 0.0, cameraZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    //front facing
    // Door
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0); 
    glVertex3f(-0.5, 0.0, 2.0);
    glVertex3f(-0.5, -1.0, 2.0);
    glVertex3f(0.0, -0.8, 2.0);
    glVertex3f(0.0, -0.2, 2.0);
    glEnd();

    //yellow door inside of white door
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.2, 0.0);
    glVertex3f(-0.5, 0.0, 2.0);
    glVertex3f(-0.5, -1.0, 2.0);
    glVertex3f(0.0, -0.8, 2.0);
    glVertex3f(0.0, -0.2, 2.0);
    glEnd();

    //white door inside of blue wall
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.5, 0.0, 2.0);
    glVertex3f(-0.5, -1.0, 2.0);
    glVertex3f(0.5, -1.0, 2.0);
    glVertex3f(0.5, 0.0, 2.0);
    glEnd();


    // Dinding depan
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5); // Gray color
    glVertex3f(-1.0, 1.0, 2.0);
    glVertex3f(-1.0, -1.0, 2.0);
    glVertex3f(1.0, -1.0, 2.0);
    glVertex3f(1.0, 1.0, 2.0);
    glEnd();

    // Brown triangle
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.3, 0.0); // Brown color
    glVertex3f(0.0, 2.0, 1.5);
    glVertex3f(-1.0, 1.0, 2.0);
    glVertex3f(1.0, 1.0, 2.0);
    glEnd();

    // Brown quads
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.3, 0.7); // Adjusted color
    glVertex3f(0.3, 1.6, 0.0);
    glVertex3f(0.6, 1.3, 0.0);
    glVertex3f(0.6, 2.3, 0.0);
    glVertex3f(0.3, 2.3, 0.0);

    glVertex3f(0.3, 1.6, 0.3);
    glVertex3f(0.6, 1.3, 0.3);
    glVertex3f(0.6, 2.3, 0.3);
    glVertex3f(0.3, 2.3, 0.3);

    glVertex3f(0.3, 2.3, 0.0);
    glVertex3f(0.3, 2.3, 0.3);
    glVertex3f(0.3, 1.6, 0.3);
    glVertex3f(0.3, 1.6, 0.0);

    glVertex3f(0.6, 2.3, 0.0);
    glVertex3f(0.6, 1.3, 0.0);
    glVertex3f(0.6, 1.3, 0.3);
    glVertex3f(0.6, 2.3, 0.3);
    glEnd();
    // Brown top
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.3, 0.0); // Brown color
    glVertex3f(0.0, 2.0, 1.5);
    glVertex3f(1.0, 1.0, 2.0);
    glVertex3f(1.0, 1.0, -2.0);
    glVertex3f(0.0, 2.0, -1.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.3, 0.0); // Brown color
    glVertex3f(0.0, 2.0, 1.5);
    glVertex3f(-1.0, 1.0, 2.0);
    glVertex3f(-1.0, 1.0, -2.0);
    glVertex3f(0.0, 2.0, -1.5);
    glEnd();

    //shape black lines on white windows
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 0.5, 0.0);
    glVertex3f(1.0, -0.5, 0.0);
    glVertex3f(1.0, 0.0, 0.5);
    glVertex3f(1.0, 0.0, -0.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-1.0, 0.0, 0.5);
    glVertex3f(-1.0, 0.0, -0.5);
    glVertex3f(-1.0, 0.5, 0.0);
    glVertex3f(-1.0, -0.5, 0.0);
    glEnd();

    //black lines for white door inside of blue wall
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-0.5, 0.0, 2.0);
    glVertex3f(-0.5, -1.0, 2.0);
    glVertex3f(0.5, -1.0, 2.0);
    glVertex3f(0.5, 0.0, 2.0);
    glEnd();

    //square shape black outline for white window
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 0.5, 0.5);
    glVertex3f(1.0, -0.5, 0.5);
    glVertex3f(1.0, -0.5, -0.5);
    glVertex3f(1.0, 0.5, -0.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-1.0, 0.5, 0.5);
    glVertex3f(-1.0, -0.5, 0.5);
    glVertex3f(-1.0, -0.5, -0.5);
    glVertex3f(-1.0, 0.5, -0.5);
    glEnd();

    //Jendela putih
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 0.5, 0.5);
    glVertex3f(1.0, -0.5, 0.5);
    glVertex3f(1.0, -0.5, -0.5);
    glVertex3f(1.0, 0.5, -0.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-1.0, 0.5, 0.5);
    glVertex3f(-1.0, -0.5, 0.5);
    glVertex3f(-1.0, -0.5, -0.5);
    glVertex3f(-1.0, 0.5, -0.5);
    glEnd();

    // Dinding kanan kiri
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5); // Gray color
    glVertex3f(1.0, 1.0, 2.0);
    glVertex3f(1.0, -1.0, 2.0);
    glVertex3f(1.0, -1.0, -2.0);
    glVertex3f(1.0, 1.0, -2.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5); // Gray color
    glVertex3f(-1.0, 1.0, 2.0);
    glVertex3f(-1.0, -1.0, 2.0);
    glVertex3f(-1.0, -1.0, -2.0);
    glVertex3f(-1.0, 1.0, -2.0);
    glEnd();

    // Dinding belakang
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5); // Gray color
    glVertex3f(-1.0, 1.0, -2.0);
    glVertex3f(-1.0, -1.0, -2.0);
    glVertex3f(1.0, -1.0, -2.0);
    glVertex3f(1.0, 1.0, -2.0);
    glEnd();

    // atap segitiga belakang
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.3, 0.0); // Brown color
    glVertex3f(0.0, 2.0, -1.5);
    glVertex3f(-1.0, 1.0, -2.0);
    glVertex3f(1.0, 1.0, -2.0);
    glEnd();

    // Rumput
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.8, 0.0); // Green color
    glVertex3f(-6.0, -1.0, 6.0);
    glVertex3f(6.0, -1.0, 6.0);
    glVertex3f(6.0, -1.0, -6.0);
    glVertex3f(-6.0, -1.0, -6.0);
    glEnd();

    //Semak Semak
    glColor3f(0.8, 0.5, 0.2); 
    glBegin(GL_TRIANGLES);
    glVertex3f(-5.0, -1.0, -5.0);
    glVertex3f(-4.8, -1.0, -5.0);
    glVertex3f(-4.9, -0.5, -5.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f(-4.0, -1.0, -4.5);
    glVertex3f(-3.8, -1.0, -4.5);
    glVertex3f(-3.9, -0.5, -4.5);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f(-3.0, -1.0, -5.5);
    glVertex3f(-2.8, -1.0, -5.5);
    glVertex3f(-2.9, -0.5, -5.5);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f(-2.0, -1.0, -4.0);
    glVertex3f(-1.8, -1.0, -4.0);
    glVertex3f(-1.9, -0.5, -4.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f(-1.0, -1.0, -5.0);
    glVertex3f(-0.8, -1.0, -5.0);
    glVertex3f(-0.9, -0.5, -5.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f(-4.0, -1.0, -5.5);
    glVertex3f(-3.8, -1.0, -5.5);
    glVertex3f(-3.9, -0.5, -5.5);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f(-2.0, -1.0, -5.0);
    glVertex3f(-1.8, -1.0, -5.0);
    glVertex3f(-1.9, -0.5, -5.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f(-3.0, -1.0, -4.0);
    glVertex3f(-2.8, -1.0, -4.0);
    glVertex3f(-2.9, -0.5, -4.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f(-5.0, -1.0, -4.5);
    glVertex3f(-4.8, -1.0, -4.5);
    glVertex3f(-4.9, -0.5, -4.5);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f(-1.0, -1.0, -4.0);
    glVertex3f(-0.8, -1.0, -4.0);
    glVertex3f(-0.9, -0.5, -4.0);
    glEnd();

    //Matahari
    glColor3f(1.0, 1.0, 0.0); // Yellow color
    glTranslatef(0.0, 5.0, -8.0); // Position the sun higher and farther behind
    glutSolidSphere(1.0, 50, 50); // Draw a yellow sphere representing the sun
    
    // Awan 
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    static GLfloat cloudPosition = 1.5; // Tentukan posisi awan awal
    cloudPosition += cloudSpeed; // Tingkatkan posisi awan dengan kecepatan
    if (cloudPosition > 7.0 || cloudPosition < -7.0) {
        cloudSpeed = -cloudSpeed; // Reset posisi awan jika sudah mencapai batas tertentu
    }
    glTranslatef(cloudPosition, 5.5, -10.0); // Ganti posisi awan
    glScalef(1.5, 0.5, 1.0);
    glutSolidSphere(1.0, 50, 50);
    glPopMatrix();

    drawTree();

    glutSwapBuffers();
}

void updateCloudPosition() {
    cloudPositionX += cloudDirection;

    // Jika awan mencapai batas sebelah kanan atau kiri, ubah arahnya
    if (cloudPositionX > 7.0 || cloudPositionX < -7.0) {
        cloudDirection = -cloudDirection;
    }
}

void idle() {
    updateCloudPosition();
    glutPostRedisplay();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (GLfloat)w / (GLfloat)h, 2.0, 50.0);
    glMatrixMode(GL_MODELVIEW);
}

//langit
void init() {
    glClearColor(0.7, 0.7, 1.0, 1.0); 
    glEnable(GL_DEPTH_TEST);
}


void specialKeys(int key, int x, int y) {
    const GLfloat angleStep = 0.1;  // Ukuran langkah pergeseran sudut kamera
    const GLfloat radiusStep = 0.1; // Ukuran langkah pergeseran jarak kamera

    switch (key) {
    case GLUT_KEY_UP:
        cameraRadius -= radiusStep;
        break;
    case GLUT_KEY_DOWN:
        cameraRadius += radiusStep;
        break;
    case GLUT_KEY_LEFT:
        cameraAngle += angleStep;
        break;
    case GLUT_KEY_RIGHT:
        cameraAngle -= angleStep;
        break;
    }

    glutPostRedisplay();
}