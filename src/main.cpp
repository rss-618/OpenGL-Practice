#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "rss618", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	
	

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
			std::cout << "GLEW IS NOT OKAY!" << std::endl;
		}
	std::cout << glGetString(GL_VERSION) << std::endl;
	//float array of positions
	float positions[] = {
		//x, y (opengl doesn't know this though.) -> need to tell opengl the layout after it is bound=(glBindBuffer)
		-0.5f, -0.5f,//verticies
		0.0f, 0.5f,
		0.5f, -0.5f
	};
	unsigned int buffer;
	//generate buffer
	glGenBuffers(1, &buffer);//passes address so that there is no need to make a copy of value itself?
	//bind buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffer); //type , buffer id
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);// <type>,  <howmany> * <size of datatype in bytes>, data being buffered, type of draw(eg.) static or dynamic)
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2,GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0); //type , buffer id

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);
		//Create Triangle
		glDrawArrays(GL_TRIANGLES, 0, 3); //open gl is a state machine (specifier, number of verticies>

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}