#include "date.h"

TEST(days_gets_testcase, days_gets_test) {
	Date date1(29, 4, 2020);
	EXPECT_EQ(date1.get_day(), 29);
	EXPECT_EQ(date1.get_month(), 4);
	EXPECT_EQ(date1.get_year(), 2020);
}

TEST(days_between_testcase, days_between_test) {
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