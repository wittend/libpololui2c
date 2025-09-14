/// C++
#include <gtest/gtest.h>

#include "cmake-build-debug/_deps/googletest-src/googletest/include/gtest/gtest.h"
#include "cmake-build-debug/_deps/googletest-src/googletest/include/gtest/internal/gtest-internal.h"
#include "cmake-build-release/_deps/googletest-src/googletest/include/gtest/gtest-test-part.h"
#include "cmake-build-release/_deps/googletest-src/googletest/include/gtest/gtest_pred_impl.h"

extern "C" {
#include "pololu_i2c.h"
}

TEST(AdapterInit, InitializesFdToMinusOne) {
    pololu_i2c_adapter a;
    a.fd = 123; // ensure it's not -1 to start
    pololu_i2c_init(&a);
    EXPECT_EQ(a.fd, -1);
}

TEST(ErrorStrings, KnownCodesReturnNonEmptyDescriptions) {
    EXPECT_STREQ(pololu_i2c_error_string(ERROR_NONE), "No error");
    EXPECT_STRNE(pololu_i2c_error_string(ERROR_PROTOCOL), "");
    EXPECT_STRNE(pololu_i2c_error_string(ERROR_TIMEOUT), "");
    EXPECT_STRNE(pololu_i2c_error_string(ERROR_ADDRESS_NACK), "");
    // Should be resilient to negative inputs (API returns abs(error))
    EXPECT_STREQ(pololu_i2c_error_string(-ERROR_TIMEOUT), "Timeout");
}
