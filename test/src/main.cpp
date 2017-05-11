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
 * @file        main.cpp
 * @author      Younguk Kim
 * @date        2017
 */

#include <iostream>

#include <bluekyulib/system/path.hpp>

#if BOOST_VERSION >= 106100
#include <boost/dll/runtime_symbol_info.hpp>
#endif

int main(int argc, char* argv[])
{
    std::cout << "Program location: " << bluekyulib::system::get_application_path() << std::endl;

#if BOOST_VERSION >= 106100
    std::cout << "Program location (boost-dll): " << boost::dll::program_location() << std::endl;
#endif

    return 0;
}
