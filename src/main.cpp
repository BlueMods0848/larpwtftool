#include <iostream>
#include "gennonce.hpp"
#include "sendwebhook.hpp"
#include "globals.hpp"
#include "termcolor/termcolor.hpp"
#include <windows.h>

int opt;
bool running = true;

void pause()
{
    std::cout << "Press enter to continue...";
    std::cin.ignore();
    std::cin.get();
}

void clear()
{
    system("cls");
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    SetConsoleTitleA("LARP.WTF");

    while(running)
    {
        clear();
        std::cout << termcolor::blue << R"(
                                                                                 
▄▄▄        ▄▄▄▄   ▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄   ▄▄▄▄  ▄▄▄  ▄▄▄▄ ▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄ 
███      ▄██▀▀██▄ ███▀▀███▄ ███▀▀███▄ ▀███  ███  ███▀ ▀▀▀███▀▀▀ ███▀▀▀▀▀ 
███      ███  ███ ███▄▄███▀ ███▄▄███▀  ███  ███  ███     ███    ███▄▄    
███      ███▀▀███ ███▀▀██▄  ███▀▀▀▀    ███▄▄███▄▄███     ███    ███▀▀    
████████ ███  ███ ███  ▀███ ███   ██    ▀████▀████▀      ███    ███      
                                                                         
        )" << termcolor::reset << "\n";

        std::cout << termcolor::green;
        std::cout << "1. Generate Nonce\n"
                << "2. Send Webhook\n"
                << "3. Playfab loginwithcustomid\n"
                << "4. Exit\n";
        std::cout << termcolor::blue << "Select an option: ";
        std::cin >> opt;
        switch(opt)
        {
            case 1:
                std::cout << "Please enter your FRL Token: ";
                std::cin >> globals.frlToken;
                std::cout << "Please enter games app id: ";
                std::cin >> globals.appId;
                std::cout << "Nonce: " << GenNonce.generateNonce(globals.frlToken, globals.appId) << "\n";
                pause();
                break;
            case 2:
                std::cout << "Please enter the webhook url: ";
                std::cin >> globals.webhookUrl;
                std::cout << "Please enter the message to send: ";
                std::cin >> globals.webhookMessage;
                std::cout << "Please enter the number of messages to send: ";
                std::cin >> globals.webhAmtToSend;
                SendWebhook.sendWebhook(globals.webhookUrl, globals.webhookMessage, globals.webhAmtToSend);
                pause();
                break;
            case 3: 
                std::cout << "Playfab loginwithcustomid functionality is not implemented yet. will be next update\n";
                pause();
                break;
            case 4:
                running = false;
        }

        std::cout << termcolor::reset;
    }

    return 0;
}