#pragma once
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <iostream>
#include "globals.hpp"
#include "httplib.h"
#include "json.hpp"

using json = nlohmann::json;

struct genNonce
{
    std::string generateNonce(const std::string& frlToken, const std::string& appId)
    {
        std::string token;
        std::string nonce;

        httplib::SSLClient cli("graph.oculus.com", 443);

        json authBody = {
            {"access_token", frlToken},
            {"app_id", appId}
        };

        auto authR = cli.Post("/authenticate_application", authBody.dump(), "application/json");

        if(authR && authR->status == 200)
        {
            json responseJson = json::parse(authR->body);
            token = responseJson["access_token"].get<std::string>();
        }

        json nonceBody = {
            {"access_token", token}
        };

        auto nonceR = cli.Post("/user_nonce_generate", nonceBody.dump(), "application/json");
        if(nonceR && nonceR->status == 200)
        {
            json responseJson = json::parse(nonceR->body);
            nonce = responseJson["nonce"].get<std::string>();
        }
        return nonce;
    }
}; genNonce GenNonce;