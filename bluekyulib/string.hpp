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
* @file        string.hpp
* @author      Younguk Kim
* @date        2017
*/

#pragma once

#include <string>
#include <vector>
#include <regex>

namespace bluekyulib {

/**
 * Split string @p src with given @p regex.
 *
 * @note: https://gist.github.com/filsinger/3910580
 */
inline std::vector<std::string> split(const std::string& src, const std::regex& regex)
{
    return { std::sregex_token_iterator(src.begin(), src.end(), regex, -1), std::sregex_token_iterator() };
}

}
