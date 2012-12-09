class TGround
{
private:
	float _radius;
	float normal;
	GLUquadric *ground;
    GLuint groundTexture; //used to store planettextures
public:
	TGround(void);
	TGround(float radius);
	~TGround(void);
	float GetRadius(void);
	void draw();
	void init();
};

