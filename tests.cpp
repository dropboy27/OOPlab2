#include <gtest/gtest.h>
#include <sstream>
#include <utility>
#include "mystring.h"

const size_t NPOS = static_cast<size_t>(-1);

TEST(Constructors, Default)
{
    String s;
    EXPECT_EQ(s.size(), 0u);
    EXPECT_STREQ(s.data(), "");
}

TEST(Constructors, FromCString)
{
    String s("Hello");
    EXPECT_EQ(s.size(), 5u);
    EXPECT_STREQ(s.data(), "Hello");
}

TEST(Constructors, FromNullptr)
{
    String s(nullptr);
    EXPECT_EQ(s.size(), 0u);
    EXPECT_STREQ(s.data(), "");
}

TEST(Copy, IsDeep)
{
    String a("abc");
    String b(a);
    b.push_back('d');
    EXPECT_STREQ(a.data(), "abc");
    EXPECT_STREQ(b.data(), "abcd");
}

TEST(Move, EmptiesSource)
{
    String a("abc");
    String b(std::move(a));
    EXPECT_STREQ(b.data(), "abc");
    EXPECT_EQ(a.size(), 0u);
}

TEST(Assign, Copy)
{
    String a("abc");
    String b;
    b = a;
    EXPECT_STREQ(b.data(), "abc");
    EXPECT_STREQ(a.data(), "abc");
}

TEST(Assign, SelfAssignment)
{
    String a("abc");
    a = a;
    EXPECT_STREQ(a.data(), "abc");
}

TEST(PushBack, BufferGrowth)
{
    String s;
    for (int i = 0; i < 100; i++)
    {
        s.push_back('x');
    }
    EXPECT_EQ(s.size(), 100u);
    EXPECT_EQ(s.data()[100], '\0');
}

TEST(Append, Regular)
{
    String s("Hello");
    s.append(", World!");
    EXPECT_STREQ(s.data(), "Hello, World!");
}

TEST(Append, Nullptr)
{
    String s("abc");
    s.append(nullptr);
    EXPECT_STREQ(s.data(), "abc");
}

TEST(Print, Regular)
{
    String s("Hello");
    std::ostringstream out;
    s.print(out);
    EXPECT_EQ(out.str(), "Hello");
}

TEST(Find, ControlExample)
{
    String s("Hello, World!");
    EXPECT_EQ(s.find("World"), 7u);
}

TEST(Find, NotFound)
{
    String s("abc");
    EXPECT_EQ(s.find("x"), NPOS);
}

TEST(WordHistogram, ControlExample)
{
    String s("a bb a c a");
    String words[10];
    size_t counts[10];
    size_t n = 0;
    s.word_histogram(words, counts, n);
    EXPECT_EQ(n, 3u);
    EXPECT_STREQ(words[0].data(), "a");
    EXPECT_EQ(counts[0], 3u);
    EXPECT_STREQ(words[1].data(), "bb");
    EXPECT_EQ(counts[1], 1u);
    EXPECT_STREQ(words[2].data(), "c");
    EXPECT_EQ(counts[2], 1u);
}

TEST(WordHistogram, EmptyString)
{
    String s;
    String words[10];
    size_t counts[10];
    size_t n = 5;
    s.word_histogram(words, counts, n);
    EXPECT_EQ(n, 0u);
}