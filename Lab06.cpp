// Lab06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int main()
{
	string background = "images1/backgrounds/winter.png";
	string foreground = "images1/characters/yoda.png";

	//loads image
	Texture backgroundTex;
	if (!backgroundTex.loadFromFile(background)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}

	//loads image
	Texture foregroundTex;
	if (!foregroundTex.loadFromFile(foreground)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}

	
	Image backgroundImage;// creates image
	backgroundImage = backgroundTex.copyToImage();// fills image with picture data from texture
	Image foregroundImage;// creates image
	foregroundImage = foregroundTex.copyToImage();// fills image with picture data from texture

	Color greenColor = foregroundImage.getPixel(0, 0);

	Vector2u sz = backgroundImage.getSize();
	for (int y = 0; y < sz.y; y++) {
		for (int x = 0; x < sz.x; x++) {
			
			//These two loops will run the code inside for each pixel in the background image
			//access the current pixel at x, y
			Color g = foregroundImage.getPixel(x,y);
			Color winter = backgroundImage.getPixel(x, y);
		
			 if(g == greenColor) {
				foregroundImage.setPixel(x, y, winter);
			
			}
			
		}
	}
	

	//By default, just show the foreground image
	RenderWindow window(VideoMode(1024, 768), "Here's the output");
	Sprite sprite1;
	Texture tex1;
	tex1.loadFromImage(foregroundImage);
	sprite1.setTexture(tex1);
	window.clear();
	window.draw(sprite1);
	window.display();
	while (true);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
