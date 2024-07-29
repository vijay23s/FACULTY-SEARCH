#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <iomanip>
#include <windows.h>
using namespace std;

class faculty {
public:
    vector<string> tags;
};
int getWindowWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

void printHeader(const std::string& text, char borderChar = '*') {
    int windowWidth = getWindowWidth();

    // Calculate the width needed for padding
    int padding = windowWidth - text.length() - 2; // 2 for the border characters

    // Ensure padding is non-negative
    padding = std::max(padding, 0);

    std::cout << std::setfill(borderChar) << std::setw(padding / 2) << "" << text
              << std::setw(padding / 2) << "" << std::endl;
    std::cout << std::setfill(' ') << std::setw(windowWidth) << "" << std::endl;
}

std::string toLowerCase(const std::string& input) {
    std::string result = input;

    // Convert each character to lowercase
    for (char& c : result) {
        c = std::tolower(c);
    }

    return result;
}

std::string removeSpaces(const std::string& input) {
      std::string result = input;

    // Remove spaces
    result.erase(std::remove_if(result.begin(), result.end(), ::isspace), result.end());

    // Remove special characters (.,,* in this case)
    result.erase(std::remove_if(result.begin(), result.end(), [](char c) {
        return c == '.' || c == ',' || c == '*';
    }), result.end());

    return result;
}

void openWebBrowser(const std::string& url) {
    // Use the system function to open the link
    #ifdef _WIN32
        // On Windows, use the "start" command
        const char* command = "start";
    #elif defined(APPLE)
        // On macOS, use "open"
        const char* command = "open";
    #else
        // On Linux, use "xdg-open"
        const char* command = "xdg-open";
    #endif

    // Form the full command
    std::string fullCommand = std::string(command) + " " + url;

    // Execute the command
    int result = system(fullCommand.c_str());

    // Check if the system call was successful
    if (result == 0) {
        std::cout << "Link opened successfully." << std::endl;
    } else {
        std::cerr << "Failed to open the link." << std::endl;
    }
}

faculty searchbytag(const vector<faculty> &x) {
    cout << "Enter the search: " << endl;
    string searchtag;
    std::getline(std::cin, searchtag);

     searchtag = toLowerCase(searchtag);
       cout << searchtag << endl;
     searchtag = removeSpaces(searchtag);



     cout << searchtag << endl;
    int n = x.size();
    for (int i = 0; i < n; i++) {
        int l = x[i].tags.size();

        for (int j = 0; j < l; j++) {
            if (searchtag == x[i].tags[j]) {
                return x[i];
            }
        }
    }

    // Return a default faculty object if no match is found
    return faculty();
}



int main() {
    // Create 9 faculty objects
    faculty KCN, HMC, TNC, UL, KV, PTR, MNS, KDK, MBC,t2022,t2023,t2021,HOME;

    // Assign tags and links for each faculty
    KCN.tags = {"KCN", "narasimha","kc","drkcn","knarasimhamurthy","murthy","kcn","kcmurthy","drmurthy","drnarasimhamurthy","drnarasimha"};
    HMC.tags = {"HMC", "chandra","hmchandrashekar","shekar","hmc","chandrashekhar","chandru","drhmchandrashekhar","drchandrashekhar","drhmc"};
    TNC.tags = {"TNC", "chandrika","tnchandrika","tnc","tnchandrika","chandrikatn","drtnc","drtnchandrika","drchandrika",""};
    UL.tags = {"UL", "usha","ushal","ul","drusha","drushal","drul"};
    KV.tags = {"KV", "vishwanath","kvishwanath","vishwanathk","kv","drkv","drvishwanath","drkvishwanath"};
    PTR.tags = {"PTR", "puneeth","puneethtr","ptr","drpuneeth","drptr","puneethkumar","puneethkumartr","drpuneethkumartr","drpuneethkumar","punith"};
    MNS.tags = {"MNS", "mns", "sujatha","drmns","drsujatha","sujathamn","drsujathamn","drmnsujatha"};
    KDK.tags = {"KDK", "kdk", "kumuda","drkumuda","drkdk","drkdkumuda","kumudakd","drkumudakd"};
    MBC.tags = {"MBC", "mbc", "mallikarjun","mallikarjunbc","drmallikarjun","drmbc","drmallikarjunbc","bcmallikarjun","drbcmallikarjun"};
    t2022.tags= {"t2022","2022"};
    t2023.tags ={"t2023", "2023"};
    t2021.tags= {"t2021", "2021"};
    HOME.tags=  {"HOME","home","ete","etc"};
    vector<faculty> fac_list = {KCN, HMC, TNC, UL, KV, PTR, MNS, KDK, MBC,t2022,t2023,t2021,HOME};

    //cout << "Hello world!" << endl;

    // Search for the faculty member
    printHeader("DEPARTMENT OF ELETRONICS AND TELECOMMUNICATION");
    faculty result = searchbytag(fac_list);

    // Check the tags of the result and launch the corresponding link
    for (const auto &tag : result.tags) {
        if (tag == "KCN") {
            cout << "Launching link for KCN" << endl;
            // Add code to launch KCN link
            std::string urlToOpen = "https://scholar.google.co.in/citations?user=hHSGiLkAAAAJ&hl=en";
            openWebBrowser(urlToOpen);

        } else if (tag == "HMC") {
            cout << "Launching link for HMC" << endl;
            // Add code to launch HMC link
            std::string urlToOpen = "https://scholar.google.co.in/citations?user=b_ArqgQAAAAJ&hl=en";
            openWebBrowser(urlToOpen);
        } else if (tag == "TNC") {
            cout << "Launching link for TNC" << endl;
            // Add code to launch TNC link
            std::string urlToOpen = "https://scholar.google.co.in/citations?user=5KIZzXAAAAAJ&hl=en";
            openWebBrowser(urlToOpen);
        } // Add similar conditions for other faculties
            else if (tag == "UL") {
            cout << "Launching link for UL" << endl;
            // Add code to launch TNC link
            std::string urlToOpen = "https://scholar.google.co.in/citations?user=_dDu32IAAAAJ";
            openWebBrowser(urlToOpen);
        }
        else if (tag == "KV") {
            cout << "Launching link for KV" << endl;
            // Add code to launch TNC link
            std::string urlToOpen = "https://scholar.google.co.in/citations?user=m0l-rjoAAAAJ&hl=en";
            openWebBrowser(urlToOpen);
        }
        else if (tag == "PTR") {
            cout << "Launching link for PTR" << endl;
            // Add code to launch TNC link
            std::string urlToOpen = "https://scholar.google.com/citations?user=4YTtXlcAAAAJ&hl=en ";
            openWebBrowser(urlToOpen);
        }
        else if (tag == "MNS") {
            cout << "Launching link for MNS" << endl;
            // Add code to launch TNC link
            std::string urlToOpen = "https://sit.irins.org/profile/91225";
            openWebBrowser(urlToOpen);
        }
        else if (tag == "MBC") {
            cout << "Launching link for MBC" << endl;
            // Add code to launch TNC link
            std::string urlToOpen = "https://scholar.google.co.in/citations?user=mB9WIXAAAAAJ&hl=en";
            openWebBrowser(urlToOpen);
        }
        else if (tag == "KDK") {
            cout << "Launching link for KDK" << endl;
            // Add code to launch TNC link
            std::string urlToOpen = "https://sit.irins.org/profile/91233";
            openWebBrowser(urlToOpen);
        }
        else if (tag == "t2022") {
            cout << "Launching link for t2022" << endl;
            // Add code to launch TNC link
            std::string urlToOpen = "https://weblaunch2022-git-hub-io.vercel.app/";
            openWebBrowser(urlToOpen);
        }
        else if (tag == "t2023") {
            cout << "Launching link for t2023" << endl;
            // Add code to launch TNC link
            std::string urlToOpen = "https://weblaunch2023-git-hub-io.vercel.app/";
            openWebBrowser(urlToOpen);
        }
         else if (tag == "t2021") {
            cout << "Launching link for t2021" << endl;
            // Add code to launch TNC link
            std::string urlToOpen = "https://weblaunch2021-git-hub-io.vercel.app/";
            openWebBrowser(urlToOpen);
        }
        else if (tag == "HOME") {
            cout << "Launching link for HOME PAGE" << endl;
            // Add code to launch TNC link
            std::string urlToOpen = "https://mainweb-git-hub-io.vercel.app/";
            openWebBrowser(urlToOpen);
        }

        // Add additional conditions for other faculties
    }

    return 0;
}