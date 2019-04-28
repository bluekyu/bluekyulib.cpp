/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2017-2019, Younguk Kim.
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
* @date        2017-2019
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

#include <boost/spirit/include/qi_parse.hpp>
#include <boost/spirit/include/qi_numeric.hpp>
#include <boost/optional.hpp>

namespace bluekyulib {

/**
 * @note: http://www.kumobius.com/2013/08/c-string-to-int/
 */
inline bool parse_numeric(const std::string& src, int& result)
{
    auto iter = src.cbegin();
    bool ok = boost::spirit::qi::parse(iter, src.cend(), boost::spirit::int_, result);
    return ok && (iter == src.cend());
}

inline bool parse_numeric(const std::string& src, unsigned int& result)
{
    auto iter = src.cbegin();
    bool ok = boost::spirit::qi::parse(iter, src.cend(), boost::spirit::uint_, result);
    return ok && (iter == src.cend());
}

inline bool parse_numeric(const std::string& src, float& result)
{
    auto iter = src.cbegin();
    bool ok = boost::spirit::qi::parse(iter, src.cend(), boost::spirit::float_, result);
    return ok && (iter == src.cend());
}

template <class T>
inline boost::optional<T> parse_numeric(const std::string& src);

template <>
inline boost::optional<int> parse_numeric(const std::string& src)
{
    int result;
    bool ok = parse_numeric(src, result);
    return { ok, result };
}

template <>
inline boost::optional<unsigned int> parse_numeric(const std::string& src)
{
    unsigned int result;
    bool ok = parse_numeric(src, result);
    return { ok, result };
}

template <>
inline boost::optional<float> parse_numeric(const std::string& src)
{
    float result;
    bool ok = parse_numeric(src, result);
    return { ok, result };
}

}
