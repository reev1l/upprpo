#include <gtest/gtest.h>

#include "candle.h"

class CandleTest : public ::testing::Test {

protected:

Candle greenCandle{10.0, 15.0, 8.0, 14.0};

Candle redCandle{14.0, 15.0, 8.0, 10.0};

Candle dojCandle{10.0, 10.0, 10.0, 10.0};

};

  

TEST_F(CandleTest, BodyContains_GreenCandle) {



EXPECT_TRUE(greenCandle.body_contains(10.0));

EXPECT_TRUE(greenCandle.body_contains(12.0));

EXPECT_TRUE(greenCandle.body_contains(14.0));

EXPECT_FALSE(greenCandle.body_contains(9.0));

EXPECT_FALSE(greenCandle.body_contains(15.0));

}

  

TEST_F(CandleTest, BodyContains_RedCandle) {



EXPECT_TRUE(redCandle.body_contains(10.0));

EXPECT_TRUE(redCandle.body_contains(12.0));

EXPECT_TRUE(redCandle.body_contains(14.0));

EXPECT_FALSE(redCandle.body_contains(9.0));

EXPECT_FALSE(redCandle.body_contains(15.0));

}

  

TEST_F(CandleTest, BodyContains_DojiCandle) {


EXPECT_TRUE(dojCandle.body_contains(10.0));

EXPECT_FALSE(dojCandle.body_contains(9.9));

EXPECT_FALSE(dojCandle.body_contains(10.1));

}

  

TEST_F(CandleTest, Contains_GreenCandle) {

EXPECT_TRUE(greenCandle.contains(8.0));

EXPECT_TRUE(greenCandle.contains(10.0));

EXPECT_TRUE(greenCandle.contains(15.0));

EXPECT_TRUE(greenCandle.contains(12.0));

EXPECT_FALSE(greenCandle.contains(7.0));

EXPECT_FALSE(greenCandle.contains(16.0));

}

  

TEST_F(CandleTest, Contains_Boundaries) {

Candle candle{5.0, 10.0, 0.0, 7.0};

EXPECT_TRUE(candle.contains(0.0)); 

EXPECT_TRUE(candle.contains(10.0)); 

EXPECT_FALSE(candle.contains(-0.1));

EXPECT_FALSE(candle.contains(10.1));

}



TEST_F(CandleTest, Contains_OutOfRange) {

EXPECT_FALSE(greenCandle.contains(7.5));

EXPECT_FALSE(greenCandle.contains(15.5));

}


TEST_F(CandleTest, FullSize_GreenCandle) {

EXPECT_DOUBLE_EQ(greenCandle.full_size(), 7.0);

}

  

TEST_F(CandleTest, FullSize_RedCandle) {

EXPECT_DOUBLE_EQ(redCandle.full_size(), 7.0);

}

  

TEST_F(CandleTest, FullSize_Various) {

Candle candle1{5.0, 15.0, 0.0, 10.0};

Candle candle2{10.0, 10.0, 10.0, 10.0};

EXPECT_DOUBLE_EQ(candle1.full_size(), 15.0);

EXPECT_DOUBLE_EQ(candle2.full_size(), 0.0);

}


TEST_F(CandleTest, BodySize_GreenCandle) {


EXPECT_DOUBLE_EQ(greenCandle.body_size(), 4.0);

}

  

TEST_F(CandleTest, BodySize_RedCandle) {

EXPECT_DOUBLE_EQ(redCandle.body_size(), 4.0);

}

  

TEST_F(CandleTest, BodySize_DojiCandle) {


EXPECT_DOUBLE_EQ(dojCandle.body_size(), 0.0);

}

  

TEST_F(CandleTest, BodySize_Various) {

Candle candle{5.0, 10.0, 0.0, 15.0};

EXPECT_DOUBLE_EQ(candle.body_size(), 10.0);

}


TEST_F(CandleTest, IsGreen_TrueForGreenCandle) {

EXPECT_TRUE(greenCandle.is_green());

}

  

TEST_F(CandleTest, IsGreen_FalseForRedCandle) {

EXPECT_FALSE(redCandle.is_green());

}

  

TEST_F(CandleTest, IsGreen_FalseForDojiCandle) {

EXPECT_FALSE(dojCandle.is_green());

}

  

TEST_F(CandleTest, IsGreen_EdgeCase) {

Candle almostGreen{10.0, 15.0, 8.0, 10.0000001};

EXPECT_TRUE(almostGreen.is_green());

}

  

TEST_F(CandleTest, IsRed_FalseForGreenCandle) {

EXPECT_FALSE(greenCandle.is_red());

}

  

TEST_F(CandleTest, IsRed_TrueForRedCandle) {

EXPECT_TRUE(redCandle.is_red());

}

  

TEST_F(CandleTest, IsRed_FalseForDojiCandle) {

EXPECT_FALSE(dojCandle.is_red());

}

  

TEST_F(CandleTest, IsRed_EdgeCase) {

Candle almostRed{10.0, 15.0, 8.0, 9.9999999};

EXPECT_TRUE(almostRed.is_red());

}

  

TEST_F(CandleTest, Integration_GreenCandleProperties) {

EXPECT_TRUE(greenCandle.is_green());

EXPECT_FALSE(greenCandle.is_red());

EXPECT_DOUBLE_EQ(greenCandle.full_size(), 7.0);

EXPECT_DOUBLE_EQ(greenCandle.body_size(), 4.0);

}

  

TEST_F(CandleTest, Integration_RedCandleProperties) {

EXPECT_TRUE(redCandle.is_red());

EXPECT_FALSE(redCandle.is_green());

EXPECT_DOUBLE_EQ(redCandle.full_size(), 7.0);

EXPECT_DOUBLE_EQ(redCandle.body_size(), 4.0);

}

TEST_F(CandleTest, Integration_ContainmentLogic) {

for (double price = 10.0; price <= 14.0; price += 0.5) {

EXPECT_TRUE(greenCandle.contains(price));

if (greenCandle.body_contains(price)) {

EXPECT_TRUE(greenCandle.contains(price));

}

}

}