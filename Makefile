main_game: main_game.cpp
	g++ -o sample.exe  main_game.cpp  gameRunner.cpp  playfield.cpp  shape/shapeI.cpp  shape/shapeS.cpp  shape/shape.cpp  -lm  -framework  OpenGL  -framework  GLUT