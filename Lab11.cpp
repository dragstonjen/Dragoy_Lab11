#include <iostream>
#include <regex>
#include <string>

using namespace std;

struct Website {
private:
    string URL;
    string name;
    string description;

public:

    Website(const string& url, const string& siteName, const string& siteDescription)
        : URL(url), name(siteName), description(siteDescription) {}

    bool isValidURL() const {
        regex urlPattern(R"(^(https?|ftp)://[^\s/$.?#].[^\s]*$)");
        return regex_match(URL, urlPattern);
    }

    string getProtocol() const {
        regex protocolPattern(R"(^(https?|ftp))");
        smatch match;
        if (regex_search(URL, match, protocolPattern)) {
            return match.str();
        }
        return "Unknown";
    }

    void displayInfo() const {
        cout << "Website Name: " << name << "\n"
             << "Description: " << description << "\n"
             << "URL: " << URL << "\n"
             << "Protocol: " << getProtocol() << "\n"
             << "URL is " << (isValidURL() ? "valid" : "invalid") << ".\n";
    }
};

int main() {
    Website site("https://steamcommunity.com/profiles/76561198404409068/", "Steam", "A gaming community profile.");
    site.displayInfo();

    return 0;
}
