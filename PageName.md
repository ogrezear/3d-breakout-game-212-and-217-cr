# Introduction #

Add your content here.


# Details #

Add your content here.  Format your content with:
  * Text in **bold** or _italic_
  * Headings, paragraphs, and lists
  * Automatic links to other wiki pages

<p>212CR Portfolio A2:</p>

<p>3D Break-out Game</p>

<p><b>Florin Nicusor Coada</b></p>

<p><b> SID:2887289</b></p>

<p><b>Contents</b></p>

<table cellpadding='0' border='1' cellspacing='0'>
<tbody>
<tr>
<td valign='top'><p>The Task</p></td>
<td valign='top'><p>Page 3</p></td>
</tr>

<tr>
<td valign='top'> </td>
<td valign='top'> </td>
</tr>

<tr>
<td valign='top'><p>The Solution</p></td>
<td valign='top'><p>Page 3</p></td>
</tr>

<tr>
<td valign='top'> </td>
<td valign='top'> </td>
</tr>

<tr>
<td valign='top'><p>Publication Class</p></td>
<td valign='top'><p>Page 3</p></td>
</tr>

<tr>
<td valign='top'> </td>
<td valign='top'> </td>
</tr>

<tr>
<td valign='top'><p>Book and Disc Class</p></td>
<td valign='top'><p>Page 4</p></td>
</tr>

<tr>
<td valign='top'> </td>
<td valign='top'> </td>
</tr>

<tr>
<td valign='top'><p>Test 1 – Independent item initialization</p></td>
<td valign='top'><p>Page 4</p></td>
</tr>

<tr>
<td valign='top'> </td>
<td valign='top'> </td>
</tr>

<tr>
<td valign='top'><p>Functions – adding updateID()</p></td>
<td valign='top'><p>Page 5</p></td>
</tr>

<tr>
<td valign='top'> </td>
<td valign='top'> </td>
</tr>

<tr>
<td valign='top'><p>Test 2 –List of objects</p></td>
<td valign='top'><p>Page 5</p></td>
</tr>

<tr>
<td valign='top'> </td>
<td valign='top'> </td>
</tr>

<tr>
<td valign='top'><p>C++ versus Python</p></td>
<td valign='top'><p>Page 6</p></td>
</tr>

<tr>
<td valign='top'> </td>
<td valign='top'> </td>
</tr>

<tr>
<td valign='top'><p>Terminology</p></td>
<td valign='top'><p>Page 7</p></td>
</tr>

<tr>
<td valign='top'> </td>
<td valign='top'> </td>
</tr>

<tr>
<td valign='top'><p>Python source code</p></td>
<td valign='top'><p>Page 8</p></td>
</tr>

<tr>
<td valign='top'> </td>
<td valign='top'> </td>
</tr>

<tr>
<td valign='top'><p>C++ source code</p></td>
<td valign='top'><p>Page 10</p></td>
</tr>

<tr>
<td valign='top'> </td>
<td valign='top'> </td>
</tr>

<tr>
<td valign='top'><p>References</p></td>
<td valign='top'><p>Page 13</p></td>
</tr>

</tbody>
</table>

<p><b>Abstract</b> </p>

<p>The task is to design a 3D Breakout Game making use of all the techniques learned during the tutorials. These techniques include use of OpenGL for the 3D design and vector based physics for the collision detection. This report describes the development for the 3D content used for this assignment. The project includes use of techniques such as 2D texturing, shading, lighting and basic shape construction. The final product has incorporated all of the techniques enumerated earlier, created using the <b>glut</b> library and special functions. The game design presents some of the features required from a game, a menu, score and game logics. </p>

<p><b>The task</b></p>

<p>The aim of the assignment is to develop the graphics for an interactive 3D game that makes use of computer graphics principles and algorithms taught in lectures. </p>

<p><b>Background theory </b></p>

<p><b>The Game </b></p>

<p>The 3D Breakout, a cylindrical wall that consists of 3D bricks, exists in the middle of the simulation area. An example of how the game should look like is shown in the following figure. </p>

<p>A single player controls three curved bats, each positioned at an angle of 120 degrees to each other. The bats can move clockwise or anticlockwise using the keyboard arrow keys (or mouse if preferred) as input. The cylindrical wall is situated in the middle of the circle and is constructed by twelve bricks in such a way that it looks like a shaft. The main idea of the 3D game is to knock down all the 3D bricks and ‘destroy’ the well. An example of the Breakout game in operation is illustrated below. </p>

<p>The score for this game is done using the similar rules:</p>

<p>- 3 points are awarded for killing a brick</p>

<p>- 1 point is taken for hitting the bat</p>

<p>- The ball is affected by friction, in order to regain speed hit the sides of the bats</p>

<p>- The player will not be penalised for hitting the sides o</p>

<p><b>The ball</b></p>

<p>The main object in the game is the <b>ball</b>, which is used to destroy the bricks in order to obtain points. Based on physics the ball is used to bounce of the bat at certain angles in order for the user to have a slight control over the ball trajectory. The ball is supposed to be made out of wood so, a wood texture has been applied to it. The use of the texture extends beyond reasons of aspect, one other reason being the ability to allow the user to see how the ball is rolling on the ground. The rolling of the ball is made using simple rotation functions from the <b>glut</b> library, which will be later explained. The construction of this object has been done using the <b>gluSphere()</b> function offered by the library.</p>

<p>The ball was the first item constructed for this assignment, since it is the only item with collision detection, and early testing was needed to be sure that the collision algorithm is working. </p>

<p><b>Creating the ground</b></p>

<p>The second object created was the <b>ground</b>, above which the <b>bats</b> and the <b>bricks</b> have later been added. Based on the number of items needed to be added to the game, I have decided to use a radius of 8 units, which will allows to add everything and to make sure that there will not be any unwanted interactions between objects.</p>

<p>Because the theme for the game was a wooden breakout game, I have decided to texturize the ground with a wooden floor like image. Because the image itself was not bright enough to be used, material lighting has been added to it in order to make it brighter. </p>

<p>GLfloat lightAmbient<a href='.md'>.md</a> = {0.7,0.7,0.7,1.0};</p>

<p>glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,lightAmbient);</p>

<p>Like in the case of the ball, special functions from the <b>glut</b> library have been used in order to create a circle upon which the game scene will be constructed. </p>

<p>gluDisk(ground,0,_radius,360,360); // create the ground</p>_

<p><b>Creating bricks and bats</b></p>

<p>The <b>bricks</b> and the <b>bats</b> used in the game are the only object constructed from scratch. The construction process is identical for both of these items, the only difference between them being their functionality. While the bricks are stable, creating the well, the bats are made to be mobile, in order to hit the ball in order to achieve a grater score. </p>

<table cellpadding='0' border='1' cellspacing='0'>
<tbody>
<tr>
<td valign='top'><p><b>Bricks</b></p></td>
<td valign='top'><p><b>Bats</b></p></td>
</tr>

<tr>
<td valign='top'><p>Basic shading</p></td>
<td valign='top'><p>Basic shading</p>

</td>
</tr>

<tr>
<td valign='top'><p>No lateral collision with the ball</p></td>
<td valign='top'><p>Lateral collision with the ball</p>

</td>
</tr>

<tr>
<td valign='top'><p>Different colours specified with glMaterial</p></td>
<td valign='top'><p>Same colour copied from the ground </p>

<p>Texture</p>

</td>
</tr>

<tr>
<td valign='top'><p>No movement</p></td>
<td valign='top'><p>Movement around the Y axis</p>

</td>
</tr>

<tr>
<td valign='top'><p>3 points reward for hitting a brick</p></td>
<td valign='top'><p>-1 points reward for hitting a bat</p>

</td>
</tr>

<tr>
<td valign='top'><p>Displayed using glList</p></td>
<td valign='top'><p>Displayed using glList</p></td>
</tr>

</tbody>
</table>

<p>Bats and Bricks (similarities and differences)</p>

<p>The process of constructing the bats includes drawing each vertex in order to create the faces and calculating the normal for each faces in order to obtain good shading.</p>

<p><b>The menu</b></p>

<p>Because all the games have a form of <b>menu</b>, I have decided to construct a simple menu, using the available functions offered by the <b>glut</b> library. My solution to this problem was to create four spheres, each one of them representing a menu option. The four options listed in the menu are<b> Start</b>, <b>Controls</b>, <b>Rules</b>, and <b>Exit.</b> The navigation through the options is done using the <b>left</b> and <b>right</b> <b>arrow</b> keys, while the selection (if available) is done by pressing <b>Enter</b>. Each of the menu options has a special page with instructions.</p>

<p>For example, the <b>Controls</b> page does not have any selection, but while the user is at this page, he will see the controls listed below the buttons. When a <b>menu option</b> is <b>selected</b> the ball corresponding to it, is moving closer to the camera and starts spinning. </p>

<p><b>The Skybox</b></p>

<p>In order to improve the game, I have decided to add a <b>Skybox</b>. The skybox was created as a sphere on which was applied a <b>sky image,</b> as texture. Because the light source for the application system has been set inside this sphere, the texture that was applied was visible from the inside, creating the impression of being amongst the clouds space. This has been done using simple functions, which will be presented later in the report. </p>

<p><b>The cameras</b></p>

<p>For this project I have decided to create three different cameras. Two of the cameras have been designed to have no interactiond with the user and one to let the user set his own viewing point. </p>

<p>Each camera’s purpose and construction will be explained in the section below.</p>

<p><b> Camera 1</b></p>

<p>The first camera designed for this project has been made to allow the user to watch the game from above just like in a <b>2D breakout game type</b>. This camera is used to ease the game for the user, thus allowing him to achieve a higher score. The camera has no interaction with the user, and it’s always looking at the same point. It is placed at a heigh of <b>23 units </b>on the <b>Y axis</b>, and a distance of <b>3 units</b> on the <b>Z axis.</b></p>

<table cellpadding='0' border='1' cellspacing='0'>
<tbody>
<tr>
<td valign='top'><p><b>Camera 1</b></p></td>
<td valign='top'> </td>
</tr>

<tr>
<td valign='top'><p>-Movement : None</p>

<p>-Advantages: good overall view of the game scene</p>

<p>-Drawbacks: </p>

<p>- no possibility for looking behind </p>

<p>the camera </p>

<p>- no orientation options</p>

<p>- no 3D feeling</p>

</td>
<td valign='top'><p>Camera 1</p></td>
</tr>

</tbody>
</table>

<p><b>Camera 2</b></p>

<p>The second camera is designed as a “<b>follow camera</b>” that will always stay behind the ball, following it as it hits the bats, the outer radius of the circle and the bricks. This camera helps to create a “be the ball” feeling that will allow the users to see “though the eyes” of the ball. </p>

<p>The camera is placed by multiplying the coordinates of the ball by a value of <b>1.5</b> on the <b>X</b> and <b>Z-axis</b>, and a value of <b>3 </b>on the <b>Y-axis</b>. The orientation is always towards the <b>tip</b> of the <b>_speed</b> vector of the ball.</p>_

<table cellpadding='0' border='1' cellspacing='0'>
<tbody>
<tr>
<td valign='top'><p><b>Camera 2</b></p></td>
<td valign='top'> </td>
</tr>

<tr>
<td valign='top'><p>-Movement : X,Z axis depending on the ball</p>

<p>-Advantages: be the ball feeling</p>

<p>-Drawbacks: </p>

<p>- no orientation options</p>

</td>
<td valign='top'><p>Camera 2 –X,Z axis</p></td>
</tr>

<tr>
<td valign='top'><p>Camera 2 - Y,X,Z axis</p></td>
</tr>

</tbody>
</table>

<p><b>Camera 3</b></p>

<p>This camera is based on a cylinder type movement. While the <b>origin point</b> remains in the centre point of the cylinder, the radius and the height are suffering changes, allowing the user to define new viewing perspectives. In other words, the camera is moving on the outside of a cylinder by focusing always on the (0,0,0) point. </p>

<p>Moving the camera left or right is based on incrementing or decrementing the value of <b>x</b> according to the type of movement the user wants to apply. After getting the value of <b>x</b>, because the centre of the circle on which the camera is moving the equation for finding the <b>z</b> value is , where <b>r</b> is the radius.</p>

<p>The camera is also capable for up and down movements on the cylinder and this has been made possible by changing the value of <b>y</b> according to the needs of the user, without altering the value of <b>x</b> or <b>z</b>. </p>

<p>The last feature of the camera is the <b>Zoom In </b>or <b>Out </b>function. The technique for zooming in or out is in fact based on increasing or decreasing the radius for the cylinder base. The equation used is <b>x=x<b>(r+size)/r</b>, where</b><b>x</b> is the coordinate on the <b>x axis</b> , <b>r</b> is the radius for the base of the cylinder, and <b>size</b> the value used to increase or decrease the radius.</p>

<p>This type of camera has been initially designed by me for a 3D solar system. </p>

<table cellpadding='0' border='1' align='left' cellspacing='0'>
<tbody>
<tr>
<td valign='top'><p><b>Camera 3</b></p>

<p>-Movement : x, z or y axis</p>

<p>-Advantages: simulate the orbit of a </p>

<p>planet</p>

<p>-Drawbacks: </p>

<p>-focus only on the origin point</p>

<p>-no possibility for looking behind </p>

<p>the camera </p>

<p>-reduced orientation options</p>

</td>
<td valign='top'><p>Camera 3 model</p></td>
</tr>

</tbody>
</table>

<p><b> 2. Methodology and results</b></p>

<p><b> Creating the classes</b></p>

<p><b> Ball Class</b></p>

<p>The most important class in the game is the <b>Ball</b> class, which has the purpose to store information about the ball and functions performed on it. The class contains variables used to store textures, position and rotation angles, ad functions used to detect collision move the ball and apply textures.</p>

<p><b>Class variables:</b></p>

<p>All the class variables are listed in a table below, explaining their use and purpose. </p>

<table cellpadding='0' border='1' cellspacing='0'>
<tbody>
<tr>
<td valign='top'><p><b>Ball class – variables</b></p>

</td>
</tr>

<tr>
<td valign='top'><p>Name</p></td>
<td valign='top'><p><b>Purpose </b></p>

</td>
<td valign='top'><p><b>Type</b></p></td>
</tr>

<tr>
<td valign='top'><p><i>ballx</p></td></i><td valign='top'><p>Store the <b>x</b> coordinate of the ball, updated by the <b>move()</b> function</p></td>
<td valign='top'><p>double</p></td>
</tr>

<tr>
<td valign='top'><p><i>ballz</p></td></i><td valign='top'><p>Store the <b>z</b> coordinate of the ball, updated by the <b>move()</b> function</p></td>
<td valign='top'><p>double</p></td>
</tr>

<tr>
<td valign='top'><p><i>bally</p></td></i><td valign='top'><p>Store the <b>y</b> coordinate of the ball, which is always equal to the radius of the ball</p></td>
<td valign='top'><p>double</p></td>
</tr>

<tr>
<td valign='top'><p><i>radius</p></td></i><td valign='top'><p>Store the <b>radius</b> of the ball.</p></td>
<td valign='top'><p>double</p></td>
</tr>

<tr>
<td valign='top'><p><i>speed</p></td></i><td valign='top'><p>This variable is used to store the <b>speed vector</b> for the ball.</p></td>
<td valign='top'><p>TVector</p></td>
</tr>

<tr>
<td valign='top'><p>angle2</p></td>
<td valign='top'><p>Store the <b>angle between</b> the speed vector and (1,0,0) vector. This variable is updated after each collision in order to obtain a correct ball rolling. </p></td>
<td valign='top'><p>float</p></td>
</tr>

<tr>
<td valign='top'><p>ballq</p></td>
<td valign='top'><p>This variable is used to store a polygon that will be texturized and then wrapped on a sphere. In this way I can use any texture I want for the ball</p></td>
<td valign='top'><p>GLUquadric</p>

</td>
</tr>

<tr>
<td valign='top'><p>ballTexture</p></td>
<td valign='top'><p>Used to store the <b>texture</b> that will be applied.</p></td>
<td valign='top'><p>GLuint</p>

</td>
</tr>

<tr>
<td valign='top'><p>cd</p></td>
<td valign='top'><p>This variable is used to help <b>reducing the bugs </b>caused by collision detection.</p></td>
<td valign='top'><p>int</p></td>
</tr>

<tr>
<td valign='top'><p>delta</p></td>
<td valign='top'><p>Store the <b>magnitude</b> of the speed vector. Based on this value the collision detection is more or less accurate.</p></td>
<td valign='top'><p>double</p></td>
</tr>

<tr>
<td valign='top'><p>path</p></td>
<td valign='top'><p>String used to store <b>different textures</b>.</p></td>
<td valign='top'><p>string</p></td>
</tr>

<tr>
<td valign='top'><p>pos</p></td>
<td valign='top'><p>Position vector defined as <b>(<i>ballx,0,</i>ballz)</b></p></td>
<td valign='top'><p>TVector</p></td>
</tr>

<tr>
<td valign='top'><p>spin</p></td>
<td valign='top'><p>Value of the angle of rotation around self <b>Z axis</b>.</p></td>
<td valign='top'><p>double</p></td>
</tr>

<tr>
<td valign='top'><p>texNr</p></td>
<td valign='top'><p><b>Number of texture</b> to be applied.</p></td>
<td valign='top'><p>int</p></td>
</tr>

</tbody>
</table>

<p><b>Class functions:</b></p>

<p>The class constructor is used to initialize the position of the ball, speed, radius and texture number. The parameters sent to the class construction are </p>

<p>a <b>TVector</b> type item <b>speed</b>, with the movement over the <b>X </b>and <b>Z</b> <b>axis</b>, because the ball has no vertical movement. The other parameters are <b>ballx</b>, <b>ballz</b>, <b><i>radius</b>, and</i><b>texNr</b>, which as mentioned before are used to store the position, radius, and texture number. The vertical coordinate of the ball is equalized with the same value stored as the radius size.</p>

<p>The class functions will be listed in a table specifying all the functions and their purpose. </p>

<table cellpadding='0' border='1' cellspacing='0'>
<tbody>
<tr>
<td valign='top'><p><b>Ball class functions</b></p></td>
</tr>

<tr>
<td valign='top'><p><b>Function name</b></p></td>
<td valign='top'><p><b>Purpose</b></p></td>
</tr>

<tr>
<td valign='top'><p>Ball(void);</p>

</td>
<td valign='top'><p>Default class constructor, never used</p></td>
</tr>

<tr>
<td valign='top'><p>Ball(TVector speed, float ballx, float ballz, float radius, int texNr);</p>

</td>
<td valign='top'><p>Class constructor used to initialise ball type as mentioned above.</p></td>
</tr>

<tr>
<td valign='top'><p>void reset(TVector speed, float ballx, float ballz, float radius, int texNr);</p>

</td>
<td valign='top'><p>The function is used to reinitialise the ball when a new game starts.</p></td>
</tr>

<tr>
<td valign='top'><p>void draw();</p>

</td>
<td valign='top'><p>Function used to draw the ball.</p></td>
</tr>

<tr>
<td valign='top'><p>void move();</p>

</td>
<td valign='top'><p>This functions is used to move the ball on the <b>X,Z </b>plane.</p></td>
</tr>

<tr>
<td valign='top'><p>double GetX();</p>

</td>
<td valign='top'><p>Return the <b>x</b> position of the ball.</p></td>
</tr>

<tr>
<td valign='top'><p>double GetZ();</p>

</td>
<td valign='top'><p>Return the <b>z</b> position of the ball.</p></td>
</tr>

<tr>
<td valign='top'><p>void setTex();</p>

</td>
<td valign='top'><p>Initialise the <b>path</b> variable with, texture paths.</p></td>
</tr>

<tr>
<td valign='top'><p>void init();</p>

</td>
<td valign='top'><p>Initialise the textures, to be later plied.</p></td>
</tr>

<tr>
<td valign='top'><p>void spinZ();</p>

</td>
<td valign='top'><p>Spin the ball around, self <b>Z axis</b> in order to create a rolling effect.</p></td>
</tr>

<tr>
<td valign='top'><p>double GetY();</p></td>
<td valign='top'><p>Return the <b>y</b> position of the ball.</p></td>
</tr>

<tr>
<td valign='top'><p>TVector GetSpeed()</p></td>
<td valign='top'><p>Return the <b><i>speed</b> vector.</p></td>
</tr></i>

<tr>
<td valign='top'><p>int collision();</p>

</td>
<td valign='top'><p>Check to see if the <b>ball collides</b> with anything. If true the function will return the value 1, and a sound will be played.</p></td>
</tr>

<tr>
<td valign='top'><p>void setSpeed();</p>

</td>
<td valign='top'><p>Function used for <b>recalculating the ball speed vector</b> after collision.</p></td>
</tr>

<tr>
<td valign='top'><p>TVector angleCheck();</p>

</td>
<td valign='top'><p>This function is used to check if the ball is “inside” a bat and returns the normal collision vector. Because the collision was not working properly, the vector has been disregarded. </p></td>
</tr>

<tr>
<td valign='top'><p>void setSpeedFromBat(TVector normal);</p>

</td>
<td valign='top'><p>Calculate collision using a specific collision normal vector. </p></td>
</tr>

<tr>
<td valign='top'><p>void sideCollision();</p>

</td>
<td valign='top'><p>Check to see if there are any collisions with the sides of the bats. </p></td>
</tr>

</tbody>
</table>

<p>The most important function regarding the 3D content of the game is represented by the <b>draw()</b> function which is used to draw and rotate the ball in a correct manner. </p>

<p>void Ball::draw()</p>

<p>{</p>

<p>//enable use of texture</p>

<p>glEnable ( GL_TEXTURE_2D );</p>

<p>glBindTexture ( GL_TEXTURE_2D, ballTexture);//set texture to be used</p>

<p>glMatrixMode(GL_MODELVIEW);</p>

<p>glPushMatrix();</p>

<p>glTranslatef(<i>ballx,</i>bally,_ballz); //place the ball in the scene</p>_

<p>glRotatef(angle2,0,-1,0); /**rotate the ball on the self Y axis in order </p>**

<p>to obtain corect rolling efect **/</p>**

<p>glRotatef(spin,0,0,-1); //rotate the ball on the self z axis</p>

<p>gluSphere(ballq,_radius,20,20); // draw the ball</p>_

<p>glPopMatrix();</p>

<p>glDisable ( GL_TEXTURE_2D );//disable use of textures</p>

<p>}</p>

<p>Ball class - draw function</p>

<p>The movement of the functions is done by adding the <b>x</b> and <b>z </b>value of the <b><i>speed</b> vector to the</i><b>x </b>and <b>z</b> coordinates of the ball.</p>

<p>//update ball position</p>

<p><i>ballx=</i>ballx+<i>speed.</i>x;</p>

<p><i>ballz=</i>ballz+<i>speed.</i>z;</p>

<p>The <b>spinZ()</b> function of the class is used to increment the value of the spin angle by 30. If the value of the angle reaches a value greater than 360 the values will be reduced by making, the spin values equal to <b>spin%360</b>.</p>

<p>void Ball::spinZ()</p>

<p>{</p>

<p>spin+=30;</p>

<p>spin=int(spin)%360;</p>

<p>}</p>

<p>spinZ() function </p>

<p><b> Tbat and Tbrick classes</b></p>

<p>Because these classes are very similar, I have decided to present them together. The constructor of both classes takes as values the angle of the bat/brick from the <b>(1,0,0) vector</b>, the inner radius and the outer radius and the row number for the brick type objects. Based on the values stored with the use of the constructor, the points of the bats/ bricks are being generated. </p>

<p>void Tbrick::makeBrick()</p>

<p>{</p>

<p>double deg20;//20 degree angle to be converted to radians</p>

<p>deg20=deg2rad(20);</p>

<p>int i;</p>

<p>//generate lower front points</p>

<p>for(i=0;i&lt;4;i++){</p>

<p><i>points<a href='i.md'>i</a>.</i>x=<i>radius*cos(</i>angle+i*deg20);</p>

<p><i>points<a href='i.md'>i</a>.</i>z=<i>radius*sin(</i>angle+i*deg20);</p>

<p><i>points<a href='i.md'>i</a>.</i>y=**rowheight;</p>**

<p>}</p>

<p>//generate lower back</p>

<p>for(i=7;i&gt;=4;i--){</p>

<p><i>points<a href='i.md'>i</a>.</i>x=<i>points[i-4].</i>x**(<i>outRadius/</i>radius);</p>**

<p><i>points<a href='i.md'>i</a>.</i>z=<i>points[i-4].</i>z**(<i>outRadius/</i>radius);</p>**

<p><i>points<a href='i.md'>i</a>.</i>y=**rowheight;</p>**

<p>}</p>

<p>//generate upper points(front and back)</p>

<p>for(i=8;i&lt;=15;i++){</p>

<p><i>points<a href='i.md'>i</a>.</i>x=<i>points[i-8].</i>x;</p>

<p><i>points<a href='i.md'>i</a>.</i>z=<i>points[i-8].</i>z;</p>

<p><i>points<a href='i.md'>i</a>.</i>y=<i>points[i-8].</i>y+_height;</p>_

<p>}</p>

<p>}</p>

<p>Base on the points generated above the <b>draw()</b> function of both of the classes will create the <b>front</b>,<b> back</b>, <b>top </b>and <b>side faces</b>. During the drawing process for the faces of the objects, the normal for each face is calculated, based on the coordinates of the points created in the <b>makeBrick()</b> or <b>makeBat()</b> functions.</p>

<p>The normal is defined as the <b>cross product</b> between two vectors located on the same plane, and starting from the same point of origin. The vectors used to calculate the normal are obtained by subtracting one vector from two of its neighbours.</p>

<p>//draw the front face</p>

<p>glBegin(GL_QUAD_STRIP);</p>

<p>for(int i=0;i&lt;=3;i++){</p>

<p>if(i==3) glNormal3f(<i>normal<a href='2.md'>2</a>.X(),</i>normal<a href='2.md'>2</a>.Y(), _normal<a href='2.md'>2</a>.Z());</p>_

<p>else{ <i>normal<a href='i.md'>i</a> = ((</i>points[i+8] - _points<a href='i.md'>i</a>)<i>(</i>points[i+1] - **points<a href='i.md'>i</a>)).unit();</p>**_<p>glNormal3f(<i>normal<a href='i.md'>i</a>.</i>x, <i>normal<a href='i.md'>i</a>.</i>y, <i>normal<a href='i.md'>i</a>.</i>z);}</p>

<p>// Construct a quad</p>

<p>glVertex3f(<i>points<a href='i.md'>i</a>.X(),</i>points<a href='i.md'>i</a>.Y(), _points<a href='i.md'>i</a>.Z());</p>_

<p>glVertex3f(<i>points[i+8].X(),</i>points[i+8].Y(), _points[i+8].Z());</p>_

<p>}</p>

<p>glEnd();</p>

<p>Part of the draw function</p>

<p>The items are displayed using <b>glLists</b>, to reduce the rendering time. Because the bats must move in order to catch the ball, they must be redrawn each time the left arrow or right arrow key is pressed. In order to move the bat with the required distance the bats are reinitialised using a new value for the angles. The function used to draw the bricks is always checking before drawing a brick, to see if the brick has been hit by the ball or not. This is done by storing data about the bricks inside of a matrix:</p>

<p>- <b>1 </b> the brick is alive</p>

<p>-<b> 0 </b>the brick is dead</p>

<table cellpadding='0' border='1' align='left' cellspacing='0'>
<tbody>
<tr>
<td valign='top'><p><b> Column</b></p>

<p><b>Row</b></p></td>
<td valign='top'><p><b>1</b></p></td>
<td valign='top'><p><b>2</b></p></td>
<td valign='top'><p><b>3</b></p></td>
<td valign='top'><p><b>4</b></p></td>
<td valign='top'><p><b>5</b></p></td>
<td valign='top'><p><b>6</b></p></td>
</tr>

<tr>
<td valign='top'><p><b>1</b></p></td>
<td valign='top'><p>1</p></td>
<td valign='top'><p>1</p></td>
<td valign='top'><p>1</p></td>
<td valign='top'><p>1</p></td>
<td valign='top'><p>1</p></td>
<td valign='top'><p>1</p></td>
</tr>

<tr>
<td valign='top'><p><b>2</b></p></td>
<td valign='top'><p>1</p></td>
<td valign='top'><p>1</p></td>
<td valign='top'><p>1</p></td>
<td valign='top'><p>1</p></td>
<td valign='top'><p>1</p></td>
<td valign='top'><p>1</p></td>
</tr>

<tr>
<td valign='top'><p><b>3</b></p></td>
<td valign='top'><p>1</p></td>
<td valign='top'><p>0</p></td>
<td valign='top'><p>1</p></td>
<td valign='top'><p>1</p></td>
<td valign='top'><p>1</p></td>
<td valign='top'><p>1</p></td>
</tr>

<tr>
<td valign='top'><p><b>4</b></p></td>
<td valign='top'><p>0</p></td>
<td valign='top'><p>0</p></td>
<td valign='top'><p>0</p></td>
<td valign='top'><p>1</p></td>
<td valign='top'><p>0</p></td>
<td valign='top'><p>1</p></td>
</tr>

<tr>
<td valign='top'><p><b>5</b></p></td>
<td valign='top'><p>0</p></td>
<td valign='top'><p>0</p></td>
<td valign='top'><p>0</p></td>
<td valign='top'><p>1</p></td>
<td valign='top'><p>0</p></td>
<td valign='top'><p>0</p></td>
</tr>

<tr>
<td valign='top'><p><b>6</b></p></td>
<td valign='top'><p>0</p></td>
<td valign='top'><p>0</p></td>
<td valign='top'><p>0</p></td>
<td valign='top'><p>0</p></td>
<td valign='top'><p>0</p></td>
<td valign='top'><p>0</p></td>
</tr>

</tbody>
</table>

<table cellpadding='0' align='left' cellspacing='0'>
<tbody>
<tr>
<td align='left' valign='top'><p>brickOnOff matrix</p></td>
</tr>

</tbody>
</table>

<p>By “wrapping” the matrix, I was able to obtain the well needed for my breakout game. Each time the ball would hit a lower brick, one brick from the top would disappear in order to allow the user to gain more points. The come for the bricks and bats generation will be added in the appendix section.<br />
</p>

<p><b>TGround class</b></p>

<p>The <b>TGround</b> class is used to create the ground. This is a very simple class that receives only <b>1</b> parameter through the constructor. The parameter received represents the <b>radius</b> of the circle representing the ground. The <b>draw()</b> function of the class creates a disk, with the <b>gluDisk()</b> function, with the inner radius of 0 and the outer radius equal to the radius specified in the constructor stored in the <b><i>radius</b> variable. A texture is applied to this disk in order to create a wood like floor for the game.(See the</i><b>Background theory</b> section about the ground)</p>

<p><b>Text class</b></p>

<p>This class was created for printing text strings inside the game. The class has only two function, a constructor which receives as input, the position of the text on the <b>X,Y,Z axis</b>, the <b>text</b> to be displayed and the <b>type</b> of text. The <b>type</b> of text receives a value of <b>1</b> or <b>2</b> in order to better select the style of text needed. </p>

<p>The second function of this class, is the <b>print()</b> function which prints the desired text on the screen using <b>glut</b> special functions.</p>

<p><b>Menus class</b></p>

<p>The purpose of this class is to create a simple me nu for the game. This class stores no special variables or functions to operate with them. The only three functions for this class are made for initializing the textures, spinning some of the menu items and drawing the menu and the text displayed when a menu option is selected. The class has been created in order to incorporate all the functions enumerated above in one single object. </p>

<p><b> Special features:</b></p>

<p><b>Textures</b></p>

<p>The textures for this project have been done using tutorials from the internet. One of the most useful tutorials was found at <b><i><a href='http://www.opengl.org/discussion_boards/ubbthreads.php?ubb=showflat&amp;Number=267363'>http://www.opengl.org/discussion_boards/ubbthreads.php?ubb=showflat&amp;amp;Number=267363</a></i></b> . The users not only explained how the textures work, they also published a piece of code that was used to load the textures for the application. As stated inside the <b>textures.cpp</b> file, <b>I do not present this piece of code as being developed by myself</b>. I do however understand the code that was presented and I have decided to use it to texture items present in my 3D breakout game. The code is based upon loading <b>.bmp</b> files that are then read pixel by pixel and then applied to an orthogonal. The same orthogonal is later used to represent the face of a sphere, representing a ball, a circle plane, or the skybox. </p>

<p><b> Sounds</b></p>

<p>The background sound for the planet system has been created with the use of <b>windows.h</b> library. This library offers a simple audio rendering function <b>PlaySound("</b>sounds/Ball_Rolling.wav<b>",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);</b>. The function loads a wave file which is looped for an infinite number of times or until the application is closed. The sound presented is used as a background sound while the user is inside the menu. The audio file has been downloaded from <b>zedge.com</b> and it is used with no commercial purpose. The other sounds used in the application have a similar <b>PlaySound</b> function, the only difference between them, being the parameters. </p>

<p> else switch (collision()){</p>

<p>case 1: PlaySound("sounds/roll4.wav",NULL,SND_FILENAME|SND_ASYNC); //play sound of ball hits bat</p>

<p>break;</p>

<p>case 2: PlaySound("sounds/boing.wav",NULL,SND_FILENAME|SND_ASYNC); //play sound if ball hits circle edge</p>

<p>break;</p>

<p>};</p>

<p>Caption from ball move() function</p>

<p>Based on the value return by the <b>collision()</b> function <b>0</b> if <b>no collision</b>, <b>1</b> if <b>collision</b> with the <b>brick</b> well or <b>bats</b>, and <b>2</b> if <b>collision</b> with the outer edge of the <b>ground</b>. </p>

<p><b> The Skybox</b></p>

<p>The techniques behind developing the <b>Skybox</b> have been crated in a previous assignment, which required me to create 3D Planetary System. The <b>Skybox</b> is in fact a big sphere, position at <b>(0,0,0)</b> coordinates, with a radius of <b>30</b> units. Because the light is placed inside the sphere, the interior of the texture is visible and creates the feeling of space. The cloud texture has been used, after being chosen as the best one for the wood themed game. </p>

<p><b>Lighting </b></p>

<p>The lighting of the scene has been done using <b>glut</b> special functions. By enabling, the light source and defining its positions I was able to create a well lighten scene. Because the default light was creating a scene that I have considered too dark, a new <b>lightAmbient </b>value has been defined with the purpose of increasing the luminosity of the scene. </p>

<p>GLfloat lightAmbient<a href='.md'>.md</a> = {0.7,0.7,0.7,1.0}; //increase luminosity of the scene</p>

<p>Special <b>glMaterial </b>ambient has been added to the ground, because even after the increase of luminosity of the light source, was still not bright enough. </p>

<p><b> The Score</b></p>

<p>The score has been calculated using the rules presented above. After storing the score in a <b>int</b> type variable, the a special conversion function is used, to convert it to a <b>char</b> type string. After the conversion takes place, a new text item is initialised and then displayed, showing on the screen the current score. Based on the position of the camera, the location of the score is changing.</p>

<p>void setScore()</p>

<p>{</p>

<p>s<a href='0.md'>0</a>=char(48+score/100);</p>

<p>s<a href='1.md'>1</a>=char(48+(score%100)/10);</p>

<p>s<a href='2.md'>2</a>=char(48+score%10);</p>

<p>}</p>

<p>setScore() function used to convert from int value to char string</p>

<p><b> User interaction</b></p>

<p>The user interaction with the game is made using two <b>glut</b> special function, which receives input from the keyboard, as ASCII values or as special defined values.</p>

<p>One of the function is <b>void KeyboardCallBack(unsigned char key, int A, int B)</b></p>

<p>that receives input from the keyboard as ASCII values or character. Based on the values sent by the pressed keys, I was able to program the game to produce various examples.</p>

<p>case '#':</p>

<p>cameraType++;</p>

<p>cameraType=cameraType%3+1;</p>

<p>break; // change the camera type</p>

<p>Function used to change camera type on press of #</p>

<p>The other function used is <b>void SpecialKeyboardCallBack(int key1, int A, int B)</b></p>

<p>The difference between this function and the one presented earlier is that the later one can be used to receive input from keys like <b>left</b> or <b>right arrow</b>, which are unavailable for the first one. Because these keys are used for moving object left or right, I have decided to assign them the same role. </p>

<p>case GLUT_KEY_LEFT:</p>

<p>if(menuSelection&gt;1) menuSelection--;</p>

<p>break;</p>

<p>Left key special value</p>

<p>Below is a table, showing all the keys used and their purpose. </p>

<table cellpadding='0' border='1' cellspacing='0'>
<tbody>
<tr>
<td valign='top'><p><b>Key </b></p></td>
<td valign='top'><p><b>Code</b></p></td>
<td valign='top'><p><b>Action</b></p></td>
</tr>

<tr>
<td valign='top'><p>Left arrow</p></td>
<td valign='top'><p>GLUT_KEY_LEFT</p></td>
<td valign='top'><p>Move left through the menu, or move the bat towards left</p></td>
</tr>

<tr>
<td valign='top'><p>Right arrow</p></td>
<td valign='top'><p>GLUT_KEY_RIGHT</p></td>
<td valign='top'><p>Move right through the menu, or move the bat towards right</p></td>
</tr>

<tr>
<td valign='top'><p>Enter</p></td>
<td valign='top'><p>13</p></td>
<td valign='top'><p>Select menu option</p></td>
</tr>

<tr>
<td valign='top'><p>q</p></td>
<td valign='top'><p>‘q’</p></td>
<td valign='top'><p>Zoom in</p></td>
</tr>

<tr>
<td valign='top'><p>e</p></td>
<td valign='top'><p>‘e’</p></td>
<td valign='top'><p>Zoom out</p></td>
</tr>

<tr>
<td valign='top'><p>w</p></td>
<td valign='top'><p>‘w’</p></td>
<td valign='top'><p>Move camera 3 up</p></td>
</tr>

<tr>
<td valign='top'><p>s</p></td>
<td valign='top'><p>‘s’</p></td>
<td valign='top'><p>Move camera 3 down</p></td>
</tr>

<tr>
<td valign='top'><p>a</p></td>
<td valign='top'><p>‘a’</p></td>
<td valign='top'><p>Move camera 3 left</p></td>
</tr>

<tr>
<td valign='top'><p>d</p></td>
<td valign='top'><p>‘d’</p></td>
<td valign='top'><p>Move camera 3 right</p></td>
</tr>

<tr>
<td valign='top'><p>o</p></td>
<td valign='top'><p>‘o’</p></td>
<td valign='top'><p>Un pause the game</p></td>
</tr>

<tr>
<td valign='top'><p>p</p></td>
<td valign='top'><p>‘p’</p></td>
<td valign='top'><p>Pause the game</p></td>
</tr>

<tr>
<td valign='top'><p>#</p></td>
<td valign='top'><p>‘#’</p></td>
<td valign='top'><p>Toggle through cameras</p></td>
</tr>

</tbody>
</table>

<p>Keys and their uses</p>

<p><b> Conclusion</b></p>

<p>The part of the project described above represents the second coursework for the 212CR 3D Graphics Programming. The purpose of this coursework is to demonstrate knowledge of 3D design using <b>OpenGL</b> and <b>glut </b>library. The development also makes proof of lighting and texturing knowledge, as well as general C++ programming techniques. </p>

<p>This task has been a good opportunity to further develop my knowledge of OpenGL and C++ programming.</p>

<p><b>References</b></p>

<p>1. Lighthouse 3D, (n/a) <i>OpenGL Tutorials </i><a href='online.md'>online</a> available from &lt;<a href='http://www.lighthouse3d.com/opengl/&gt;'>http://www.lighthouse3d.com/opengl/&amp;gt;</a> <a href='2.md'>March 2011</a></p>

<p>2. Gold Standard Group,(2011) <i>The OpenGL Programming Guide – The Redbook</i><a href='online.md'>online</a> available from &lt; <a href='http://www.opengl.org/documentation/red_book/&gt;'>http://www.opengl.org/documentation/red_book/&amp;gt;</a> <a href='12.md'>March 2011</a></p>

<p>3. Gold Standard Group, (2011) <i>Transparency, Translucency and Blending</i> <a href='online.md'>online</a> available from &lt; <a href='http://www.opengl.org/resources/faq/technical/transparency.htm&gt;'>http://www.opengl.org/resources/faq/technical/transparency.htm&amp;gt;</a> <a href='7.md'>March 2011</a></p>

<p>4. Gold Standard Group,(2010) <i>Texture on a sphere</i> <a href='online.md'>online</a> available from </p>

<p>&lt; <a href='http://www.opengl.org/discussion_boards/ubbthreads.php?ubb=showflat&amp;Number=267363&gt;'>http://www.opengl.org/discussion_boards/ubbthreads.php?ubb=showflat&amp;amp;Number=267363&amp;gt;</a> <a href='12.md'>March 2011</a></p>

<p>5. Gold Standard Group, (2010) <i>OpenGL Documentation</i> <a href='online.md'>online</a> available from</p>

<p>&lt; <a href='http://www.opengl.org/sdk/docs/man/xhtml/'>http://www.opengl.org/sdk/docs/man/xhtml/</a> &gt; <a href='10.md'>March 2011</a></p>

<p>6. Liarokapis, F. (2010) <i>Interaction and Callbacks</i> <a href='online.md'>online</a> available from &lt;</p>

<p>&lt; <a href='http://moodle.coventry.ac.uk/ec/mod/resource/view.php?id=13424&gt;'>http://moodle.coventry.ac.uk/ec/mod/resource/view.php?id=13424&amp;gt;</a> <a href='9.md'>March 2011</a></p>

<p>7. Liarokapis, F. (2010)<i> Colour</i> <a href='online.md'>online</a> available from </p>

<p>&lt;<a href='http://moodle.coventry.ac.uk/ec/mod/resource/view.php?id=12940&gt;'>http://moodle.coventry.ac.uk/ec/mod/resource/view.php?id=12940&amp;gt;</a> <a href='.md'>9 March 2011</a></p>

<p>8. Stackoverflow.com (2011) <i>Ball Collision</i><a href='online.md'>online</a> available from &lt; <a href='http://stackoverflow.com/questions/4613345/python-pygame-ball-collision-with-interior-of-circle&gt;'>http://stackoverflow.com/questions/4613345/python-pygame-ball-collision-with-interior-of-circle&amp;gt;</a> <a href='5.md'>march 2011</a></p>

<p>9. Stackoverflow.com (2011) <i>How to calculate bounce angle?</i><a href='online.md'>online</a> available from &lt; <a href='http://stackoverflow.com/questions'>http://stackoverflow.com/questions</a> /573084/how-to-calculate-bounce-angle/573206#573206&gt; <a href='7.md'>march 2011</a></p>

<p>10. Stackoverflow.com (2011) <i>Normal vector of a line segment</i> <a href='online.md'>online</a> available from &lt; <a href='http://stackoverflow.com/questions/1243614/how-do-i-calculate-the-normal-vector-of-a-line-segment&gt;'>http://stackoverflow.com/questions/1243614/how-do-i-calculate-the-normal-vector-of-a-line-segment&amp;gt;</a> <a href='8.md'>March 2011</a></p>

<p>11. Glprogramming.com (n/a) <i>Lighting </i><a href='online.md'>online</a> available from &lt; <a href='http://glprogramming.com/red/chapter05.html&gt;'>http://glprogramming.com/red/chapter05.html&amp;gt;</a> <a href='10.md'>March 2011</a></p>