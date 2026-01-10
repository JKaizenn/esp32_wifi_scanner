#include "credentialManager.h"

/**************
 * DEFAULT CONSTRUCTOR
 **************/
CredentialManager::CredentialManager() {
    // Open preferences
    preferences.begin(NAMESPACE, false);
}

/**************
 * DESTRUCTOR
 **************/
CredentialManager::~CredentialManager() {
    preferences.end();
}

/**************
 * SAVE
 **************/
void CredentialManager::save(const String& ssid, const String& password)
{
    preferences.putString(KEY_SSID, ssid);
    preferences.putString(KEY_PASSWORD, password);
}

/**************
 * GET SSID
 **************/
String CredentialManager::getSsid()
{
    return preferences.getString(KEY_SSID, "");
}

/**************
 * GET PASSWORD
 **************/
String CredentialManager::getPassword()
{
    return preferences.getString(KEY_PASSWORD, "");
}

/**************
 * HAS CREDENTIALS
 **************/
bool CredentialManager::hasCredentials()
{
    return preferences.isKey(KEY_SSID);
}

/**************
 * CLEAR
 **************/
void CredentialManager::clear()
{
    preferences.remove(KEY_SSID);
    preferences.remove(KEY_PASSWORD);
}