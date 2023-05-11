#include <glad/glad.h>

class DrawClass
{
public:
    void CreateBuffersPosOnly(float* firstTriangle, float size , unsigned int _vertexCount)
    {
        unsigned int VBO;
        vertexCount = _vertexCount;

        glGenVertexArrays(1, &VAO);        //Generate VAO buffer save it in VAO variable

        glGenBuffers(1, &VBO);              //Generate Buffer VBO to save the array to

        //Bind The VAO , anything that happens below it is saved/bind in the VAO buffer
        glBindVertexArray(VAO);

        //in order to send the array to GPU we bind VBO to the GL_ARRAY_BUFFER
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        //use the GL_ARRAY_BUFFER to send the array to the graphic card
        glBufferData(GL_ARRAY_BUFFER, size, firstTriangle, GL_STATIC_DRAW);

        //We need to send position correctly to the vertex shader through the layout location = 0 
        //because we have x,y,z  it's 3 elements with size of float 
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);       //UnBind VBO
        glBindVertexArray(0);                   //UnBind VAO
    }

    void CreateBuffersPosColor(float* firstTriangle, float size, unsigned int _vertexCount)
    {
        unsigned int VBO;
        vertexCount = _vertexCount;

        glGenVertexArrays(1, &VAO);        //Generate VAO buffer save it in VAO variable

        glGenBuffers(1, &VBO);              //Generate Buffer VBO to save the array to

        //Bind The VAO , anything that happens below it is saved/bind in the VAO buffer
        glBindVertexArray(VAO);

        //in order to send the array to GPU we bind VBO to the GL_ARRAY_BUFFER
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        //use the GL_ARRAY_BUFFER to send the array to the graphic card
        glBufferData(GL_ARRAY_BUFFER, size, firstTriangle, GL_STATIC_DRAW);

        //We need to send position correctly to the vertex shader through the layout location = 0 
        //because we have x,y,z,w  it's 3 elements with size of float 
        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 0);
        glEnableVertexAttribArray(0);

        //Take color to location 1
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)( 4 * sizeof(float)));
        glEnableVertexAttribArray(1);


        glBindBuffer(GL_ARRAY_BUFFER, 0);       //UnBind VBO
        glBindVertexArray(0);                   //UnBind VAO
    }

    void CreateBuffersIndices(
        float* vertices, float size,        //vertex array and it's size
        unsigned int* indices, float  indicessize, //indices array and it's size
        unsigned int _vertexCount)
    {
        unsigned int VBO;
        unsigned int EBO;

        vertexCount = _vertexCount;

        glGenVertexArrays(1, &VAO);        //Generate VAO buffer save it in VAO variable

        glGenBuffers(1, &VBO);              //Generate Buffer VBO to save the array to
        glGenBuffers(1, &EBO);              //Generate EBO buffer for the indices

        //Bind The VAO , anything that happens below it is saved/bind in the VAO buffer
        glBindVertexArray(VAO);

        /****VBO***/
        //in order to send the array to GPU we bind VBO to the GL_ARRAY_BUFFER
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        //use the GL_ARRAY_BUFFER to send the array to the graphic card
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);


        /***EBO***/
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicessize, indices, GL_STATIC_DRAW);


        //We need to send position correctly to the vertex shader through the layout location = 0 
        //because we have x,y,z,w  it's 3 elements with size of float 
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 0);
        glEnableVertexAttribArray(0);

        //Take normal to location 1
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        //Take texture coords to location 2
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
        glEnableVertexAttribArray(2);


        glBindBuffer(GL_ARRAY_BUFFER, 0);       //UnBind VBO
        glBindVertexArray(0);                   //UnBind VAO
    }


    void Draw()
    {
        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        glDrawArrays(GL_TRIANGLES, 0, vertexCount);
    }

    void DrawIndices()
    {
        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        glDrawElements(GL_TRIANGLES, vertexCount,GL_UNSIGNED_INT , 0);
    }

private:
    unsigned int VAO;
    unsigned int vertexCount;
};
