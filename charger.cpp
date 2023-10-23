#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace sf;
using namespace std;

int main()
{
    int width = 1200, height = 800;

    RenderWindow window(VideoMode(width, height), "Charger");

    int x(200), y(20), rectangle_y(0), rectangle_x(60);

    int size = width / rectangle_x -8;

    Clock clock;
    srand(time(0));

    double timer(0), delay(0.3);
    int position = 0;
    bool once = false;

    RectangleShape* rect = new RectangleShape[size];
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float time = clock.getElapsedTime().asSeconds();
        timer += time;
        clock.restart();

        window.clear();
        if (!once) 
        {

            for (int i(0); i < size; i++)
            {
                timer += time;
                rectangle_y = 400;

                y = height - rectangle_y;

                rect[i].setSize(Vector2f(rectangle_x, rectangle_y));
                rect[i].setFillColor(Color::Cyan);


                if (i == size - 2)
                {
                    rect[i].setSize(Vector2f(rectangle_x, rectangle_y*0.8));
                    rect[i].setFillColor(Color::Cyan);
                    rect[i].setPosition(x, 240);
                }

                if (i == size - 1)
                {
                    rect[i].setSize(Vector2f(rectangle_x, rectangle_y * 0.6));
                    rect[i].setFillColor(Color::Cyan);
                    rect[i].setPosition(x, 280);

                }

            
                if (i != size - 1 && i != size - 2)rect[i].setPosition(x, y - 200);
           
                window.draw(rect[i]);


                x += rectangle_x+5;
            
            }
            once = true;
            

        }

        for (int k(0); k < size; k++)
        {
            window.draw(rect[k]);
        }
        if (timer > delay)
        {
            rect[position].setFillColor(Color::Green);
            if (position < size - 1)position++;
            timer = 0;

        }

        x = 0;

        window.display();
    }
    

    delete[] rect;

}