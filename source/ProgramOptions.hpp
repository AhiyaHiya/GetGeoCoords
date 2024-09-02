#pragma once

#include <boost/program_options.hpp>

#include <memory>
#include <string>

namespace ProgramOptions
{
class ProgramOptions
{
public:
    ProgramOptions();

    std::string GetApiKey();

    void ParseCommandLine(std::int32_t argc, char** argv);
    void PrintHelp();
    bool RequestedHelp();

private:
    boost::program_options::options_description m_options = boost::program_options::options_description("Program options");
    boost::program_options::variables_map m_variables = boost::program_options::variables_map();
};

std::shared_ptr<ProgramOptions> Create();
}

