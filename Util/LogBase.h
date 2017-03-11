#ifndef LOG_H
#define LOG_H

#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Layout.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>

#include <boost/format.hpp>
#include <memory>
#include <bitset>
#include <mutex>
#include <string>

using namespace std;

namespace util {

namespace log {
enum Severity {
    verbose,
    info,
    warning,
    error,
    timer,
    severity_count
};

typedef boost::format Fmt;
}


class LogBase {

public:
    static LogBase* Inst();
    void Log(const log::Fmt& msg, log::Severity s = log::info);
    bool Enable(log::Severity s, bool enable = true);
    bool IsEnabled(log::Severity s) const;
    void DisableAll(bool b);
    virtual ~LogBase();

private:
    LogBase();

private:
    std::bitset<log::severity_count> m_enabled;
    static LogBase *instance;
    log4cpp::Appender *appender;
    log4cpp::Category &root = log4cpp::Category::getRoot();

    struct timespec start;
    vector<pair<string, string>> measurements;
};

void Log(const std::string& str, log::Severity s = log::info);
void DisableAllLogs(bool b);

template <typename P1>
void Log(const std::string& fmt, const P1& p1, log::Severity s = log::info) {
    LogBase::Inst()->Log(log::Fmt(fmt) % p1, s);
}

template <typename P1, typename P2>
void Log(const std::string& fmt, const P1& p1, const P2& p2, log::Severity s = log::info) {
    LogBase::Inst()->Log( log::Fmt(fmt) % p1 % p2, s ) ;
}

template <typename P1, typename P2, typename P3>
void Log(const std::string& fmt, const P1& p1, const P2& p2, const P3& p3, log::Severity s = log::info) {
    LogBase::Inst()->Log(log::Fmt(fmt) % p1 % p2 % p3, s);
}

template <typename P1, typename P2, typename P3, typename P4>
void Log(const std::string& fmt, const P1& p1, const P2& p2, const P3& p3, const P4& p4, log::Severity s = log::info) {
    LogBase::Inst()->Log(log::Fmt(fmt) % p1 % p2 % p3 % p4, s);
}

template <typename P1, typename P2, typename P3, typename P4, typename P5>
void Log(const std::string& fmt, const P1& p1, const P2& p2, const P3& p3, const P4& p4, const P5& p5, log::Severity s = log::info) {
    LogBase::Inst()->Log(log::Fmt(fmt) % p1 % p2 % p3 % p4 % p5, s);
}

}

#endif
