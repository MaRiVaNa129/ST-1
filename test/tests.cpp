// Copyright 2026 UNN-CS

#include <gtest/gtest.h>
#include <cstdint>
#include "alg.h"

TEST(checkPrimeTest, ZeroAndOne) {
    EXPECT_FALSE(checkPrime(0));
    EXPECT_FALSE(checkPrime(1));
}

TEST(checkPrimeTest, SmallPrimes) {
    EXPECT_TRUE(checkPrime(2));
    EXPECT_TRUE(checkPrime(3));
    EXPECT_TRUE(checkPrime(5));
    EXPECT_TRUE(checkPrime(7));
}

TEST(checkPrimeTest, SmallComposites) {
    EXPECT_FALSE(checkPrime(4));
    EXPECT_FALSE(checkPrime(6));
    EXPECT_FALSE(checkPrime(8));
    EXPECT_FALSE(checkPrime(9));
    EXPECT_FALSE(checkPrime(10));
}

TEST(checkPrimeTest, MediumNumbers) {
    EXPECT_TRUE(checkPrime(11));
    EXPECT_TRUE(checkPrime(13));
    EXPECT_TRUE(checkPrime(17));
    EXPECT_TRUE(checkPrime(19));
    EXPECT_TRUE(checkPrime(23));
    EXPECT_FALSE(checkPrime(21));
    EXPECT_FALSE(checkPrime(25));
    EXPECT_FALSE(checkPrime(27));
}

TEST(checkPrimeTest, LargePrime) {
    EXPECT_TRUE(checkPrime(97));
    EXPECT_TRUE(checkPrime(101));
    EXPECT_TRUE(checkPrime(997));
}

TEST(checkPrimeTest, EvenNumbers) {
    for (uint64_t i = 4; i <= 100; i += 2) {
        EXPECT_FALSE(checkPrime(i));
    }
}

TEST(nPrimeTest, FirstPrimes) {
    EXPECT_EQ(nPrime(1), 2);
    EXPECT_EQ(nPrime(2), 3);
    EXPECT_EQ(nPrime(3), 5);
    EXPECT_EQ(nPrime(4), 7);
    EXPECT_EQ(nPrime(5), 11);
}

TEST(nPrimeTest, LaterPrimes) {
    EXPECT_EQ(nPrime(10), 29);
    EXPECT_EQ(nPrime(15), 47);
    EXPECT_EQ(nPrime(20), 71);
    EXPECT_EQ(nPrime(25), 97);
}

TEST(nPrimeTest, ZeroInput) {
    EXPECT_EQ(nPrime(0), 0);
}

TEST(nPrimeTest, HundredthPrime) {
    EXPECT_EQ(nPrime(100), 541);
}

TEST(nextPrimeTest, FromSmallNumbers) {
    EXPECT_EQ(nextPrime(0), 2);
    EXPECT_EQ(nextPrime(1), 2);
    EXPECT_EQ(nextPrime(2), 3);
    EXPECT_EQ(nextPrime(3), 5);
    EXPECT_EQ(nextPrime(4), 5);
}

TEST(nextPrimeTest, FromComposites) {
    EXPECT_EQ(nextPrime(6), 7);
    EXPECT_EQ(nextPrime(8), 11);
    EXPECT_EQ(nextPrime(9), 11);
    EXPECT_EQ(nextPrime(10), 11);
    EXPECT_EQ(nextPrime(12), 13);
    EXPECT_EQ(nextPrime(14), 17);
}

TEST(nextPrimeTest, FromPrimes) {
    EXPECT_EQ(nextPrime(5), 7);
    EXPECT_EQ(nextPrime(7), 11);
    EXPECT_EQ(nextPrime(11), 13);
    EXPECT_EQ(nextPrime(13), 17);
    EXPECT_EQ(nextPrime(17), 19);
}

TEST(nextPrimeTest, FromLargeNumbers) {
    EXPECT_EQ(nextPrime(100), 101);
    EXPECT_EQ(nextPrime(200), 211);
    EXPECT_EQ(nextPrime(500), 503);
}

TEST(sumPrimeTest, SmallBounds) {
    EXPECT_EQ(sumPrime(2), 0);
    EXPECT_EQ(sumPrime(3), 2);
    EXPECT_EQ(sumPrime(4), 5);
    EXPECT_EQ(sumPrime(5), 5);
}

TEST(sumPrimeTest, MediumBounds) {
    EXPECT_EQ(sumPrime(10), 17);
    EXPECT_EQ(sumPrime(15), 41);
    EXPECT_EQ(sumPrime(20), 77);
}

TEST(sumPrimeTest, KnownValues) {
    EXPECT_EQ(sumPrime(30), 129);
    EXPECT_EQ(sumPrime(100), 1060);
}

TEST(sumPrimeTest, ZeroAndOne) {
    EXPECT_EQ(sumPrime(0), 0);
    EXPECT_EQ(sumPrime(1), 0);
}
