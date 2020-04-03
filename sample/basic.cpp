#include <iostream>

#include "../argparse/argparse.hpp"

using namespace argparse;
using namespace std;

int main(const int argc, const char **argv)
{
    try
    {
        auto parser = ArgumentParser("FooBar");
        parser.add_argument("help", "-h", "--help", "Displays the help message");
        parser.add_argument("conf", "-c", "--conf", "Path to a file", STORE);
        parser.add_argument("force", "-f", "", "Force hello world", FLAG);

        if (!parser.parse(argv, argc))
        {
            cout << "Error parsing arguments" << endl;
            return 1;
        }
        else if (parser.get("help").is_set())
        {
            parser.print_usage();
            return 0;
        }

        auto conf_arg = parser.get("conf");
        if (conf_arg.is_set())
        {
            cout << "Conf file: " << conf_arg.get_value() << endl;
        }
        else
        {
            cout << "No configuration given." << endl;
        }

        if (parser.get("force").is_set())
        {
            cout << "HELLO WORLD" << endl;
        }
    }
    catch (const char *error)
    {
        cerr << "ERROR: " << error << endl;
        return 1;
    }
    catch (std::string &error)
    {
        cerr << "ERROR: " << error << endl;
        return 1;
    }

    return 0;
}
