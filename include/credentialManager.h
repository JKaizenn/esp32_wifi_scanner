#ifndef CREDENTIAL_MANAGER_H
#define CREDENTIAL_MANAGER_H
#include <Preferences.h>
#include <Arduino.h>

class CredentialManager
{
public:
    CredentialManager();
    ~CredentialManager();

    // Delete - Copy and Move Constructors only one manager should exist
    CredentialManager(const CredentialManager&) = delete;
    CredentialManager& operator=(const CredentialManager&) = delete;
    CredentialManager(CredentialManager&&) = delete;
    CredentialManager& operator=(CredentialManager&&) = delete;

    // Public methods
    void save(const String& ssid, const String& password);
    String getSsid();
    String getPassword();
    bool hasCredentials();
    void clear();

private:
    Preferences preferences; // The library object

    static constexpr const char* NAMESPACE    {"wifi"};
    static constexpr const char* KEY_SSID     {"ssid"};
    static constexpr const char* KEY_PASSWORD {"password"};
};

#endif