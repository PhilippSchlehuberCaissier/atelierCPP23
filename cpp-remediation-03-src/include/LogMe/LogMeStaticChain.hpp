#pragma once
#include <fstream>
#include <iostream>
#include <list>
#include <vector>

namespace LogMe
{
    enum logging_level {
        Critical = 10,
        Error    = 20,
        Warn     = 30,
        Info     = 40,
        Debug    = 50
    };


    // FIXME copy the formatter
    
    // FIXME define some template base case
    // and a full spezialisation
    struct FormatterBase 

    // Default formatter
    // FIXME construct elements that can be chained
    struct DefaultFormatter 

    // Use it
    template <class FormatterPolicy = DefaultFormatter>
    class Logger
    {
        std::ofstream m_os;
        logging_level m_level = Info;

        public:
            Logger() = default;
            Logger(const std::string& path) : m_os{path} {}

            void set_debug_level(logging_level level) { m_level = level; }

            template <typename ArgType>
            void log(logging_level level, const ArgType& msg) {
                if (level <= m_level) {
                    FormatterPolicy::format(std::cerr, msg);
                    if (m_os.is_open())
                        FormatterPolicy::format(m_os, msg);
                } 
            }

            template <typename ArgType> void debug(const ArgType& msg) { log(Debug, msg); }
            template <typename ArgType> void info(const ArgType& msg) { log(Info, msg); }
            template <typename ArgType> void warn(const ArgType& msg) { log(Warn, msg); }
            template <typename ArgType> void critical(const ArgType& msg) { log(Critical, msg); }
            template <typename ArgType> void error(const ArgType& msg) { log(Error, msg); }
    };


    // Part 2 (Default logger)
    namespace internal {
        // FIXME m_default_logger;
    }


    void set_debug_level(logging_level level); 
    template <typename ArgType> void debug(const ArgType& msg) { internal::m_default_logger.debug(msg); }
    template <typename ArgType> void info(const ArgType& msg) { internal::m_default_logger.info(msg); }
    template <typename ArgType> void warn(const ArgType& msg) { internal::m_default_logger. warn(msg); }
    template <typename ArgType> void critical(const ArgType& msg) { internal::m_default_logger.critical(msg); }
    template <typename ArgType> void error(const ArgType& msg) { internal::m_default_logger.error(msg); }



    // Part 3 (Stream Logger -> Pattern Adapter)
    // FIXME
    class StreamLogger
    {
        Logger<FormatterPolicy>         m_logger;
        logging_level                   m_flag = Info;

        public:
            StreamLogger() = default;
            StreamLogger(const std::string& path) : m_logger{path} {}

            friend
            StreamLogger& operator<< (StreamLogger& s, logging_level level) {
                s.m_flag = level;
                return s;
            }

            
            template <class ArgType>
            friend
            StreamLogger& operator<< (StreamLogger& s, const ArgType& msg) { s.m_logger.log(s.m_flag, msg); return s; }
    };
}