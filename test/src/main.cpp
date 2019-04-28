/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2017, Younguk Kim.
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
 * @file        main.cpp
 * @author      Younguk Kim
 * @date        2017
 */

#include <iostream>

#include <bluekyulib/system/path.hpp>
#include <bluekyulib/string.hpp>

#if BOOST_VERSION >= 106100
#include <boost/dll/runtime_symbol_info.hpp>
#endif

template <class T>
void test_parse_numeric(const std::string& src)
{
    auto result = bluekyulib::parse_numeric<T>(src);
    if (result)
        std::cout << "Parse: " << *result << std::endl;
    else
        std::cout << "Failed to parse: " << src << std::endl;
}

int main(int argc, char* argv[])
{
    std::cout << "Program location: " << bluekyulib::system::get_application_path() << std::endl;

#if BOOST_VERSION >= 106100
    std::cout << "Program location (boost-dll): " << boost::dll::program_location() << std::endl;
#endif

    std::cout << std::endl << std::endl;

    std::string str = "Hello, World!";
    std::cout << "String: " << str << std::endl;
    for (const auto& word: bluekyulib::split(str, std::regex(" ")))
        std::cout << "'" << word << "'" << std::endl;

    // Test parse_numeric
    test_parse_numeric<int>("-123");
    test_parse_numeric<int>("-12.3");
    test_parse_numeric<unsigned int>("123");
    test_parse_numeric<unsigned int>("-123");
    test_parse_numeric<float>("-12.3");
    test_parse_numeric<float>(".123");

    return 0;
}
