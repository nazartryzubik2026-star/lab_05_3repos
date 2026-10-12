#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5_3/Source.cpp" // Шлях до файлу Source.cpp

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab53
{
    TEST_CLASS(UnitTestLab53)
    {
    public:

        // Тест 1: Перевірка гілки |x| > 1 (наприклад, x = 2.0)
        TEST_METHOD(TestMethod_X_GreaterThan_1)
        {
            double x = 2.0;
            // Варіант 16: (cos^2(x) + 1) / e^x
            double expected = (cos(x) * cos(x) + 1.0) / exp(x);
            double actual = s(x);

            Assert::AreEqual(expected, actual, 0.00001);
        }

        // Тест 2: Перевірка гілки |x| <= 1 (наприклад, x = 0.5)
        TEST_METHOD(TestMethod_X_LessThanOrEqual_1)
        {
            double x = 0.5;
            // Еталонне значення суми ряду для k від 0 до 4:
            // x + x^3/3! + x^5/5! + x^7/7! + x^9/9!
            double expected = x
                + pow(x, 3) / 6.0
                + pow(x, 5) / 120.0
                + pow(x, 7) / 5040.0
                + pow(x, 9) / 362880.0;
            double actual = s(x);

            Assert::AreEqual(expected, actual, 0.00001);
        }
    };
}