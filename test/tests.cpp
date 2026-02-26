// Copyright 2025 UNN-CS.

#include <gtest/gtest.h>
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value);
uint64_t nPrime(uint64_t n);
uint64_t nextPrime(uint64_t value);
uint64_t sumPrime(uint64_t hbound);

TEST(CheckPrimeTest, HandlesSmallNumbers) {
  EXPECT_FALSE(checkPrime(0));
  EXPECT_FALSE(checkPrime(1));
  EXPECT_TRUE(checkPrime(2));
  EXPECT_TRUE(checkPrime(3));
}

TEST(CheckPrimeTest, HandlesCompositeNumbers) {
  EXPECT_FALSE(checkPrime(4));
  EXPECT_FALSE(checkPrime(9));
  EXPECT_FALSE(checkPrime(100));
}

TEST(CheckPrimeTest, HandlesPrimeNumbers) {
  EXPECT_TRUE(checkPrime(5));
  EXPECT_TRUE(checkPrime(13));
  EXPECT_TRUE(checkPrime(97));
}

TEST(NPrimeTest, FirstPrime) {
  EXPECT_EQ(nPrime(1), 2);
}

TEST(NPrimeTest, ThirdPrime) {
  EXPECT_EQ(nPrime(3), 5);
}

TEST(NPrimeTest, TenthPrime) {
  EXPECT_EQ(nPrime(10), 29);
}

TEST(NextPrimeTest, AfterComposite) {
  EXPECT_EQ(nextPrime(4), 5);
}

TEST(NextPrimeTest, AfterPrime) {
  EXPECT_EQ(nextPrime(11), 13);
}

TEST(NextPrimeTest, LargerNumber) {
  EXPECT_EQ(nextPrime(100), 101);
}

TEST(SumPrimeTest, SmallRange) {
  EXPECT_EQ(sumPrime(10), 17);
}

TEST(SumPrimeTest, MediumRange) {
  EXPECT_EQ(sumPrime(15), 41);
}

TEST(SumPrimeTest, NoPrimes) {
  EXPECT_EQ(sumPrime(2), 0);
}
