/**
 * @file        path.hpp
 * @author      Younguk Kim
 * @date        2016
 * @copyright   The MIT License (see the LICENSE file.)
 */

#ifndef BLUEKYULIB_SYSTEM_PATH_HPP
#define BLUEKYULIB_SYSTEM_PATH_HPP

#include <system_error>

#include <boost/filesystem/path.hpp>
#include <boost/predef/os.h>

#if BOOST_OS_LINUX
#include <unistd.h>
#include <limits.h>
#elif BOOST_OS_WINDOWS
#include <windows.h>
#else
#error Not implemented!
#endif

namespace bluekyulib {
namespace system {

/**
 * Get absolute path of the current application (executable file).
 *
 * @return Absolute path of the current application.
 */
inline boost::filesystem::path get_application_path(void)
{
#if BOOST_OS_LINUX

    // See CERT POS30-C for secure code.
    boost::filesystem::path::value_type path[PATH_MAX+1];
    ssize_t length = ::readlink("/proc/self/exe", path, sizeof(path)-1);
    
    if (length != -1)
    {
        path[length] = '\0';
        return boost::filesystem::path(path);
    }
    else
    {
        throw std::system_error(std::error_code(GetLastError(), std::system_category()), "Fail to run readlink.");
    }

#elif BOOST_OS_WINDOWS

    boost::filesystem::path::value_type path[MAX_PATH+1];
    const DWORD length = ::GetModuleFileNameW(NULL, path, sizeof(path)-1);

    if (length != 0)
    {
        path[length] = L'\0';
        return boost::filesystem::path(path);
    }
    else
    {
        throw std::system_error(std::error_code(GetLastError(), std::system_category()), "Fail to run GetModuleFileNameW.");
    }

#endif
}

}   // namespace system
}   // namespace bluekyulib

#endif  // #ifndef BLUEKYULIB_SYSTEM_PATH_HPP
