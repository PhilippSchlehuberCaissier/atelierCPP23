#pragma once
#include <fstream>
#include <iostream>

namespace LogMe
{
    enum logging_level {
        Critical = 10,
        Error    = 20,
        Warn     = 30,
        Info     = 40,
        Debug    = 50
    };

    class Logger
    {
        std::ofstream m_os;
        logging_level m_level = Info;

        public:
            Logger() = default;
            Logger(const std::string& path);

            void set_debug_level(logging_level level); 

            // FIXME log for all types

            // FIXME debug info etc

    };


    // Part 2 (Default logger)
    // FIXME global Logger
    namespace internal {
        // FIXME
    }


    // Part 3 (Stream Logger -> Pattern Adapter)
    class StreamLogger
    {
        Logger         m_logger;
        logging_level  m_flag = Info;

        public:
            StreamLogger() = default;
            StreamLogger(const std::string& path);

            // FIXME Streamlogger
    };
}