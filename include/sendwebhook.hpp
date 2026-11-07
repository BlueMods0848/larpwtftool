#pragma once
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <iostream>
#include "globals.hpp"
#include "httplib.h"
#include "json.hpp"
#include <thread>
#include <chrono>

using json = nlohmann::json;

struct sendwbh
{
    void sendWebhook(const std::string& webhookUrl, const std::string& message, int amount)
    {
        std::string prfx = "https://discord.com/";
        std::string tkn = webhookUrl.substr(prfx.length());
        httplib::SSLClient cli("discord.com", 443);

        json payload = {
            {"content", message}
        };

        for(int i = 0; i < amount; i++)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            auto res = cli.Post(("/" + tkn).c_str(), payload.dump(), "application/json");
            if(res && res->status == 204)
            {
                std::cout << "Webhook sent successfully!\n";
            }
            else
            {
                std::cout << "Failed to send webhook. Status: " << (res ? std::to_string(res->status) : "No response") << "\n";
            }
        }
    }
}; sendwbh SendWebhook;