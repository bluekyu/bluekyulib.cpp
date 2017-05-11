/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2016, Center of human-centered interaction for coexistence.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * @file        path.hpp
 * @author      Younguk Kim
 * @date        2016
 */

#pragma once

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
 *
 * @note    boost 1.61 supports DLL library and `boost::dll::program_location()` function.
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

}
}
