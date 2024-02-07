

#include <GL/glew.h> 
#include <GLFW/glfw3.h> 
#include <iostream>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <vector>
#include "Mesh.h"
#include "Shader.h"
#include "Window.h"
#include "Camara.h"
#include <stack>
#include <math.h>



//Dimensiones de la ventana 


//const GLint WIDTH = 800, HEIGHT = 600;

//Convertimos a radianes 
const float	toRadians = 3.14159265f / 180.0f;

Window mainWindow;
std::vector<Mesh*> meshList;
std::vector<Shader> shaderList;
Camara camara;

GLfloat deltaTime = 0.0f;
GLfloat lastTime = 0.0f;


bool direction = true;
float triOffset = 0.0f;
float triMaxoffSet = 0.7f;
float triIncrement = 0.0005f;
float curAnglebrazos = 0.0f;
float curAngle_antebrazos = 0.0f;
float curAngle_piernas = 0.0f;
float curAngle_piernas_P = 0.0f;
float curAngle_Hombros = 0.0f;
float spinNeck = 0.0f;
float spinTorso = 0.0f;
float raiseBicep = 0.0f;
float curSize = 0.0f;
float maxSize = 90.0f;
float minSize = -90.0f;
bool sizeDirection = true;
float oscilatebrazos = 0.01f;
float oscilate_antebrazos = 0.01f;
float oscilate_piernas = 0.01f;
float oscilate_piernas_P = 0.01f;
float oscilate_Hombros = 0.01f;
float oscilate_Neck = 0.01f;
float spinNose = 0.0f;


//Creamos vertex shader 
static const char* vShader = "Shaders/shader.vert";


static const char* fShader = "Shaders/shader.frag";

//CREACIONES DE OBJETOS ,FUNCIONES PARA QUE TENGA SENTIDO LA MANIU


void CreateObjects() {


	unsigned int indicesCUBO[] = {
		7, 4, 5,
		7, 6, 5,
		3, 0, 1,
		3, 2, 1,
		6, 5, 1,
		6, 2, 1,
		7, 4, 0,
		7, 3, 0,
		3, 7, 6,
		3, 2, 6,
		0, 4, 5,
		0, 1, 5
	};
	GLfloat verticesCUBO[]{
		0.0f, 0.0f, 0.0f,//0
		1.0f, 0.0f, 0.0f,//1
		1.0f, 1.0f, 0.0f,//2
		0.0f, 1.0f, 0.0f,//3
		0.0f, 0.0f, 1.0f,//4
		1.0f, 0.0f, 1.0f,//5
		1.0f, 1.0f, 1.0f,//6
		0.0f, 1.0f, 1.0f //7
	};


	
	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(verticesCUBO, indicesCUBO, 24, 36);
	meshList.push_back(obj1);


	Mesh* obj2 = new Mesh();
	obj2->CreateMesh(verticesCUBO, indicesCUBO, 24, 36);
	meshList.push_back(obj2);

	
	Mesh* obj3 = new Mesh();
	obj3->CreateMesh(verticesCUBO, indicesCUBO, 24, 36);
	meshList.push_back(obj3);

	
	Mesh* obj4 = new Mesh();
	obj4->CreateMesh(verticesCUBO, indicesCUBO, 24, 36);
	meshList.push_back(obj4);

	
	Mesh* obj5 = new Mesh();
	obj5->CreateMesh(verticesCUBO, indicesCUBO, 24, 36);
	meshList.push_back(obj5);

	
	Mesh* obj6 = new Mesh();
	obj6->CreateMesh(verticesCUBO, indicesCUBO, 24, 36);
	meshList.push_back(obj6);

	
	Mesh* obj7 = new Mesh();
	obj7->CreateMesh(verticesCUBO, indicesCUBO, 24, 36);
	meshList.push_back(obj7);

	Mesh* obj8 = new Mesh();
	obj8->CreateMesh(verticesCUBO, indicesCUBO, 24, 36);
	meshList.push_back(obj8);

	Mesh* obj9 = new Mesh();
	obj9->CreateMesh(verticesCUBO, indicesCUBO, 24, 36);
	meshList.push_back(obj9);


	Mesh* obj10 = new Mesh();
	obj10->CreateMesh(verticesCUBO, indicesCUBO, 24, 36);
	meshList.push_back(obj10);


	Mesh* obj11 = new Mesh();
	obj11->CreateMesh(verticesCUBO, indicesCUBO, 24, 36);
	meshList.push_back(obj11);


	Mesh* obj12 = new Mesh();
	obj12->CreateMesh(verticesCUBO, indicesCUBO, 24, 36);
	meshList.push_back(obj12);


	Mesh* obj13 = new Mesh();
	obj13->CreateMesh(verticesCUBO, indicesCUBO, 24, 36);
	meshList.push_back(obj13);



	Mesh* obj14 = new Mesh();
	obj14->CreateMesh(verticesCUBO, indicesCUBO, 24, 36);
	meshList.push_back(obj14);

	Mesh* obj15 = new Mesh();
	obj15->CreateMesh(verticesCUBO, indicesCUBO, 24, 36);
	meshList.push_back(obj15);


}


void CreateShaders() {
	Shader* shader1 = new Shader();
	shader1->CreateFromFiles(vShader, fShader);
	shaderList.push_back(*shader1);
}

int main() {

	mainWindow = Window(800, 600);
	mainWindow.Initialise();



	CreateObjects();
	CreateShaders();

	camara = Camara(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90.0f, 0.0f, 4.0f, 0.3f);



	GLuint uniformProjection = 0;
	GLuint uniformXModel = 0;
	GLuint uniformView = 0;

	glm::mat4 projection = glm::perspective(45.0f, mainWindow.getBufferHeight() / mainWindow.getBufferWidth(), 0.1f, 100.0f);




	while (!mainWindow.getShouldClose()) {


		





		

		spinNose += 1.1f; //CON ESTO HACEMOS GIRAR LA NARIZ DE COFMA CONSTANTE
		
		//ESTA PARTE  DEL CODIGO ES PARA MANIPULAR VARIABLES DE CAMBIO DE ANGULOS Y QUE ESTEN RESTRINGIDAS A MOVIMIENTOS ANATOMICAMENTE CORRECTOS

		//ANIMACION DE LA FIGURA ----- inicio -----------

		


		
		//ANIMACION DE LA FIGURA ----- final -----------

		GLfloat now = glfwGetTime();
		deltaTime = now - lastTime;
		lastTime = now;

		glfwPollEvents();

		camara.keyControl(mainWindow.getsKeys(), deltaTime);
		camara.mouseControl(mainWindow.getXChange(), mainWindow.getYChange());


		bool* keys_angles = mainWindow.getsKeys();
		//PRESIONAR P PARA GIRAR EL TORSO (TODO EL CUERPO SOBRE EL EJE Y)

		if (keys_angles[GLFW_KEY_P]) {
			spinTorso += 0.01f;
		}


		
		if (keys_angles[GLFW_KEY_X]) {


			curAnglebrazos += oscilatebrazos;
			if (curAnglebrazos >= 90.0f) {
				oscilatebrazos += -0.01f;
			}
			if (curAnglebrazos <= -90.0f) {
				oscilatebrazos += 0.01f;
			}

			curAngle_antebrazos += oscilate_antebrazos;
			if (curAngle_antebrazos >= 30.0f) {
				oscilate_antebrazos += -0.01f;
			}
			if (curAngle_antebrazos <= 0.0f) {
				oscilate_antebrazos += 0.01f;
			}

			curAngle_piernas += oscilate_piernas;
			if (curAngle_piernas >= 45.0f) {
				oscilate_piernas += -0.01f;
			}
			if (curAngle_piernas <= -45.0f) {
				oscilate_piernas += 0.01f;
			}

			curAngle_piernas_P += oscilate_piernas_P;
			if (curAngle_piernas_P >= 25.0f) {
				oscilate_piernas_P += -0.01f;
			}
			if (curAngle_piernas_P <= 0.0f) {
				oscilate_piernas_P += 0.01f;
			}

			curAngle_Hombros += oscilate_Hombros;
			if (curAngle_Hombros >= 20.0f) {
				oscilate_Hombros += -0.01f;
			}
			if (curAngle_Hombros <= -20.0f) {
				oscilate_Hombros += 0.01f;
			}

			spinNeck += oscilate_Neck;
			if (spinNeck >= 90.0f) {
				oscilate_Neck += -0.01f;
			}
			if (spinNeck <= 0.0f) {
				oscilate_Neck += 0.01f;
			}
		}

		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		shaderList[0].UseShader();
		uniformXModel = shaderList[0].GetModelLocation();
		uniformProjection = shaderList[0].GetProjectionLocation();
		uniformView = shaderList[0].GetViewLocation();

		//TORSO

		//Matriz identidad
		glm::mat4 Identidad_TMP_DER(1.0f);
		glm::mat4 Identidad_TMP_IZQ(1.0f);
		glm::mat4 Identidad_THBA_DER(1.0f);
		glm::mat4 Identidad_THBA_IZQ(1.0f);
		glm::mat4 Identidad_HCueCN(1.0f);

        // STACK TORSO-MUSLO-PANTORRILLA-DERECHA - TMP_DER -----------------------------------------------------

		std::stack<glm::mat4> TMP_DER;
		std::stack<glm::mat4> TMP_IZQ;
		std::stack<glm::mat4> THBA_DER;
		std::stack<glm::mat4> THBA_IZQ;
		std::stack<glm::mat4> HCueCN;
		
		TMP_DER.push(Identidad_TMP_DER);
		TMP_IZQ.push(Identidad_TMP_IZQ);
		THBA_DER.push(Identidad_THBA_DER);
		THBA_IZQ.push(Identidad_THBA_IZQ);

		//CODIGO PARA EL TOROSO DE TMP_DER Y TMP_IZQ
		Identidad_TMP_DER = glm::translate(Identidad_TMP_DER, glm::vec3(2.0f, 0.0f, 1.0f));
		Identidad_TMP_DER = glm::rotate(Identidad_TMP_DER, spinTorso * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		Identidad_TMP_DER = glm::translate(Identidad_TMP_DER, glm::vec3(-2.0f, 0.0f, -1.0f));

		Identidad_TMP_IZQ = Identidad_TMP_DER;
		Identidad_THBA_DER = Identidad_TMP_DER;

		TMP_DER.push(Identidad_TMP_DER);
		TMP_IZQ.push(Identidad_TMP_IZQ);
		THBA_DER.push(Identidad_THBA_DER);


		//CODIGO PARA EL LA MUSLO DE TMP_DER-------------------------------------

		Identidad_TMP_DER = glm::translate(Identidad_TMP_DER, glm::vec3(1.0f, 0.0f, 1.0f));
		Identidad_TMP_DER = glm::rotate(Identidad_TMP_DER, curAngle_piernas * toRadians, glm::vec3(-1.0f, 0.0f, 0.0f));
		Identidad_TMP_DER = glm::translate(Identidad_TMP_DER, glm::vec3(-1.0f, -4.0f, -1.0f));

		TMP_DER.push(Identidad_TMP_DER);

		//CODIGO PARA EL LA PIERNA DE TMP_DER-------------------------------------

		Identidad_TMP_DER = glm::translate(Identidad_TMP_DER, glm::vec3(1.0f, 0.0f, 1.0f));
		Identidad_TMP_DER = glm::rotate(Identidad_TMP_DER, curAngle_piernas_P * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		Identidad_TMP_DER = glm::translate(Identidad_TMP_DER, glm::vec3(-1.0f, -4.0f, -1.0f));

		TMP_DER.push(Identidad_TMP_DER);
		//PIE DERECHO
		Identidad_TMP_DER = glm::translate(Identidad_TMP_DER, glm::vec3(1.0f, 0.0f, 1.0f));
		Identidad_TMP_DER = glm::rotate(Identidad_TMP_DER, 180.0f* toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		Identidad_TMP_DER = glm::translate(Identidad_TMP_DER, glm::vec3(-1.0f, -0.5f, -2.0f));

		TMP_DER.push(Identidad_TMP_DER);

		//CODIGO PARA EL LA MUSLO DE TMP_IZQ-------------------------------------

		Identidad_TMP_IZQ = glm::translate(Identidad_TMP_IZQ, glm::vec3(3.0f, 0.0f, 1.0f));
		Identidad_TMP_IZQ = glm::rotate(Identidad_TMP_IZQ, curAngle_piernas * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		Identidad_TMP_IZQ = glm::translate(Identidad_TMP_IZQ, glm::vec3(-1.0f, -4.0f, -1.0f));

		TMP_IZQ.push(Identidad_TMP_IZQ);

		//CODIGO PARA EL LA PIERNA DE TMP_IZQ-------------------------------------

		Identidad_TMP_IZQ = glm::translate(Identidad_TMP_IZQ, glm::vec3(1.0f, 0.0f, 1.0f));
		Identidad_TMP_IZQ = glm::rotate(Identidad_TMP_IZQ, curAngle_piernas_P * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		Identidad_TMP_IZQ = glm::translate(Identidad_TMP_IZQ, glm::vec3(-1.0f, -4.0f, -1.0f));

		TMP_IZQ.push(Identidad_TMP_IZQ);
		//PIE IZQUIERDO
		Identidad_TMP_IZQ = glm::translate(Identidad_TMP_IZQ, glm::vec3(1.0f, 0.0f, 1.0f));
		Identidad_TMP_IZQ = glm::rotate(Identidad_TMP_IZQ, 180.0f * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		Identidad_TMP_IZQ = glm::translate(Identidad_TMP_IZQ, glm::vec3(-1.0f, -0.5f, -2.0f));

		TMP_IZQ.push(Identidad_TMP_IZQ);

		//CODIGO MATRICES PARA HOMBROS-BRAZO-ANTEBRAZO-DERECHO-------------------------

		//HOMBRO
		Identidad_THBA_DER = glm::translate(Identidad_THBA_DER, glm::vec3(2.0f, 8.0f, 1.0f));
		Identidad_THBA_DER = glm::rotate(Identidad_THBA_DER, curAngle_Hombros * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		Identidad_THBA_DER = glm::translate(Identidad_THBA_DER, glm::vec3(-4.0f, 0.0f, -1.0f));

		//DECLARACION GLOBAL PARA QUE SOLO HAY UN HOMBRO PARA EL SATCK DERECHO Y IZQUIERDO (DER ES EL IZQ)
		Identidad_THBA_IZQ = Identidad_THBA_DER;
		Identidad_HCueCN = Identidad_THBA_DER;
		HCueCN.push(Identidad_HCueCN);
		THBA_IZQ.push(Identidad_THBA_IZQ);
		THBA_DER.push(Identidad_THBA_DER);

		//BRAZO DERECHO
		Identidad_THBA_DER = glm::translate(Identidad_THBA_DER, glm::vec3(7.0f, 0.0f, 1.0f));
		Identidad_THBA_DER = glm::rotate(Identidad_THBA_DER, curAnglebrazos * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		Identidad_THBA_DER = glm::translate(Identidad_THBA_DER, glm::vec3(-1.0f, -3.0f, -1.0f));

		THBA_DER.push(Identidad_THBA_DER);


		//ANTEBRAZO DERECHO
		Identidad_THBA_DER = glm::translate(Identidad_THBA_DER, glm::vec3(1.0f, 0.0f, 1.0f));
		Identidad_THBA_DER = glm::rotate(Identidad_THBA_DER, curAngle_antebrazos * toRadians, glm::vec3(-1.0f, 0.0f, 0.0f));
		Identidad_THBA_DER = glm::translate(Identidad_THBA_DER, glm::vec3(-1.0f, -3.0f, -1.0f));

		THBA_DER.push(Identidad_THBA_DER);

		//BRAZO IZQUIERDO
		Identidad_THBA_IZQ = glm::translate(Identidad_THBA_IZQ, glm::vec3(1.0f, 0.0f, 1.0f));
		Identidad_THBA_IZQ = glm::rotate(Identidad_THBA_IZQ, curAnglebrazos * toRadians, glm::vec3(-1.0f, 0.0f, 0.0f));
		Identidad_THBA_IZQ = glm::translate(Identidad_THBA_IZQ, glm::vec3(-1.0f, -3.0f, -1.0f));

		THBA_IZQ.push(Identidad_THBA_IZQ);


		//ANTEBRAZO IZQUIERDO
		Identidad_THBA_IZQ = glm::translate(Identidad_THBA_IZQ, glm::vec3(1.0f, 0.0f, 1.0f));
		Identidad_THBA_IZQ = glm::rotate(Identidad_THBA_IZQ, curAngle_antebrazos * toRadians, glm::vec3(-1.0f, 0.0f, 0.0f));
		Identidad_THBA_IZQ = glm::translate(Identidad_THBA_IZQ, glm::vec3(-1.0f, -3.0f, -1.0f));

		THBA_IZQ.push(Identidad_THBA_IZQ);


		//CUELLO 

		Identidad_HCueCN = glm::translate(Identidad_HCueCN, glm::vec3(4.0f, 2.0f, 1.0f));
		Identidad_HCueCN = glm::rotate(Identidad_HCueCN, spinNeck * toRadians, glm::vec3(0.0f, -1.0f, 0.0f));
		Identidad_HCueCN = glm::translate(Identidad_HCueCN, glm::vec3(-1.0f, 0.0f, -1.0f));

		HCueCN.push(Identidad_HCueCN);

		//CABEZA 

		Identidad_HCueCN = glm::translate(Identidad_HCueCN, glm::vec3(1.0f, 2.0f, 1.0f));
		Identidad_HCueCN = glm::rotate(Identidad_HCueCN,  0.0f* toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		Identidad_HCueCN = glm::translate(Identidad_HCueCN, glm::vec3(-2.0f, 0.0f, -2.0f));

		HCueCN.push(Identidad_HCueCN);


		//NARIZ 

		Identidad_HCueCN = glm::translate(Identidad_HCueCN, glm::vec3(2.0f, 2.0f, 4.0f));
		Identidad_HCueCN = glm::rotate(Identidad_HCueCN, spinNose * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		Identidad_HCueCN = glm::translate(Identidad_HCueCN, glm::vec3(-0.5f, 0.0f, -0.5f));

		HCueCN.push(Identidad_HCueCN);



































		//DIBUJAR TMP_DER--Y TMP_IZQ------------------inicio-----------------------------------------------------------------


		glm::mat4  DRAW_TMP_DER_Pie = glm::scale(TMP_DER.top(), glm::vec3(2.0f, 1.0f, 4.0f));
		glUniformMatrix4fv(uniformXModel, 1, GL_FALSE, glm::value_ptr(DRAW_TMP_DER_Pie));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camara.calculateViewMatrix()));

		meshList[0]->RenderMesh();

		TMP_DER.pop();



		glm::mat4  DRAW_TMP_DER_P = glm::scale(TMP_DER.top(), glm::vec3(2.0f, 4.0f, 2.0f));
		glUniformMatrix4fv(uniformXModel, 1, GL_FALSE, glm::value_ptr(DRAW_TMP_DER_P));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camara.calculateViewMatrix()));

		meshList[1]->RenderMesh();

		TMP_DER.pop();

		glm::mat4  DRAW_TMP_DER_M = glm::scale(TMP_DER.top(), glm::vec3(2.0f, 4.0f, 2.0f));
		glUniformMatrix4fv(uniformXModel, 1, GL_FALSE, glm::value_ptr(DRAW_TMP_DER_M));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camara.calculateViewMatrix()));

		meshList[2]->RenderMesh();

		TMP_DER.pop();

		glm::mat4  DRAW_TMP_IZQ_Pie = glm::scale(TMP_IZQ.top(), glm::vec3(2.0f, 1.0f, 4.0f));
		glUniformMatrix4fv(uniformXModel, 1, GL_FALSE, glm::value_ptr(DRAW_TMP_IZQ_Pie));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camara.calculateViewMatrix()));

		meshList[3]->RenderMesh();

		TMP_IZQ.pop();

		glm::mat4  DRAW_TMP_IZQ_P = glm::scale(TMP_IZQ.top(), glm::vec3(2.0f, 4.0f, 2.0f));
		glUniformMatrix4fv(uniformXModel, 1, GL_FALSE, glm::value_ptr(DRAW_TMP_IZQ_P));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camara.calculateViewMatrix()));

		meshList[4]->RenderMesh();

		TMP_IZQ.pop();

		glm::mat4  DRAW_TMP_IZQ_M = glm::scale(TMP_IZQ.top(), glm::vec3(2.0f, 4.0f, 2.0f));
		glUniformMatrix4fv(uniformXModel, 1, GL_FALSE, glm::value_ptr(DRAW_TMP_IZQ_M));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camara.calculateViewMatrix()));

		meshList[5]->RenderMesh();

		TMP_IZQ.pop();

		//DIBUJAR TMP_DER--Y TMP_IZQ------------------final----------------------------------------------

		
		//DIBUJAR CUELLO CABEZA Y NARIZ (HCueCN)-----Inicio----------------------------------------------


		glm::mat4  DRAW_HCueCN_N = glm::scale(HCueCN.top(), glm::vec3(1.0f, 1.0f, 1.0f));
		glUniformMatrix4fv(uniformXModel, 1, GL_FALSE, glm::value_ptr(DRAW_HCueCN_N));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camara.calculateViewMatrix()));

		meshList[6]->RenderMesh();

		HCueCN.pop();


		glm::mat4  DRAW_HCueCN_C = glm::scale(HCueCN.top(), glm::vec3(4.0f, 4.0f, 4.0f));
		glUniformMatrix4fv(uniformXModel, 1, GL_FALSE, glm::value_ptr(DRAW_HCueCN_C));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camara.calculateViewMatrix()));

		meshList[7]->RenderMesh();

		HCueCN.pop();


		glm::mat4  DRAW_HCueCN_Cue = glm::scale(HCueCN.top(), glm::vec3(2.0f, 2.0f, 2.0f));
		glUniformMatrix4fv(uniformXModel, 1, GL_FALSE, glm::value_ptr(DRAW_HCueCN_Cue));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camara.calculateViewMatrix()));

		meshList[8]->RenderMesh();

		HCueCN.pop();





		//DIBUJAR CUELLO CABEZA Y NARIZ (HCueCN)-----Final----------------------------------------------




		//DIBUJAR THBA_DER Y THBA_IZQ-----------------Inicio------------------------------------------------


		//CODIGO PARA DIBUJAR EL ANTEBRAZO IZQUIERDO (IZQ_A)

		glm::mat4  DRAW_THBA_IZQ_A = glm::scale(THBA_IZQ.top(), glm::vec3(2.0f, 3.0f, 2.0f));
		glUniformMatrix4fv(uniformXModel, 1, GL_FALSE, glm::value_ptr(DRAW_THBA_IZQ_A));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camara.calculateViewMatrix()));

		meshList[9]->RenderMesh();

		THBA_IZQ.pop();

		//CODIGO PARA DIBUJAR EL BRAZO IZQUIERDO (IZQ_B)

		glm::mat4  DRAW_THBA_IZQ_B = glm::scale(THBA_IZQ.top(), glm::vec3(2.0f, 3.0f, 2.0f));
		glUniformMatrix4fv(uniformXModel, 1, GL_FALSE, glm::value_ptr(DRAW_THBA_IZQ_B));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camara.calculateViewMatrix()));

		meshList[10]->RenderMesh();

		THBA_IZQ.pop();


		//CODIGO PARA DIBUJAR EL ANTEBRAZO DERECHO (DER_A)

		glm::mat4  DRAW_THBA_DER_A = glm::scale(THBA_DER.top(), glm::vec3(2.0f, 3.0f, 2.0f));
		glUniformMatrix4fv(uniformXModel, 1, GL_FALSE, glm::value_ptr(DRAW_THBA_DER_A));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camara.calculateViewMatrix()));

		meshList[11]->RenderMesh();

		THBA_DER.pop();

		//CODIGO PARA DIBUJAR EL BRAZO DERECHO (DER_B)
		glm::mat4  DRAW_THBA_DER_B = glm::scale(THBA_DER.top(), glm::vec3(2.0f, 3.0f, 2.0f));
		glUniformMatrix4fv(uniformXModel, 1, GL_FALSE, glm::value_ptr(DRAW_THBA_DER_B));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camara.calculateViewMatrix()));

		meshList[12]->RenderMesh();

		THBA_DER.pop();


		//CODIGO PARA DIBUJAR LOS HOMBROS (H)
		glm::mat4  DRAW_THBA_DER_H = glm::scale(THBA_DER.top(), glm::vec3(8.0f, 2.0f, 2.0f));
		glUniformMatrix4fv(uniformXModel, 1, GL_FALSE, glm::value_ptr(DRAW_THBA_DER_H));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camara.calculateViewMatrix()));

		meshList[13]->RenderMesh();

		THBA_DER.pop();



		//DIBUJAR THBA_DER Y THBA_IZQ-----------------Final------------------------------------------------



		//CODIGO GLOBAL PARA DIBUJAR EL TORSO
		glm::mat4  DRAW_TMP_DER_T = glm::scale(TMP_DER.top(), glm::vec3(4.0f, 8.0f, 2.0f));
		glUniformMatrix4fv(uniformXModel, 1, GL_FALSE, glm::value_ptr(DRAW_TMP_DER_T));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camara.calculateViewMatrix()));

		meshList[14]->RenderMesh();

		TMP_DER.pop();




		//model = glm::translate(model, glm::vec3(1.0f, 2.0f, 1.0f));
		/*model = glm::rotate(model, 45.0f * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(1.0f, 3.0f, 0.5f));
		glUniformMatrix4fv(uniformXModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camara.calculateViewMatrix()));

		meshList[0]->RenderMesh();*/


		
























		glUseProgram(0);

		mainWindow.swapBuffers();

	}

	return 0;


}








