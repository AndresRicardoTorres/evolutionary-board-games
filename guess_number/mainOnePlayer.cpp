#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/program_options.hpp>
#include <iostream>
#include <iterator>
#include <string>
#include <list>

#include "guess_number/GuessNumberOnePlayer.h"

namespace po = boost::program_options;

std::list<std::string> sepByComma(std::string str) {
    std::list<std::string> splitVec;
    boost::split(splitVec, str, boost::is_any_of(",") );
    return splitVec;
}

std::list<int> parseIntList(std::list<std::string> vectorStr) {
    std::list<int> vectorInt;

    while(!vectorStr.empty()){

        std::string aStr = vectorStr.front();
        int aInt = 0;
        try {
            aInt = boost::lexical_cast<int>(aStr);
        } catch (boost::bad_lexical_cast) {
            std::cout << "conversion failed : " << aStr <<
            " is not a number" << std::endl;
        }
        vectorInt.push_back(aInt);
        vectorStr.pop_front();
    }

    return vectorInt;
}

std::list<int> readIntList(std::string str) {
    return parseIntList(sepByComma(str));
}

int main(int argc, char *argv[]) {
    try {
        po::options_description desc("Allowed options");
        desc.add_options()
            ("help"    , "produce help message")
            ("secret"  , po::value<std::string>(), "Goal numbers")
            ("program" , po::value<std::string>(), "Program code");

        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);

        if (vm.count("help")) {
            std::cout << desc << std::endl;
            return 0;
        }

        if (vm.count("secret") && vm.count("program")) {
            std::list<int> goal = readIntList(vm["secret"].as<std::string>());
            std::list<int> code = readIntList(vm["program"].as<std::string>());
            GuessNumberOnePlayer *objGame = new GuessNumberOnePlayer(goal
                                                                    , code);
            int score = objGame->play();
            std::cout << score << std::endl;
            delete objGame;
        } else {
            std::cout << desc << std::endl;
        }
    }
    catch(std::exception& e) {
        std::cerr << "error: " << e.what() << std::endl;
        return 1;
    }
    catch(...) {
        std::cerr << "Exception of unknown type!" << std::endl;
    }

    return 0;
}
