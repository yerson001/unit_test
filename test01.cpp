void fake_fn(void *, uint32_t) { ; }
TEST_F(CmdProcessor, CmdProcessorEnqueueQueueFull)
{
    Retcode_T retVal = RETCODE_OK;
    xQueueSend_fake.return_val = errQUEUE_FULL;
    retVal = CmdProcessor_Enqueue(&cmdProcessor, fake_fn, NULL, 1);

    EXPECT_EQ(UINT32_C(1), xQueueSend_fake.call_count);
    EXPECT_EQ(RETCODE_FAILURE, Retcode_GetCode(retVal));
}

TEST_F(CmdProcessor, CmdProcessorEnqueueSuccess)
{
    Retcode_T retVal = RETCODE_OK;
    xQueueSend_fake.return_val = pdPASS;

    retVal = CmdProcessor_Enqueue(&cmdProcessor, fake_fn, NULL, 1);

    EXPECT_EQ(UINT32_C(1), xQueueSend_fake.call_count);
    EXPECT_EQ(RETCODE_OK, Retcode_GetCode(retVal));
}

TEST(LeapYearIterationTest, OddYearsAreNotLeapYears) {
    LeapYearCalendar leapYearCalendar;
    auto oddYears = std::vector<int>{1, 3, 711, 2013};
    for (auto oddYear :  oddYears) {
        ASSERT_FALSE(leapYearCalendar.isLeap(oddYear));
    }
}

TEST(CalcTest, Add) {
    ASSERT_EQ(2, add(1, 1));
    ASSERT_EQ(5, add(3, 2));
    ASSERT_EQ(10, add(7, 3));
}
