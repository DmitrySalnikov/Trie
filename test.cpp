#include "Trie.h"
#include "../gtest/gtest/gtest.h"

TEST(trie, add) {
    Trie example;
    example.add("Vasya", "46464");
    example.add("Petya", "asdad");
    example.add("Alla", "sdfsfs");
    example.add("Alladin", "433");
}

TEST(trie, find) {
    Trie example;
    example.add("Vasya", "46464");
    example.add("Petya", "asdad");
    example.add("Alla", "sdfsfs");
    example.add("Alladin", "433");
    EXPECT_EQ(nullptr, example.find("lolo"));
    EXPECT_EQ(0, strcmp("46464", example.find("Vasya")));
    EXPECT_EQ(0, strcmp("asdad", example.find("Petya")));
    EXPECT_EQ(0, strcmp("433", example.find("Alladin")));
    EXPECT_EQ(0, strcmp("sdfsfs", example.find("Alla")));
}

TEST(trie, remove) {
    Trie example;
    example.add("Vasya", "46464");
    example.add("Petya", "asdad");
    example.add("Alla", "sdfsfs");
    example.add("Alladin", "433");
    EXPECT_EQ(nullptr, example.find("lolo"));
    example.remove("Vasya");
    EXPECT_EQ(nullptr, example.find("Vasya"));
    example.remove("Petya");
    EXPECT_EQ(nullptr, example.find("Petya"));
    example.remove("Alladin");
    EXPECT_EQ(nullptr, example.find("Alladin"));
    EXPECT_EQ(0, strcmp("sdfsfs", example.find("Alla")));
    example.remove("Alla");
    EXPECT_EQ(nullptr, example.find("Alla"));
    EXPECT_EQ(nullptr, example.find("Alladin"));
}

TEST(trie, simple) {
    Trie example;
    example.add("Vasya", "46464");
    example.add("Petya", "asdad");
    example.add("Alla", "sdfsfs");
    example.add("Alladin", "433");
    example.remove("lolo");
    EXPECT_EQ(0, strcmp("433", example.find("Alladin")));
    EXPECT_EQ(nullptr, example.find("lolo"));
    example.add("Alla", "8952");
    EXPECT_EQ(0, strcmp("8952", example.find("Alla")));
    example.remove("Alladin");
    EXPECT_EQ(0, strcmp("8952", example.find("Alla")));
    example.remove("Alla");
    EXPECT_EQ(nullptr, example.find("Alla"));
    example.add("Vasyas", "36464");
    EXPECT_EQ(0, strcmp("46464", example.find("Vasya")));
    EXPECT_EQ(0, strcmp("36464", example.find("Vasyas")));
    example.remove("Vasya");
    EXPECT_EQ(nullptr, example.find("Vasya"));
    EXPECT_EQ(0, strcmp("36464", example.find("Vasyas")));
    example.remove("Vasya");
    example.add("Petya", "2asdad");
    EXPECT_EQ(0, strcmp("2asdad", example.find("Petya")));
    example.remove("Petya");
    EXPECT_EQ(nullptr, example.find("Petya"));
}

TEST(trie, russian) {
    Trie example;
    example.add("Вася", "ляляля");
    example.add("Петя", "жужужу");
    example.add("Алла", "с наркoманами sdssdsd");
    example.add("Алладин", "433");
    example.remove("ололо");
    EXPECT_EQ(0, strcmp("433", example.find("Алладин")));
    EXPECT_EQ(nullptr, example.find("ололо"));
    example.add("Алла", "8952");
    EXPECT_EQ(0, strcmp("8952", example.find("Алла")));
    example.remove("Алладин");
    EXPECT_EQ(0, strcmp("8952", example.find("Алла")));
    example.remove("Алла");
    EXPECT_EQ(nullptr, example.find("Алла"));
    example.add("Васяс", "36464");
    EXPECT_EQ(0, strcmp("ляляля", example.find("Вася")));
    EXPECT_EQ(0, strcmp("36464", example.find("Васяс")));
    example.remove("Вася");
    EXPECT_EQ(nullptr, example.find("Вася"));
    EXPECT_EQ(0, strcmp("36464", example.find("Васяс")));
    example.remove("Вася");
    example.add("Петя", "2жужужу");
    EXPECT_EQ(0, strcmp("2жужужу", example.find("Петя")));
    example.remove("Петя");
    EXPECT_EQ(nullptr, example.find("Петя"));
}

TEST(trie, empty) {
    Trie example;
    example.add("", "");
    EXPECT_EQ(0, strcmp("", example.find("")));
    example.add("", "343442");
    EXPECT_EQ(0, strcmp("343442", example.find("")));
    example.remove("");
    EXPECT_EQ(nullptr, example.find(""));
    example.add("", "");
    EXPECT_EQ(0, strcmp("", example.find("")));
    example.remove("");
    EXPECT_EQ(nullptr, example.find(""));
}

TEST(trie, once) {
    Trie example;
    example.add("q", "");
    EXPECT_EQ(0, strcmp("", example.find("q")));
    example.add("q", "343442");
    EXPECT_EQ(0, strcmp("343442", example.find("q")));
    example.remove("q");
    EXPECT_EQ(nullptr, example.find("q"));
    example.add("q", "q");
    EXPECT_EQ(0, strcmp("q", example.find("q")));
    example.remove("q");
    EXPECT_EQ(nullptr, example.find("q"));
}

GTEST_API_ int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
