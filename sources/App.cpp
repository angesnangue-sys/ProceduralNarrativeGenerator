#include "App.h"
#include <iostream>


App::App()
{
    mIsRunning = true;
}

void App::Run()
{
    while (mIsRunning)
    {
        showmenu();

        int choice;
        std::cin >> choice;
        std::cin.ignore();

        handlechoice(choice);
    }
}

void App::showmenu()
{
    std::cout << "\n=== MENU PRINCIPAL ===\n";
    std::cout << "1 - Generer une histoire\n";
    std::cout << "2 - Quitter\n";
    std::cout << "Votre choix : ";
}

void App::handlechoice(int choice)
{
    std::string element;
        switch (choice)
        {
            case 1:
                std::cout << "Histoire : \n";
                std::cout << generator.Generateparagraph() << std::endl;
                break;
            case 2:
              mIsRunning = false;
              break;
            
            default:
                std::cout << "Choix invalide. \n";
                break; 
    }
}
