#include <gtest/gtest.h>
#include <card.hpp>

// Example test case
TEST(libpoker_testCard, card_constructor) {
    auto c = poker::Card::newCard("2H");
    EXPECT_EQ(poker::Rank::TWO, c.value().rank);
    EXPECT_EQ(poker::Suite::HEART, c.value().suite);
    c = poker::Card::newCard("10H");
    EXPECT_EQ(poker::Rank::TEN, c.value().rank);
    EXPECT_EQ(poker::Suite::HEART, c.value().suite);
}

TEST(MyProjectTest, AnotherTest) {
    EXPECT_TRUE(true);
}