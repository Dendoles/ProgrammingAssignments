// Šuráb, Denis 1DAE13
#include <iostream>
#include<windows.h>
void CleanScreen();

int main()
{
    //RGBA app
    float r{ }, g{ }, b{ }, a{ };
    float divider{ 255.0f };

    std::cout << "RGBA in [0, 255]? ";
    std::cin >> r >> g >> b >> a;
    std::cout << "RGBA in [0.0f, 1.0f]: " << std::endl;
    //calculaton
    r /= divider;
    g /= divider;
    b /= divider;
    a /= divider;

    std::cout << r << std::endl << g << std::endl << b << std::endl << a;
    CleanScreen();
    
    //Distance convertion app
    float distanceInKm{ };
    std::cout << "Distance in km? ";
    std::cin >> distanceInKm;

    std::cout << distanceInKm * 1000 << " meters, " << distanceInKm * 100000 << " cm";
    CleanScreen();

    //Angle in radians app
    const double pi = 3.14159265358979323846;
    double radiants{ };

    std::cout << "Angle in radians? ";
    std::cin >> radiants;

    std::cout << radiants * (180 / pi) << " degrees";
    CleanScreen();

    //Angle in degrees app
    double angle{ };

    std::cout << "Angle in degrees? ";
    std::cin >> angle;

    std::cout << (angle * pi) / 180 << " radians";
    CleanScreen();

    //Velocity app
    int seconds{ };

    std::cout << "Seconds of one rotation? ";
    std::cin >> seconds;
    std::cout << 360 / seconds << " degrees/second";
    CleanScreen();

    //Distance in meters after elapsed time app
    int speed{ }; //km/h * -1 
    int elapsedTime{ }; //minutes
    float dividingNumber{ 16.66666667f };

    std::cout << "Speed (km/h)? ";
    std::cin >> speed;
    std::cout << "Elapsed time (minutes)?  ";
    std::cin >> elapsedTime;

    std::cout << (speed * dividingNumber) * elapsedTime << " meters";
    CleanScreen();

    //Velocity of an falling object app
    int timeFalling{ }; //time inputed by user in seconds
    float gravitionalAcceleration{ 9.8f }; //meters per second
    
    std::cout << "Seconds? ";
    std::cin >> timeFalling;

    std::cout << "Velocity " << gravitionalAcceleration * timeFalling << " m/sec";
    CleanScreen();

    //Area and circumference of circle app
    double radiusOfCircle{ };

    std::cout << "Radius of circle? ";
    std::cin >> radiusOfCircle;

    std::cout << "Circumference: " << 2 * pi * radiusOfCircle << std::endl;
    std::cout << "Area: " << pi * (radiusOfCircle * radiusOfCircle);
    CleanScreen();

    //Area and circumference of rectangle
    int widthOfRectangle{ };
    int heightOfRectangle{ };

    std::cout << "Width and height? ";
    std::cin >> widthOfRectangle >> heightOfRectangle;

    std::cout << "Circumference: " << 2 * widthOfRectangle + 2 * heightOfRectangle << std::endl;
    std::cout << "Area: " << widthOfRectangle * heightOfRectangle;
    CleanScreen();

    //Area of triangle
    int baseOfTriangle{ };
    int heightOfTriangle{ };

    std::cout << "Base and height? ";
    std::cin >> baseOfTriangle >> heightOfTriangle;

    std::cout << "Area: " << (baseOfTriangle * heightOfTriangle) / 2;
    CleanScreen();
}

void CleanScreen()
{
    Sleep(1000);
    std::cout << std::endl << std::endl << "Just wait a sec...";
    Sleep(3000);
    system("cls");
}