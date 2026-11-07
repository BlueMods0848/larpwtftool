#pragma once

#include <iostream>
#include <string>

struct Globals
{
    std::string frlToken;
    std::string appId;
    
    std::string webhookUrl;
    std::string webhookMessage;
    int webhAmtToSend;
}; Globals globals;