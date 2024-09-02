#include "ProgramOptions.hpp"

#include <boost/program_options.hpp>

#include <cassert>
#include <iostream>

namespace ProgramOptions
{
ProgramOptions::ProgramOptions()
{
    m_options.add_options()
        ("help", "produce help message")
        ("api_key", boost::program_options::value<std::string>(), "API key used to access Google map services");
}

std::string ProgramOptions::GetApiKey()
{
    if (m_variables.count("api_key"))
    {
        return m_variables["api_key"].as<std::string>();
    }
    return "";
}

void ProgramOptions::ParseCommandLine(std::int32_t argc, char** argv)
{
    assert(argc && "Expect non-zero arg count");
    assert(argv && "Expect non-null argument array");

    auto options = boost::program_options::parse_command_line(argc, argv, m_options);
    boost::program_options::store(options, m_variables);
    boost::program_options::notify(m_variables);
}

void ProgramOptions::PrintHelp()
{
    std::cout << m_options << "\n";
}

bool ProgramOptions::RequestedHelp()
{
    return m_variables.empty() || m_variables.count("help");
}

std::shared_ptr<ProgramOptions> Create()
{
    return std::make_shared<ProgramOptions>();
}
}