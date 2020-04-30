#include "date.h"

TEST(days_between_testcase, days_between_test) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
  Date date1;
  EXPECT_EQ(date1.get_month(), 1);
  EXPECT_EQ(date1.days_between(2, 1, 1900), 1);
  EXPECT_EQ(date1.days_between(1, 1, 1901), 365);
  EXPECT_EQ(date1.days_between(2, 1, 1901), 366);
}

TEST(days_newyear_testcase, days_newyear_test) {
	Date date1;
	date1.next_day();
	EXPECT_EQ(date1.days_since_newyear(), 1);
}