#include <iostream>
#include <SFML/Graphics.hpp>
const int clearlines = 10;
int map[] = {0};
int width = 16, height = 12, timesmapby = 100;
float delaysecs = 1;
void display(sf::RenderWindow& window), consoledisplay(), logic(), testingmap(), delay();
int loadmap();
int main(){
    std::cout << "S&ND B0X++  -By Daniel S\n";
    std::cout << "map width: ";
    std::cin >> width;
    std::cout << "map height: ";
    std::cin >> height;
    std::cout << "delay (seconds): ";
    std::cin >> delaysecs;
    std::cout << "window size (pixels*width/height): ";
    std::cin >> timesmapby;
    srand(clock());
    loadmap();
    //testingmap();
    sf::RenderWindow window(sf::VideoMode(width*timesmapby, height*timesmapby), "S&ND B0X", sf::Style::Close);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed){
                window.close();
                return 0;
            }
        }
        ////////////SIM LOOP////////////////
        logic();
        consoledisplay();
        display(window);
        delay();


        ////////////END SIM LOOP////////////
    }
    return 0;
}


void display(sf::RenderWindow& window){
    int p = 0;
    window.clear(sf::Color::Black);
    for(int y = 0; y< height; y++){
        for(int x = 0; x < width; x++){
                       // std::cout << p;
            //std::cout << map[p];
            if(map[p] != 0){
                //std::cout << p;
                sf::RectangleShape square(sf::Vector2f(timesmapby, timesmapby));
                if(map[p] == 7){
                    square.setFillColor(sf::Color(255, 255, 255));
                }
                else if(map[p] == 5){
                    square.setFillColor(sf::Color(255, 255, 0));
                }
                else if(map[p] == 8){
                    square.setFillColor(sf::Color(255, 0, 255));
                }
                square.setPosition(x*timesmapby, y*timesmapby);
                window.draw(square);
            }
            p++;
        }
    }
    window.display();

}


void consoledisplay(){ //consoledisplays to console
    for(int m = 0; m < clearlines; m++){
        std::cout << "\n";
    }
    int i = 0;
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
           std::cout << map[i]; 
           i++;
        }
        std::cout << "\n";
    }
}

void logic(){
    // int p = (width*height);
    int rndnum = rand() % 2;
    // std::cout << "randnum: " << rndnum << "\n";
    
for (int i = (width * height); i > 0; i--){
        int x = i % width;
        int y = i / width;
        
        if (map[i] == 8 || map[i] == 5){
            if (y < height - 1 && map[i + width] == 0){
                map[i + width] = 5;
                if(map[i] == 5){
                    map[i] = 0;
                }
            }
            else if (y < height - 1 && x > 0 && x < width - 1 && map[i + width - 1] == 0 && map[i + width + 1] == 0){
                if (rndnum == 0){
                    map[i + width - 1] = 5;
                }
                else {
                    map[i + width + 1] = 5;
                }
                if(map[i] == 5){
                    map[i] = 0;
                }
            }
            else if (y < height - 1 && x > 0 && map[i + width - 1] == 0){
                map[i + width - 1] = 5;
                if(map[i] == 5){
                    map[i] = 0;
                }
            }
            else if (y < height - 1 && x < width - 1 && map[i + width + 1] == 0){
                map[i + width + 1] = 5;
                if(map[i] == 5){
                    map[i] = 0;
                }
            }
        }
    }
}


void testingmap(){
   width = 25;
   height = 25;
    for(int i = 0; i < (width*height); i++){
        map[i] = 0;
    }
    for(int i = width*((height/4)*3); i < width*((height/4)*3) + (width/2) - 5; i++){
        map[i] = 7;
    }
    for(int i = width*((height/4)*3)+width/2 + 6; i < width*((height/4)*3) + width; i++){
        map[i] = 7;
    }
    for(int i = width*height - width; i < width*height; i++){
        map[i] = 7;
    }
    for(int i = width*(height/2)+width/4+1; i < width*(height/2)+width/2+width/4; i++){
        map[i] = 7;
    }
    for(int i = width/2-1; i < width/2+1; i++){
        map[i] = 8;
    }
}

void delay()
{
    unsigned long tix = (delaysecs * CLOCKS_PER_SEC);
    unsigned long newtix = clock() + tix;
    while (newtix > clock()){}
    return;
}

int loadmap()
{
    FILE *mapfile;
    if (fopen("map.txt", "r") == NULL)
    {
        std::cout << "\nmap.txt not found... defaulting to big test map";
        testingmap();
        //std::cout << "map.txt not found. exiting...";
        exit(1);
    }
    mapfile = fopen("./map.txt", "r");
    for (int i = 0; i < (width * height); i++)
    {
        fscanf(mapfile, "%d,", &map[i]);
    }
    return 0;
}
